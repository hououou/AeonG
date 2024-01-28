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
#include "utils/visitor.hpp"
#include <list>

#include "kvstore/kvstore.hpp"
#include "utils/settings.hpp"
#include "storage/v2/name_id_mapper.hpp"
#include "storage/v2/delta.hpp"
#include <json/json.hpp>

namespace history_delta {


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

   explicit History_delta(const std::string &storage_directory,bool realTimeFlag);

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

  std::map<uint64_t,std::vector<nlohmann::json>> GetEdgeDelta(uint64_t c_ts,uint64_t c_te,std::string type,uint64_t gid);
   std::pair<std::map<uint64_t,nlohmann::json>,std::map<uint64_t,std::vector<nlohmann::json>>> GetAllVertexDeltas(uint64_t c_ts,uint64_t c_te,std::string type);
  std::map<uint64_t,std::vector<nlohmann::json>> GetDeleteEdgeDeltas(uint64_t c_ts,uint64_t c_te,std::string type,uint64_t v_gid);
  
  
  std::pair<std::map<int,nlohmann::json>,std::map<int,std::vector<nlohmann::json>>> GetAllDeltas(uint64_t c_ts,uint64_t c_te,std::string type,std::string filter_type);
  
  std::tuple<std::map<int,nlohmann::json>,std::map<int,std::vector<nlohmann::json>>,std::map<int,std::vector<nlohmann::json>>> GetAllDeltas2(uint64_t c_ts,uint64_t c_te,std::string type,std::string filter_type);
  
  std::pair<std::map<int,nlohmann::json>,std::map<int,std::vector<nlohmann::json>>> GetAllDeltas3(uint64_t c_ts,uint64_t c_te,std::string type,std::string prefix);

  // std::pair<std::map<uint64_t,nlohmann::json>,std::map<uint64_t,std::vector<nlohmann::json>>> GetAllVertexDeltas(uint64_t c_ts,uint64_t c_te,std::string type);
  // std::map<uint64_t,std::vector<nlohmann::json>> GetDeleteEdgeDeltas(uint64_t c_ts,uint64_t c_te,std::string type,uint64_t v_gid);
  
  std::pair<std::map<std::string,nlohmann::json>,std::map<int,std::vector<nlohmann::json>>> GetAllEdgeDeltas(uint64_t c_ts,uint64_t c_te,std::string type);
  std::pair<std::vector<nlohmann::json>,bool> GetVertexInfo(storage::Gid gid,uint64_t c_ts,uint64_t c_te,std::string type);
  std::pair<std::vector<nlohmann::json>,bool> GetEdgeInfo(uint64_t c_ts,uint64_t c_te,std::string type,uint64_t gid);
  
  std::vector<nlohmann::json> GetDeleteEdgeInfo(uint64_t c_ts,uint64_t c_te,std::string type,uint64_t gid);
  
  std::pair<bool,std::vector<int>> getDeadInfo(storage::Delta* vertex_deltas,uint64_t c_ts,uint64_t c_te,std::string types_,bool is_vertex);
  // std::pair<std::vector<nlohmann::json>,bool> getDeadInfo2(query::VertexAccessor current_vertex_,uint64_t c_ts,uint64_t c_te);
  std::pair<std::vector<nlohmann::json>,bool> GetEdgeInfo2(uint64_t c_ts,uint64_t c_te,std::string type,uint64_t gid);
  
  void GetTimeTableAll();
  /**
   * Saves gid_delta_ map to the kvstorage.
   *
   */
  void SaveDeltaAll();
  void SaveAnchorAll(std::map<std::string, std::string> &value);
  /**
   * Saves a delta object to the map.
   *
   * @param delta
   *
   * @throw AuthException if unable to save the user.
   */

  void SaveDelta(storage::Gid gid,const std::optional<storage::Gid> to_gid,const uint64_t start,const uint64_t commit,storage::Delta& delta,storage::NameIdMapper &name_id_mapper);
  void SaveVertexAnchor(storage::Gid gid,const uint64_t start,std::vector<storage::LabelId> &labels,std::map<storage::PropertyId, storage::PropertyValue> &maybe_properties,storage::NameIdMapper &name_id_mapper);
  void SaveEdgeAnchor(storage::Gid gid,const uint64_t start,std::map<storage::PropertyId, storage::PropertyValue> &maybe_properties,storage::NameIdMapper &name_id_mapper);
  void SaveVertexAnchor(storage::Gid gid,const uint64_t start,nlohmann::json data);
  void SaveEdgeAnchor(storage::Gid gid,const uint64_t start,nlohmann::json data);
  void SaveEdgeAnchorAll(uint64_t tid,std::map<std::string, std::string>& data);
  /**
   * Returns whether there are deltas in the storage.
   *
   * @return `true` if the storage contains any users, `false` otherwise
   */
  bool HasDeltas() const;

  std::string getPrefix(storage::Gid gid,const uint64_t start,bool vertex);

  bool RemoveOldHistory(const std::chrono::milliseconds &retention_period);

 private:
  bool realTimeFlagConstant=false;
  //hash index 用来存储object的min_ts max_te
  std::map<uint64_t,std::pair<uint64_t,uint64_t>> vertex_time_table_;//存储顶点的id，历史开始时间，历史结束时间
  std::map<uint64_t,std::pair<uint64_t,uint64_t>> edge_time_table_;//存储边的id，历史开始时间，历史结束时间
  //hash index 只存储当前事务
  std::map<uint64_t,std::pair<uint64_t,uint64_t>> vertex_time_tmp_;//存储顶点的id，历史开始时间，历史结束时间
  std::map<uint64_t,std::pair<uint64_t,uint64_t>> edge_time_tmp_;//存储边的id，历史开始时间，历史结束时间
  //gid,delta-num: <json>
  std::map<uint64_t,std::pair<int,nlohmann::json>> vertex_anchor_;
  std::list<std::map<std::string, std::string>> edge_anchor_;

  kvstore::KVStore storage_;
  // std::map<uint64_t,uint64_t> before_gid_commit_;
  std::map<std::tuple<std::string,uint64_t,uint64_t>, nlohmann::json> gid_delta_delta_;//prefix,gid,commit_te
  std::map<std::string, nlohmann::json> gid_delta_;//save the same actions of one transaction
};
}  // namespace auth
