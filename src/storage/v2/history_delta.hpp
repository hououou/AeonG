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

  void GetDelta(const std::string &gid_name) const;

  std::pair<std::vector<nlohmann::json>,bool> GetVertexInfo(storage::Gid gid,uint64_t c_ts,uint64_t c_te,std::string type);
  std::pair<std::vector<nlohmann::json>,bool> GetEdgeInfo(uint64_t c_ts,uint64_t c_te,std::string type,uint64_t gid);
  std::vector<nlohmann::json> GetDeleteEdgeInfo(uint64_t c_ts,uint64_t c_te,std::string type,uint64_t gid);
  void GetTimeTableAll();
  void SaveDeltaAll();
  void SaveAnchorAll(std::map<std::string, std::string> &value);

  void SaveDelta(storage::Gid gid,const std::optional<storage::Gid> to_gid,const uint64_t start,const uint64_t commit,storage::Delta& delta,storage::NameIdMapper &name_id_mapper);
  void SaveVertexAnchor(storage::Gid gid,const uint64_t start,std::vector<storage::LabelId> &labels,std::map<storage::PropertyId, storage::PropertyValue> &maybe_properties,storage::NameIdMapper &name_id_mapper);
  void SaveEdgeAnchor(storage::Gid gid,const uint64_t start,std::map<storage::PropertyId, storage::PropertyValue> &maybe_properties,storage::NameIdMapper &name_id_mapper);
  void SaveVertexAnchor(storage::Gid gid,const uint64_t start,nlohmann::json data);
  void SaveEdgeAnchor(storage::Gid gid,const uint64_t start,nlohmann::json data);
  void SaveEdgeAnchorAll(uint64_t tid,std::map<std::string, std::string>& data);

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
