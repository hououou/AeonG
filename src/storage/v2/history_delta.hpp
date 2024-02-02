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
}  // namespace auth
