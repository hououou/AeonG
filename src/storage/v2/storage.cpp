// Copyright 2022 Memgraph Ltd.
//
// Use of this software is governed by the Business Source License
// included in the file licenses/BSL.txt; by using this file, you agree to be bound by the terms of the Business Source
// License, and you may not use this file except in compliance with the Business Source License.
//
// As of the Change Date specified in that file, in accordance with
// the Business Source License, use of this software will be governed
// by the Apache License, Version 2.0, included in the file
// licenses/APL.txt.

#include "storage/v2/storage.hpp"
#include <algorithm>
#include <atomic>
#include <memory>
#include <mutex>
#include <variant>

#include <fstream>
#include <iostream>

#include "storage/v2/history_delta.hpp"

#include <gflags/gflags.h>

#include "io/network/endpoint.hpp"
#include "storage/v2/durability/durability.hpp"
#include "storage/v2/durability/metadata.hpp"
#include "storage/v2/durability/paths.hpp"
#include "storage/v2/durability/snapshot.hpp"
#include "storage/v2/durability/wal.hpp"
#include "storage/v2/edge_accessor.hpp"
#include "storage/v2/indices.hpp"
#include "storage/v2/mvcc.hpp"
#include "storage/v2/replication/config.hpp"
#include "storage/v2/transaction.hpp"
#include "storage/v2/vertex_accessor.hpp"
#include "utils/file.hpp"
#include "utils/logging.hpp"
#include "utils/memory_tracker.hpp"
#include "utils/message.hpp"
#include "utils/rw_lock.hpp"
#include "utils/spin_lock.hpp"
#include "utils/stat.hpp"
#include "utils/uuid.hpp"

/// REPLICATION ///
#include "storage/v2/replication/replication_client.hpp"
#include "storage/v2/replication/replication_server.hpp"
#include "storage/v2/replication/rpc.hpp"

#include "query/serialization/property_value.hpp"
#include "storage/v2/history_vertex.hpp"

namespace storage {

namespace {
enum class ObjectType : uint8_t { MAP, TEMPORAL_DATA };
}  // namespace

std::vector<storage::PropertyValue> DeserializePropertyValueList(const nlohmann::json::array_t &data);
std::map<std::string, storage::PropertyValue> DeserializePropertyValueMap(const nlohmann::json::object_t &data);

storage::PropertyValue DeserializePropertyValue(const nlohmann::json &data) {
  if (data.is_null()) {
    return storage::PropertyValue();
  }

  if (data.is_boolean()) {
    return storage::PropertyValue(data.get<bool>());
  }

  if (data.is_number_integer()) {
    return storage::PropertyValue(data.get<int64_t>());
  }

  if (data.is_number_float()) {
    return storage::PropertyValue(data.get<double>());
  }

  if (data.is_string()) {
    return storage::PropertyValue(data.get<std::string>());
  }

  if (data.is_array()) {
    return storage::PropertyValue(DeserializePropertyValueList(data));
  }

  MG_ASSERT(data.is_object(), "Unknown type found in the trigger storage");

  switch (data["type"].get<ObjectType>()) {
    case ObjectType::MAP:
      return storage::PropertyValue(DeserializePropertyValueMap(data));
    case ObjectType::TEMPORAL_DATA:
      return storage::PropertyValue(storage::TemporalData{data["value"]["type"].get<storage::TemporalType>(),
                                                          data["value"]["microseconds"].get<int64_t>()});
  }
}

std::vector<storage::PropertyValue> DeserializePropertyValueList(const nlohmann::json::array_t &data) {
  std::vector<storage::PropertyValue> property_values;
  property_values.reserve(data.size());
  for (const auto &value : data) {
    property_values.emplace_back(DeserializePropertyValue(value));
  }

  return property_values;
}

std::map<std::string, storage::PropertyValue> DeserializePropertyValueMap(const nlohmann::json::object_t &data) {
  MG_ASSERT(data.at("type").get<ObjectType>() == ObjectType::MAP, "Invalid map serialization");
  std::map<std::string, storage::PropertyValue> property_values;

  const nlohmann::json::object_t &values = data.at("value");
  for (const auto &[key, value] : values) {
    property_values.emplace(key, DeserializePropertyValue(value));
  }

  return property_values;
}

nlohmann::json SerializePropertyValueVector(const std::vector<storage::PropertyValue> &values);

nlohmann::json SerializePropertyValueMap(const std::map<std::string, storage::PropertyValue> &parameters);

nlohmann::json SerializePropertyValue(const storage::PropertyValue &property_value) {
  using Type = storage::PropertyValue::Type;
  switch (property_value.type()) {
    case Type::Null:
      return {};
    case Type::Bool:
      return property_value.ValueBool();
    case Type::Int:
      return property_value.ValueInt();
    case Type::Double:
      return property_value.ValueDouble();
    case Type::String:
      return property_value.ValueString();
    case Type::List:
      return SerializePropertyValueVector(property_value.ValueList());
    case Type::Map:
      return SerializePropertyValueMap(property_value.ValueMap());
    case Type::TemporalData:
      const auto temporal_data = property_value.ValueTemporalData();
      auto data = nlohmann::json::object();
      data.emplace("type", static_cast<uint64_t>(ObjectType::TEMPORAL_DATA));
      data.emplace("value", nlohmann::json::object({{"type", static_cast<uint64_t>(temporal_data.type)},
                                                    {"microseconds", temporal_data.microseconds}}));
      return data;
  }
}

nlohmann::json SerializePropertyValueVector(const std::vector<storage::PropertyValue> &values) {
  nlohmann::json array = nlohmann::json::array();
  for (const auto &value : values) {
    array.push_back(SerializePropertyValue(value));
  }
  return array;
}

nlohmann::json SerializePropertyValueMap(const std::map<std::string, storage::PropertyValue> &parameters) {
  nlohmann::json data = nlohmann::json::object();
  data.emplace("type", static_cast<uint64_t>(ObjectType::MAP));
  data.emplace("value", nlohmann::json::object());

  for (const auto &[key, value] : parameters) {
    data["value"][key] = SerializePropertyValue(value);
  }

  return data;
};

using OOMExceptionEnabler = utils::MemoryTracker::OutOfMemoryExceptionEnabler;

namespace {
[[maybe_unused]] constexpr uint16_t kEpochHistoryRetention = 1000;
}  // namespace

auto AdvanceToVisibleVertex(utils::SkipList<Vertex>::Iterator it, utils::SkipList<Vertex>::Iterator end,
                            std::optional<VertexAccessor> *vertex, Transaction *tx, View view, Indices *indices,
                            Constraints *constraints, Config::Items config) {
  while (it != end) {
    *vertex = VertexAccessor::Create(&*it, tx, indices, constraints, config, view);
    if (!*vertex) {
      ++it;
      continue;
    }
    break;
  }
  return it;
}

AllVerticesIterable::Iterator::Iterator(AllVerticesIterable *self, utils::SkipList<Vertex>::Iterator it)
    : self_(self),
      it_(AdvanceToVisibleVertex(it, self->vertices_accessor_.end(), &self->vertex_, self->transaction_, self->view_,
                                 self->indices_, self_->constraints_, self->config_)) {}

VertexAccessor AllVerticesIterable::Iterator::operator*() const { return *self_->vertex_; }

AllVerticesIterable::Iterator &AllVerticesIterable::Iterator::operator++() {
  ++it_;
  it_ = AdvanceToVisibleVertex(it_, self_->vertices_accessor_.end(), &self_->vertex_, self_->transaction_, self_->view_,
                               self_->indices_, self_->constraints_, self_->config_);
  return *this;
}

VerticesIterable::VerticesIterable(AllVerticesIterable vertices) : type_(Type::ALL) {
  new (&all_vertices_) AllVerticesIterable(std::move(vertices));
}

VerticesIterable::VerticesIterable(LabelIndex::Iterable vertices) : type_(Type::BY_LABEL) {
  new (&vertices_by_label_) LabelIndex::Iterable(std::move(vertices));
}

VerticesIterable::VerticesIterable(LabelPropertyIndex::Iterable vertices) : type_(Type::BY_LABEL_PROPERTY) {
  new (&vertices_by_label_property_) LabelPropertyIndex::Iterable(std::move(vertices));
}

VerticesIterable::VerticesIterable(VerticesIterable &&other) noexcept : type_(other.type_) {
  switch (other.type_) {
    case Type::ALL:
      new (&all_vertices_) AllVerticesIterable(std::move(other.all_vertices_));
      break;
    case Type::BY_LABEL:
      new (&vertices_by_label_) LabelIndex::Iterable(std::move(other.vertices_by_label_));
      break;
    case Type::BY_LABEL_PROPERTY:
      new (&vertices_by_label_property_) LabelPropertyIndex::Iterable(std::move(other.vertices_by_label_property_));
      break;
  }
}

VerticesIterable &VerticesIterable::operator=(VerticesIterable &&other) noexcept {
  switch (type_) {
    case Type::ALL:
      all_vertices_.AllVerticesIterable::~AllVerticesIterable();
      break;
    case Type::BY_LABEL:
      vertices_by_label_.LabelIndex::Iterable::~Iterable();
      break;
    case Type::BY_LABEL_PROPERTY:
      vertices_by_label_property_.LabelPropertyIndex::Iterable::~Iterable();
      break;
  }
  type_ = other.type_;
  switch (other.type_) {
    case Type::ALL:
      new (&all_vertices_) AllVerticesIterable(std::move(other.all_vertices_));
      break;
    case Type::BY_LABEL:
      new (&vertices_by_label_) LabelIndex::Iterable(std::move(other.vertices_by_label_));
      break;
    case Type::BY_LABEL_PROPERTY:
      new (&vertices_by_label_property_) LabelPropertyIndex::Iterable(std::move(other.vertices_by_label_property_));
      break;
  }
  return *this;
}

VerticesIterable::~VerticesIterable() {
  switch (type_) {
    case Type::ALL:
      all_vertices_.AllVerticesIterable::~AllVerticesIterable();
      break;
    case Type::BY_LABEL:
      vertices_by_label_.LabelIndex::Iterable::~Iterable();
      break;
    case Type::BY_LABEL_PROPERTY:
      vertices_by_label_property_.LabelPropertyIndex::Iterable::~Iterable();
      break;
  }
}

VerticesIterable::Iterator VerticesIterable::begin() {
  switch (type_) {
    case Type::ALL:
      return Iterator(all_vertices_.begin());
    case Type::BY_LABEL:
      return Iterator(vertices_by_label_.begin());
    case Type::BY_LABEL_PROPERTY:
      return Iterator(vertices_by_label_property_.begin());
  }
}

VerticesIterable::Iterator VerticesIterable::end() {
  switch (type_) {
    case Type::ALL:
      return Iterator(all_vertices_.end());
    case Type::BY_LABEL:
      return Iterator(vertices_by_label_.end());
    case Type::BY_LABEL_PROPERTY:
      return Iterator(vertices_by_label_property_.end());
  }
}

VerticesIterable::Iterator::Iterator(AllVerticesIterable::Iterator it) : type_(Type::ALL) {
  new (&all_it_) AllVerticesIterable::Iterator(std::move(it));
}

VerticesIterable::Iterator::Iterator(LabelIndex::Iterable::Iterator it) : type_(Type::BY_LABEL) {
  new (&by_label_it_) LabelIndex::Iterable::Iterator(std::move(it));
}

VerticesIterable::Iterator::Iterator(LabelPropertyIndex::Iterable::Iterator it) : type_(Type::BY_LABEL_PROPERTY) {
  new (&by_label_property_it_) LabelPropertyIndex::Iterable::Iterator(std::move(it));
}

VerticesIterable::Iterator::Iterator(const VerticesIterable::Iterator &other) : type_(other.type_) {
  switch (other.type_) {
    case Type::ALL:
      new (&all_it_) AllVerticesIterable::Iterator(other.all_it_);
      break;
    case Type::BY_LABEL:
      new (&by_label_it_) LabelIndex::Iterable::Iterator(other.by_label_it_);
      break;
    case Type::BY_LABEL_PROPERTY:
      new (&by_label_property_it_) LabelPropertyIndex::Iterable::Iterator(other.by_label_property_it_);
      break;
  }
}

VerticesIterable::Iterator &VerticesIterable::Iterator::operator=(const VerticesIterable::Iterator &other) {
  Destroy();
  type_ = other.type_;
  switch (other.type_) {
    case Type::ALL:
      new (&all_it_) AllVerticesIterable::Iterator(other.all_it_);
      break;
    case Type::BY_LABEL:
      new (&by_label_it_) LabelIndex::Iterable::Iterator(other.by_label_it_);
      break;
    case Type::BY_LABEL_PROPERTY:
      new (&by_label_property_it_) LabelPropertyIndex::Iterable::Iterator(other.by_label_property_it_);
      break;
  }
  return *this;
}

VerticesIterable::Iterator::Iterator(VerticesIterable::Iterator &&other) noexcept : type_(other.type_) {
  switch (other.type_) {
    case Type::ALL:
      new (&all_it_) AllVerticesIterable::Iterator(std::move(other.all_it_));
      break;
    case Type::BY_LABEL:
      new (&by_label_it_) LabelIndex::Iterable::Iterator(std::move(other.by_label_it_));
      break;
    case Type::BY_LABEL_PROPERTY:
      new (&by_label_property_it_) LabelPropertyIndex::Iterable::Iterator(std::move(other.by_label_property_it_));
      break;
  }
}

VerticesIterable::Iterator &VerticesIterable::Iterator::operator=(VerticesIterable::Iterator &&other) noexcept {
  Destroy();
  type_ = other.type_;
  switch (other.type_) {
    case Type::ALL:
      new (&all_it_) AllVerticesIterable::Iterator(std::move(other.all_it_));
      break;
    case Type::BY_LABEL:
      new (&by_label_it_) LabelIndex::Iterable::Iterator(std::move(other.by_label_it_));
      break;
    case Type::BY_LABEL_PROPERTY:
      new (&by_label_property_it_) LabelPropertyIndex::Iterable::Iterator(std::move(other.by_label_property_it_));
      break;
  }
  return *this;
}

VerticesIterable::Iterator::~Iterator() { Destroy(); }

void VerticesIterable::Iterator::Destroy() noexcept {
  switch (type_) {
    case Type::ALL:
      all_it_.AllVerticesIterable::Iterator::~Iterator();
      break;
    case Type::BY_LABEL:
      by_label_it_.LabelIndex::Iterable::Iterator::~Iterator();
      break;
    case Type::BY_LABEL_PROPERTY:
      by_label_property_it_.LabelPropertyIndex::Iterable::Iterator::~Iterator();
      break;
  }
}

VertexAccessor VerticesIterable::Iterator::operator*() const {
  switch (type_) {
    case Type::ALL:
      return *all_it_;
    case Type::BY_LABEL:
      return *by_label_it_;
    case Type::BY_LABEL_PROPERTY:
      return *by_label_property_it_;
  }
}

VerticesIterable::Iterator &VerticesIterable::Iterator::operator++() {
  switch (type_) {
    case Type::ALL:
      ++all_it_;
      break;
    case Type::BY_LABEL:
      ++by_label_it_;
      break;
    case Type::BY_LABEL_PROPERTY:
      ++by_label_property_it_;
      break;
  }
  return *this;
}

bool VerticesIterable::Iterator::operator==(const Iterator &other) const {
  switch (type_) {
    case Type::ALL:
      return all_it_ == other.all_it_;
    case Type::BY_LABEL:
      return by_label_it_ == other.by_label_it_;
    case Type::BY_LABEL_PROPERTY:
      return by_label_property_it_ == other.by_label_property_it_;
  }
}

Storage::Storage(Config config)
    : indices_(&constraints_, config.items),
      isolation_level_(config.transaction.isolation_level),
      config_(config),
      snapshot_directory_(config_.durability.storage_directory / durability::kSnapshotDirectory),
      wal_directory_(config_.durability.storage_directory / durability::kWalDirectory),
      lock_file_path_(config_.durability.storage_directory / durability::kLockFile),
      uuid_(utils::GenerateUUID()),
      epoch_id_(utils::GenerateUUID()),
      global_locker_(file_retainer_.AddLocker()) {
        //hjm begin
      // saved_history_deltas_.init(config_.durability.storage_directory/"history_deltas");
         saved_history_deltas_.emplace(config_.durability.storage_directory/"history_deltas",config_.items.realTimeFlag);
        //recover kv's time_table index
        // saved_history_deltas_->GetTimeTableAll(); //hjm begin timetable
        //hjm end
  if (config_.durability.snapshot_wal_mode != Config::Durability::SnapshotWalMode::DISABLED ||
      config_.durability.snapshot_on_exit || config_.durability.recover_on_startup) {
    // Create the directory initially to crash the database in case of
    // permission errors. This is done early to crash the database on startup
    // instead of crashing the database for the first time during runtime (which
    // could be an unpleasant surprise).
    utils::EnsureDirOrDie(snapshot_directory_);
    // Same reasoning as above.
    utils::EnsureDirOrDie(wal_directory_);

    // Verify that the user that started the process is the same user that is
    // the owner of the storage directory.
    durability::VerifyStorageDirectoryOwnerAndProcessUserOrDie(config_.durability.storage_directory);

    // Create the lock file and open a handle to it. This will crash the
    // database if it can't open the file for writing or if any other process is
    // holding the file opened.
    lock_file_handle_.Open(lock_file_path_, utils::OutputFile::Mode::OVERWRITE_EXISTING);
    MG_ASSERT(lock_file_handle_.AcquireLock(),
              "Couldn't acquire lock on the storage directory {}"
              "!\nAnother Memgraph process is currently running with the same "
              "storage directory, please stop it first before starting this "
              "process!",
              config_.durability.storage_directory);
  }
  if (config_.durability.recover_on_startup) {
    auto info = durability::RecoverData(snapshot_directory_, wal_directory_, &uuid_, &epoch_id_, &epoch_history_,
                                        &vertices_, &edges_, &edge_count_, &name_id_mapper_, &indices_, &constraints_,
                                        config_.items, &wal_seq_num_);
    if (info) {
      vertex_id_ = info->next_vertex_id;
      edge_id_ = info->next_edge_id;
      timestamp_ = std::max(timestamp_, info->next_timestamp);
      if (info->last_commit_timestamp) {
        last_commit_timestamp_ = *info->last_commit_timestamp;
      }
    }
  } else if (config_.durability.snapshot_wal_mode != Config::Durability::SnapshotWalMode::DISABLED ||
             config_.durability.snapshot_on_exit) {
    bool files_moved = false;
    auto backup_root = config_.durability.storage_directory / durability::kBackupDirectory;
    for (const auto &[path, dirname, what] :
         {std::make_tuple(snapshot_directory_, durability::kSnapshotDirectory, "snapshot"),
          std::make_tuple(wal_directory_, durability::kWalDirectory, "WAL")}) {
      if (!utils::DirExists(path)) continue;
      auto backup_curr = backup_root / dirname;
      std::error_code error_code;
      for (const auto &item : std::filesystem::directory_iterator(path, error_code)) {
        utils::EnsureDirOrDie(backup_root);
        utils::EnsureDirOrDie(backup_curr);
        std::error_code item_error_code;
        std::filesystem::rename(item.path(), backup_curr / item.path().filename(), item_error_code);
        MG_ASSERT(!item_error_code, "Couldn't move {} file {} because of: {}", what, item.path(),
                  item_error_code.message());
        files_moved = true;
      }
      MG_ASSERT(!error_code, "Couldn't backup {} files because of: {}", what, error_code.message());
    }
    if (files_moved) {
      spdlog::warn(
          "Since Memgraph was not supposed to recover on startup and "
          "durability is enabled, your current durability files will likely "
          "be overridden. To prevent important data loss, Memgraph has stored "
          "those files into a .backup directory inside the storage directory.");
    }
  }
  //hjm begin rocksdb retention
  if (config_.rocksdb_retention.retention_on_startup){
    reclaim_rocksdb_runner_.Run("Rocksdb GC", config_.rocksdb_retention.retention_interval, [this] { this->ReclaimHistoryRentention(config_.rocksdb_retention.retention_period); });
  }
  //hjm end
  if (config_.durability.snapshot_wal_mode != Config::Durability::SnapshotWalMode::DISABLED) {
    snapshot_runner_.Run("Snapshot", config_.durability.snapshot_interval, [this] {
      if (auto maybe_error = this->CreateSnapshot(); maybe_error.HasError()) {
        switch (maybe_error.GetError()) {
          case CreateSnapshotError::DisabledForReplica:
            spdlog::warn(
                utils::MessageWithLink("Snapshots are disabled for replicas.", "https://memgr.ph/replication"));
            break;
        }
      }
    });
  }
  if (config_.gc.type == Config::Gc::Type::PERIODIC) {
    gc_runner_.Run("Storage GC", config_.gc.interval, [this] { this->CollectGarbage<false>(); });
  }

  if (timestamp_ == kTimestampInitialId) {
    commit_log_.emplace();
  } else {
    commit_log_.emplace(timestamp_);
  }
}

Storage::~Storage() {
  if (config_.gc.type == Config::Gc::Type::PERIODIC) {
    gc_runner_.Stop();
  }
  {
    // Clear replication data
    replication_server_.reset();
    replication_clients_.WithLock([&](auto &clients) { clients.clear(); });
  }
  if (wal_file_) {
    wal_file_->FinalizeWal();
    wal_file_ = std::nullopt;
  }
  if (config_.durability.snapshot_wal_mode != Config::Durability::SnapshotWalMode::DISABLED) {
    snapshot_runner_.Stop();
  }
  if (config_.durability.snapshot_on_exit) {
    if (auto maybe_error = this->CreateSnapshot(); maybe_error.HasError()) {
      switch (maybe_error.GetError()) {
        case CreateSnapshotError::DisabledForReplica:
          spdlog::warn(utils::MessageWithLink("Snapshots are disabled for replicas.", "https://memgr.ph/replication"));
          break;
      }
    }
  }
}

Storage::Accessor::Accessor(Storage *storage, IsolationLevel isolation_level)
    : storage_(storage),
      // The lock must be acquired before creating the transaction object to
      // prevent freshly created transactions from dangling in an active state
      // during exclusive operations.
      storage_guard_(storage_->main_lock_),
      transaction_(storage->CreateTransaction(isolation_level)),
      is_transaction_active_(true),
      config_(storage->config_.items) {}

Storage::Accessor::Accessor(Accessor &&other) noexcept
    : storage_(other.storage_),
      storage_guard_(std::move(other.storage_guard_)),
      transaction_(std::move(other.transaction_)),
      commit_timestamp_(other.commit_timestamp_),
      is_transaction_active_(other.is_transaction_active_),
      config_(other.config_) {
  // Don't allow the other accessor to abort our transaction in destructor.
  other.is_transaction_active_ = false;
  other.commit_timestamp_.reset();
}

Storage::Accessor::~Accessor() {
  if (is_transaction_active_) {
    Abort();
  }

  FinalizeTransaction();
}
// hjm begin
//rocksdb 回收old history
bool Storage::ReclaimHistoryRentention(const std::chrono::milliseconds &retention_period){
  return saved_history_deltas_->RemoveOldHistory(retention_period);
}

//根据kv文件创建历史边
EdgeAccessor Storage::Accessor::CreateHistoryEdge(const EdgeAccessor&another,nlohmann::json gid_delta_,history_delta::historyContext &historyContext_){
  Delta *delta = nullptr;
  auto edge_it = new Edge(another.edge_.ptr->gid,delta,another.edge_.ptr->transaction_st,another.edge_.ptr->from_gid,another.edge_.ptr->to_gid);
  // auto edge= EdgeRef(&*edge_it);
  
  //current information
  //properties 
  auto maybe_properties=another.edge_.ptr->properties.Properties();
  for (const auto &prop : maybe_properties ){
    edge_it->properties.SetProperty(prop.first,prop.second);
  }

  //deleted info
  //properties 
  if(gid_delta_.find("SP")!=gid_delta_.end()){
    auto history_props_=gid_delta_["SP"];
    for(auto it_iter= history_props_.begin(); it_iter != history_props_.end(); ++it_iter){
      auto key = it_iter.key();
      auto value=it_iter.value();
      auto property_id = PropertyId::FromUint(storage_->name_id_mapper_.NameToId(key));
      auto property_value = DeserializePropertyValue(value);//query::serialization::
      edge_it->properties.SetProperty(property_id,property_value);
    }
  }
  
  //TT_TS TT_TE
  auto property_id = PropertyId::FromUint(storage_->name_id_mapper_.NameToId("transaction_ts"));
  auto property_value = storage::PropertyValue(gid_delta_["TT_TS"].get<int64_t>());
  edge_it->properties.SetProperty(property_id,property_value);

  auto property_id2 = PropertyId::FromUint(storage_->name_id_mapper_.NameToId("transaction_te"));
  auto property_value2 = storage::PropertyValue(gid_delta_["TT_TE"].get<int64_t>());
  edge_it->properties.SetProperty(property_id2,property_value2);

  edge_it->transaction_st=gid_delta_["TT_TS"].get<uint64_t>();
  // edge_it->tt_te=gid_delta_["TT_TE"].get<uint64_t>();

  auto edge= EdgeRef(&*edge_it);

 return EdgeAccessor(edge, another.edge_type_, another.from_vertex_, another.to_vertex_, another.transaction_, &storage_->indices_,&storage_->constraints_, another.config_);
  // return EdgeAccessor{edge, another.edge_type_, another.from_vertex_, another.to_vertex_, another.transaction_,another.indices_,another.constraints_,another.config_};
}

//根据delta创建历史边
EdgeAccessor Storage::Accessor::CreateHistoryEdge2(const EdgeAccessor &another,int index,history_delta::historyContext& historyContext_){
  Delta *delta = nullptr;
  auto edge_it = new Edge(another.edge_.ptr->gid,delta,another.edge_.ptr->transaction_st,another.edge_.ptr->from_gid,another.edge_.ptr->to_gid);
  auto maybe_properties=another.edge_.ptr->properties.Properties();
  for (const auto &prop : maybe_properties ){
    edge_it->properties.SetProperty(prop.first,prop.second);
  }

  //dead info
  auto deltas=another.edge_.ptr->delta;
  int index_=0;
  while (deltas != nullptr) {
    if(deltas->action==storage::Delta::Action::SET_PROPERTY){
      edge_it->properties.SetProperty(deltas->property.key,deltas->property.value);
    }
    //reconstruct end
    if(index_+1==index) break;
    // Move to the next delta.
    deltas = deltas->next.load(std::memory_order_acquire);    
    index_++;
  }
  
  //TT_TS TT_TE
  //Gid::FromUint
  auto property_id = PropertyId::FromUint(storage_->name_id_mapper_.NameToId("transaction_ts"));
  auto property_value = storage::PropertyValue((int64_t)deltas->transaction_st);
  edge_it->properties.SetProperty(property_id,property_value);

  auto property_id2 = PropertyId::FromUint(storage_->name_id_mapper_.NameToId("transaction_te"));
  auto property_value2 = storage::PropertyValue((int64_t)deltas->commit_timestamp);
  edge_it->properties.SetProperty(property_id2,property_value2);

  edge_it->transaction_st=deltas->transaction_st;
  // edge_it->tt_te=deltas->commit_timestamp;

  auto edge= EdgeRef(&*edge_it);

  // std::vector<EdgeAccessor> ret;
  // auto vertex_gid=another.from_vertex_->gid.AsUint();
  // if(all_vertex_.find(vertex_gid)!=all_vertex_.end()){
  //   for(auto vertex:all_vertex_[vertex_gid]){
  //     if(vertex.transaction_st>=deltas->transaction_st & vertex.tt_te<=deltas->commit_timestamp){
  //       ret.emplace_back(edge, another.edge_type_, vertex, another.to_vertex_, another.transaction_, &storage_->indices_,&storage_->constraints_, another.config_);
  //     }
  //   }
  // }else{
  //   ret.emplace_back(edge, another.edge_type_, another.from_vertex_, another.to_vertex_, another.transaction_, &storage_->indices_,&storage_->constraints_, another.config_);
  // }
  // return std::move(ret);
  return EdgeAccessor(edge, another.edge_type_, another.from_vertex_, another.to_vertex_, another.transaction_, &storage_->indices_,&storage_->constraints_, another.config_);
}

//根据kv文件创建历史节点
VertexAccessor Storage::Accessor::CreateHistoryVertex(const VertexAccessor &another,nlohmann::json gid_delta_,history_delta::historyContext &historyContext_){

  auto vertex = new Vertex(another.vertex_->gid,another.vertex_->delta,another.vertex_->transaction_st);
  //current information
  //properties 
  auto maybe_properties=another.vertex_->properties.Properties();
  for (const auto &prop : maybe_properties ){
    vertex->properties.SetProperty(prop.first,prop.second);
  }
  //labels 
  vertex->labels=another.vertex_->labels;
   //edges
  vertex->in_edges=another.vertex_->in_edges;
  vertex->out_edges=another.vertex_->out_edges;


  //deleted info
  //properties 
  if(gid_delta_.find("SP")!=gid_delta_.end()){
    auto history_props_=gid_delta_["SP"];
    for(auto it_iter= history_props_.begin(); it_iter != history_props_.end(); ++it_iter){
      auto key = it_iter.key();
      auto value=it_iter.value();
      auto property_id = PropertyId::FromUint(storage_->name_id_mapper_.NameToId(key));
      auto property_value = DeserializePropertyValue(value);//query::serialization::
      vertex->properties.SetProperty(property_id,property_value);
    }
  }
  
  //labels 
  if(gid_delta_.find("L")!=gid_delta_.end()){
    auto history_labels_=gid_delta_["L"].get<std::vector<std::pair<std::string,std::string>>>();;
    for (auto [key,value]:history_labels_){
       auto label_id = LabelId::FromUint(storage_->name_id_mapper_.NameToId(value));
       auto it = std::find(vertex->labels.begin(), vertex->labels.end(), label_id);
      if (key=="AL") {
        if (it != vertex->labels.end()) continue;
        vertex->labels.push_back(label_id);
      } else {
        if (it == vertex->labels.end()) continue;
        std::swap(*it, vertex->labels.back());
        vertex->labels.pop_back();
      }
    }
  }

  //TT_TS TT_TE
  auto property_id = PropertyId::FromUint(storage_->name_id_mapper_.NameToId("transaction_ts"));
  auto property_value = storage::PropertyValue(gid_delta_["TT_TS"].get<int64_t>());
  vertex->properties.SetProperty(property_id,property_value);

  auto property_id2 = PropertyId::FromUint(storage_->name_id_mapper_.NameToId("transaction_te"));
  auto property_value2 = storage::PropertyValue(gid_delta_["TT_TE"].get<int64_t>());
  vertex->properties.SetProperty(property_id2,property_value2);
  
  vertex->transaction_st=gid_delta_["TT_TS"].get<uint64_t>();
  // vertex->tt_te=gid_delta_["TT_TE"].get<uint64_t>();
  //TODO edges
  
  return VertexAccessor{vertex, another.transaction_, another.indices_, another.constraints_, another.config_};
}

//根据delta创建历史节点
VertexAccessor Storage::Accessor::CreateHistoryVertex2(const VertexAccessor &another,int index,history_delta::historyContext& historyContext_){
  auto deltas=another.vertex_->delta;
  auto vertex = new Vertex(another.vertex_->gid,deltas,another.vertex_->transaction_st);
  //Current info
  auto maybe_properties=another.vertex_->properties.Properties();
  for (const auto &prop : maybe_properties ){
    vertex->properties.SetProperty(prop.first,prop.second);
  }
  vertex->labels=another.vertex_->labels;
  vertex->in_edges=another.vertex_->in_edges;
  vertex->out_edges=another.vertex_->out_edges;
  
  //dead info
  int index_=0;
  while (deltas != nullptr) {
    switch (deltas->action) {
      case storage::Delta::Action::DELETE_OBJECT:{
        //  std::cout<<index_<<" DELETE_OBJECT\n";
        //do nothing
        break;
      }
      case storage::Delta::Action::RECREATE_OBJECT: {
        // std::cout<<index_<<" RECREATE_OBJECT\n";
        break;
      }
      case storage::Delta::Action::SET_PROPERTY: {
        // std::cout<<index_<<" SET_PROPERTY\n";
        vertex->properties.SetProperty(deltas->property.key,deltas->property.value);
        break;
      }
      case storage::Delta::Action::ADD_LABEL:
      case storage::Delta::Action::REMOVE_LABEL: {
        // std::cout<<index_<<" labels\n";
        auto label_id =deltas->label;
        auto it = std::find(vertex->labels.begin(), vertex->labels.end(), label_id);
        if (deltas->action==storage::Delta::Action::ADD_LABEL) {
          if (it != vertex->labels.end()) continue;
          vertex->labels.push_back(label_id);
        } else {
          if (it == vertex->labels.end()) continue;
          std::swap(*it, vertex->labels.back());
          vertex->labels.pop_back();
        }
        break;
      }
      case storage::Delta::Action::ADD_OUT_EDGE:{
        // std::cout<<index_<<" edges\n";
        break;
      }
      case storage::Delta::Action::REMOVE_OUT_EDGE: {
        // std::cout<<index_<<" edges\n";
        break;
      }
      case storage::Delta::Action::ADD_IN_EDGE:
      case storage::Delta::Action::REMOVE_IN_EDGE:
        // std::cout<<index_<<" edges\n";
        break;
    }
    //reconstruct end
    if(index_+1==index) break;

    // Move to the next delta.
    deltas = deltas->next.load(std::memory_order_acquire);    
    index_++;
  }
  //TT_TS TT_TE
  //Gid::FromUint
  auto property_id = PropertyId::FromUint(storage_->name_id_mapper_.NameToId("transaction_ts"));
  auto property_value = storage::PropertyValue((int64_t)deltas->transaction_st);
  vertex->properties.SetProperty(property_id,property_value);

  auto property_id2 = PropertyId::FromUint(storage_->name_id_mapper_.NameToId("transaction_te"));
  auto property_value2 = storage::PropertyValue((int64_t)deltas->commit_timestamp);
  vertex->properties.SetProperty(property_id2,property_value2);
  
  vertex->transaction_st=deltas->transaction_st;
  // vertex->tt_te=deltas->commit_timestamp;
  return VertexAccessor{vertex, another.transaction_, another.indices_, another.constraints_, another.config_};
}

//还原kv中的删除节点
storage::HistoryVertex Storage::Accessor::CreateHistoryDelteVertex(uint64_t gid,nlohmann::json gid_delta_){
  //properties
  std::vector<LabelId> maybe_labels;
  std::map<PropertyId, PropertyValue> maybe_properties;

  //properties 
  if(gid_delta_.find("SP")!=gid_delta_.end()){
    auto history_props_=gid_delta_["SP"];
    for(auto it_iter= history_props_.begin(); it_iter != history_props_.end(); ++it_iter){
      auto key = it_iter.key();
      auto value=it_iter.value();
      auto property_id = PropertyId::FromUint(storage_->name_id_mapper_.NameToId(key));
      auto property_value = DeserializePropertyValue(value);//query::serialization::
      if(property_value.type()!=storage::PropertyValue::Type::Null) maybe_properties[property_id]=property_value;
      else maybe_properties[property_id]=storage::PropertyValue("NULL");
    }
  }
  
  //labels 
  if(gid_delta_.find("L")!=gid_delta_.end()){
    auto history_labels_=gid_delta_["L"].get<std::vector<std::pair<std::string,std::string>>>();
    for (auto [key,value]:history_labels_){
       auto label_id = LabelId::FromUint(storage_->name_id_mapper_.NameToId(value));
       auto it = std::find(maybe_labels.begin(), maybe_labels.end(), label_id);
      if (key=="AL") {
        if (it != maybe_labels.end()) continue;
        maybe_labels.push_back(label_id);
      } else {
        if (it == maybe_labels.end()) continue;
        std::swap(*it, maybe_labels.back());
        maybe_labels.pop_back();
      }
    }
  }

  //TT_TS TT_TE
  auto property_id = PropertyId::FromUint(storage_->name_id_mapper_.NameToId("transaction_ts"));
  auto property_value = storage::PropertyValue(gid_delta_["TT_TS"].get<int64_t>());
  maybe_properties[property_id]=property_value;

  auto property_id2 = PropertyId::FromUint(storage_->name_id_mapper_.NameToId("transaction_te"));
  auto property_value2 = storage::PropertyValue(gid_delta_["TT_TE"].get<int64_t>());
  maybe_properties[property_id2]=property_value2;


  auto tt_ts=gid_delta_["TT_TS"].get<uint64_t>();
  auto tt_te=gid_delta_["TT_TE"].get<uint64_t>();
  //TODO edges

  auto new_vertex=HistoryVertex(Gid::FromUint(gid),tt_ts,tt_te);
  new_vertex.labels=maybe_labels;
  new_vertex.properties=maybe_properties;
  
  return new_vertex;
}


/**
 * @brief 根据kv文件创建历史节点
 * 
 * @param vertex_ history_vertex
 * @param gid_delta_ 
 * @param historyContext_ 
 * @return storage::HistoryVertex* 
 */
storage::HistoryVertex Storage::Accessor::CreateHistoryVertexFromKV(const storage::HistoryVertex vertex_,nlohmann::json gid_delta_,history_delta::historyContext &historyContext_){
  //properties
  auto maybe_labels= vertex_.labels;
  auto maybe_properties=vertex_.properties;

  //deleted info
  auto property_ids = PropertyId::FromUint(storage_->name_id_mapper_.NameToId("delete_info"));
  auto property_values = storage::PropertyValue(gid_delta_.dump());
  maybe_properties[property_ids]=property_values;
  
  //properties 
  // if(gid_delta_.find("SP")!=gid_delta_.end()){
  //   auto history_props_=gid_delta_["SP"];
  //   for(auto it_iter= history_props_.begin(); it_iter != history_props_.end(); ++it_iter){
  //     auto key = it_iter.key();
  //     auto value=it_iter.value();
  //     auto property_id = PropertyId::FromUint(storage_->name_id_mapper_.NameToId(key));
  //     auto property_value = DeserializePropertyValue(value);//query::serialization::
  //     if(property_value.type()!=storage::PropertyValue::Type::Null) maybe_properties[property_id]=property_value;
  //     else maybe_properties[property_id]=storage::PropertyValue("NULL");
  //   }
  // }
  
  // //labels 
  // if(gid_delta_.find("L")!=gid_delta_.end()){
  //   auto history_labels_=gid_delta_["L"].get<std::vector<std::pair<std::string,std::string>>>();;
  //   for (auto [key,value]:history_labels_){
  //      auto label_id = LabelId::FromUint(storage_->name_id_mapper_.NameToId(value));
  //      auto it = std::find(maybe_labels.begin(), maybe_labels.end(), label_id);
  //     if (key=="AL") {
  //       if (it != maybe_labels.end()) continue;
  //       maybe_labels.push_back(label_id);
  //     } else {
  //       if (it == maybe_labels.end()) continue;
  //       std::swap(*it, maybe_labels.back());
  //       maybe_labels.pop_back();
  //     }
  //   }
  // }
 
  // //TT_TS TT_TE
  // auto property_id = PropertyId::FromUint(storage_->name_id_mapper_.NameToId("transaction_ts"));
  // auto property_value = storage::PropertyValue(gid_delta_["TT_TS"].get<int64_t>());
  // maybe_properties[property_id]=property_value;

  // auto property_id2 = PropertyId::FromUint(storage_->name_id_mapper_.NameToId("transaction_te"));
  // auto property_value2 = storage::PropertyValue(gid_delta_["TT_TE"].get<int64_t>());
  // maybe_properties[property_id2]=property_value2;


  auto tt_ts=gid_delta_["TT_TS"].get<uint64_t>();
  auto tt_te=gid_delta_["TT_TE"].get<uint64_t>();
  //TODO edges

  auto new_vertex=HistoryVertex(vertex_.gid,tt_ts,tt_te);
  new_vertex.labels=maybe_labels;
  new_vertex.properties=maybe_properties;

  //edges
  // std::cout<<"CreateHistoryVertexFromKV::943\n";
  // new_vertex.in_history_edges=vertex_.in_history_edges;
  // new_vertex.out_history_edges=vertex_.out_history_edges;
  new_vertex.in_edges=vertex_.in_edges;
  new_vertex.out_edges=vertex_.out_edges;
  
  return new_vertex;
}

/**
 * @brief v2.0 根据kv文件创建历史节点
 * 
 * @param vertex_ VertexAccessor
 * @param gid_delta_ 
 * @param historyContext_ 
 * @return storage::HistoryVertex* 
 */
storage::HistoryVertex Storage::Accessor::CreateHistoryVertexFromKV(const VertexAccessor &another,nlohmann::json gid_delta_,history_delta::historyContext &historyContext_){
  //properties
  auto deltas=another.vertex_->delta;
  auto maybe_properties=another.vertex_->properties.Properties();
  auto maybe_labels=another.vertex_->labels;
  //deleted info
  auto property_ids = PropertyId::FromUint(storage_->name_id_mapper_.NameToId("delete_info"));
  auto property_values = storage::PropertyValue(gid_delta_.dump());
  maybe_properties[property_ids]=property_values;
  //dead info
  // while (deltas != nullptr) {
  //   switch (deltas->action) {
  //     case storage::Delta::Action::SET_PROPERTY: {
  //       auto property_value=deltas->property.value;
  //       if(property_value.type()!=storage::PropertyValue::Type::Null) maybe_properties[deltas->property.key]=property_value;
  //       else{
  //         maybe_properties[deltas->property.key]=storage::PropertyValue("NULL");;
  //       }
  //       break;
  //     }
  //     case storage::Delta::Action::ADD_LABEL:
  //     case storage::Delta::Action::REMOVE_LABEL: {
  //       auto label_id =deltas->label;
  //       auto it = std::find(maybe_labels.begin(), maybe_labels.end(), label_id);
  //       if (deltas->action==storage::Delta::Action::ADD_LABEL) {
  //         if (it != maybe_labels.end()) continue;
  //         maybe_labels.push_back(label_id);
  //       } else {
  //         if (it == maybe_labels.end()) continue;
  //         std::swap(*it, maybe_labels.back());
  //         maybe_labels.pop_back();
  //       }
  //       break;
  //     }
  //     default:break;
  //   }
  //   // Move to the next delta.
  //   deltas = deltas->next.load(std::memory_order_acquire);    
  // }
  
  // //deleted info
  // //properties 
  // if(gid_delta_.find("SP")!=gid_delta_.end()){
  //   auto history_props_=gid_delta_["SP"];
  //   for(auto it_iter= history_props_.begin(); it_iter != history_props_.end(); ++it_iter){
  //     auto key = it_iter.key();
  //     auto value=it_iter.value();
  //     auto property_id = PropertyId::FromUint(storage_->name_id_mapper_.NameToId(key));
  //     auto property_value = DeserializePropertyValue(value);//query::serialization::
  //     if(property_value.type()!=storage::PropertyValue::Type::Null) maybe_properties[property_id]=property_value;
  //     else maybe_properties[property_id]=storage::PropertyValue("NULL");
  //   }
  // }
  
  // //labels 
  // if(gid_delta_.find("L")!=gid_delta_.end()){
  //   auto history_labels_=gid_delta_["L"].get<std::vector<std::pair<std::string,std::string>>>();;
  //   for (auto [key,value]:history_labels_){
  //      auto label_id = LabelId::FromUint(storage_->name_id_mapper_.NameToId(value));
  //      auto it = std::find(maybe_labels.begin(), maybe_labels.end(), label_id);
  //     if (key=="AL") {
  //       if (it != maybe_labels.end()) continue;
  //       maybe_labels.push_back(label_id);
  //     } else {
  //       if (it == maybe_labels.end()) continue;
  //       std::swap(*it, maybe_labels.back());
  //       maybe_labels.pop_back();
  //     }
  //   }
  // }

  // //TT_TS TT_TE
  // auto property_id = PropertyId::FromUint(storage_->name_id_mapper_.NameToId("transaction_ts"));
  // auto property_value = storage::PropertyValue(gid_delta_["TT_TS"].get<int64_t>());
  // maybe_properties[property_id]=property_value;

  // auto property_id2 = PropertyId::FromUint(storage_->name_id_mapper_.NameToId("transaction_te"));
  // auto property_value2 = storage::PropertyValue(gid_delta_["TT_TE"].get<int64_t>());
  // maybe_properties[property_id2]=property_value2;


  auto tt_ts=gid_delta_["TT_TS"].get<uint64_t>();
  auto tt_te=gid_delta_["TT_TE"].get<uint64_t>();
  //TODO edges
  auto new_vertex=HistoryVertex(another.vertex_->gid,tt_ts,tt_te);
  new_vertex.labels=maybe_labels;
  new_vertex.properties=maybe_properties;

  //edges
  //还原尚未被删除的边
  // new_vertex.in_history_edges=CreateHistoryDeleteEdgeFromVertex(deltas,"AIE");
  // new_vertex.out_history_edges=CreateHistoryDeleteEdgeFromVertex(deltas,"AOE");
  //边
  new_vertex.in_edges=another.vertex_->in_edges;
  new_vertex.out_edges=another.vertex_->out_edges;
  // std::cout<<"CreateHistoryVertexFromKV::1021\n";
  
  return new_vertex;
}

/**
 * @brief v2.0 根据delta创建历史节点
 * 
 * @param another VertexAccessor
 * @param index deltas需要还原的index
 * @param historyContext_ 
 * @return storage::HistoryVertex* 
 */
// storage::HistoryVertex Storage::Accessor::SetHistoryVertexFromDelta(const VertexAccessor &another,std::tuple< std::map<storage::PropertyId,storage::PropertyValue>,uint64_t,uint64_t> & maybe_props,history_delta::historyContext& historyContext_){
//   auto deltas=another.vertex_->delta;
//   //Current info
//   auto maybe_labels=another.vertex_->labels;
//   auto tt_ts=std::get<1>(maybe_props);
//   auto tt_te=std::get<2>(maybe_props);
//   auto maybe_properties=std::get<0>(maybe_props);
//   auto property_id = PropertyId::FromUint(storage_->name_id_mapper_.NameToId("transaction_ts"));
//   auto property_id2 = PropertyId::FromUint(storage_->name_id_mapper_.NameToId("transaction_te"));
//   auto property_value = storage::PropertyValue((int64_t)tt_ts);
//   maybe_properties[property_id]=property_value;
//   auto property_value2 = storage::PropertyValue((int64_t)tt_te);
//   maybe_properties[property_id2]=property_value2;

//   auto new_vertex=HistoryVertex(another.vertex_->gid,tt_ts,tt_te);
//   new_vertex.labels=maybe_labels;
//   new_vertex.properties=maybe_properties;
//   //edges
//   new_vertex.in_edges=another.vertex_->in_edges;
//   new_vertex.out_edges=another.vertex_->out_edges;
//   return new_vertex;
// }


storage::HistoryVertex Storage::Accessor::CreateHistoryVertexFromDelta(const VertexAccessor &another,std::tuple< std::map<storage::PropertyId,storage::PropertyValue>,uint64_t,uint64_t> & maybe_props,history_delta::historyContext& historyContext_){
  auto deltas=another.vertex_->delta;
  //Current info
  auto maybe_labels=another.vertex_->labels;
  auto tt_ts=std::get<1>(maybe_props);
  auto tt_te=std::get<2>(maybe_props);
  auto maybe_properties=std::get<0>(maybe_props);
  auto property_id = PropertyId::FromUint(storage_->name_id_mapper_.NameToId("transaction_ts"));
  auto property_id2 = PropertyId::FromUint(storage_->name_id_mapper_.NameToId("transaction_te"));
  auto property_value = storage::PropertyValue((int64_t)tt_ts);
  maybe_properties[property_id]=property_value;
  auto property_value2 = storage::PropertyValue((int64_t)tt_te);
  maybe_properties[property_id2]=property_value2;


  auto new_vertex=HistoryVertex(another.vertex_->gid,tt_ts,tt_te);
  new_vertex.labels=maybe_labels;
  new_vertex.properties=maybe_properties;
  //edges
  new_vertex.in_edges=another.vertex_->in_edges;
  new_vertex.out_edges=another.vertex_->out_edges;
  return new_vertex;
}

storage::HistoryVertex Storage::Accessor::CreateHistoryVertexFromDelta(const VertexAccessor &another,int index,history_delta::historyContext& historyContext_){
  auto deltas=another.vertex_->delta;
  //Current info
  auto maybe_properties=another.vertex_->properties.Properties();
  auto maybe_labels=another.vertex_->labels;
  
  //dead info
  auto tt_ts=another.vertex_->transaction_st;
  // auto tt_te=another.vertex_->tt_te;//original
  // auto tt_te=another.tt_te();//wzy 0512
  auto tt_te=(uint64_t)std::numeric_limits<int64_t>::max();//wzy 0512
  int index_=0;
  while (deltas != nullptr) {
    if(index==0) break;
    switch (deltas->action) {
      case storage::Delta::Action::DELETE_OBJECT:
      case storage::Delta::Action::RECREATE_OBJECT:  {
        tt_ts=deltas->transaction_st;
        tt_te=deltas->commit_timestamp;
        break;
      }
      case storage::Delta::Action::SET_PROPERTY: {
        auto property_value=deltas->property.value;
        if(property_value.type()!=storage::PropertyValue::Type::Null) maybe_properties[deltas->property.key]=property_value;
        else{
          maybe_properties[deltas->property.key]=storage::PropertyValue("NULL");;
        }
        tt_ts=deltas->transaction_st;
        tt_te=deltas->commit_timestamp;
        break;
      }
      case storage::Delta::Action::ADD_LABEL:
      case storage::Delta::Action::REMOVE_LABEL: {
        auto label_id =deltas->label;
        auto it = std::find(maybe_labels.begin(), maybe_labels.end(), label_id);
        if (deltas->action==storage::Delta::Action::ADD_LABEL) {
          if (it != maybe_labels.end()) continue;
          maybe_labels.push_back(label_id);
        } else {
          if (it == maybe_labels.end()) continue;
          std::swap(*it, maybe_labels.back());
          maybe_labels.pop_back();
        }
        tt_ts=deltas->transaction_st;
        tt_te=deltas->commit_timestamp;
        break;
      }
      case storage::Delta::Action::ADD_OUT_EDGE:
      case storage::Delta::Action::REMOVE_OUT_EDGE:
      case storage::Delta::Action::ADD_IN_EDGE:
      case storage::Delta::Action::REMOVE_IN_EDGE:
        break;
    }
    //reconstruct end
    index_++;
    if(index_==index) break;

    // Move to the next delta.
    deltas = deltas->next.load(std::memory_order_acquire);    
  }
  
  auto property_id = PropertyId::FromUint(storage_->name_id_mapper_.NameToId("transaction_ts"));
  auto property_id2 = PropertyId::FromUint(storage_->name_id_mapper_.NameToId("transaction_te"));
  auto property_value = storage::PropertyValue((int64_t)tt_ts);
  maybe_properties[property_id]=property_value;
  auto property_value2 = storage::PropertyValue((int64_t)tt_te);
  maybe_properties[property_id2]=property_value2;

  auto new_vertex=HistoryVertex(another.vertex_->gid,tt_ts,tt_te);
  new_vertex.labels=maybe_labels;
  new_vertex.properties=maybe_properties;

  //edges
  //还原尚未被删除的边
  // new_vertex.in_history_edges=CreateHistoryDeleteEdgeFromVertex(deltas,"AIE");
  // new_vertex.out_history_edges=CreateHistoryDeleteEdgeFromVertex(deltas,"AOE");
  //边
  new_vertex.in_edges=another.vertex_->in_edges;
  new_vertex.out_edges=another.vertex_->out_edges;
  // for(auto &[edgetype,vertex,edgeref]:another.vertex_->in_edges){
  //   // std::cout<<"add history in edge:"<<edgeref.ptr->transaction_st<<" "<<edgeref.ptr->tt_te<<"\n";
  //   auto history_edge=new HistoryEdge(edgeref.ptr->gid,edgeref.ptr->transaction_st,edgeref.ptr->tt_te,edgeref.ptr->from_gid,edgeref.ptr->to_gid,edgetype,edgeref.ptr->delta);
  //   history_edge->properties=edgeref.ptr->properties.Properties();
  //   new_vertex->in_history_edges.emplace_back(history_edge);
  // }
  // new_vertex->out_history_edges=CreateHistoryDeleteEdgeFromVertex(new_vertex,deltas,"AOE");
  // for(auto &[edgetype,vertex,edgeref]:another.vertex_->out_edges){
  //   // std::cout<<"add history out edge:"<<edgeref.ptr->transaction_st<<" "<<edgeref.ptr->tt_te<<"\n";
  //   auto history_edge=new HistoryEdge(edgeref.ptr->gid,edgeref.ptr->transaction_st,edgeref.ptr->tt_te,edgeref.ptr->from_gid,edgeref.ptr->to_gid,edgetype,edgeref.ptr->delta);
  //   history_edge->properties=edgeref.ptr->properties.Properties();
  //   new_vertex->out_history_edges.emplace_back(history_edge);
  // }
  return new_vertex;
}

/**
 * @brief 还原kv中anchor类型的节点
 * 
 * @param gid 
 * @param gid_delta_ 
 * @param in_edges 
 * @param out_edges 
 * @return storage::HistoryVertex 
 */
storage::HistoryVertex Storage::Accessor::CreateAnchorVertex(uint64_t gid,nlohmann::json gid_delta_,std::vector<std::tuple<EdgeTypeId, Vertex *, EdgeRef>> in_edges,std::vector<std::tuple<EdgeTypeId, Vertex *, EdgeRef>> out_edges){
  //properties
  std::vector<LabelId> maybe_labels;
  std::map<PropertyId, PropertyValue> maybe_properties;

  //properties 
  if(gid_delta_.find("SP")!=gid_delta_.end()){
    auto history_props_=gid_delta_["SP"];
    for(auto it_iter= history_props_.begin(); it_iter != history_props_.end(); ++it_iter){
      auto key = it_iter.key();
      auto value=it_iter.value();
      auto property_id = PropertyId::FromUint(storage_->name_id_mapper_.NameToId(key));
      auto property_value = DeserializePropertyValue(value);//query::serialization::
      if(property_value.type()!=storage::PropertyValue::Type::Null) maybe_properties[property_id]=property_value;
      else maybe_properties[property_id]=storage::PropertyValue("NULL");
    }
  }
  
  //labels 
  if(gid_delta_.find("L")!=gid_delta_.end()){
    auto history_labels_=gid_delta_["L"].get<std::vector<std::pair<std::string,std::string>>>();
    for (auto [key,value]:history_labels_){
       auto label_id = LabelId::FromUint(storage_->name_id_mapper_.NameToId(value));
       auto it = std::find(maybe_labels.begin(), maybe_labels.end(), label_id);
      if (key=="AL") {
        if (it != maybe_labels.end()) continue;
        maybe_labels.push_back(label_id);
      } else {
        if (it == maybe_labels.end()) continue;
        std::swap(*it, maybe_labels.back());
        maybe_labels.pop_back();
      }
    }
  }

  //TT_TS TT_TE
  auto property_id = PropertyId::FromUint(storage_->name_id_mapper_.NameToId("transaction_ts"));
  auto property_value = storage::PropertyValue(gid_delta_["TT_TS"].get<int64_t>());
  maybe_properties[property_id]=property_value;

  auto property_id2 = PropertyId::FromUint(storage_->name_id_mapper_.NameToId("transaction_te"));
  auto property_value2 = storage::PropertyValue(gid_delta_["TT_TE"].get<int64_t>());
  maybe_properties[property_id2]=property_value2;


  auto tt_ts=gid_delta_["TT_TS"].get<uint64_t>();
  auto tt_te=gid_delta_["TT_TE"].get<uint64_t>();
  //TODO edges

  auto new_vertex=HistoryVertex(Gid::FromUint(gid),tt_ts,tt_te);
  new_vertex.labels=maybe_labels;
  new_vertex.properties=maybe_properties;
  new_vertex.in_edges=in_edges;
  new_vertex.out_edges=out_edges;
  
  return new_vertex;
}

/**
 * @brief 
 * 
 * @param in_edges_ 历史顶点的入边
 * @param edge_types 需要筛选的边的类型
 * @return Result<std::vector<EdgeAccessor>> 返回边的访问
 */
Result<std::vector<EdgeAccessor>> Storage::Accessor::Edges(std::vector<std::tuple<EdgeTypeId, Vertex *, EdgeRef>> &edges_,const std::vector<EdgeTypeId> &edge_types,storage::Gid gid,bool from,std::optional<storage::Gid> existing_gid){
  std::vector<std::tuple<EdgeTypeId, Vertex *, EdgeRef>> edges;
  {
    if (edge_types.empty() & !existing_gid) {
      edges = edges_;
    } else {
      for (const auto &item : edges_) {
        const auto &[edge_type, expand_vertex, edge] = item;
        if (existing_gid && expand_vertex->gid != *existing_gid) continue;
        if (!edge_types.empty() && std::find(edge_types.begin(), edge_types.end(), edge_type) == edge_types.end())
          continue;
        edges.push_back(item);
      }
    }
  }
  std::vector<EdgeAccessor> ret;
  ret.reserve(edges.size());
  for (const auto &item : edges) {
    const auto &[edge_type, expand_vertex, edge] = item;
    // EdgeAccessor(edge, edge_type, expand_vertex,expand_vertex, &transaction_, &storage_->indices_,
    //                   &storage_->constraints_, config_);
    storage::Gid from_gid=from?expand_vertex->gid:gid;
    storage::Gid to_gid=from?gid:expand_vertex->gid;
    // std::cout<<"from gid:"<<from_gid.AsUint()<<" "<<to_gid.AsUint()<<"\n";
    // EdgeAccessor(edge, edge_type, expand_vertex,expand_vertex, &transaction_, &storage_->indices_,
    //                   &storage_->constraints_,from_gid,to_gid,config_);
    ret.emplace_back(edge, edge_type, expand_vertex,expand_vertex, &transaction_, &storage_->indices_,
                      &storage_->constraints_, from_gid,to_gid,config_);
    // ret.emplace_back(edge, edge_type, expand_vertex,expand_vertex, &transaction_, &storage_->indices_,
    //                   &storage_->constraints_,config_);
  
  }

  //当前节点 to_vertex没有 应该不受影响
  return std::move(ret);
}

/**
 * @brief v3.0
 * 
 * @param another 
 * @param index 
 * @return storage::HistoryEdge 
 */
storage::HistoryEdge Storage::Accessor::CreateHistoryEdgeFromDelta(const EdgeAccessor &another,int index){
  auto deltas=another.edge_.ptr->delta;
  // std::map<PropertyId, PropertyValue> PropertyStore::Properties()
  // wzy edit no-prop-edge-version
  // auto maybe_properties=another.edge_.ptr->properties.Properties(); //before
  std::map<PropertyId, PropertyValue> maybe_properties;
  //wzy end
  //dead info
  int index_=0;
  auto tt_ts=another.edge_.ptr->transaction_st;
  // auto tt_te=another.edge_.ptr->tt_te;//original
  // auto tt_te=another.tt_te();
  auto tt_te=(uint64_t)std::numeric_limits<int64_t>::max();//wzy 0512
  while (deltas != nullptr) {
    if(index==0) break;
    switch (deltas->action) {
      case storage::Delta::Action::DELETE_OBJECT:
      case storage::Delta::Action::RECREATE_OBJECT:  {
        tt_ts=deltas->transaction_st;
        tt_te=deltas->commit_timestamp;
        break;
      }
      case storage::Delta::Action::SET_PROPERTY: {
        // wzy begin no-prop
        // auto property_value =deltas->property.value;
        // if(property_value.type()!=storage::PropertyValue::Type::Null) maybe_properties[deltas->property.key]=property_value;
        // else{
        //   maybe_properties[deltas->property.key]=storage::PropertyValue("NULL");;
        // }
        // wzy end
        tt_ts=deltas->transaction_st;
        tt_te=deltas->commit_timestamp;
        break;
      }
      default:break;
    }
    //reconstruct end
    index_++;
    if(index_==index) break;
    // Move to the next delta.
    deltas = deltas->next.load(std::memory_order_acquire);    
  }
  //TT_TS TT_TE
  auto property_id = PropertyId::FromUint(storage_->name_id_mapper_.NameToId("transaction_ts"));
  auto property_id2 = PropertyId::FromUint(storage_->name_id_mapper_.NameToId("transaction_te"));
  
  auto property_value = storage::PropertyValue((int64_t)tt_ts);
  maybe_properties[property_id]=property_value;
  auto property_value2 = storage::PropertyValue((int64_t)tt_te);
  maybe_properties[property_id2]=property_value2;

  auto history_edge=HistoryEdge(another.edge_.ptr->gid,tt_ts,tt_te,another.edge_.ptr->from_gid,another.edge_.ptr->to_gid,another.EdgeType(),nullptr);
  history_edge.properties=maybe_properties;
  return history_edge;
}

/**
 * @brief v3.0 
 * 
 * @param another 
 * @param gid_delta_ 
 * @return storage::HistoryEdge 
 */
storage::HistoryEdge Storage::Accessor::CreateHistoryEdgeFromKV(const EdgeAccessor &another,nlohmann::json gid_delta_){
  auto maybe_properties=another.edge_.ptr->properties.Properties();
  auto from_gid=another.FromVertex().Gid();
  auto to_gid=another.ToVertex().Gid();
  //还原到最近的dead info
  auto deltas=another.edge_.ptr->delta;
  while (deltas != nullptr) {
    switch (deltas->action) {
      case storage::Delta::Action::SET_PROPERTY: {
        auto property_value =deltas->property.value;
        if(property_value.type()!=storage::PropertyValue::Type::Null) maybe_properties[deltas->property.key]=property_value;
        else{
          maybe_properties[deltas->property.key]=storage::PropertyValue("NULL");;
        }
        break;
      }
      default:break;
    }
    // Move to the next delta.
    deltas = deltas->next.load(std::memory_order_acquire);    
  }
  

  //TT_TS TT_TE
  auto property_id = PropertyId::FromUint(storage_->name_id_mapper_.NameToId("transaction_ts"));
  auto property_value = storage::PropertyValue(gid_delta_["TT_TS"].get<int64_t>());
  maybe_properties[property_id]=property_value;

  auto property_id2 = PropertyId::FromUint(storage_->name_id_mapper_.NameToId("transaction_te"));
  auto property_value2 = storage::PropertyValue(gid_delta_["TT_TE"].get<int64_t>());
  maybe_properties[property_id2]=property_value2;
  auto tt_ts=gid_delta_["TT_TS"].get<uint64_t>();
  auto tt_te=gid_delta_["TT_TE"].get<uint64_t>();
  // std::cout<<"CreateHistoryEdgeFromKV1:"<<tt_ts<<" "<<tt_te<<" "<<from_gid.AsUint()<<" "<<to_gid.AsUint()<<" ""\n";
  //TODO edges
  auto history_edge=HistoryEdge(another.edge_.ptr->gid,tt_ts,tt_te,from_gid,to_gid,another.EdgeType(),nullptr); 
  history_edge.properties=maybe_properties;
  return history_edge;
}

/**
 * @brief v3.0 
 * 
 * @param edge_ 
 * @param gid_delta_ 
 * @return storage::HistoryEdge 
 */
storage::HistoryEdge Storage::Accessor::CreateHistoryEdgeFromKV(storage::HistoryEdge edge_,nlohmann::json gid_delta_){
  auto maybe_properties=edge_.properties;
  //properties 
  // wzy begin no-edge-version
  // if(gid_delta_.find("SP")!=gid_delta_.end()){
  //   auto history_props_=gid_delta_["SP"];
  //   for(auto it_iter= history_props_.begin(); it_iter != history_props_.end(); ++it_iter){
  //     auto key = it_iter.key();
  //     auto value=it_iter.value();
  //     auto property_id = PropertyId::FromUint(storage_->name_id_mapper_.NameToId(key));
  //     auto property_value = DeserializePropertyValue(value);//query::serialization::
  //     if(property_value.type()!=storage::PropertyValue::Type::Null) maybe_properties[property_id]=property_value;
  //     else{
  //       maybe_properties[property_id]=storage::PropertyValue("NULL");;
  //     }
  //   }
  // }
  // wzy end

  //TT_TS TT_TE
  auto property_id = PropertyId::FromUint(storage_->name_id_mapper_.NameToId("transaction_ts"));
  auto property_value = storage::PropertyValue(gid_delta_["TT_TS"].get<int64_t>());
  maybe_properties[property_id]=property_value;

  auto property_id2 = PropertyId::FromUint(storage_->name_id_mapper_.NameToId("transaction_te"));
  auto property_value2 = storage::PropertyValue(gid_delta_["TT_TE"].get<int64_t>());
  maybe_properties[property_id2]=property_value2;
  auto tt_ts=gid_delta_["TT_TS"].get<uint64_t>();
  auto tt_te=gid_delta_["TT_TE"].get<uint64_t>();
  // std::cout<<"CreateHistoryEdgeFromKV2:"<<tt_ts<<" "<<tt_te<<" "<<edge_.from_gid.AsUint()<<" "<<edge_.to_gid.AsUint()<<"\n";
  //TODO edges
  auto history_edge=HistoryEdge(edge_.gid,tt_ts,tt_te,edge_.from_gid,edge_.to_gid,edge_.type,nullptr);
  history_edge.properties=maybe_properties;
  return history_edge;
}

/**
 * @brief v3.0
 * 
 * @param another 
 * @param gid_delta_ 
 * @return storage::HistoryEdge 
 */
storage::HistoryEdge Storage::Accessor::CreateAnchorEdge(const EdgeAccessor &another,nlohmann::json gid_delta_){
  std::map<PropertyId, PropertyValue> maybe_properties;
  //properties 
  // wzy begin no-prop-ver
  // if(gid_delta_.find("SP")!=gid_delta_.end()){
  //   auto history_props_=gid_delta_["SP"];
  //   for(auto it_iter= history_props_.begin(); it_iter != history_props_.end(); ++it_iter){
  //     auto key = it_iter.key();
  //     auto value=it_iter.value();
  //     auto property_id = PropertyId::FromUint(storage_->name_id_mapper_.NameToId(key));
  //     auto property_value = DeserializePropertyValue(value);//query::serialization::
  //     if(property_value.type()!=storage::PropertyValue::Type::Null) maybe_properties[property_id]=property_value;
  //     else maybe_properties[property_id]=storage::PropertyValue("NULL");
  //   }
  // }
  // wzy end
  
  //TT_TS TT_TE
  auto property_id = PropertyId::FromUint(storage_->name_id_mapper_.NameToId("transaction_ts"));
  auto property_value = storage::PropertyValue(gid_delta_["TT_TS"].get<int64_t>());
  maybe_properties[property_id]=property_value;

  auto property_id2 = PropertyId::FromUint(storage_->name_id_mapper_.NameToId("transaction_te"));
  auto property_value2 = storage::PropertyValue(gid_delta_["TT_TE"].get<int64_t>());
  maybe_properties[property_id2]=property_value2;


  auto tt_ts=gid_delta_["TT_TS"].get<uint64_t>();
  auto tt_te=gid_delta_["TT_TE"].get<uint64_t>();
  auto history_edge=HistoryEdge(another.edge_.ptr->gid,tt_ts,tt_te,another.edge_.ptr->from_gid,another.edge_.ptr->to_gid,another.EdgeType(),nullptr);
  history_edge.properties=maybe_properties;
  return history_edge;
}

//创建历史边
storage::HistoryEdge Storage::Accessor::CreateHistoryEdgeFromDelta(const EdgeAccessor &another){
  auto tt_te=(uint64_t)std::numeric_limits<int64_t>::max();//wzy 0512
  auto history_edge=HistoryEdge(another.edge_.ptr->gid,another.edge_.ptr->transaction_st,tt_te,another.edge_.ptr->from_gid,another.edge_.ptr->to_gid,another.EdgeType(),another.edge_.ptr->delta);
  history_edge.properties=another.edge_.ptr->properties.Properties();
  return history_edge;
}

// //根据delta创建历史边
storage::HistoryEdge Storage::Accessor::CreateHistoryEdgeFromDelta(storage::HistoryEdge another,int index){
  auto deltas=another.delta;
  //Current info
  auto maybe_properties=another.properties;
  //dead info
  int index_=0;
  auto tt_ts=another.tt_ts;
  auto tt_te=another.tt_te;
  while (deltas != nullptr) {
    if(index==0) break;
    switch (deltas->action) {
      case storage::Delta::Action::DELETE_OBJECT:
      case storage::Delta::Action::RECREATE_OBJECT:  {
        tt_ts=deltas->transaction_st;
        tt_te=deltas->commit_timestamp;
        break;
      }
      case storage::Delta::Action::SET_PROPERTY: {
        auto property_value =deltas->property.value;
        if(property_value.type()!=storage::PropertyValue::Type::Null) maybe_properties[deltas->property.key]=property_value;
        else{
          maybe_properties[deltas->property.key]=storage::PropertyValue("NULL");;
        }
        tt_ts=deltas->transaction_st;
        tt_te=deltas->commit_timestamp;
        break;
      }
      default:break;
    }
    //reconstruct end
    index_++;
    if(index_==index) break;
    // Move to the next delta.
    deltas = deltas->next.load(std::memory_order_acquire);    
  }
  //TT_TS TT_TE
  //Gid::FromUint
  auto property_id = PropertyId::FromUint(storage_->name_id_mapper_.NameToId("transaction_ts"));
  auto property_id2 = PropertyId::FromUint(storage_->name_id_mapper_.NameToId("transaction_te"));
  
  auto property_value = storage::PropertyValue((int64_t)tt_ts);
  maybe_properties[property_id]=property_value;
  auto property_value2 = storage::PropertyValue((int64_t)tt_te);
  maybe_properties[property_id2]=property_value2;

  //TODO edges
  auto history_edge=HistoryEdge(another.gid,tt_ts,tt_te,another.from_gid,another.to_gid,another.type,another.delta);
  history_edge.properties=maybe_properties;
  return history_edge;
}


/**
 * @brief v2.0 还原历史节点中删除的还没有写入kv中的边
 * 
 * @param vertex 
 * @param delta 
 * @param types 
 * @return std::list<storage::HistoryEdge*> 
 */
std::list<storage::HistoryEdge> Storage::Accessor::CreateHistoryDeleteEdgeFromVertex(const Delta* delta,std::string types){
  std::list<storage::HistoryEdge> history_edges;
  while (delta != nullptr) {
    switch (delta->action) {
      case storage::Delta::Action::ADD_OUT_EDGE:
      case storage::Delta::Action::ADD_IN_EDGE:{
        auto edge_id=delta->vertex_edge.edge.ptr->gid;
        auto type=delta->action==storage::Delta::Action::ADD_OUT_EDGE?"AOE":"AIE";
        auto edge_type=delta->vertex_edge.edge_type;
        auto from_gid=delta->vertex_edge.edge.ptr->from_gid;
        auto to_gid=delta->vertex_edge.edge.ptr->to_gid;
        auto tt_ts=delta->transaction_st;
        // auto tt_te=delta->commit_timestamp;
        auto e_delta=delta->vertex_edge.edge.ptr->delta;
        if(type==types){
          auto history_edge=HistoryEdge(edge_id,tt_ts,tt_ts,from_gid,to_gid,edge_type,e_delta);
          history_edge.properties=delta->vertex_edge.edge.ptr->properties.Properties();
          history_edges.push_back(history_edge);
        }
        break;
      }
      default:break;
    }
    delta = delta->next.load(std::memory_order_acquire);    
  }
  return history_edges;
}


Gid Storage::Accessor::IdToGid(const uint64_t key) { return Gid::FromUint(key); }

// std::optional<EdgeAccessor> Storage::Accessor::FindEdge(Gid gid) {
//   auto edge_acc = storage_->edges_.access();
//   auto edge = edge_acc.find(gid);
//   if (edge == edge_acc.end()) return std::nullopt;
//   // return edge;//VertexAccessor::Create(&*it, &transaction_, &storage_->indices_, &storage_->constraints_, config_, view);
//   // return EdgeAccessor(edge, edge_type, from_vertex, to_vertex, &transaction_, &storage_->indices_,
//   //                     &storage_->constraints_, config_);
// }

void Storage::Accessor::InitVertex(storage::Vertex *his_vertex,std::vector<storage::LabelId> &labels,std::vector<std::pair<uint64_t,uint64_t>> &labels_tt,std::map<storage::PropertyId, std::tuple<storage::PropertyValue,uint64_t,uint64_t>> &props_tt,uint64_t tt_ts,uint64_t tt_te){
  //init labels 
  labels=his_vertex->labels;
  for(int j=0;j<labels.size();j++){
    labels_tt.emplace_back(tt_ts,tt_te);
  }
  //init props
  auto maybe_properties=his_vertex->properties.Properties();//std::map<PropertyId, PropertyValue>
  for (const auto &prop : maybe_properties ){
    if(props_tt.find(prop.first)==props_tt.end()){
      props_tt[prop.first]=std::tuple<storage::PropertyValue,uint64_t,uint64_t>();
    }
    props_tt[prop.first]=std::tuple<storage::PropertyValue,uint64_t,uint64_t>{prop.second,tt_ts,tt_te};
  }
}

void Storage::Accessor::InitVertex(storage::Vertex *vertex,history_delta::historyContextOnce &historyContext,bool delete_flag,std::vector<int> dead_deltas,std::vector<nlohmann::json> deleted_kv){
  if(!delete_flag){
    std::cout<<"init vertex 1 begin\n";
    InitVertex(vertex,historyContext.labels,historyContext.labels_tt,historyContext.props_tt,vertex->transaction_st,(uint64_t)std::numeric_limits<int64_t>::max());
    std::cout<<"init vertex 1 done\n";
    return;
  }
  if(dead_deltas.size()!=0){
    std::cout<<"init vertex 2 begin\n";
    auto deltas=vertex->delta;
    //dead info
    int index=dead_deltas[0];
    int index_=0;
    uint64_t tt_ts=vertex->transaction_st;
    uint64_t tt_te=std::numeric_limits<uint64_t>::max();
    while (deltas != nullptr) {
      switch (deltas->action) {
        case storage::Delta::Action::SET_PROPERTY: {
          vertex->properties.SetProperty(deltas->property.key,deltas->property.value);
          break;
        }
        case storage::Delta::Action::ADD_LABEL:
        case storage::Delta::Action::REMOVE_LABEL: {
          auto label_id =deltas->label;
          auto it = std::find(vertex->labels.begin(), vertex->labels.end(), label_id);
          if (deltas->action==storage::Delta::Action::ADD_LABEL) {
            if (it != vertex->labels.end()) continue;
            vertex->labels.push_back(label_id);
          } else {
            if (it == vertex->labels.end()) continue;
            std::swap(*it, vertex->labels.back());
            vertex->labels.pop_back();
          }
          break;
        }
        default:break;
      }
      tt_ts=deltas->transaction_st;
      tt_te=deltas->commit_timestamp;
      //reconstruct end
      if(index_+1==index) break;
      // Move to the next delta.
      deltas = deltas->next.load(std::memory_order_acquire);    
      index_++;
    }
    if(index_+1==index){
      InitVertex(vertex,historyContext.labels,historyContext.labels_tt,historyContext.props_tt,tt_ts,tt_te);
      std::cout<<"init vertex 2 done\n";
      return;
    }
    // std::cout<<"init vertex 2 done1\n";
    // InitVertex(vertex,historyContext.labels,historyContext.labels_tt,historyContext.props_tt,deltas->transaction_st,deltas->commit_timestamp);
    // std::cout<<"init vertex 2 done\n";
  }
  if(deleted_kv.size()!=0){
    std::cout<<"init vertex 3 begin\n";
    auto gid_delta_=deleted_kv[0];
    //properties 
    if(gid_delta_.find("SP")!=gid_delta_.end()){
      auto history_props_=gid_delta_["SP"];
      for(auto it_iter= history_props_.begin(); it_iter != history_props_.end(); ++it_iter){
        auto key = it_iter.key();
        auto value=it_iter.value();
        auto property_id = PropertyId::FromUint(storage_->name_id_mapper_.NameToId(key));
        auto property_value = DeserializePropertyValue(value);//query::serialization::
        vertex->properties.SetProperty(property_id,property_value);
      }
    }
    
    //labels 
    if(gid_delta_.find("L")!=gid_delta_.end()){
      auto history_labels_=gid_delta_["L"].get<std::vector<std::pair<std::string,std::string>>>();;
      for (auto [key,value]:history_labels_){
        auto label_id = LabelId::FromUint(storage_->name_id_mapper_.NameToId(value));
        auto it = std::find(vertex->labels.begin(), vertex->labels.end(), label_id);
        if (key=="AL") {
          if (it != vertex->labels.end()) continue;
          vertex->labels.push_back(label_id);
        } else {
          if (it == vertex->labels.end()) continue;
          std::swap(*it, vertex->labels.back());
          vertex->labels.pop_back();
        }
      }
    }
    InitVertex(vertex,historyContext.labels,historyContext.labels_tt,historyContext.props_tt,gid_delta_["TT_TS"].get<uint64_t>(),gid_delta_["TT_TE"].get<uint64_t>());
    std::cout<<"init vertex 3 done\n";
    return;
  }
  return;
}

void Storage::Accessor::getHistoryVertexFromDelta(storage::Vertex *current_vertex,std::vector<int> dead_deltas,history_delta::historyContextOnce &historyContext){
  if(dead_deltas.size()==0) return;
  auto max_index=0;
  auto begin_index=0;
  for (int i=0;i<dead_deltas.size();i++){
    auto index_=0;
    begin_index=max_index;
    max_index=dead_deltas[i];
    auto deltas=current_vertex->delta;
    while (deltas != nullptr) {
      if(!(index_>=begin_index & index_<max_index)){
        deltas = deltas->next.load(std::memory_order_acquire);    
        index_++;
        continue;
      }
      switch (deltas->action) {
        case storage::Delta::Action::SET_PROPERTY: {
          auto set_prop_id=deltas->property.key;
          auto set_prop_value=deltas->property.value;
          for(auto &prop:historyContext.props_tt){//propid value,tt_ts,tt_te
            auto prop_id=prop.first;
            if(prop_id!=set_prop_id){
              auto [a1, a2, a3]=prop.second;
              prop.second=std::tuple<storage::PropertyValue,uint64_t,uint64_t>{a1,deltas->transaction_st,a3};
            }else{
              auto [value,tt_ts,tt_te]=prop.second;//value,tt_ts,tt_te
              auto property_name = storage_->name_id_mapper_.IdToName(set_prop_id.AsUint())+"["+std::to_string(tt_ts)+","+std::to_string(tt_te)+"]";
              auto after_prop_id= PropertyId::FromUint(storage_->name_id_mapper_.NameToId(property_name));
              historyContext.props_tt[after_prop_id]=prop.second;//std::tuple<storage::PropertyValue,uint64_t,uint64_t>{value,tt_ts,tt_te};
              historyContext.props_tt[set_prop_id]=std::tuple<storage::PropertyValue,uint64_t,uint64_t>{set_prop_value,deltas->transaction_st,deltas->commit_timestamp};
            }
          }
          break;
        }
        case storage::Delta::Action::ADD_LABEL:
        case storage::Delta::Action::REMOVE_LABEL: {
          auto label_id =deltas->label;
          auto it = std::find(historyContext.labels.begin(), historyContext.labels.end(), label_id);
          if (deltas->action==storage::Delta::Action::ADD_LABEL) {
            if (it != historyContext.labels.end()) continue;
            for(auto j=0;j<historyContext.labels_tt.size();j++){
              auto label_tt=historyContext.labels_tt[j];
              auto label=historyContext.labels[j];
              if(std::find(historyContext.remove_labels.begin(), historyContext.remove_labels.end(), label) == historyContext.remove_labels.end()){
                label_tt=std::make_pair(deltas->transaction_st,label_tt.second);
              }
            }
            historyContext.labels.push_back(label_id);
            historyContext.labels_tt.emplace_back(deltas->transaction_st,deltas->commit_timestamp);
          }else{
            historyContext.remove_labels.emplace_back(label_id);
          } 
          break;
        }
        default:break;
      }
      //reconstruct end
      if(index_+1==max_index) break;
      // Move to the next delta.
      deltas = deltas->next.load(std::memory_order_acquire);    
      index_++;
    }
  }
  return ;
}

void Storage::Accessor::getHistoryVertexFromKV(std::vector<nlohmann::json> deleted_kv,history_delta::historyContextOnce &historyContext){
  if(deleted_kv.size()==0) return;
  auto max_index=0;
  auto begin_index=0;
  for (int i=0;i<deleted_kv.size();i++){
    auto gid_delta_=deleted_kv[i];
    //properties
    auto tt_ts=gid_delta_["TT_TS"].get<uint64_t>();
    auto tt_te=gid_delta_["TT_TS"].get<uint64_t>();
    if(gid_delta_.find("SP")!=gid_delta_.end()){
      auto history_props_=gid_delta_["SP"];
      for(auto it_iter= history_props_.begin(); it_iter != history_props_.end(); ++it_iter){
        auto key = it_iter.key();
        auto value=it_iter.value();
        auto set_prop_id = storage::PropertyId::FromUint(storage_->name_id_mapper_.NameToId(key));
        auto set_prop_value = DeserializePropertyValue(value);//query::serialization:
        for(auto &prop:historyContext.props_tt){
          auto prop_id=prop.first;
          if(prop_id!=set_prop_id){
            auto [a1, a2, a3]=prop.second;
            prop.second=std::tuple<storage::PropertyValue,uint64_t,uint64_t>{a1,tt_ts,a3};
          }else{
            auto [value,tt_ts,tt_te]=prop.second;//value,tt_ts,tt_te
            auto property_name = storage_->name_id_mapper_.IdToName(set_prop_id.AsUint())+"["+std::to_string(tt_ts)+","+std::to_string(tt_te)+"]";
            auto after_prop_id= PropertyId::FromUint(storage_->name_id_mapper_.NameToId(property_name));
            historyContext.props_tt[after_prop_id]=prop.second;//std::tuple<storage::PropertyValue,uint64_t,uint64_t>{value,tt_ts,tt_te};
           
            historyContext.props_tt[set_prop_id]=std::tuple<storage::PropertyValue,uint64_t,uint64_t>{set_prop_value,tt_ts,tt_te};
          }
        }
      }
    }
  
    //labels 
    if(gid_delta_.find("L")!=gid_delta_.end()){
      auto history_labels_=gid_delta_["L"].get<std::vector<std::pair<std::string,std::string>>>();;
      for (auto [key,value]:history_labels_){
        auto label_id = storage::LabelId::FromUint(storage_->name_id_mapper_.NameToId(value));
        auto it = std::find(historyContext.labels.begin(), historyContext.labels.end(), label_id);
        if (key=="AL") {
          if (it != historyContext.labels.end()) continue;
          for(auto j=0;j<historyContext.labels_tt.size();j++){
            auto label_tt=historyContext.labels_tt[j];
            auto label=historyContext.labels[j];
            if(std::find(historyContext.remove_labels.begin(), historyContext.remove_labels.end(), label) == historyContext.remove_labels.end()){
              label_tt=std::make_pair(tt_ts,label_tt.second);
            }
          }
          historyContext.labels.push_back(label_id);
          historyContext.labels_tt.emplace_back(tt_ts,tt_te);
        } else {
          historyContext.remove_labels.emplace_back(label_id);
        }
      }
    }
  }
  return ;
}

VertexAccessor Storage::Accessor::getHistoryVertexOnce(const VertexAccessor &another,std::vector<int> dead_deltas,std::vector<nlohmann::json> deleted_kv,history_delta::historyContextOnce& historyContext,bool delete_flag){
  Delta *delta = nullptr;
  auto deltas=another.vertex_->delta;
  //复制新的veretx
  auto current_vertex = new Vertex(another.vertex_->gid,deltas,another.vertex_->transaction_st);
  current_vertex->labels=another.vertex_->labels;
  auto maybe_properties=another.vertex_->properties.Properties();
  for (const auto &prop : maybe_properties ){
    current_vertex->properties.SetProperty(prop.first,prop.second);
  }
  current_vertex->in_edges=another.vertex_->in_edges;
  current_vertex->out_edges=another.vertex_->out_edges;
  
  //获取历史数据
  InitVertex(current_vertex,historyContext,delete_flag,dead_deltas,deleted_kv);
  std::cout<<"init done\n";
  getHistoryVertexFromDelta(current_vertex,dead_deltas,historyContext);
  getHistoryVertexFromKV(deleted_kv,historyContext);
  
  //重新构造新的节点
  current_vertex->labels=historyContext.labels;
  // current_vertex->labels_tt=historyContext.labels_tt;
  current_vertex->properties.ClearProperties();
  for (auto &[key,values] : historyContext.props_tt ){
    auto &[value,ts,te]=values;
    value.tt_ts=ts;
    value.tt_te=te;
    current_vertex->properties.SetProperty(key,value);
  }
  return VertexAccessor{current_vertex, another.transaction_, another.indices_, another.constraints_, another.config_};
}

VertexAccessor Storage::Accessor::CreateHistoryVertex3(uint64_t gid,nlohmann::json gid_delta_,history_delta::historyContext& historyContext_){
  auto tt_ts=gid_delta_["TT_TS"].get<uint64_t>();
  Delta *delta = nullptr;
  auto vertex = new Vertex(Gid::FromUint(gid),delta,tt_ts);
  // auto gid_delta_=gid_delta["RECREATE_OBJECT"];
  //deleted info
  //properties 
  if(gid_delta_.find("SET_PROPERTY")!=gid_delta_.end()){
    auto history_props_=gid_delta_["SET_PROPERTY"];
    for(auto it_iter= history_props_.begin(); it_iter != history_props_.end(); ++it_iter){
      auto key = it_iter.key();
      auto value=it_iter.value();
      auto property_id = PropertyId::FromUint(storage_->name_id_mapper_.NameToId(key));
      auto property_value = DeserializePropertyValue(value);//query::serialization::
      vertex->properties.SetProperty(property_id,property_value);
    }
  }
  
  //labels 
  if(gid_delta_.find("LABEL")!=gid_delta_.end()){
    auto history_labels_=gid_delta_["LABEL"].get<std::vector<std::pair<std::string,std::string>>>();;
    for (auto [key,value]:history_labels_){
       auto label_id = LabelId::FromUint(storage_->name_id_mapper_.NameToId(value));
       auto it = std::find(vertex->labels.begin(), vertex->labels.end(), label_id);
      if (key=="ADD_LABEL") {
        if (it != vertex->labels.end()) continue;
        vertex->labels.push_back(label_id);
      } else {
        if (it == vertex->labels.end()) continue;
        std::swap(*it, vertex->labels.back());
        vertex->labels.pop_back();
      }
    }
  }

  //TT_TS TT_TE
  auto property_id = PropertyId::FromUint(storage_->name_id_mapper_.NameToId("transaction_ts"));
  auto property_value = storage::PropertyValue(gid_delta_["TT_TS"].get<int64_t>());
  vertex->properties.SetProperty(property_id,property_value);

  auto property_id2 = PropertyId::FromUint(storage_->name_id_mapper_.NameToId("transaction_te"));
  auto property_value2 = storage::PropertyValue(gid_delta_["TT_TE"].get<int64_t>());
  vertex->properties.SetProperty(property_id2,property_value2);

  //TODO edges
  return VertexAccessor{vertex, &transaction_, &storage_->indices_, &storage_->constraints_, config_};
}

std::optional<VertexAccessor> Storage::Accessor::FindDeleteVertex(Gid gid, View view){
  auto acc = storage_->vertices_.access();
  auto it = acc.find(gid);
  if (it == acc.end()) return std::nullopt;
  return VertexAccessor::Creates(&*it, &transaction_, &storage_->indices_, &storage_->constraints_, config_, view);
}

//hjm end
VertexAccessor Storage::Accessor::CreateVertex() {
  OOMExceptionEnabler oom_exception;
  auto gid = storage_->vertex_id_.fetch_add(1, std::memory_order_acq_rel);
  auto acc = storage_->vertices_.access();
  auto delta = CreateDeleteObjectDelta(&transaction_);
  auto [it, inserted] = acc.insert(Vertex{storage::Gid::FromUint(gid), delta});
  MG_ASSERT(inserted, "The vertex must be inserted here!");
  MG_ASSERT(it != acc.end(), "Invalid Vertex accessor!");
  delta->prev.Set(&*it);
  return VertexAccessor(&*it, &transaction_, &storage_->indices_, &storage_->constraints_, config_);
}

VertexAccessor Storage::Accessor::CreateVertex(storage::Gid gid) {
  OOMExceptionEnabler oom_exception;
  // NOTE: When we update the next `vertex_id_` here we perform a RMW
  // (read-modify-write) operation that ISN'T atomic! But, that isn't an issue
  // because this function is only called from the replication delta applier
  // that runs single-threadedly and while this instance is set-up to apply
  // threads (it is the replica), it is guaranteed that no other writes are
  // possible.
  storage_->vertex_id_.store(std::max(storage_->vertex_id_.load(std::memory_order_acquire), gid.AsUint() + 1),
                             std::memory_order_release);
  auto acc = storage_->vertices_.access();
  auto delta = CreateDeleteObjectDelta(&transaction_);
  auto [it, inserted] = acc.insert(Vertex{gid, delta});
  MG_ASSERT(inserted, "The vertex must be inserted here!");
  MG_ASSERT(it != acc.end(), "Invalid Vertex accessor!");
  delta->prev.Set(&*it);
  return VertexAccessor(&*it, &transaction_, &storage_->indices_, &storage_->constraints_, config_);
}

std::optional<VertexAccessor> Storage::Accessor::FindVertex(Gid gid, View view) {
  auto acc = storage_->vertices_.access();
  auto it = acc.find(gid);
  if (it == acc.end()) return std::nullopt;
  return VertexAccessor::Create(&*it, &transaction_, &storage_->indices_, &storage_->constraints_, config_, view);
}

Result<std::optional<VertexAccessor>> Storage::Accessor::DeleteVertex(VertexAccessor *vertex) {
  MG_ASSERT(vertex->transaction_ == &transaction_,
            "VertexAccessor must be from the same transaction as the storage "
            "accessor when deleting a vertex!");
  auto *vertex_ptr = vertex->vertex_;

  std::lock_guard<utils::SpinLock> guard(vertex_ptr->lock);

  if (!PrepareForWrite(&transaction_, vertex_ptr)) return Error::SERIALIZATION_ERROR;

  if (vertex_ptr->deleted) {
    return std::optional<VertexAccessor>{};
  }

  if (!vertex_ptr->in_edges.empty() || !vertex_ptr->out_edges.empty()) return Error::VERTEX_HAS_EDGES;
  //hjm begin set transaction st
  auto ts=vertex_ptr->transaction_st;
  auto before_delta=vertex_ptr->delta;
  while (before_delta != nullptr){
    bool delta_is_edge=false;
    switch (before_delta->action) {
      case storage::Delta::Action::ADD_OUT_EDGE:
      case storage::Delta::Action::REMOVE_OUT_EDGE: 
      case storage::Delta::Action::ADD_IN_EDGE:
      case storage::Delta::Action::REMOVE_IN_EDGE:{
        delta_is_edge=true;
        break;
      }
      default:break;
    }
    if(delta_is_edge){
      before_delta = before_delta->next.load(std::memory_order_acquire); 
      continue;
    }  
    ts = before_delta->timestamp->load(std::memory_order_acquire);
    if(ts >= kTransactionInitialId){
      if(ts==transaction_.transaction_id){//ts >= kTransactionInitialId & 
        ts=before_delta->transaction_st;
      }else{
        std::cout<<"SERIALIZATION_ERROR"<<ts<<" "<<transaction_.transaction_id<<"\n";
        return Error::SERIALIZATION_ERROR;
      }
    }
    break;
  }
  //hjm end
  auto delta=CreateAndLinkDelta(&transaction_, vertex_ptr, Delta::RecreateObjectTag());
  vertex_ptr->deleted = true;

  //hjm begin
  delta->transaction_st=ts;
  //save vertex to restore
  nlohmann::json data = nlohmann::json::object();
  //labels
  auto maybe_labels = vertex_ptr->labels;
  auto add_labels=std::vector<std::pair<std::string,std::string>>();
  for (const auto &label : maybe_labels) {
    add_labels.emplace_back("AL",storage_->name_id_mapper_.IdToName(label.AsUint()));//name_id_mapper_.IdToName(label.AsUint())
  }
  data["L"] =add_labels;

  //properties
  auto maybe_properties = vertex_ptr->properties.Properties();;
  nlohmann::json data2 = nlohmann::json::object();
  for (const auto &prop : maybe_properties) {
    auto property_name = storage_->name_id_mapper_.IdToName(prop.first.AsUint());//delta.property.key.AsUint();//
    auto property_value = SerializePropertyValue(prop.second);//query::serialization::
    data2[property_name] = property_value;
  }
  data["SP"]=data2;
  delta->add_info=data;
  if(prinfFlag){
    auto print=prinfVertex(vertex_ptr->gid.AsUint(),ts,maybe_properties,maybe_labels);
    transaction_.prinfVertex_.emplace_back(print);
  }

  
  //hjm end

  return std::make_optional<VertexAccessor>(vertex_ptr, &transaction_, &storage_->indices_, &storage_->constraints_,
                                            config_, true);
}

Result<std::optional<std::pair<VertexAccessor, std::vector<EdgeAccessor>>>> Storage::Accessor::DetachDeleteVertex(
    VertexAccessor *vertex) {
  using ReturnType = std::pair<VertexAccessor, std::vector<EdgeAccessor>>;

  MG_ASSERT(vertex->transaction_ == &transaction_,
            "VertexAccessor must be from the same transaction as the storage "
            "accessor when deleting a vertex!");
  auto *vertex_ptr = vertex->vertex_;

  std::vector<std::tuple<EdgeTypeId, Vertex *, EdgeRef>> in_edges;
  std::vector<std::tuple<EdgeTypeId, Vertex *, EdgeRef>> out_edges;

  {
    std::lock_guard<utils::SpinLock> guard(vertex_ptr->lock);

    if (!PrepareForWrite(&transaction_, vertex_ptr)) return Error::SERIALIZATION_ERROR;

    if (vertex_ptr->deleted) return std::optional<ReturnType>{};

    in_edges = vertex_ptr->in_edges;
    out_edges = vertex_ptr->out_edges;
  }

  std::vector<EdgeAccessor> deleted_edges;
  for (const auto &item : in_edges) {
    auto [edge_type, from_vertex, edge] = item;
    EdgeAccessor e(edge, edge_type, from_vertex, vertex_ptr, &transaction_, &storage_->indices_,
                   &storage_->constraints_, config_);
    auto ret = DeleteEdge(&e);
    if (ret.HasError()) {
      MG_ASSERT(ret.GetError() == Error::SERIALIZATION_ERROR, "Invalid database state!");
      return ret.GetError();
    }

    if (ret.GetValue()) {
      deleted_edges.push_back(*ret.GetValue());
    }
  }
  for (const auto &item : out_edges) {
    auto [edge_type, to_vertex, edge] = item;
    EdgeAccessor e(edge, edge_type, vertex_ptr, to_vertex, &transaction_, &storage_->indices_, &storage_->constraints_,
                   config_);
    auto ret = DeleteEdge(&e);
    if (ret.HasError()) {
      MG_ASSERT(ret.GetError() == Error::SERIALIZATION_ERROR, "Invalid database state!");
      return ret.GetError();
    }

    if (ret.GetValue()) {
      deleted_edges.push_back(*ret.GetValue());
    }
  }

  std::lock_guard<utils::SpinLock> guard(vertex_ptr->lock);

  // We need to check again for serialization errors because we unlocked the
  // vertex. Some other transaction could have modified the vertex in the
  // meantime if we didn't have any edges to delete.

  if (!PrepareForWrite(&transaction_, vertex_ptr)) return Error::SERIALIZATION_ERROR;

  MG_ASSERT(!vertex_ptr->deleted, "Invalid database state!");
  
  //hjm begin set transaction st
  auto ts=vertex_ptr->transaction_st;
  auto before_delta=vertex_ptr->delta;
  while (before_delta != nullptr){
    bool delta_is_edge=false;
    switch (before_delta->action) {
      case storage::Delta::Action::ADD_OUT_EDGE:
      case storage::Delta::Action::REMOVE_OUT_EDGE: 
      case storage::Delta::Action::ADD_IN_EDGE:
      case storage::Delta::Action::REMOVE_IN_EDGE:{
        delta_is_edge=true;
        break;
      }
      default:break;
    }
    if(delta_is_edge){
      before_delta = before_delta->next.load(std::memory_order_acquire); 
      continue;
    }  
    ts = before_delta->timestamp->load(std::memory_order_acquire);
    if(ts >= kTransactionInitialId){
      if(ts==transaction_.transaction_id){//ts >= kTransactionInitialId & 
        ts=before_delta->transaction_st;
      }else{
        std::cout<<"SERIALIZATION_ERROR"<<ts<<" "<<transaction_.transaction_id<<"\n";
        return Error::SERIALIZATION_ERROR;
      }
    }
    break;
  }
  //hjm end

  auto delta=CreateAndLinkDelta(&transaction_, vertex_ptr, Delta::RecreateObjectTag());
  vertex_ptr->deleted = true;

  //hjm begin
  delta->transaction_st=ts;
  //save vertex to restore
  nlohmann::json data = nlohmann::json::object();
  //labels
  auto maybe_labels = vertex_ptr->labels;
  auto add_labels=std::vector<std::pair<std::string,std::string>>();
  for (const auto &label : maybe_labels) {
    add_labels.emplace_back("AL",storage_->name_id_mapper_.IdToName(label.AsUint()));//name_id_mapper_.IdToName(label.AsUint())
  }
  data["L"] =add_labels;

  //properties
  auto maybe_properties = vertex_ptr->properties.Properties();;
  nlohmann::json data2 = nlohmann::json::object();
  for (const auto &prop : maybe_properties) {
    auto property_name = storage_->name_id_mapper_.IdToName(prop.first.AsUint());//delta.property.key.AsUint();//
    auto property_value = SerializePropertyValue(prop.second);//query::serialization::
    data2[property_name] = property_value;
  }
  data["SP"]=data2;
  delta->add_info=data;

  if(prinfFlag){
    auto print=prinfVertex(vertex_ptr->gid.AsUint(),ts,maybe_properties,maybe_labels);
    transaction_.prinfVertex_.emplace_back(print);
  }
  //hjm end

  return std::make_optional<ReturnType>(
      VertexAccessor{vertex_ptr, &transaction_, &storage_->indices_, &storage_->constraints_, config_, true},
      std::move(deleted_edges));
}

Result<EdgeAccessor> Storage::Accessor::CreateEdge(VertexAccessor *from, VertexAccessor *to, EdgeTypeId edge_type) {
  OOMExceptionEnabler oom_exception;
  MG_ASSERT(from->transaction_ == to->transaction_,
            "VertexAccessors must be from the same transaction when creating "
            "an edge!");
  MG_ASSERT(from->transaction_ == &transaction_,
            "VertexAccessors must be from the same transaction in when "
            "creating an edge!");

  auto from_vertex = from->vertex_;
  auto to_vertex = to->vertex_;

  // Obtain the locks by `gid` order to avoid lock cycles.
  std::unique_lock<utils::SpinLock> guard_from(from_vertex->lock, std::defer_lock);
  std::unique_lock<utils::SpinLock> guard_to(to_vertex->lock, std::defer_lock);
  if (from_vertex->gid < to_vertex->gid) {
    guard_from.lock();
    guard_to.lock();
  } else if (from_vertex->gid > to_vertex->gid) {
    guard_to.lock();
    guard_from.lock();
  } else {
    // The vertices are the same vertex, only lock one.
    guard_from.lock();
  }

  if (!PrepareForWrite(&transaction_, from_vertex)) return Error::SERIALIZATION_ERROR;
  if (from_vertex->deleted) return Error::DELETED_OBJECT;

  if (to_vertex != from_vertex) {
    if (!PrepareForWrite(&transaction_, to_vertex)) return Error::SERIALIZATION_ERROR;
    if (to_vertex->deleted) return Error::DELETED_OBJECT;
  }


  //hjm begin set from veretx transaction st
  auto from_ts=from_vertex->ve_tt_ts;
  auto before_delta=from_vertex->delta;
  while (before_delta != nullptr){
    bool delta_is_edge=false;
    switch (before_delta->action) {
      case storage::Delta::Action::ADD_OUT_EDGE:
      case storage::Delta::Action::REMOVE_OUT_EDGE: 
      case storage::Delta::Action::ADD_IN_EDGE:
      case storage::Delta::Action::REMOVE_IN_EDGE:{
        delta_is_edge=true;
        break;
      }
      default:break;
    }
    if(!delta_is_edge){
      before_delta = before_delta->next.load(std::memory_order_acquire); 
      continue;
    }  
    from_ts = before_delta->timestamp->load(std::memory_order_acquire);
    if(from_ts >= kTransactionInitialId){
      if(from_ts==transaction_.transaction_id){//ts >= kTransactionInitialId & 
        from_ts=before_delta->transaction_st;
      }else{
        std::cout<<"SERIALIZATION_ERROR"<<from_ts<<" "<<transaction_.transaction_id<<"\n";
        return Error::SERIALIZATION_ERROR;
      }
    }
    break;
  }
  
  auto to_ts=to_vertex->ve_tt_ts;
  before_delta=to_vertex->delta;
  while (before_delta != nullptr){
    bool delta_is_edge=false;
    switch (before_delta->action) {
      case storage::Delta::Action::ADD_OUT_EDGE:
      case storage::Delta::Action::REMOVE_OUT_EDGE: 
      case storage::Delta::Action::ADD_IN_EDGE:
      case storage::Delta::Action::REMOVE_IN_EDGE:{
        delta_is_edge=true;
        break;
      }
      default:break;
    }
    if(!delta_is_edge){
      before_delta = before_delta->next.load(std::memory_order_acquire); 
      continue;
    }  
    to_ts = before_delta->timestamp->load(std::memory_order_acquire);
    if(to_ts >= kTransactionInitialId){
      if(to_ts==transaction_.transaction_id){//ts >= kTransactionInitialId & 
        to_ts=before_delta->transaction_st;
      }else{
        std::cout<<"SERIALIZATION_ERROR"<<to_ts<<" "<<transaction_.transaction_id<<"\n";
        return Error::SERIALIZATION_ERROR;
      }
    }
    break;
  } 
  //hjm end

  auto gid = storage::Gid::FromUint(storage_->edge_id_.fetch_add(1, std::memory_order_acq_rel));
  EdgeRef edge(gid);
  if (config_.properties_on_edges) {
    auto acc = storage_->edges_.access();
    auto delta = CreateDeleteObjectDelta(&transaction_);
    auto [it, inserted] = acc.insert(Edge(gid, delta));
    MG_ASSERT(inserted, "The edge must be inserted here!");
    MG_ASSERT(it != acc.end(), "Invalid Edge accessor!");
    //hjm begin
    delta->gid=gid;
    it->from_gid=from_vertex->gid;
    it->to_gid=to_vertex->gid;
    // std::cout<<"create edge here::2111"<<it->from_gid.AsUint()<<" "<<it->to_gid.AsUint()<<"\n";
    //hjm end
    edge = EdgeRef(&*it);
    delta->prev.Set(&*it);
  }

  auto delta=CreateAndLinkDelta(&transaction_, from_vertex, Delta::RemoveOutEdgeTag(), edge_type, to_vertex, edge);
  from_vertex->out_edges.emplace_back(edge_type, to_vertex, edge);
  //hjm begin
  delta->transaction_st = from_ts;
  transaction_.ve_changed.insert(from_vertex->gid);
  //hjm end
  
  delta=CreateAndLinkDelta(&transaction_, to_vertex, Delta::RemoveInEdgeTag(), edge_type, from_vertex, edge);
  to_vertex->in_edges.emplace_back(edge_type, from_vertex, edge);
  //hjm begin
  delta->transaction_st = to_ts;
  transaction_.ve_changed.insert(to_vertex->gid);
  //hjm end
  // Increment edge count.
  storage_->edge_count_.fetch_add(1, std::memory_order_acq_rel);

  return EdgeAccessor(edge, edge_type, from_vertex, to_vertex, &transaction_, &storage_->indices_,
                      &storage_->constraints_, config_);
}

Result<EdgeAccessor> Storage::Accessor::CreateEdge(VertexAccessor *from, VertexAccessor *to, EdgeTypeId edge_type,
                                                   storage::Gid gid) {
  OOMExceptionEnabler oom_exception;
  MG_ASSERT(from->transaction_ == to->transaction_,
            "VertexAccessors must be from the same transaction when creating "
            "an edge!");
  MG_ASSERT(from->transaction_ == &transaction_,
            "VertexAccessors must be from the same transaction in when "
            "creating an edge!");

  auto from_vertex = from->vertex_;
  auto to_vertex = to->vertex_;

  // Obtain the locks by `gid` order to avoid lock cycles.
  std::unique_lock<utils::SpinLock> guard_from(from_vertex->lock, std::defer_lock);
  std::unique_lock<utils::SpinLock> guard_to(to_vertex->lock, std::defer_lock);
  if (from_vertex->gid < to_vertex->gid) {
    guard_from.lock();
    guard_to.lock();
  } else if (from_vertex->gid > to_vertex->gid) {
    guard_to.lock();
    guard_from.lock();
  } else {
    // The vertices are the same vertex, only lock one.
    guard_from.lock();
  }

  if (!PrepareForWrite(&transaction_, from_vertex)) return Error::SERIALIZATION_ERROR;
  if (from_vertex->deleted) return Error::DELETED_OBJECT;

  if (to_vertex != from_vertex) {
    if (!PrepareForWrite(&transaction_, to_vertex)) return Error::SERIALIZATION_ERROR;
    if (to_vertex->deleted) return Error::DELETED_OBJECT;
  }

  //hjm begin set from veretx transaction st
  auto from_ts=from_vertex->ve_tt_ts;
  auto before_delta=from_vertex->delta;
  while (before_delta != nullptr){
    bool delta_is_edge=false;
    switch (before_delta->action) {
      case storage::Delta::Action::ADD_OUT_EDGE:
      case storage::Delta::Action::REMOVE_OUT_EDGE: 
      case storage::Delta::Action::ADD_IN_EDGE:
      case storage::Delta::Action::REMOVE_IN_EDGE:{
        delta_is_edge=true;
        break;
      }
      default:break;
    }
    if(!delta_is_edge){
      before_delta = before_delta->next.load(std::memory_order_acquire); 
      continue;
    }  
    from_ts = before_delta->timestamp->load(std::memory_order_acquire);
    if(from_ts >= kTransactionInitialId){
      if(from_ts==transaction_.transaction_id){//ts >= kTransactionInitialId & 
        from_ts=before_delta->transaction_st;
      }else{
        std::cout<<"SERIALIZATION_ERROR"<<from_ts<<" "<<transaction_.transaction_id<<"\n";
        return Error::SERIALIZATION_ERROR;
      }
    }
    break;
  }
  
  auto to_ts=to_vertex->ve_tt_ts;
  before_delta=to_vertex->delta;
  while (before_delta != nullptr){
    bool delta_is_edge=false;
    switch (before_delta->action) {
      case storage::Delta::Action::ADD_OUT_EDGE:
      case storage::Delta::Action::REMOVE_OUT_EDGE: 
      case storage::Delta::Action::ADD_IN_EDGE:
      case storage::Delta::Action::REMOVE_IN_EDGE:{
        delta_is_edge=true;
        break;
      }
      default:break;
    }
    if(!delta_is_edge){
      before_delta = before_delta->next.load(std::memory_order_acquire); 
      continue;
    }  
    to_ts = before_delta->timestamp->load(std::memory_order_acquire);
    if(to_ts >= kTransactionInitialId){
      if(to_ts==transaction_.transaction_id){//ts >= kTransactionInitialId & 
        to_ts=before_delta->transaction_st;
      }else{
        std::cout<<"SERIALIZATION_ERROR"<<to_ts<<" "<<transaction_.transaction_id<<"\n";
        return Error::SERIALIZATION_ERROR;
      }
    }
    break;
  }
    
  //hjm end

  // NOTE: When we update the next `edge_id_` here we perform a RMW
  // (read-modify-write) operation that ISN'T atomic! But, that isn't an issue
  // because this function is only called from the replication delta applier
  // that runs single-threadedly and while this instance is set-up to apply
  // threads (it is the replica), it is guaranteed that no other writes are
  // possible.
  storage_->edge_id_.store(std::max(storage_->edge_id_.load(std::memory_order_acquire), gid.AsUint() + 1),
                           std::memory_order_release);

  EdgeRef edge(gid);
  if (config_.properties_on_edges) {
    auto acc = storage_->edges_.access();
    auto delta = CreateDeleteObjectDelta(&transaction_);
    auto [it, inserted] = acc.insert(Edge(gid, delta));
    MG_ASSERT(inserted, "The edge must be inserted here!");
    MG_ASSERT(it != acc.end(), "Invalid Edge accessor!");
    //hjm begin
    it->from_gid=from_vertex->gid;
    it->to_gid=to_vertex->gid;
    delta->gid=gid;
    //hjm end
    edge = EdgeRef(&*it);
    delta->prev.Set(&*it);
  }

  auto delta=CreateAndLinkDelta(&transaction_, from_vertex, Delta::RemoveOutEdgeTag(), edge_type, to_vertex, edge);
  from_vertex->out_edges.emplace_back(edge_type, to_vertex, edge);
  //hjm begin
  delta->transaction_st = from_ts;
  transaction_.ve_changed.insert(from_vertex->gid);
  //hjm end
  delta=CreateAndLinkDelta(&transaction_, to_vertex, Delta::RemoveInEdgeTag(), edge_type, from_vertex, edge);
  to_vertex->in_edges.emplace_back(edge_type, from_vertex, edge);
  
  //hjm begin
  delta->transaction_st = to_ts;
  transaction_.ve_changed.insert(to_vertex->gid);
  //hjm end

  // Increment edge count.
  storage_->edge_count_.fetch_add(1, std::memory_order_acq_rel);

  return EdgeAccessor(edge, edge_type, from_vertex, to_vertex, &transaction_, &storage_->indices_,
                      &storage_->constraints_, config_);
}

Result<std::optional<EdgeAccessor>> Storage::Accessor::DeleteEdge(EdgeAccessor *edge) {
  MG_ASSERT(edge->transaction_ == &transaction_,
            "EdgeAccessor must be from the same transaction as the storage "
            "accessor when deleting an edge!");
  auto edge_ref = edge->edge_;
  auto edge_type = edge->edge_type_;

  std::unique_lock<utils::SpinLock> guard;
  if (config_.properties_on_edges) {
    auto edge_ptr = edge_ref.ptr;
    guard = std::unique_lock<utils::SpinLock>(edge_ptr->lock);

    if (!PrepareForWrite(&transaction_, edge_ptr)) return Error::SERIALIZATION_ERROR;

    if (edge_ptr->deleted) return std::optional<EdgeAccessor>{};
  }


  auto *from_vertex = edge->from_vertex_;
  auto *to_vertex = edge->to_vertex_;
  
  //hjm begin set ransaction st
  uint64_t ts=0;
  if (config_.properties_on_edges){
    auto edge_ptr = edge_ref.ptr;
    ts=edge_ptr->transaction_st;
    auto before_delta=edge_ptr->delta;
    if (before_delta != nullptr){
      ts = before_delta->timestamp->load(std::memory_order_acquire);
      if(ts >= kTransactionInitialId){
        if(ts==transaction_.transaction_id){//ts >= kTransactionInitialId & 
          ts=before_delta->transaction_st;
        }else{
          std::cout<<"SERIALIZATION_ERROR"<<ts<<" "<<transaction_.transaction_id<<"\n";
          return Error::SERIALIZATION_ERROR;
        }
      }
    }
  }

  auto from_ts=from_vertex->ve_tt_ts;
  auto before_delta=from_vertex->delta;
  while (before_delta != nullptr){
    bool delta_is_edge=false;
    switch (before_delta->action) {
      case storage::Delta::Action::ADD_OUT_EDGE:
      case storage::Delta::Action::REMOVE_OUT_EDGE: 
      case storage::Delta::Action::ADD_IN_EDGE:
      case storage::Delta::Action::REMOVE_IN_EDGE:{
        delta_is_edge=true;
        break;
      }
      default:break;
    }
    if(!delta_is_edge){
      before_delta = before_delta->next.load(std::memory_order_acquire); 
      continue;
    }  
    from_ts = before_delta->timestamp->load(std::memory_order_acquire);
    if(from_ts >= kTransactionInitialId){
      if(from_ts==transaction_.transaction_id){//ts >= kTransactionInitialId & 
        from_ts=before_delta->transaction_st;
      }else{
        std::cout<<"SERIALIZATION_ERROR"<<from_ts<<" "<<transaction_.transaction_id<<"\n";
        return Error::SERIALIZATION_ERROR;
      }
    }
    break;
  }
  
  auto to_ts=to_vertex->ve_tt_ts;
  before_delta=to_vertex->delta;
  while (before_delta != nullptr){
    bool delta_is_edge=false;
    switch (before_delta->action) {
      case storage::Delta::Action::ADD_OUT_EDGE:
      case storage::Delta::Action::REMOVE_OUT_EDGE: 
      case storage::Delta::Action::ADD_IN_EDGE:
      case storage::Delta::Action::REMOVE_IN_EDGE:{
        delta_is_edge=true;
        break;
      }
      default:break;
    }
    if(!delta_is_edge){
      before_delta = before_delta->next.load(std::memory_order_acquire); 
      continue;
    }  
    to_ts = before_delta->timestamp->load(std::memory_order_acquire);
    if(to_ts >= kTransactionInitialId){
      if(to_ts==transaction_.transaction_id){//ts >= kTransactionInitialId & 
        to_ts=before_delta->transaction_st;
      }else{
        std::cout<<"SERIALIZATION_ERROR"<<to_ts<<" "<<transaction_.transaction_id<<"\n";
        return Error::SERIALIZATION_ERROR;
      }
    }
    break;
  }
    
  //hjm end


  // Obtain the locks by `gid` order to avoid lock cycles.
  std::unique_lock<utils::SpinLock> guard_from(from_vertex->lock, std::defer_lock);
  std::unique_lock<utils::SpinLock> guard_to(to_vertex->lock, std::defer_lock);
  if (from_vertex->gid < to_vertex->gid) {
    guard_from.lock();
    guard_to.lock();
  } else if (from_vertex->gid > to_vertex->gid) {
    guard_to.lock();
    guard_from.lock();
  } else {
    // The vertices are the same vertex, only lock one.
    guard_from.lock();
  }

  if (!PrepareForWrite(&transaction_, from_vertex)) return Error::SERIALIZATION_ERROR;
  MG_ASSERT(!from_vertex->deleted, "Invalid database state!");

  if (to_vertex != from_vertex) {
    if (!PrepareForWrite(&transaction_, to_vertex)) return Error::SERIALIZATION_ERROR;
    MG_ASSERT(!to_vertex->deleted, "Invalid database state!");
  }

  auto delete_edge_from_storage = [&edge_type, &edge_ref, this](auto *vertex, auto *edges) {
    std::tuple<EdgeTypeId, Vertex *, EdgeRef> link(edge_type, vertex, edge_ref);
    auto it = std::find(edges->begin(), edges->end(), link);
    if (config_.properties_on_edges) {
      MG_ASSERT(it != edges->end(), "Invalid database state!");
    } else if (it == edges->end()) {
      return false;
    }
    std::swap(*it, *edges->rbegin());
    edges->pop_back();
    return true;
  };

  auto op1 = delete_edge_from_storage(to_vertex, &from_vertex->out_edges);
  auto op2 = delete_edge_from_storage(from_vertex, &to_vertex->in_edges);

  if (config_.properties_on_edges) {
    MG_ASSERT((op1 && op2), "Invalid database state!");
  } else {
    MG_ASSERT((op1 && op2) || (!op1 && !op2), "Invalid database state!");
    if (!op1 && !op2) {
      // The edge is already deleted.
      return std::optional<EdgeAccessor>{};
    }
  }

  if (config_.properties_on_edges) {
    auto *edge_ptr = edge_ref.ptr;
    auto delta=CreateAndLinkDelta(&transaction_, edge_ptr, Delta::RecreateObjectTag());
    edge_ptr->deleted = true;
    //hjm begin store edge to reconstruct
    delta->transaction_st=ts;
    delta->from_gid=edge_ptr->from_gid;
    delta->to_gid=edge_ptr->to_gid;
    //properties
    nlohmann::json data = nlohmann::json::object();
    auto maybe_properties = edge_ptr->properties.Properties();;
    nlohmann::json data2 = nlohmann::json::object();
    for (const auto &prop : maybe_properties) {
      auto property_name = storage_->name_id_mapper_.IdToName(prop.first.AsUint());//delta.property.key.AsUint();//
      auto property_value = SerializePropertyValue(prop.second);//query::serialization::
      data2[property_name] = property_value;
    }
    data["SP"]=data2;
    delta->add_info=data;
    if(prinfFlag){
      auto prinfEdges=prinfEdge(edge_type,edge_ptr->gid.AsUint(),edge_ptr->from_gid.AsUint(),edge_ptr->to_gid.AsUint(),ts,maybe_properties);
      transaction_.prinfEdge_.emplace_back(prinfEdges);
    }
    //hjm end
  }

  auto delta=CreateAndLinkDelta(&transaction_, from_vertex, Delta::AddOutEdgeTag(), edge_type, to_vertex, edge_ref);
  //hjm begin
  delta->transaction_st = from_ts;
  transaction_.ve_changed.insert(from_vertex->gid);
  //hjm end

  delta=CreateAndLinkDelta(&transaction_, to_vertex, Delta::AddInEdgeTag(), edge_type, from_vertex, edge_ref);
  //hjm begin
  delta->transaction_st = to_ts;
  transaction_.ve_changed.insert(to_vertex->gid);
  //hjm end

  // Decrement edge count.
  storage_->edge_count_.fetch_add(-1, std::memory_order_acq_rel);

  return std::make_optional<EdgeAccessor>(edge_ref, edge_type, from_vertex, to_vertex, &transaction_,
                                          &storage_->indices_, &storage_->constraints_, config_, true);
}

const std::string &Storage::Accessor::LabelToName(LabelId label) const { return storage_->LabelToName(label); }

const std::string &Storage::Accessor::PropertyToName(PropertyId property) const {
  return storage_->PropertyToName(property);
}

const std::string &Storage::Accessor::EdgeTypeToName(EdgeTypeId edge_type) const {
  return storage_->EdgeTypeToName(edge_type);
}

LabelId Storage::Accessor::NameToLabel(const std::string_view &name) { return storage_->NameToLabel(name); }

PropertyId Storage::Accessor::NameToProperty(const std::string_view &name) { return storage_->NameToProperty(name); }

EdgeTypeId Storage::Accessor::NameToEdgeType(const std::string_view &name) { return storage_->NameToEdgeType(name); }


void Storage::Accessor::AdvanceCommand() { ++transaction_.command_id; }

utils::BasicResult<ConstraintViolation, void> Storage::Accessor::Commit(
    const std::optional<uint64_t> desired_commit_timestamp) {
  MG_ASSERT(is_transaction_active_, "The transaction is already terminated!");
  MG_ASSERT(!transaction_.must_abort, "The transaction can't be committed!");
  // std::cout<<"commit here\n";
  
  std::list<Gid> my_deleted_vertices;
  std::list<Gid> my_deleted_edges;
  
  std::set<storage::Vertex *> commit_vertices;
  std::set<storage::Edge *> commit_edges;

  if (transaction_.deltas.empty()) {
    // We don't have to update the commit timestamp here because no one reads
    // it.
    storage_->commit_log_->MarkFinished(transaction_.start_timestamp);
  } else {
    // Validate that existence constraints are satisfied for all modified
    // vertices.
    for (const auto &delta : transaction_.deltas) {
      auto prev = delta.prev.Get();
      MG_ASSERT(prev.type != PreviousPtr::Type::NULLPTR, "Invalid pointer!");
      if (prev.type != PreviousPtr::Type::VERTEX) {
        continue;
      }
      // No need to take any locks here because we modified this vertex and no
      // one else can touch it until we commit.
      auto validation_result = ValidateExistenceConstraints(*prev.vertex, storage_->constraints_);
      if (validation_result) {
        Abort();
        return *validation_result;
      }
    }

    // Result of validating the vertex against unqiue constraints. It has to be
    // declared outside of the critical section scope because its value is
    // tested for Abort call which has to be done out of the scope.
    std::optional<ConstraintViolation> unique_constraint_violation;

    // Save these so we can mark them used in the commit log.
    uint64_t start_timestamp = transaction_.start_timestamp;

    {
      std::unique_lock<utils::SpinLock> engine_guard(storage_->engine_lock_);
      commit_timestamp_.emplace(storage_->CommitTimestamp(desired_commit_timestamp));
      
      // Before committing and validating vertices against unique constraints,
      // we have to update unique constraints with the vertices that are going
      // to be validated/committed.
      for (const auto &delta : transaction_.deltas) {
        auto prev = delta.prev.Get();
        MG_ASSERT(prev.type != PreviousPtr::Type::NULLPTR, "Invalid pointer!");
        if (prev.type != PreviousPtr::Type::VERTEX) {
          continue;
        }
        storage_->constraints_.unique_constraints.UpdateBeforeCommit(prev.vertex, transaction_);
      }

      // Validate that unique constraints are satisfied for all modified
      // vertices.
      for (const auto &delta : transaction_.deltas) {
        auto prev = delta.prev.Get();
        MG_ASSERT(prev.type != PreviousPtr::Type::NULLPTR, "Invalid pointer!");
        if (prev.type != PreviousPtr::Type::VERTEX) {
          continue;
        }

        // No need to take any locks here because we modified this vertex and no
        // one else can touch it until we commit.
        unique_constraint_violation =
            storage_->constraints_.unique_constraints.Validate(*prev.vertex, transaction_, *commit_timestamp_);
        if (unique_constraint_violation) {
          break;
        }
      }
      
      if (!unique_constraint_violation) {
        // Write transaction to WAL while holding the engine lock to make sure
        // that committed transactions are sorted by the commit timestamp in the
        // WAL files. We supply the new commit timestamp to the function so that
        // it knows what will be the final commit timestamp. The WAL must be
        // written before actually committing the transaction (before setting
        // the commit timestamp) so that no other transaction can see the
        // modifications before they are written to disk.
        // Replica can log only the write transaction received from Main
        // so the Wal files are consistent
        if (storage_->replication_role_ == ReplicationRole::MAIN || desired_commit_timestamp.has_value()) {
          storage_->AppendToWal(transaction_, *commit_timestamp_);
        }

        // Take committed_transactions lock while holding the engine lock to
        // make sure that committed transactions are sorted by the commit
        // timestamp in the list.
        storage_->committed_transactions_.WithLock([&](auto &committed_transactions) {
          // TODO: release lock, and update all deltas to have a local copy
          // of the commit timestamp
          MG_ASSERT(transaction_.commit_timestamp != nullptr, "Invalid database state!");
          transaction_.commit_timestamp->store(*commit_timestamp_, std::memory_order_release);
          // Replica can only update the last commit timestamp with
          // the commits received from main.
          if (storage_->replication_role_ == ReplicationRole::MAIN || desired_commit_timestamp.has_value()) {
            // Update the last commit timestamp
            storage_->last_commit_timestamp_.store(*commit_timestamp_);
          }

          // Release engine lock because we don't have to hold it anymore
          // and emplace back could take a long time.
          engine_guard.unlock();
        });

        storage_->commit_log_->MarkFinished(start_timestamp);
      }
    }

    if (unique_constraint_violation) {
      Abort();
      return *unique_constraint_violation;
    }
  }

  //transactionid->commit_time
  auto time_flag=config_.realTimeFlag;

  if(!time_flag){
    for (auto &delta : transaction_.deltas) {
      auto commit_timestamp = transaction_.commit_timestamp->load(std::memory_order_acquire);
      if(delta.transaction_st==0 ){
        delta.transaction_st=commit_timestamp+1;
      }
      delta.commit_timestamp=commit_timestamp;
      auto prev = delta.prev.Get();
      switch (prev.type) {
        case storage::PreviousPtr::Type::VERTEX: {
          storage::Vertex *vertex = prev.vertex;
          if(vertex->deleted){
            storage_->hjm_deleted_vertices_.emplace_back(vertex->gid.AsUint());
            storage_->hjm_deleted_vertices.emplace_back(vertex);
            my_deleted_vertices.push_back(vertex->gid);
            // vertex->tt_te=0; //wzy 0512
          }else{
            auto gid=vertex->gid;
            if(transaction_.v_changed.count(gid)){
              vertex->transaction_st=*commit_timestamp_;
            }
            if(transaction_.ve_changed.count(gid))vertex->ve_tt_ts=*commit_timestamp_;
          }
          break;
        }
        case storage::PreviousPtr::Type::EDGE: {
          storage::Edge *edge = prev.edge;
          edge->transaction_st=*commit_timestamp_;
          if(edge->deleted)  my_deleted_edges.push_back(edge->gid);
          break;
        }
        case storage::PreviousPtr::Type::DELTA: {
          break;
        }
        case storage::PreviousPtr::Type::NULLPTR: {
        }
      }
    }
    
    
  }else{//set realtime
    auto now_time = std::chrono::system_clock::now();
    auto real_commit_timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(now_time.time_since_epoch()).count();
    for (auto &delta : transaction_.deltas) {
      if(delta.transaction_st==0 ){
        delta.transaction_st=real_commit_timestamp;
      }
      delta.commit_timestamp=real_commit_timestamp;
      auto prev = delta.prev.Get();
      switch (prev.type) {
        case storage::PreviousPtr::Type::VERTEX: {
          storage::Vertex *vertex = prev.vertex;
          if(vertex->deleted){
            storage_->hjm_deleted_vertices_.emplace_back(vertex->gid.AsUint());
            storage_->hjm_deleted_vertices.emplace_back(vertex);
            my_deleted_vertices.push_back(vertex->gid);
          }else{
            auto gid=vertex->gid;
            if(transaction_.v_changed.count(gid)){
              vertex->transaction_st=real_commit_timestamp;
            }
            if(transaction_.ve_changed.count(gid))vertex->ve_tt_ts=real_commit_timestamp;
          }
          break;
        }
        case storage::PreviousPtr::Type::EDGE: {
          storage::Edge *edge = prev.edge;
          edge->transaction_st=real_commit_timestamp;
          if(edge->deleted)  my_deleted_edges.push_back(edge->gid);
          break;
        }
        case storage::PreviousPtr::Type::DELTA: {
          break;
        }
        case storage::PreviousPtr::Type::NULLPTR: {
        }
      }
    }

  }

  storage_->transaction_tables_.WithLock(
        [&](auto &transaction_tables) { transaction_tables[transaction_.transaction_id]=*commit_timestamp_; });
  
  // commit_edges.clear();
  // commit_vertices.clear();
  storage_->recover_deleted_vertices_.WithLock(
        [&](auto &deleted_vertices) { deleted_vertices.splice(deleted_vertices.begin(), my_deleted_vertices); });
  
  //hjm end set done

  is_transaction_active_ = false;
  

  return {};
}

void Storage::Accessor::Abort() {
  MG_ASSERT(is_transaction_active_, "The transaction is already terminated!");

  // We collect vertices and edges we've created here and then splice them into
  // `deleted_vertices_` and `deleted_edges_` lists, instead of adding them one
  // by one and acquiring lock every time.
  std::list<Gid> my_deleted_vertices;
  std::list<Gid> my_deleted_edges;

  //hjm begin
  std::list<Gid> my_deleted_vertices1;
  std::list<Gid> my_deleted_edges1;
  //hjm end

  for (const auto &delta : transaction_.deltas) {
    auto prev = delta.prev.Get();
    switch (prev.type) {
      case PreviousPtr::Type::VERTEX: {
        auto vertex = prev.vertex;
        std::lock_guard<utils::SpinLock> guard(vertex->lock);
        Delta *current = vertex->delta;
        while (current != nullptr &&
               current->timestamp->load(std::memory_order_acquire) == transaction_.transaction_id) {
          switch (current->action) {
            //hjm begin
            vertex->transaction_st=current->commit_timestamp;
            //hjm end
            case Delta::Action::REMOVE_LABEL: {
              auto it = std::find(vertex->labels.begin(), vertex->labels.end(), current->label);
              MG_ASSERT(it != vertex->labels.end(), "Invalid database state!");
              std::swap(*it, *vertex->labels.rbegin());
              vertex->labels.pop_back();
              break;
            }
            case Delta::Action::ADD_LABEL: {
              auto it = std::find(vertex->labels.begin(), vertex->labels.end(), current->label);
              MG_ASSERT(it == vertex->labels.end(), "Invalid database state!");
              vertex->labels.push_back(current->label);
              break;
            }
            case Delta::Action::SET_PROPERTY: {
              vertex->properties.SetProperty(current->property.key, current->property.value);
              break;
            }
            case Delta::Action::ADD_IN_EDGE: {
              std::tuple<EdgeTypeId, Vertex *, EdgeRef> link{current->vertex_edge.edge_type,
                                                             current->vertex_edge.vertex, current->vertex_edge.edge};
              auto it = std::find(vertex->in_edges.begin(), vertex->in_edges.end(), link);
              MG_ASSERT(it == vertex->in_edges.end(), "Invalid database state!");
              vertex->in_edges.push_back(link);
              break;
            }
            case Delta::Action::ADD_OUT_EDGE: {
              std::tuple<EdgeTypeId, Vertex *, EdgeRef> link{current->vertex_edge.edge_type,
                                                             current->vertex_edge.vertex, current->vertex_edge.edge};
              auto it = std::find(vertex->out_edges.begin(), vertex->out_edges.end(), link);
              MG_ASSERT(it == vertex->out_edges.end(), "Invalid database state!");
              vertex->out_edges.push_back(link);
              // Increment edge count. We only increment the count here because
              // the information in `ADD_IN_EDGE` and `Edge/RECREATE_OBJECT` is
              // redundant. Also, `Edge/RECREATE_OBJECT` isn't available when
              // edge properties are disabled.
              storage_->edge_count_.fetch_add(1, std::memory_order_acq_rel);
              break;
            }
            case Delta::Action::REMOVE_IN_EDGE: {
              std::tuple<EdgeTypeId, Vertex *, EdgeRef> link{current->vertex_edge.edge_type,
                                                             current->vertex_edge.vertex, current->vertex_edge.edge};
              auto it = std::find(vertex->in_edges.begin(), vertex->in_edges.end(), link);
              MG_ASSERT(it != vertex->in_edges.end(), "Invalid database state!");
              std::swap(*it, *vertex->in_edges.rbegin());
              vertex->in_edges.pop_back();
              break;
            }
            case Delta::Action::REMOVE_OUT_EDGE: {
              std::tuple<EdgeTypeId, Vertex *, EdgeRef> link{current->vertex_edge.edge_type,
                                                             current->vertex_edge.vertex, current->vertex_edge.edge};
              auto it = std::find(vertex->out_edges.begin(), vertex->out_edges.end(), link);
              MG_ASSERT(it != vertex->out_edges.end(), "Invalid database state!");
              std::swap(*it, *vertex->out_edges.rbegin());
              vertex->out_edges.pop_back();
              // Decrement edge count. We only decrement the count here because
              // the information in `REMOVE_IN_EDGE` and `Edge/DELETE_OBJECT` is
              // redundant. Also, `Edge/DELETE_OBJECT` isn't available when edge
              // properties are disabled.
              storage_->edge_count_.fetch_add(-1, std::memory_order_acq_rel);
              break;
            }
            case Delta::Action::DELETE_OBJECT: {
              vertex->deleted = true;
              my_deleted_vertices.push_back(vertex->gid);
              my_deleted_vertices1.push_back(vertex->gid);
              break;
            }
            case Delta::Action::RECREATE_OBJECT: {
              vertex->deleted = false;
              break;
            }
          }
          current = current->next.load(std::memory_order_acquire);
        }
        vertex->delta = current;
        if (current != nullptr) {
          current->prev.Set(vertex);
        }

        break;
      }
      case PreviousPtr::Type::EDGE: {
        auto edge = prev.edge;
        std::lock_guard<utils::SpinLock> guard(edge->lock);
        Delta *current = edge->delta;
        while (current != nullptr &&
               current->timestamp->load(std::memory_order_acquire) == transaction_.transaction_id) {
          switch (current->action) {
            case Delta::Action::SET_PROPERTY: {
              edge->properties.SetProperty(current->property.key, current->property.value);
              break;
            }
            case Delta::Action::DELETE_OBJECT: {
              edge->deleted = true;
              my_deleted_edges.push_back(edge->gid);
              my_deleted_edges1.push_back(edge->gid);
              break;
            }
            case Delta::Action::RECREATE_OBJECT: {
              edge->deleted = false;
              break;
            }
            case Delta::Action::REMOVE_LABEL:
            case Delta::Action::ADD_LABEL:
            case Delta::Action::ADD_IN_EDGE:
            case Delta::Action::ADD_OUT_EDGE:
            case Delta::Action::REMOVE_IN_EDGE:
            case Delta::Action::REMOVE_OUT_EDGE: {
              LOG_FATAL("Invalid database state!");
              break;
            }
          }
          //hjm begin
          edge->transaction_st=current->commit_timestamp;
          //hjm end
          current = current->next.load(std::memory_order_acquire);
        }
        edge->delta = current;
        if (current != nullptr) {
          current->prev.Set(edge);
        }

        break;
      }
      case PreviousPtr::Type::DELTA:
      // pointer probably couldn't be set because allocation failed
      case PreviousPtr::Type::NULLPTR:
        break;
    }
  }

  {
    std::unique_lock<utils::SpinLock> engine_guard(storage_->engine_lock_);
    uint64_t mark_timestamp = storage_->timestamp_;
    // Take garbage_undo_buffers lock while holding the engine lock to make
    // sure that entries are sorted by mark timestamp in the list.
    storage_->garbage_undo_buffers_.WithLock([&](auto &garbage_undo_buffers) {
      // Release engine lock because we don't have to hold it anymore and
      // emplace back could take a long time.
      engine_guard.unlock();
      garbage_undo_buffers.emplace_back(mark_timestamp, std::move(transaction_.deltas));
    });
    storage_->deleted_vertices_.WithLock(
        [&](auto &deleted_vertices) { deleted_vertices.splice(deleted_vertices.begin(), my_deleted_vertices); });
    storage_->deleted_edges_.WithLock(
        [&](auto &deleted_edges) { deleted_edges.splice(deleted_edges.begin(), my_deleted_edges); });

    //hjm begin
    storage_->recover_deleted_vertices_.WithLock(
        [&](auto &deleted_vertices) { deleted_vertices.splice(deleted_vertices.begin(), my_deleted_vertices1); });
    // storage_->recover_deleted_edges_.WithLock(
    //     [&](auto &deleted_edges) { deleted_edges.splice(deleted_edges.begin(), my_deleted_edges1); });
    //hjm end
  }

  storage_->commit_log_->MarkFinished(transaction_.start_timestamp);
  is_transaction_active_ = false;
}

void Storage::Accessor::FinalizeTransaction() {
  if (commit_timestamp_) {
    storage_->commit_log_->MarkFinished(*commit_timestamp_);
    storage_->committed_transactions_.WithLock(
        [&](auto &committed_transactions) { committed_transactions.emplace_back(std::move(transaction_)); });
    commit_timestamp_.reset();
  }
}

const std::string &Storage::LabelToName(LabelId label) const { return name_id_mapper_.IdToName(label.AsUint()); }

const std::string &Storage::PropertyToName(PropertyId property) const {
  return name_id_mapper_.IdToName(property.AsUint());
}

const std::string &Storage::EdgeTypeToName(EdgeTypeId edge_type) const {
  return name_id_mapper_.IdToName(edge_type.AsUint());
}

LabelId Storage::NameToLabel(const std::string_view &name) { return LabelId::FromUint(name_id_mapper_.NameToId(name)); }

PropertyId Storage::NameToProperty(const std::string_view &name) {
  return PropertyId::FromUint(name_id_mapper_.NameToId(name));
}

EdgeTypeId Storage::NameToEdgeType(const std::string_view &name) {
  return EdgeTypeId::FromUint(name_id_mapper_.NameToId(name));
}

bool Storage::CreateIndex(LabelId label, const std::optional<uint64_t> desired_commit_timestamp) {
  std::unique_lock<utils::RWLock> storage_guard(main_lock_);
  if (!indices_.label_index.CreateIndex(label, vertices_.access())) return false;
  const auto commit_timestamp = CommitTimestamp(desired_commit_timestamp);
  AppendToWal(durability::StorageGlobalOperation::LABEL_INDEX_CREATE, label, {}, commit_timestamp);
  commit_log_->MarkFinished(commit_timestamp);
  last_commit_timestamp_ = commit_timestamp;
  return true;
}

bool Storage::CreateIndex(LabelId label, PropertyId property, const std::optional<uint64_t> desired_commit_timestamp) {
  std::unique_lock<utils::RWLock> storage_guard(main_lock_);
  if (!indices_.label_property_index.CreateIndex(label, property, vertices_.access())) return false;
  const auto commit_timestamp = CommitTimestamp(desired_commit_timestamp);
  AppendToWal(durability::StorageGlobalOperation::LABEL_PROPERTY_INDEX_CREATE, label, {property}, commit_timestamp);
  commit_log_->MarkFinished(commit_timestamp);
  last_commit_timestamp_ = commit_timestamp;
  return true;
}

bool Storage::DropIndex(LabelId label, const std::optional<uint64_t> desired_commit_timestamp) {
  std::unique_lock<utils::RWLock> storage_guard(main_lock_);
  if (!indices_.label_index.DropIndex(label)) return false;
  const auto commit_timestamp = CommitTimestamp(desired_commit_timestamp);
  AppendToWal(durability::StorageGlobalOperation::LABEL_INDEX_DROP, label, {}, commit_timestamp);
  commit_log_->MarkFinished(commit_timestamp);
  last_commit_timestamp_ = commit_timestamp;
  return true;
}

bool Storage::DropIndex(LabelId label, PropertyId property, const std::optional<uint64_t> desired_commit_timestamp) {
  std::unique_lock<utils::RWLock> storage_guard(main_lock_);
  if (!indices_.label_property_index.DropIndex(label, property)) return false;
  // For a description why using `timestamp_` is correct, see
  // `CreateIndex(LabelId label)`.
  const auto commit_timestamp = CommitTimestamp(desired_commit_timestamp);
  AppendToWal(durability::StorageGlobalOperation::LABEL_PROPERTY_INDEX_DROP, label, {property}, commit_timestamp);
  commit_log_->MarkFinished(commit_timestamp);
  last_commit_timestamp_ = commit_timestamp;
  return true;
}

IndicesInfo Storage::ListAllIndices() const {
  std::shared_lock<utils::RWLock> storage_guard_(main_lock_);
  return {indices_.label_index.ListIndices(), indices_.label_property_index.ListIndices()};
}

utils::BasicResult<ConstraintViolation, bool> Storage::CreateExistenceConstraint(
    LabelId label, PropertyId property, const std::optional<uint64_t> desired_commit_timestamp) {
  std::unique_lock<utils::RWLock> storage_guard(main_lock_);
  auto ret = ::storage::CreateExistenceConstraint(&constraints_, label, property, vertices_.access());
  if (ret.HasError() || !ret.GetValue()) return ret;
  const auto commit_timestamp = CommitTimestamp(desired_commit_timestamp);
  AppendToWal(durability::StorageGlobalOperation::EXISTENCE_CONSTRAINT_CREATE, label, {property}, commit_timestamp);
  commit_log_->MarkFinished(commit_timestamp);
  last_commit_timestamp_ = commit_timestamp;
  return true;
}

bool Storage::DropExistenceConstraint(LabelId label, PropertyId property,
                                      const std::optional<uint64_t> desired_commit_timestamp) {
  std::unique_lock<utils::RWLock> storage_guard(main_lock_);
  if (!::storage::DropExistenceConstraint(&constraints_, label, property)) return false;
  const auto commit_timestamp = CommitTimestamp(desired_commit_timestamp);
  AppendToWal(durability::StorageGlobalOperation::EXISTENCE_CONSTRAINT_DROP, label, {property}, commit_timestamp);
  commit_log_->MarkFinished(commit_timestamp);
  last_commit_timestamp_ = commit_timestamp;
  return true;
}

utils::BasicResult<ConstraintViolation, UniqueConstraints::CreationStatus> Storage::CreateUniqueConstraint(
    LabelId label, const std::set<PropertyId> &properties, const std::optional<uint64_t> desired_commit_timestamp) {
  std::unique_lock<utils::RWLock> storage_guard(main_lock_);
  auto ret = constraints_.unique_constraints.CreateConstraint(label, properties, vertices_.access());
  if (ret.HasError() || ret.GetValue() != UniqueConstraints::CreationStatus::SUCCESS) {
    return ret;
  }
  const auto commit_timestamp = CommitTimestamp(desired_commit_timestamp);
  AppendToWal(durability::StorageGlobalOperation::UNIQUE_CONSTRAINT_CREATE, label, properties, commit_timestamp);
  commit_log_->MarkFinished(commit_timestamp);
  last_commit_timestamp_ = commit_timestamp;
  return UniqueConstraints::CreationStatus::SUCCESS;
}

UniqueConstraints::DeletionStatus Storage::DropUniqueConstraint(
    LabelId label, const std::set<PropertyId> &properties, const std::optional<uint64_t> desired_commit_timestamp) {
  std::unique_lock<utils::RWLock> storage_guard(main_lock_);
  auto ret = constraints_.unique_constraints.DropConstraint(label, properties);
  if (ret != UniqueConstraints::DeletionStatus::SUCCESS) {
    return ret;
  }
  const auto commit_timestamp = CommitTimestamp(desired_commit_timestamp);
  AppendToWal(durability::StorageGlobalOperation::UNIQUE_CONSTRAINT_DROP, label, properties, commit_timestamp);
  commit_log_->MarkFinished(commit_timestamp);
  last_commit_timestamp_ = commit_timestamp;
  return UniqueConstraints::DeletionStatus::SUCCESS;
}

ConstraintsInfo Storage::ListAllConstraints() const {
  std::shared_lock<utils::RWLock> storage_guard_(main_lock_);
  return {ListExistenceConstraints(constraints_), constraints_.unique_constraints.ListConstraints()};
}

StorageInfo Storage::GetInfo() const {
  auto vertex_count = vertices_.size();
  auto edge_count = edge_count_.load(std::memory_order_acquire);
  double average_degree = 0.0;
  if (vertex_count) {
    average_degree = 2.0 * static_cast<double>(edge_count) / vertex_count;
  }
  return {vertex_count, edge_count, average_degree, utils::GetMemoryUsage(),
          utils::GetDirDiskUsage(config_.durability.storage_directory)};
}

VerticesIterable Storage::Accessor::Vertices(LabelId label, View view) {
  return VerticesIterable(storage_->indices_.label_index.Vertices(label, view, &transaction_));
}

VerticesIterable Storage::Accessor::Vertices(LabelId label, PropertyId property, View view) {
  return VerticesIterable(storage_->indices_.label_property_index.Vertices(label, property, std::nullopt, std::nullopt,
                                                                           view, &transaction_));
}

VerticesIterable Storage::Accessor::Vertices(LabelId label, PropertyId property, const PropertyValue &value,
                                             View view) {
  return VerticesIterable(storage_->indices_.label_property_index.Vertices(
      label, property, utils::MakeBoundInclusive(value), utils::MakeBoundInclusive(value), view, &transaction_));
}

VerticesIterable Storage::Accessor::Vertices(LabelId label, PropertyId property,
                                             const std::optional<utils::Bound<PropertyValue>> &lower_bound,
                                             const std::optional<utils::Bound<PropertyValue>> &upper_bound, View view) {
  return VerticesIterable(
      storage_->indices_.label_property_index.Vertices(label, property, lower_bound, upper_bound, view, &transaction_));
}

Transaction Storage::CreateTransaction(IsolationLevel isolation_level) {
  // We acquire the transaction engine lock here because we access (and
  // modify) the transaction engine variables (`transaction_id` and
  // `timestamp`) below.
  uint64_t transaction_id;
  uint64_t start_timestamp;
  {
    std::lock_guard<utils::SpinLock> guard(engine_lock_);
    transaction_id = transaction_id_++;
    // Replica should have only read queries and the write queries
    // can come from main instance with any past timestamp.
    // To preserve snapshot isolation we set the start timestamp
    // of any query on replica to the last commited transaction
    // which is timestamp_ as only commit of transaction with writes
    // can change the value of it.
    if (replication_role_ == ReplicationRole::REPLICA) {
      start_timestamp = timestamp_;
    } else {
      start_timestamp = timestamp_++;
    }
  }
  return {transaction_id, start_timestamp, isolation_level};
}

template <bool force>
void Storage::CollectGarbage() {
  if constexpr (force) {
    // We take the unique lock on the main storage lock so we can forcefully clean
    // everything we can
    if (!main_lock_.try_lock()) {
      CollectGarbage<false>();
      return;
    }
  } else {
    // Because the garbage collector iterates through the indices and constraints
    // to clean them up, it must take the main lock for reading to make sure that
    // the indices and constraints aren't concurrently being modified.
    main_lock_.lock_shared();
  }

  utils::OnScopeExit lock_releaser{[&] {
    if constexpr (force) {
      main_lock_.unlock();
    } else {
      main_lock_.unlock_shared();
    }
  }};

  // Garbage collection must be performed in two phases. In the first phase,
  // deltas that won't be applied by any transaction anymore are unlinked from
  // the version chains. They cannot be deleted immediately, because there
  // might be a transaction that still needs them to terminate the version
  // chain traversal. They are instead marked for deletion and will be deleted
  // in the second GC phase in this GC iteration or some of the following
  // ones.
  std::unique_lock<std::mutex> gc_guard(gc_lock_, std::try_to_lock);
  if (!gc_guard.owns_lock()) {
    return;
  }

  uint64_t oldest_active_start_timestamp = commit_log_->OldestActive();
  // We don't move undo buffers of unlinked transactions to garbage_undo_buffers
  // list immediately, because we would have to repeatedly take
  // garbage_undo_buffers lock.
  std::list<std::pair<uint64_t, std::list<Delta>>> unlinked_undo_buffers;

  // We will only free vertices deleted up until now in this GC cycle, and we
  // will do it after cleaning-up the indices. That way we are sure that all
  // vertices that appear in an index also exist in main storage.
  std::list<Gid> current_deleted_edges;
  std::list<Gid> current_deleted_vertices;
  deleted_vertices_->swap(current_deleted_vertices);
  deleted_edges_->swap(current_deleted_edges);


  // Flag that will be used to determine whether the Index GC should be run. It
  // should be run when there were any items that were cleaned up (there were
  // updates between this run of the GC and the previous run of the GC). This
  // eliminates high CPU usage when the GC doesn't have to clean up anything.
  bool run_index_cleanup = !committed_transactions_->empty() || !garbage_undo_buffers_->empty();

  //hjm add begin;
  std::list<std::pair<Gid, LabelId>> saved_deltas;
  std::list<std::pair<Gid, Delta>> saved_deltas2;

  std::ofstream ofs_edge;
  std::ofstream ofs_vertex;
  ofs_edge.open("/home/hjm/history_info/history_edge.txt",std::ios::out|std::ios::app);
  ofs_vertex.open("/home/hjm/history_info/history_vertex.txt",std::ios::out|std::ios::app);
  while (true) {
    // We don't want to hold the lock on commited transactions for too long,
    // because that prevents other transactions from committing.
    Transaction *transaction;
    {
      auto committed_transactions_ptr = committed_transactions_.Lock();
      if (committed_transactions_ptr->empty()) {
        break;
      }
      transaction = &committed_transactions_ptr->front();
    }
    auto commit_timestamp = transaction->commit_timestamp->load(std::memory_order_acquire);
    if (commit_timestamp >= oldest_active_start_timestamp) {
      break;
    }
    std::list<std::pair<uint64_t, std::list<Delta>>> saved_buffers;
    std::list<std::tuple<Gid,uint64_t,uint64_t>> saved_gids;

    for (Delta &a : transaction->deltas){
      auto start=a.transaction_st;
      auto commit=a.commit_timestamp;
      if(a.transaction_st!=a.commit_timestamp){
        saved_history_deltas_->SaveDelta(a.gid,a.to_gid,start,commit,a,name_id_mapper_);
        saved_gids.emplace_back(a.gid,a.transaction_st,a.commit_timestamp);
      }
    }

    std::map<std::string, std::string> gid_anchor_all_;
    // std::cout<<"commit after:"<<transaction->transaction_id<<" "<<transaction->gid_anchor_edge_.size()<<" "<<transaction->gid_anchor_all_.size()<<"\n";
    for(auto [key,maybe_properties]:transaction->gid_anchor_edge_){
      auto gid=key.first;
      auto ts=key.second;
      nlohmann::json data = nlohmann::json::object();
      nlohmann::json data2 = nlohmann::json::object();
      for (const auto &prop : maybe_properties) {
        auto property_name = name_id_mapper_.IdToName(prop.first.AsUint());//delta.property.key.AsUint();//
        auto property_value = SerializePropertyValue(prop.second);//query::serialization::
        data2[property_name] = property_value;
      }
      data["SP"]=data2;
      auto prefix=saved_history_deltas_->getPrefix(gid,ts,false);
      gid_anchor_all_[prefix]=data.dump();
    }

    for(auto [key,values]:transaction->gid_anchor_vertex_){
      auto gid=key.first;
      auto ts=key.second;
      nlohmann::json data = nlohmann::json::object();
      auto maybe_properties=values.first;
      auto maybe_labels=values.second;
      nlohmann::json data2 = nlohmann::json::object();
      for (const auto &prop : maybe_properties) {
        auto property_name = name_id_mapper_.IdToName(prop.first.AsUint());//delta.property.key.AsUint();//
        auto property_value = SerializePropertyValue(prop.second);//query::serialization::
        data2[property_name] = property_value;
      }
      data["SP"]=data2;

      auto add_labels=std::vector<std::pair<std::string,std::string>>();
      for (const auto &label : maybe_labels) {
        add_labels.emplace_back("AL",name_id_mapper_.IdToName(label.AsUint()));//name_id_mapper_.IdToName(label.AsUint())
      }
      data["L"] =add_labels;
      auto prefix=saved_history_deltas_->getPrefix(gid,ts,true);
      gid_anchor_all_[prefix]=data.dump();
    }
    
    //hjm begin prinf edge
    for(auto key:transaction->prinfEdge_){
      uint64_t ts=key.tt_ts_;
      uint64_t f_gid=key.f_gid_;
      uint64_t t_gid=key.t_gid_;
      // auto f_ts=key.f_ts_;
      // auto t_ts=key.t_ts_;
      std::map<PropertyId, PropertyValue> maybe_properties=key.props_;
      std::string props="";
      for (const auto &prop : maybe_properties) {
        auto property_name = name_id_mapper_.IdToName(prop.first.AsUint());//delta.property.key.AsUint();//
        auto property_value = SerializePropertyValue(prop.second);//query::serialization::
        if(props=="")props="r."+property_name+"="+property_value.dump();
        else props+=",r."+property_name+"="+property_value.dump();
      }
      auto label=name_id_mapper_.IdToName(key.edge_type_.AsUint());
      auto gid=std::to_string(key.gid_);
      auto print_fgid=std::to_string(f_gid);//+":"+std::to_string(f_ts);
      auto print_tgid=std::to_string(t_gid);//+":"+std::to_string(t_ts);
      auto print_ts=std::to_string(ts);
      auto write_string=gid+"####"+print_fgid+"####"+print_tgid+"####"+print_ts+"####"+label+"####"+props+"\n";
      ofs_edge<<write_string;
    }
   
    for(auto key:transaction->prinfVertex_){
      auto gid=key.gid_;
      uint64_t ts=key.tt_ts_;
      auto maybe_labels=key.labels_;
      std::string labels="";
      for (const auto &label : maybe_labels) {
        auto label_name=name_id_mapper_.IdToName(label.AsUint());
        if(labels=="") labels=label_name;
        else labels+=":"+label_name;
      }
      std::map<PropertyId, PropertyValue> maybe_properties=key.props_;
      std::string props="";
      for (const auto &prop : maybe_properties) {
        auto property_name = name_id_mapper_.IdToName(prop.first.AsUint());//delta.property.key.AsUint();//
        auto property_value = SerializePropertyValue(prop.second);//query::serialization::
        if(props=="")props="r."+property_name+"="+property_value.dump();
        else props+=",r."+property_name+"="+property_value.dump();
      }
      auto print_key1=std::to_string(gid)+":"+std::to_string(ts);
      auto write_string=std::to_string(gid)+"####"+std::to_string(ts)+"####"+labels+"####"+props+"\n";
      ofs_vertex<<write_string;
    }
    
    //hjm end
    // saved_history_deltas_->GetAll();
    saved_history_deltas_->SaveDeltaAll();
    saved_history_deltas_->SaveAnchorAll(gid_anchor_all_);

    // saved_history_deltas_->SaveTimeTableAll();
    std::list<Gid> current_deleted_edges1;
    std::list<Gid> current_deleted_vertices1;
    recover_deleted_vertices_->swap(current_deleted_vertices1);
    recover_deleted_edges_->swap(current_deleted_edges1);

    // for(auto [key,value]:vertex_time_table_){
    //   std::cout<<"storag::2689 "<<key.AsUint()<<" "<<value.first<<" "<<value.second<<"\n";
    // }


    //hjm end


    // When unlinking a delta which is the first delta in its version chain,
    // special care has to be taken to avoid the following race condition:
    //
    // [Vertex] --> [Delta A]
    //
    //    GC thread: Delta A is the first in its chain, it must be unlinked from
    //               vertex and marked for deletion
    //    TX thread: Update vertex and add Delta B with Delta A as next
    //
    // [Vertex] --> [Delta B] <--> [Delta A]
    //
    //    GC thread: Unlink delta from Vertex
    //
    // [Vertex] --> (nullptr)
    //
    // When processing a delta that is the first one in its chain, we
    // obtain the corresponding vertex or edge lock, and then verify that this
    // delta still is the first in its chain.
    // When processing a delta that is in the middle of the chain we only
    // process the final delta of the given transaction in that chain. We
    // determine the owner of the chain (either a vertex or an edge), obtain the
    // corresponding lock, and then verify that this delta is still in the same
    // position as it was before taking the lock.
    //
    // Even though the delta chain is lock-free (both `next` and `prev`) the
    // chain should not be modified without taking the lock from the object that
    // owns the chain (either a vertex or an edge). Modifying the chain without
    // taking the lock will cause subtle race conditions that will leave the
    // chain in a broken state.
    // The chain can be only read without taking any locks.


    //first stage cut off chain 
    for (Delta &delta : transaction->deltas) {
      while (true) {
        auto prev = delta.prev.Get();
        switch (prev.type) {
          case PreviousPtr::Type::VERTEX: {
            Vertex *vertex = prev.vertex;
            std::lock_guard<utils::SpinLock> vertex_guard(vertex->lock);
            if (vertex->delta != &delta) {
              // Something changed, we're not the first delta in the chain
              // anymore.
              continue;
            }
            vertex->delta = nullptr;
            if (vertex->deleted) {
              current_deleted_vertices.push_back(vertex->gid);
              auto gids=vertex->gid;

            }
            break;
          }
          case PreviousPtr::Type::EDGE: {
            Edge *edge = prev.edge;
            std::lock_guard<utils::SpinLock> edge_guard(edge->lock);
            if (edge->delta != &delta) {
              // Something changed, we're not the first delta in the chain
              // anymore.
              continue;
            }
            edge->delta = nullptr; 
            if (edge->deleted) {
              current_deleted_edges.push_back(edge->gid);
            }
            break;
          }
          case PreviousPtr::Type::DELTA: {
            if (prev.delta->timestamp->load(std::memory_order_acquire) == commit_timestamp) {
              // The delta that is newer than this one is also a delta from this
              // transaction. We skip the current delta and will remove it as a
              // part of the suffix later.
              break;
            }
            std::unique_lock<utils::SpinLock> guard;
            {
              // We need to find the parent object in order to be able to use
              // its lock.
              auto parent = prev;
              while (parent.type == PreviousPtr::Type::DELTA) {
                parent = parent.delta->prev.Get();
              }
              switch (parent.type) {
                case PreviousPtr::Type::VERTEX:{
                  guard = std::unique_lock<utils::SpinLock>(parent.vertex->lock);
                  break;
                }
                case PreviousPtr::Type::EDGE:{
                  guard = std::unique_lock<utils::SpinLock>(parent.edge->lock);
                  break;
                }
                case PreviousPtr::Type::DELTA:
                case PreviousPtr::Type::NULLPTR:
                  LOG_FATAL("Invalid database state!");
              }
            }
            if (delta.prev.Get() != prev) {
              // Something changed, we could now be the first delta in the
              // chain.
              continue;
            }
            Delta *prev_delta = prev.delta;
            prev_delta->next.store(nullptr, std::memory_order_release);
            break;
          }
          case PreviousPtr::Type::NULLPTR: {
            LOG_FATAL("Invalid pointer!");
          }
        }
        break;
      }
    }

    committed_transactions_.WithLock([&](auto &committed_transactions) {
      unlinked_undo_buffers.emplace_back(0, std::move(transaction->deltas));
      committed_transactions.pop_front();
    });
  }
  
  // saved_history_deltas_->GetAll();
  //hjm begin
  ofs_edge.close();
  ofs_vertex.close();
  //hjm end

  // After unlinking deltas from vertices, we refresh the indices. That way
  // we're sure that none of the vertices from `current_deleted_vertices`
  // appears in an index, and we can safely remove the from the main storage
  // after the last currently active transaction is finished.
  if (run_index_cleanup) {
    // This operation is very expensive as it traverses through all of the items
    // in every index every time.
    RemoveObsoleteEntries(&indices_, oldest_active_start_timestamp);
    constraints_.unique_constraints.RemoveObsoleteEntries(oldest_active_start_timestamp);
  }

  {
    std::unique_lock<utils::SpinLock> guard(engine_lock_);
    uint64_t mark_timestamp = timestamp_;
    // Take garbage_undo_buffers lock while holding the engine lock to make
    // sure that entries are sorted by mark timestamp in the list.
    garbage_undo_buffers_.WithLock([&](auto &garbage_undo_buffers) {
      // Release engine lock because we don't have to hold it anymore and
      // this could take a long time.
      guard.unlock();
      // TODO(mtomic): holding garbage_undo_buffers_ lock here prevents
      // transactions from aborting until we're done marking, maybe we should
      // add them one-by-one or something
      for (auto &[timestamp, undo_buffer] : unlinked_undo_buffers) {
        timestamp = mark_timestamp;
      }
      garbage_undo_buffers.splice(garbage_undo_buffers.end(), unlinked_undo_buffers);
    });
    for (auto vertex : current_deleted_vertices) {
      garbage_vertices_.emplace_back(mark_timestamp, vertex);
    }
  }

  garbage_undo_buffers_.WithLock([&](auto &undo_buffers) {
    // if force is set to true we can simply delete all the leftover undos because
    // no transaction is active
    if constexpr (force) {
        undo_buffers.clear();
    } else {
      while (!undo_buffers.empty() && undo_buffers.front().first <= oldest_active_start_timestamp) {
         undo_buffers.pop_front();
      }
    }
  });
  {
    auto vertex_acc = vertices_.access();
    if constexpr (force) {
      // if force is set to true, then we have unique_lock and no transactions are active
      // so we can clean all of the deleted vertices
      while (!garbage_vertices_.empty()) {
        MG_ASSERT(vertex_acc.remove(garbage_vertices_.front().second), "Invalid database state!");
        // hjm begin 
        auto gid=garbage_vertices_.front().second.AsUint();
        auto it = std::find(hjm_deleted_vertices_.begin(), hjm_deleted_vertices_.end(), gid);
        if (it != hjm_deleted_vertices_.end()) {
          std::swap(*it, hjm_deleted_vertices_.back());
          hjm_deleted_vertices_.pop_back();
        }
        // hjm end
        garbage_vertices_.pop_front();
      }
    } else {
      while (!garbage_vertices_.empty() && garbage_vertices_.front().first < oldest_active_start_timestamp) {
        MG_ASSERT(vertex_acc.remove(garbage_vertices_.front().second), "Invalid database state!");
        // hjm begin 
        auto gid=garbage_vertices_.front().second.AsUint();
        auto it = std::find(hjm_deleted_vertices_.begin(), hjm_deleted_vertices_.end(), gid);
        if (it != hjm_deleted_vertices_.end()) {
          std::swap(*it, hjm_deleted_vertices_.back());
          hjm_deleted_vertices_.pop_back();
        }
        //hjm end
        garbage_vertices_.pop_front();
      }
    }
  }
  {
    auto edge_acc = edges_.access();
    for (auto edge : current_deleted_edges) {
      MG_ASSERT(edge_acc.remove(edge), "Invalid database state!");
      // std::cout<<"remove edge here"<<edge.AsUint()<<std::endl; 
    }
  }
}

// tell the linker he can find the CollectGarbage definitions here
template void Storage::CollectGarbage<true>();
template void Storage::CollectGarbage<false>();

bool Storage::InitializeWalFile() {
  if (config_.durability.snapshot_wal_mode != Config::Durability::SnapshotWalMode::PERIODIC_SNAPSHOT_WITH_WAL)
    return false;
  if (!wal_file_) {
    wal_file_.emplace(wal_directory_, uuid_, epoch_id_, config_.items, &name_id_mapper_, wal_seq_num_++,
                      &file_retainer_);
  }
  return true;
}

void Storage::FinalizeWalFile() {
  ++wal_unsynced_transactions_;
  if (wal_unsynced_transactions_ >= config_.durability.wal_file_flush_every_n_tx) {
    wal_file_->Sync();
    wal_unsynced_transactions_ = 0;
  }
  if (wal_file_->GetSize() / 1024 >= config_.durability.wal_file_size_kibibytes) {
    wal_file_->FinalizeWal();
    wal_file_ = std::nullopt;
    wal_unsynced_transactions_ = 0;
  } else {
    // Try writing the internal buffer if possible, if not
    // the data should be written as soon as it's possible
    // (triggered by the new transaction commit, or some
    // reading thread EnabledFlushing)
    wal_file_->TryFlushing();
  }
}

void Storage::AppendToWal(const Transaction &transaction, uint64_t final_commit_timestamp) {
  if (!InitializeWalFile()) return;
  // Traverse deltas and append them to the WAL file.
  // A single transaction will always be contained in a single WAL file.
  auto current_commit_timestamp = transaction.commit_timestamp->load(std::memory_order_acquire);

  if (replication_role_.load() == ReplicationRole::MAIN) {
    replication_clients_.WithLock([&](auto &clients) {
      for (auto &client : clients) {
        client->StartTransactionReplication(wal_file_->SequenceNumber());
      }
    });
  }

  // Helper lambda that traverses the delta chain on order to find the first
  // delta that should be processed and then appends all discovered deltas.
  auto find_and_apply_deltas = [&](const auto *delta, const auto &parent, auto filter) {
    while (true) {
      auto older = delta->next.load(std::memory_order_acquire);
      if (older == nullptr || older->timestamp->load(std::memory_order_acquire) != current_commit_timestamp) break;
      delta = older;
    }
    while (true) {
      if (filter(delta->action)) {
        wal_file_->AppendDelta(*delta, parent, final_commit_timestamp);
        replication_clients_.WithLock([&](auto &clients) {
          for (auto &client : clients) {
            client->IfStreamingTransaction(
                [&](auto &stream) { stream.AppendDelta(*delta, parent, final_commit_timestamp); });
          }
        });
      }
      auto prev = delta->prev.Get();
      MG_ASSERT(prev.type != PreviousPtr::Type::NULLPTR, "Invalid pointer!");
      if (prev.type != PreviousPtr::Type::DELTA) break;
      delta = prev.delta;
    }
  };

  // The deltas are ordered correctly in the `transaction.deltas` buffer, but we
  // don't traverse them in that order. That is because for each delta we need
  // information about the vertex or edge they belong to and that information
  // isn't stored in the deltas themselves. In order to find out information
  // about the corresponding vertex or edge it is necessary to traverse the
  // delta chain for each delta until a vertex or edge is encountered. This
  // operation is very expensive as the chain grows.
  // Instead, we traverse the edges until we find a vertex or edge and traverse
  // their delta chains. This approach has a drawback because we lose the
  // correct order of the operations. Because of that, we need to traverse the
  // deltas several times and we have to manually ensure that the stored deltas
  // will be ordered correctly.

  // 1. Process all Vertex deltas and store all operations that create vertices
  // and modify vertex data.
  for (const auto &delta : transaction.deltas) {
    auto prev = delta.prev.Get();
    MG_ASSERT(prev.type != PreviousPtr::Type::NULLPTR, "Invalid pointer!");
    if (prev.type != PreviousPtr::Type::VERTEX) continue;
    find_and_apply_deltas(&delta, *prev.vertex, [](auto action) {
      switch (action) {
        case Delta::Action::DELETE_OBJECT:
        case Delta::Action::SET_PROPERTY:
        case Delta::Action::ADD_LABEL:
        case Delta::Action::REMOVE_LABEL:
          return true;

        case Delta::Action::RECREATE_OBJECT:
        case Delta::Action::ADD_IN_EDGE:
        case Delta::Action::ADD_OUT_EDGE:
        case Delta::Action::REMOVE_IN_EDGE:
        case Delta::Action::REMOVE_OUT_EDGE:
          return false;
      }
    });
  }
  // 2. Process all Vertex deltas and store all operations that create edges.
  for (const auto &delta : transaction.deltas) {
    auto prev = delta.prev.Get();
    MG_ASSERT(prev.type != PreviousPtr::Type::NULLPTR, "Invalid pointer!");
    if (prev.type != PreviousPtr::Type::VERTEX) continue;
    find_and_apply_deltas(&delta, *prev.vertex, [](auto action) {
      switch (action) {
        case Delta::Action::REMOVE_OUT_EDGE:
          return true;

        case Delta::Action::DELETE_OBJECT:
        case Delta::Action::RECREATE_OBJECT:
        case Delta::Action::SET_PROPERTY:
        case Delta::Action::ADD_LABEL:
        case Delta::Action::REMOVE_LABEL:
        case Delta::Action::ADD_IN_EDGE:
        case Delta::Action::ADD_OUT_EDGE:
        case Delta::Action::REMOVE_IN_EDGE:
          return false;
      }
    });
  }
  // 3. Process all Edge deltas and store all operations that modify edge data.
  for (const auto &delta : transaction.deltas) {
    auto prev = delta.prev.Get();
    MG_ASSERT(prev.type != PreviousPtr::Type::NULLPTR, "Invalid pointer!");
    if (prev.type != PreviousPtr::Type::EDGE) continue;
    find_and_apply_deltas(&delta, *prev.edge, [](auto action) {
      switch (action) {
        case Delta::Action::SET_PROPERTY:
          return true;

        case Delta::Action::DELETE_OBJECT:
        case Delta::Action::RECREATE_OBJECT:
        case Delta::Action::ADD_LABEL:
        case Delta::Action::REMOVE_LABEL:
        case Delta::Action::ADD_IN_EDGE:
        case Delta::Action::ADD_OUT_EDGE:
        case Delta::Action::REMOVE_IN_EDGE:
        case Delta::Action::REMOVE_OUT_EDGE:
          return false;
      }
    });
  }
  // 4. Process all Vertex deltas and store all operations that delete edges.
  for (const auto &delta : transaction.deltas) {
    auto prev = delta.prev.Get();
    MG_ASSERT(prev.type != PreviousPtr::Type::NULLPTR, "Invalid pointer!");
    if (prev.type != PreviousPtr::Type::VERTEX) continue;
    find_and_apply_deltas(&delta, *prev.vertex, [](auto action) {
      switch (action) {
        case Delta::Action::ADD_OUT_EDGE:
          return true;

        case Delta::Action::DELETE_OBJECT:
        case Delta::Action::RECREATE_OBJECT:
        case Delta::Action::SET_PROPERTY:
        case Delta::Action::ADD_LABEL:
        case Delta::Action::REMOVE_LABEL:
        case Delta::Action::ADD_IN_EDGE:
        case Delta::Action::REMOVE_IN_EDGE:
        case Delta::Action::REMOVE_OUT_EDGE:
          return false;
      }
    });
  }
  // 5. Process all Vertex deltas and store all operations that delete vertices.
  for (const auto &delta : transaction.deltas) {
    auto prev = delta.prev.Get();
    MG_ASSERT(prev.type != PreviousPtr::Type::NULLPTR, "Invalid pointer!");
    if (prev.type != PreviousPtr::Type::VERTEX) continue;
    find_and_apply_deltas(&delta, *prev.vertex, [](auto action) {
      switch (action) {
        case Delta::Action::RECREATE_OBJECT:
          return true;

        case Delta::Action::DELETE_OBJECT:
        case Delta::Action::SET_PROPERTY:
        case Delta::Action::ADD_LABEL:
        case Delta::Action::REMOVE_LABEL:
        case Delta::Action::ADD_IN_EDGE:
        case Delta::Action::ADD_OUT_EDGE:
        case Delta::Action::REMOVE_IN_EDGE:
        case Delta::Action::REMOVE_OUT_EDGE:
          return false;
      }
    });
  }

  // Add a delta that indicates that the transaction is fully written to the WAL
  // file.
  wal_file_->AppendTransactionEnd(final_commit_timestamp);

  FinalizeWalFile();

  replication_clients_.WithLock([&](auto &clients) {
    for (auto &client : clients) {
      client->IfStreamingTransaction([&](auto &stream) { stream.AppendTransactionEnd(final_commit_timestamp); });
      client->FinalizeTransactionReplication();
    }
  });
}

void Storage::AppendToWal(durability::StorageGlobalOperation operation, LabelId label,
                          const std::set<PropertyId> &properties, uint64_t final_commit_timestamp) {
  if (!InitializeWalFile()) return;
  wal_file_->AppendOperation(operation, label, properties, final_commit_timestamp);
  {
    if (replication_role_.load() == ReplicationRole::MAIN) {
      replication_clients_.WithLock([&](auto &clients) {
        for (auto &client : clients) {
          client->StartTransactionReplication(wal_file_->SequenceNumber());
          client->IfStreamingTransaction(
              [&](auto &stream) { stream.AppendOperation(operation, label, properties, final_commit_timestamp); });
          client->FinalizeTransactionReplication();
        }
      });
    }
  }
  FinalizeWalFile();
}

utils::BasicResult<Storage::CreateSnapshotError> Storage::CreateSnapshot() {
  if (replication_role_.load() != ReplicationRole::MAIN) {
    return CreateSnapshotError::DisabledForReplica;
  }

  std::lock_guard snapshot_guard(snapshot_lock_);

  // Take master RW lock (for reading).
  std::shared_lock<utils::RWLock> storage_guard(main_lock_);

  // Create the transaction used to create the snapshot.
  auto transaction = CreateTransaction(IsolationLevel::SNAPSHOT_ISOLATION);

  // Create snapshot.
  durability::CreateSnapshot(&transaction, snapshot_directory_, wal_directory_,
                             config_.durability.snapshot_retention_count, &vertices_, &edges_, &name_id_mapper_,
                             &indices_, &constraints_, config_.items, uuid_, epoch_id_, epoch_history_,
                             &file_retainer_);

  // Finalize snapshot transaction.
  commit_log_->MarkFinished(transaction.start_timestamp);
  return {};
}

bool Storage::LockPath() {
  auto locker_accessor = global_locker_.Access();
  return locker_accessor.AddPath(config_.durability.storage_directory);
}

bool Storage::UnlockPath() {
  {
    auto locker_accessor = global_locker_.Access();
    if (!locker_accessor.RemovePath(config_.durability.storage_directory)) {
      return false;
    }
  }

  // We use locker accessor in seperate scope so we don't produce deadlock
  // after we call clean queue.
  file_retainer_.CleanQueue();
  return true;
}

void Storage::FreeMemory() {
  CollectGarbage<true>();

  // SkipList is already threadsafe
  vertices_.run_gc();
  edges_.run_gc();
  indices_.label_index.RunGC();
  indices_.label_property_index.RunGC();
}

uint64_t Storage::CommitTimestamp(const std::optional<uint64_t> desired_commit_timestamp) {
  if (!desired_commit_timestamp) {
    return timestamp_++;
  } else {
    timestamp_ = std::max(timestamp_, *desired_commit_timestamp + 1);
    return *desired_commit_timestamp;
  }
}

bool Storage::SetReplicaRole(io::network::Endpoint endpoint, const replication::ReplicationServerConfig &config) {
  // We don't want to restart the server if we're already a REPLICA
  if (replication_role_ == ReplicationRole::REPLICA) {
    return false;
  }

  replication_server_ = std::make_unique<ReplicationServer>(this, std::move(endpoint), config);

  replication_role_.store(ReplicationRole::REPLICA);
  return true;
}

bool Storage::SetMainReplicationRole() {
  // We don't want to generate new epoch_id and do the
  // cleanup if we're already a MAIN
  if (replication_role_ == ReplicationRole::MAIN) {
    return false;
  }

  // Main instance does not need replication server
  // This should be always called first so we finalize everything
  replication_server_.reset(nullptr);

  {
    std::unique_lock engine_guard{engine_lock_};
    if (wal_file_) {
      wal_file_->FinalizeWal();
      wal_file_.reset();
    }

    // Generate new epoch id and save the last one to the history.
    if (epoch_history_.size() == kEpochHistoryRetention) {
      epoch_history_.pop_front();
    }
    epoch_history_.emplace_back(std::move(epoch_id_), last_commit_timestamp_);
    epoch_id_ = utils::GenerateUUID();
  }

  replication_role_.store(ReplicationRole::MAIN);
  return true;
}

utils::BasicResult<Storage::RegisterReplicaError> Storage::RegisterReplica(
    std::string name, io::network::Endpoint endpoint, const replication::ReplicationMode replication_mode,
    const replication::ReplicationClientConfig &config) {
  MG_ASSERT(replication_role_.load() == ReplicationRole::MAIN, "Only main instance can register a replica!");

  const bool name_exists = replication_clients_.WithLock([&](auto &clients) {
    return std::any_of(clients.begin(), clients.end(), [&](auto &client) { return client->Name() == name; });
  });

  if (name_exists) {
    return RegisterReplicaError::NAME_EXISTS;
  }

  MG_ASSERT(replication_mode == replication::ReplicationMode::SYNC || !config.timeout,
            "Only SYNC mode can have a timeout set");

  auto client = std::make_unique<ReplicationClient>(std::move(name), this, endpoint, replication_mode, config);
  if (client->State() == replication::ReplicaState::INVALID) {
    return RegisterReplicaError::CONNECTION_FAILED;
  }

  return replication_clients_.WithLock([&](auto &clients) -> utils::BasicResult<Storage::RegisterReplicaError> {
    // Another thread could have added a client with same name while
    // we were connecting to this client.
    if (std::any_of(clients.begin(), clients.end(),
                    [&](auto &other_client) { return client->Name() == other_client->Name(); })) {
      return RegisterReplicaError::NAME_EXISTS;
    }

    clients.push_back(std::move(client));
    return {};
  });
}

bool Storage::UnregisterReplica(const std::string_view name) {
  MG_ASSERT(replication_role_.load() == ReplicationRole::MAIN, "Only main instance can unregister a replica!");
  return replication_clients_.WithLock([&](auto &clients) {
    return std::erase_if(clients, [&](const auto &client) { return client->Name() == name; });
  });
}

std::optional<replication::ReplicaState> Storage::GetReplicaState(const std::string_view name) {
  return replication_clients_.WithLock([&](auto &clients) -> std::optional<replication::ReplicaState> {
    const auto client_it =
        std::find_if(clients.cbegin(), clients.cend(), [name](auto &client) { return client->Name() == name; });
    if (client_it == clients.cend()) {
      return std::nullopt;
    }
    return (*client_it)->State();
  });
}

ReplicationRole Storage::GetReplicationRole() const { return replication_role_; }

std::vector<Storage::ReplicaInfo> Storage::ReplicasInfo() {
  return replication_clients_.WithLock([](auto &clients) {
    std::vector<Storage::ReplicaInfo> replica_info;
    replica_info.reserve(clients.size());
    std::transform(clients.begin(), clients.end(), std::back_inserter(replica_info),
                   [](const auto &client) -> ReplicaInfo {
                     return {client->Name(), client->Mode(), client->Timeout(), client->Endpoint(), client->State()};
                   });
    return replica_info;
  });
}

void Storage::SetIsolationLevel(IsolationLevel isolation_level) {
  std::unique_lock main_guard{main_lock_};
  isolation_level_ = isolation_level;
}

}  // namespace storage
