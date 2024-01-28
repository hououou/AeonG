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
#include <tuple>
#include <vector>

#include "storage/v2/delta.hpp"
#include "storage/v2/edge_ref.hpp"
#include "storage/v2/id_types.hpp"
#include "storage/v2/property_store.hpp"
#include "utils/spin_lock.hpp"
#include <json/json.hpp>
#include "storage/v2/history_edge.hpp"
namespace storage {

struct HistoryVertex {
  HistoryVertex()  {
   
  }
  HistoryVertex(HistoryVertex* another){
    tt_te=another->tt_te;
    tt_ts=another->tt_ts;
    gid=another->gid;
    labels=another->labels;
    properties=another->properties;
    in_edges=another->in_edges;
    out_edges=another->out_edges;
    in_history_edges=another->in_history_edges;
    out_history_edges=another->out_history_edges;
  }

  HistoryVertex(Gid gid) : gid(gid) {
    tt_ts=0;
    tt_te=std::numeric_limits<uint64_t>::max();
  }
  HistoryVertex(Gid gid,uint64_t tt_ts,uint64_t tt_te) : gid(gid),tt_ts(tt_ts),tt_te(tt_te){
    tt_ts=0;
    tt_te=std::numeric_limits<uint64_t>::max();
  }
  Gid gid;
  std::vector<LabelId> labels;
  // std::map<std::string, nlohmann::json> properties;
  std::map<PropertyId, PropertyValue> properties;

  std::vector<std::tuple<EdgeTypeId, Vertex *, EdgeRef>> in_edges;
  std::vector<std::tuple<EdgeTypeId, Vertex *, EdgeRef>> out_edges;


  // std::vector<std::tuple<EdgeTypeId, Vertex *, uint64_t>> in_edges;// edgetypeid vertex_id edge_id
  // std::vector<std::tuple<EdgeTypeId, Vertex *, uint64_t>> out_edges;// edgetypeid vertex_id edge_id
  
  std::list<storage::HistoryEdge> in_history_edges;
  std::list<storage::HistoryEdge> out_history_edges;
  // std::vector<std::tuple<EdgeTypeId, uint64_t, uint64_t>> current_in_edges;// edgetypeid vertex_id edge_id
  // std::vector<std::tuple<EdgeTypeId, uint64_t, uint64_t>> current_out_edges;

  uint64_t tt_ts;//transaction start time
  uint64_t tt_te;//transaction end time

  // bool HasLabel(LabelId label);
  //hjm end
};

// bool HasLabel(LabelId label){
//   auto it = std::find(labels.begin(), labels.end(), label);
//   if (it != labels.end()) return true;
//   return false;
// }

static_assert(alignof(HistoryVertex) >= 8, "The HistoryVertex should be aligned to at least 8!");

inline bool operator==(const HistoryVertex &first, const HistoryVertex &second) { return first.gid == second.gid; }
inline bool operator<(const HistoryVertex &first, const HistoryVertex &second) { return first.gid < second.gid; }
inline bool operator==(const HistoryVertex &first, const Gid &second) { return first.gid == second; }
inline bool operator<(const HistoryVertex &first, const Gid &second) { return first.gid < second; }


}  // namespace storage
