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

#include <chrono>
#include <cstdint>
#include <filesystem>
#include "storage/v2/isolation_level.hpp"
#include "storage/v2/transaction.hpp"

namespace storage {

/// Pass this class to the \ref Storage constructor to change the behavior of
/// the storage. This class also defines the default behavior.
struct Config {
  struct Gc {
    enum class Type { NONE, PERIODIC };

    Type type{Type::PERIODIC};
    std::chrono::milliseconds interval{std::chrono::milliseconds(1000)};
  } gc;

  struct Items {
    bool properties_on_edges{true};
    int AnchorNum {11};
    bool realTimeFlag{false};
    //for multiple anchor nums
    // std::vector<int> AnchorNumLists{10,100,1000};
    // std::vector<int> HotNumLists{1000,10000,100000};
    
  } items;

  struct Durability {
    enum class SnapshotWalMode { DISABLED, PERIODIC_SNAPSHOT, PERIODIC_SNAPSHOT_WITH_WAL };

    std::filesystem::path storage_directory{"storage"};

    bool recover_on_startup{false};

    SnapshotWalMode snapshot_wal_mode{SnapshotWalMode::DISABLED};

    std::chrono::milliseconds snapshot_interval{std::chrono::minutes(2)};
    uint64_t snapshot_retention_count{3};

    uint64_t wal_file_size_kibibytes{20 * 1024};
    uint64_t wal_file_flush_every_n_tx{100000};

    bool snapshot_on_exit{false};

  } durability;

  struct Transaction {
    IsolationLevel isolation_level{IsolationLevel::SNAPSHOT_ISOLATION};
    // const int NUM{11};
  } transaction;

  struct RocksDB_retention {
    bool retention_on_startup{false};//是否启动
    std::chrono::milliseconds retention_interval{std::chrono::minutes(1)};//异步清理的时间间隔
    std::chrono::milliseconds retention_period{std::chrono::minutes(1)};//清理多久以前的数据
    // const int NUM{11};
  } rocksdb_retention;

};
}  // namespace storage
