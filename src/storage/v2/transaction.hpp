// Copyright 2021 Memgraph Ltd.
//
// Use of this software is governed by the Business Source License
// included in the file licenses/BSL.txt; by using this file, you agree to be bound by the terms of the Business Source
// License, and you may not use this file except in compliance with the Business Source License.
//
// As of the Change Date specified in that file, in accordance with
// the Business Source License, use of this software will be governed
// by the Apache License, Version 2.0, included in the file
// licenses/APL.txt.

#pragma once

#include <atomic>
#include <limits>
#include <list>
#include <memory>
#include <set>
#include "utils/skip_list.hpp"

#include "storage/v2/delta.hpp"
#include "storage/v2/edge.hpp"
#include "storage/v2/isolation_level.hpp"
#include "storage/v2/property_value.hpp"
#include "storage/v2/vertex.hpp"
#include "storage/v2/view.hpp"

namespace storage {

const uint64_t kTimestampInitialId = 0;
const uint64_t kTransactionInitialId = 1ULL << 63U;
const std::vector<int> AnchorNumLists{10,100,1000};//{2,4,7};//{10,100,1000};
const std::vector<int> HotNumLists{1000,10000,100000};//{1k 10k 100k 2*2+2+1,32,62};//{1000,10000,100000}; (num+1)*anchor_num+1
const bool MultipleAnchorFlag=false;//false;//true
const bool AnchorFlag=true;//true;
const bool prinfFlag=false;//true

struct prinfEdge{
  prinfEdge(EdgeTypeId edge_type,uint64_t gid,uint64_t f_gid,uint64_t t_gid,uint64_t tt_ts,std::map<PropertyId, PropertyValue> props){
    edge_type_=edge_type;
    gid_=gid;
    f_gid_=f_gid;
    t_gid_=t_gid;
    tt_ts_=tt_ts;
    props_=props;
  }
  EdgeTypeId edge_type_;
  uint64_t gid_;
  uint64_t f_gid_;
  uint64_t t_gid_;
  uint64_t tt_ts_;
  std::map<PropertyId, PropertyValue> props_;
};

struct prinfVertex{
  prinfVertex(uint64_t gid,uint64_t tt_ts,std::map<PropertyId, PropertyValue> props,std::vector<LabelId> labels){
    gid_=gid;
    tt_ts_=tt_ts;
    props_=props;
    labels_=labels;
  }
  uint64_t gid_;
  uint64_t tt_ts_;
  std::vector<uint64_t> edges_id_;
  std::map<PropertyId, PropertyValue> props_;
  std::vector<LabelId> labels_;
};

struct Transaction {
  Transaction(uint64_t transaction_id, uint64_t start_timestamp, IsolationLevel isolation_level)
      : transaction_id(transaction_id),
        start_timestamp(start_timestamp),
        command_id(0),
        must_abort(false),
        isolation_level(isolation_level) {
        }

  Transaction(Transaction &&other) noexcept
      : transaction_id(other.transaction_id),
        start_timestamp(other.start_timestamp),
        commit_timestamp(std::move(other.commit_timestamp)),
        command_id(other.command_id),
        deltas(std::move(other.deltas)),
        must_abort(other.must_abort),
        isolation_level(other.isolation_level) {
          gid_anchor_edge_=other.gid_anchor_edge_;
          gid_anchor_vertex_=other.gid_anchor_vertex_;
          prinfEdge_=other.prinfEdge_;
          prinfVertex_=other.prinfVertex_;
          v_changed=other.v_changed;
          ve_changed=other.ve_changed;
        }

  Transaction(const Transaction &) = delete;
  Transaction &operator=(const Transaction &) = delete;
  Transaction &operator=(Transaction &&other) = delete;

  ~Transaction() {}

  /// @throw std::bad_alloc if failed to create the `commit_timestamp`
  void EnsureCommitTimestampExists() {
    if (commit_timestamp != nullptr) return;
    commit_timestamp = std::make_unique<std::atomic<uint64_t>>(transaction_id);
  }
  
  uint64_t transaction_id;
  uint64_t start_timestamp;
  // The `Transaction` object is stack allocated, but the `commit_timestamp`
  // must be heap allocated because `Delta`s have a pointer to it, and that
  // pointer must stay valid after the `Transaction` is moved into
  // `commited_transactions_` list for GC.
  std::unique_ptr<std::atomic<uint64_t>> commit_timestamp;
  uint64_t command_id;
  std::list<Delta> deltas;
  bool must_abort;
  IsolationLevel isolation_level;


  std::set<Gid> v_changed;
  std::set<Gid> ve_changed;
  std::map<std::pair<Gid,uint64_t>, std::pair<std::map<PropertyId, PropertyValue>,std::vector<LabelId>>> gid_anchor_vertex_;
  std::map<std::pair<Gid,uint64_t>, std::map<PropertyId, PropertyValue>> gid_anchor_edge_;
  std::vector<prinfEdge> prinfEdge_;
  std::vector<prinfVertex> prinfVertex_;

};

inline bool operator==(const Transaction &first, const Transaction &second) {
  return first.transaction_id == second.transaction_id;
}
inline bool operator<(const Transaction &first, const Transaction &second) {
  return first.transaction_id < second.transaction_id;
}
inline bool operator==(const Transaction &first, const uint64_t &second) { return first.transaction_id == second; }
inline bool operator<(const Transaction &first, const uint64_t &second) { return first.transaction_id < second; }

}  // namespace storage
