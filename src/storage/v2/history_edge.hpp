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

#include <limits>

#include "storage/v2/delta.hpp"
#include "storage/v2/id_types.hpp"
#include "storage/v2/property_store.hpp"
#include "utils/logging.hpp"
#include "utils/spin_lock.hpp"
#include "storage/v2/history_vertex.hpp"
#include <json/json.hpp>
namespace storage {

// struct HistoryVertex;

struct HistoryEdge {
  HistoryEdge(){
  
  }

  HistoryEdge(HistoryEdge* another){
    tt_te=another->tt_te;
    tt_ts=another->tt_ts;
    gid=another->gid;
    from_gid=another->from_gid;
    to_gid=another->to_gid;
    type=another->type;
    properties=another->properties;
  }

  HistoryEdge(Gid gid) : gid(gid) {
    tt_ts=0;
  }

  HistoryEdge(Gid gid, uint64_t transaction_st,Gid from_gid,Gid to_gid) : gid(gid),tt_ts(transaction_st),from_gid(from_gid),to_gid(to_gid){
    // tt_ts=0;
    tt_te=(uint64_t)std::numeric_limits<int64_t>::max();
  }
  
  HistoryEdge(Gid gid, uint64_t tt_ts,uint64_t tt_te,Gid from_gid,Gid to_gid,storage::EdgeTypeId type,Delta *delta) : gid(gid),tt_ts(tt_ts),tt_te(tt_te),from_gid(from_gid),to_gid(to_gid),type(type),delta(delta){
  }

  HistoryEdge(Gid edge_id,Gid from_gid,Gid to_gid,storage::EdgeTypeId edge_type,Delta *delta):gid(edge_id),from_gid(from_gid),to_gid(to_gid),type(edge_type),delta(delta){
    tt_ts=0;
    tt_te=(uint64_t)std::numeric_limits<int64_t>::max();
  }
  Gid gid;
  uint64_t tt_ts;
  uint64_t tt_te;
  Gid from_gid;
  Gid to_gid;
  storage::EdgeTypeId type;
  std::map<PropertyId, PropertyValue> properties;

  Delta *delta;
  // std::map<std::string, nlohmann::json> properties;
};

static_assert(alignof(HistoryEdge) >= 8, "The HistoryEdge should be aligned to at least 8!");

inline bool operator==(const HistoryEdge &first, const HistoryEdge &second) { return ((first.gid == second.gid) & (first.tt_ts == second.tt_ts) & (first.tt_te == second.tt_te)); }
// inline bool operator===(const HistoryEdge &first, const HistoryEdge &second) { return first.gid == second.gid & first.tt_ts == second.tt_ts & first.tt_te == second.tt_te; }
inline bool operator<(const HistoryEdge &first, const HistoryEdge &second) { return first.gid < second.gid; }
inline bool operator==(const HistoryEdge &first, const Gid &second) { return first.gid == second; }
inline bool operator<(const HistoryEdge &first, const Gid &second) { return first.gid < second; }

}  // namespace storage
