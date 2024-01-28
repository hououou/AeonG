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

namespace storage {

struct Vertex {
  Vertex(Gid gid, Delta *delta) : gid(gid), deleted(false), delta(delta) {
    // last_commit=0;
    transaction_st=0;
    // tt_te=(uint64_t)std::numeric_limits<int64_t>::max();

    ve_tt_ts=0;
    // ve_tt_te=(uint64_t)std::numeric_limits<int64_t>::max();

    num=0;
    MG_ASSERT(delta == nullptr || delta->action == Delta::Action::DELETE_OBJECT,
              "Vertex must be created with an initial DELETE_OBJECT delta!");
  }
  Vertex(Gid gid, Delta *delta,uint64_t transaction_st) : gid(gid),deleted(false),transaction_st(transaction_st),delta(delta){
    transaction_st=0;
    // last_commit=0;
    // tt_te=(uint64_t)std::numeric_limits<int64_t>::max(); //wzy 0512
    num=0;
    ve_tt_ts=0;
    // ve_tt_te=(uint64_t)std::numeric_limits<int64_t>::max(); //wzy 0512
  }
  Gid gid;

  std::vector<LabelId> labels;
  PropertyStore properties;

  std::vector<std::tuple<EdgeTypeId, Vertex *, EdgeRef>> in_edges;
  std::vector<std::tuple<EdgeTypeId, Vertex *, EdgeRef>> out_edges;

  mutable utils::SpinLock lock;
  bool deleted;
  // uint8_t PAD;
  // uint16_t PAD;

  //hjm begin add start-timestamp
  int num;//用来控制写入
  // int totalNum;
  //顶点label和properties的事务时间
  // uint64_t last_commit;
  uint64_t transaction_st;
  // uint64_t tt_te; //wzy 0512
  //顶点关联边的事务时间
  uint64_t ve_tt_ts;
  // uint64_t ve_tt_te;
  //表示是顶点的修改还是顶点边的修改的delta
  // bool vertex_changed;
  // bool ve_changed;
  //hjm end
  Delta *delta;
};

static_assert(alignof(Vertex) >= 8, "The Vertex should be aligned to at least 8!");

inline bool operator==(const Vertex &first, const Vertex &second) { return first.gid == second.gid; }
inline bool operator<(const Vertex &first, const Vertex &second) { return first.gid < second.gid; }
inline bool operator==(const Vertex &first, const Gid &second) { return first.gid == second; }
inline bool operator<(const Vertex &first, const Gid &second) { return first.gid < second; }

//hjm begin
// inline bool operator==(const Gid &first, const Gid &second) { return first == second; }
//hjm end

}  // namespace storage
