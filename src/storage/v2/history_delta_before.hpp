// Copyright 2021 Memgraph Ltd.
//
// Licensed as a Memgraph Enterprise file under the Memgraph Enterprise
// License (the "License"); by using this file, you agree to be bound by the terms of the License, and you may not use
// this file except in compliance with the License. You may obtain a copy of the License at https://memgraph.com/legal.
//
//

#pragma once

#include <mutex>
#include <optional>
#include <vector>

#include "kvstore/kvstore.hpp"
#include "utils/settings.hpp"
#include "storage/v2/name_id_mapper.hpp"
#include "storage/v2/delta.hpp"
#include <json/json.hpp>

namespace history_delta {

//hjm begin 结构体信息
struct historyContext{
  std::map<uint64_t,std::vector<nlohmann::json>> fiter_history_datas_;//kv store中筛选的历史数据
  std::map<uint64_t,nlohmann::json> fiter_history_delete;//kv store中筛选的被删除的节点信息
  std::map<std::pair<uint64_t,uint64_t>,storage::Vertex*> all_vertex_;//历史数据+现有数据的集合map gid,transaction_ts vertex
  uint64_t c_ts;//约束事务开始时间
  uint64_t c_te;//约束事务结束时间
  std::string types;//约束的类型
};

struct historyContextOnce{
 std::vector<storage::LabelId> labels;
 std::vector<std::pair<uint64_t,uint64_t>> labels_tt;
 std::map<storage::PropertyId, std::tuple<storage::PropertyValue,uint64_t,uint64_t>> props_tt;
 std::vector<storage::LabelId> remove_labels;
};

class History_delta final {
 public:
   explicit History_delta(const std::string &storage_directory);

  //  History_delta();

  /**
   * Gets a history delta from the storage.
   *
   * @param gid_name
   *
   * @return a delta when the delta exists, nullopt otherwise
   * @throw Exception if unable to load user data.
   */
  void GetDelta(const std::string &gid_name) const;


/**
   * Gets all history delta from the storage.
   *
   *
   * @return a delta when the delta exists, nullopt otherwise
   * @throw Exception if unable to load user data.
   */
  void GetAll() const;
  std::map<uint64_t,std::vector<nlohmann::json>> GetEdgeDelta(uint64_t c_ts,uint64_t c_te,std::string type,uint64_t gid);
   std::pair<std::map<uint64_t,nlohmann::json>,std::map<uint64_t,std::vector<nlohmann::json>>> GetAllVertexDeltas(uint64_t c_ts,uint64_t c_te,std::string type);
  std::map<uint64_t,std::vector<nlohmann::json>> GetDeleteEdgeDeltas(uint64_t c_ts,uint64_t c_te,std::string type,uint64_t v_gid);
  
  
  std::pair<std::map<int,nlohmann::json>,std::map<int,std::vector<nlohmann::json>>> GetAllDeltas(uint64_t c_ts,uint64_t c_te,std::string type,std::string filter_type);
  
  std::tuple<std::map<int,nlohmann::json>,std::map<int,std::vector<nlohmann::json>>,std::map<int,std::vector<nlohmann::json>>> GetAllDeltas2(uint64_t c_ts,uint64_t c_te,std::string type,std::string filter_type);
  
  std::pair<std::map<int,nlohmann::json>,std::map<int,std::vector<nlohmann::json>>> GetAllDeltas3(uint64_t c_ts,uint64_t c_te,std::string type,std::string prefix);

  // std::pair<std::map<uint64_t,nlohmann::json>,std::map<uint64_t,std::vector<nlohmann::json>>> GetAllVertexDeltas(uint64_t c_ts,uint64_t c_te,std::string type);
  // std::map<uint64_t,std::vector<nlohmann::json>> GetDeleteEdgeDeltas(uint64_t c_ts,uint64_t c_te,std::string type,uint64_t v_gid);
  
  std::pair<std::map<std::string,nlohmann::json>,std::map<int,std::vector<nlohmann::json>>> GetAllEdgeDeltas(uint64_t c_ts,uint64_t c_te,std::string type);

  /**
   * Saves gid_delta_ map to the kvstorage.
   *
   */
  void SaveDeltaAll();


  /**
   * Saves a delta object to the map.
   *
   * @param delta
   *
   * @throw AuthException if unable to save the user.
   */
  void SaveDelta(storage::Gid gid,const std::optional<storage::Gid> to_gid,const uint64_t start,const uint64_t commit,storage::Delta& delta,storage::NameIdMapper &name_id_mapper);
  
  /**
   * Returns whether there are deltas in the storage.
   *
   * @return `true` if the storage contains any users, `false` otherwise
   */
  bool HasDeltas() const;

 private:
  std::map<storage::Gid,std::pair<uint64_t,uint64_t>> vertex_time_table_;//存储顶点的id，历史开始时间，历史结束时间
  std::map<uint64_t,std::pair<uint64_t,uint64_t>> edge_time_table_;//存储边的id，历史开始时间，历史结束时间
  kvstore::KVStore storage_;
  std::map<std::string, nlohmann::json> gid_delta_;//save the same actions of one transaction
};
}  // namespace auth
