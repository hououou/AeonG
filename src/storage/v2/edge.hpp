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

namespace storage {

struct Vertex;

struct Edge {
  Edge(Gid gid, Delta *delta) : gid(gid), deleted(false), delta(delta) {
    transaction_st=0;
    // tt_te=(uint64_t)std::numeric_limits<int64_t>::max();
    num=0;
    MG_ASSERT(delta == nullptr || delta->action == Delta::Action::DELETE_OBJECT,
              "Edge must be created with an initial DELETE_OBJECT delta!");
  }

  Edge(Gid gid, Delta *delta,uint64_t transaction_st,Gid from_gid,Gid to_gid) : gid(gid),deleted(false),transaction_st(transaction_st),from_gid(from_gid),to_gid(to_gid),delta(delta){
    transaction_st=0;
    num=0;
    // tt_te=(uint64_t)std::numeric_limits<int64_t>::max();
  }

  Gid gid;

  PropertyStore properties;

  mutable utils::SpinLock lock;
  bool deleted;
  // uint8_t PAD;
  // uint16_t PAD;

  //hjm begin add start-timestamp
  // uint64_t last_t;
  uint64_t transaction_st;
  // uint64_t tt_te;
  Gid from_gid;
  Gid to_gid;
  int num;
  //hjm end

  Delta *delta;
};

static_assert(alignof(Edge) >= 8, "The Edge should be aligned to at least 8!");

inline bool operator==(const Edge &first, const Edge &second) { return first.gid == second.gid; }
inline bool operator<(const Edge &first, const Edge &second) { return first.gid < second.gid; }
inline bool operator==(const Edge &first, const Gid &second) { return first.gid == second; }
inline bool operator<(const Edge &first, const Gid &second) { return first.gid < second; }

}  // namespace storage
