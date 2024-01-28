// Copyright 2021 Memgraph Ltd.
//
// Licensed as a Memgraph Enterprise file under the Memgraph Enterprise
// License (the "License"); by using this file, you agree to be bound by the terms of the License, and you may not use
// this file except in compliance with the License. You may obtain a copy of the License at https://memgraph.com/legal.
//
//

#include "storage/v2/history_delta.hpp"
#include "query/db_accessor.hpp"
#include <cstring>
#include <iostream>
#include <limits>
#include <utility>
#include <fstream>
#include <fmt/format.h>

#include "auth/exceptions.hpp"
#include "utils/flag_validation.hpp"
#include "utils/license.hpp"
#include "utils/logging.hpp"
#include "utils/message.hpp"
#include "utils/settings.hpp"
#include "utils/string.hpp"
#include <json/json.hpp>
#include "query/serialization/property_value.hpp"
#include "storage/v2/storage.hpp"



namespace history_delta {
namespace {
enum class ObjectType : uint8_t { MAP, TEMPORAL_DATA };
}  // namespace

nlohmann::json SerializePropertyValueVector(const std::vector<storage::PropertyValue> &values);

nlohmann::json SerializePropertyValueMap(const std::map<std::string, storage::PropertyValue> &parameters);

nlohmann::json SerializePropertyValue(const storage::PropertyValue &property_value) {
  using Type = storage::PropertyValue::Type;
  switch (property_value.type()) {
    case Type::Null:
      return {};
    case Type::Bool:
      return property_value.ValueBool();
    case Type::Int:
      return property_value.ValueInt();
    case Type::Double:
      return property_value.ValueDouble();
    case Type::String:
      return property_value.ValueString();
    case Type::List:
      return SerializePropertyValueVector(property_value.ValueList());
    case Type::Map:
      return SerializePropertyValueMap(property_value.ValueMap());
    case Type::TemporalData:
      const auto temporal_data = property_value.ValueTemporalData();
      auto data = nlohmann::json::object();
      data.emplace("type", static_cast<uint64_t>(ObjectType::TEMPORAL_DATA));
      data.emplace("value", nlohmann::json::object({{"type", static_cast<uint64_t>(temporal_data.type)},
                                                    {"microseconds", temporal_data.microseconds}}));
      return data;
  }
}

nlohmann::json SerializePropertyValueVector(const std::vector<storage::PropertyValue> &values) {
  nlohmann::json array = nlohmann::json::array();
  for (const auto &value : values) {
    array.push_back(SerializePropertyValue(value));
  }
  return array;
}

nlohmann::json SerializePropertyValueMap(const std::map<std::string, storage::PropertyValue> &parameters) {
  nlohmann::json data = nlohmann::json::object();
  data.emplace("type", static_cast<uint64_t>(ObjectType::MAP));
  data.emplace("value", nlohmann::json::object());

  for (const auto &[key, value] : parameters) {
    data["value"][key] = SerializePropertyValue(value);
  }

  return data;
};


//时间约束比较
 bool TemporalCheck(uint64_t object_ts,uint64_t object_te,uint64_t c_ts,uint64_t c_te,std::string type){
  if(type=="as of"){
    if(object_ts<=c_ts & object_te>c_te ){
      return true;
    }
  }
  if(type=="from to"){
      if(object_ts<c_te & object_te>c_ts ){
      return true;
    }
  }
  if(type=="between and"){
      if(object_ts<=c_te & object_te>c_ts ){
      return true;
    }
  }
  return false;
}

// 字符串分割
std::vector<std::string> splits(const std::string &str, const std::string &pattern){
    std::vector<std::string> res;
    if (str == "")
        return res;
    std::string strs = str + pattern;
    size_t pos = strs.find(pattern);
    while (pos != strs.npos)
    {
      std::string temp = strs.substr(0, pos);
      res.push_back(temp);
      //去掉已分割的字符串,在剩下的字符串中进行分割
      strs = strs.substr(pos + 1, strs.size());
      pos = strs.find(pattern);
    }
    return res;
}

void uint_convert_to_string(const int64_t time,std::string &res){
  auto size=sizeof(time);
  char *buffer = (char *)std::malloc(size);
  std::memcpy(buffer, &time, size);
  std::string start_str(buffer,size);
  res=start_str;
  std::free(buffer);
}

std::tuple<uint64_t,int,int> string_convert_to_uint(std::string res){
  auto size=sizeof(uint64_t);
  auto length=res.length();
  //获取gid
  size_t pos = res.find(":");
  auto get_size=length-2*size-3-pos;
  auto gid_str=res.substr(pos+1,get_size);//3:4 12 20-2*8
  auto gid=(uint64_t)std::stoi(gid_str);
  //处理时间
  auto redo_str1=res.substr(length-size);//12:
  auto redo_str2=res.substr(length-2*size-1,size);//3:12
  char redo[size];
  char redo2[size];
  for(int i=0;i<size;i++){
    redo[i]=redo_str1[i];
    redo2[i]=redo_str2[i];
  }
  auto ts = *(int*) redo2;// redo_str;
  auto te = *(int*) redo;
  return std::make_tuple(gid,ts,te);
}

/**
 * 合并两个json数据
 * 数据类型包含以下几种：
 * SET_PROPERTY:
 * RECREATE_OBJECT
 * ADD_LABEL:
 * ADD_OUT_EDGE:
 * REMOVE_OUT_EDGE:
 * 
 * */
void combineVertex(nlohmann::json before_data,nlohmann::json &current_data){
  //如果当前数据是RECREATE_OBJECT，则表示这个版本不需要和前面的数据进行合并
  // auto find_recreate=current_data.find("RECREATE_OBJECT");
  // if(find_recreate!=current_data.end()) return;
  
  for (auto it = before_data.begin(); it != before_data.end(); ++it) {
    auto it_key = it.key();
    auto it_value=it.value();
    auto it_iter=current_data.find(it_key);
    if(it_iter==current_data.end()){//如果当前数据没有这种类型，则直接添加
      current_data.emplace(it_key,it_value);
    }else{//否则，需要合并value的json
      if(it_key=="SP"){
        auto now_prop_value = current_data["SP"];
        auto before_prop_value=it_value;
        for(auto before_iter= before_prop_value.begin(); before_iter != before_prop_value.end(); ++before_iter){
          auto before_iter_key = before_iter.key();
          auto before_iter_value=before_iter.value();
          auto bb=now_prop_value.find(before_iter_key);
          if(bb==now_prop_value.end()){
            current_data["SP"].emplace(before_iter_key,before_iter_value);
          }
        }
      }
      else if(it_key=="L"){
        auto &current_info=current_data[it_key];
        for(auto before_label:before_data[it_key]){
          current_info.emplace_back(before_label);
        }  
      }  
      // else if(it_key!="TT_TS" &it_key!="TT_TE"){
      //   auto now_edges_value = current_data[it_key];//edges info
      //   auto before_edge_value=it_value;
      //   for (auto its = before_edge_value.begin(); its != before_edge_value.end(); ++its){
      //     auto its_key = its.key();
      //     auto its_value=its.value();
      //     auto its_iter=now_edges_value.find(its_key);
      //     if(its_iter==now_edges_value.end()){//如果当前数据没有这种类型，则直接添加
      //       now_edges_value.emplace(its_key,its_value);
      //     }else if(its_key=="SP"){
            
      //     }
      //   }
      // }
    }
  }
}

void combineEdge(nlohmann::json before_data,nlohmann::json &current_data){
  for (auto it = before_data.begin(); it != before_data.end(); ++it) {
     auto edge_id = it.key();
     if(edge_id=="TT_TS" || edge_id=="TT_TE" ||edge_id=="Type" ||edge_id=="Fid"||edge_id=="Tid") continue;
     auto edge_jsons=it.value();
     auto it_iter=current_data.find(edge_id);
    if(it_iter==current_data.end()){//如果当前数据没有这个节点的信息，则直接添加
      current_data.emplace(edge_id,edge_jsons);
    }else{
      // std::cout<<"combine edge:"<<before_data[edge_id].dump()<<" "<<current_data[edge_id].dump()<<"\n";
      combineVertex(before_data[edge_id],current_data[edge_id]);
    }
  }
}

//获取delta顶点或者边的属性
std::pair<bool,std::vector<int>> getDeadInfo(std::optional<query::VertexAccessor> current_vertex_,std::optional<storage::HistoryEdge*> current_edge_,uint64_t c_ts,uint64_t c_te,std::string types_,bool is_vertex){
  //dead info 属性 label和边 不需要考虑
  std::cout<<"get dead info\n";
  auto dead_deltas=std::vector<int>();//记住delta的下标
  auto vertex_deltas=current_vertex_?current_vertex_->getDeltas():(*current_edge_)->delta;
  auto tmp_ts=0;
  auto tmp_te=0;
  int index_=0;
  auto need_deleted_flag=true;
  bool delta_is_edge=false;
  while (vertex_deltas != nullptr) {
    delta_is_edge=false;
    switch (vertex_deltas->action) {
      case storage::Delta::Action::ADD_OUT_EDGE:
      case storage::Delta::Action::REMOVE_OUT_EDGE: 
      case storage::Delta::Action::ADD_IN_EDGE:
      case storage::Delta::Action::REMOVE_IN_EDGE:{
        delta_is_edge=true;
        break;
      }
      default:break;
    }
    // auto prev = vertex_deltas->prev.Get();
    // if(prev.type==storage::PreviousPtr::Type::DELTA){
    //   switch (vertex_deltas->action) {
    //     case storage::Delta::Action::ADD_OUT_EDGE:
    //     case storage::Delta::Action::REMOVE_OUT_EDGE: 
    //     case storage::Delta::Action::ADD_IN_EDGE:
    //     case storage::Delta::Action::REMOVE_IN_EDGE:{
    //       delta_is_edge=true;
    //       break;
    //     }
    //     default:break;
    //   }
    // }
    auto transaction_ts=vertex_deltas->transaction_st;
    auto transaction_te=vertex_deltas->commit_timestamp!=0?vertex_deltas->commit_timestamp:std::numeric_limits<uint64_t>::max();
    
    // if(!is_vertex & delta_is_vertex) continue;//需要边的数据 delta是顶点
    if(transaction_ts>= transaction_te){//节点刚创建的状态，直接跳过
      break;
    }

    if(is_vertex & delta_is_edge) {
      // tmp_ts=transaction_ts;
      // tmp_te=transaction_te;
      vertex_deltas = vertex_deltas->next.load(std::memory_order_acquire);    
      index_++;
      continue;
    }//需要顶点的数据 delta是边
    
    // std::cout<<"dead delta:"<<transaction_ts<<" "<<transaction_te<<" "<<tmp_ts<<" "<<tmp_te<<" "<<index_<<"\n";
    //如果是下一个事务的操作,并且上一个事务通过约束条件的判断，则创建新的点
    if((transaction_ts!=tmp_ts || transaction_te!=tmp_te) & history_delta::TemporalCheck(tmp_ts,tmp_te,c_ts,c_te,types_)){//&TemporalCheck(tmp_ts,tmp_te,c_ts,c_te,types)
      dead_deltas.emplace_back(index_);
      // std::cout<<"test index here1:"<<index_<<"\n";
      if(types_=="as of") {//如果是时间点，则直接返回，也不需要遍历delted history的记录
        need_deleted_flag=false;
        break;
      }
    }

    tmp_ts=transaction_ts;
    tmp_te=transaction_te;

    // Move to the next delta.
    vertex_deltas = vertex_deltas->next.load(std::memory_order_acquire);    
    index_++;
  }

  //最后一个事务的数据
  if(need_deleted_flag){
    if((tmp_ts!=tmp_te) & history_delta::TemporalCheck(tmp_ts,tmp_te,c_ts,c_te,types_)){//&TemporalCheck(tmp_ts,tmp_te,c_ts,c_te,types)
      dead_deltas.emplace_back(index_);
      // std::cout<<"test index here2:"<<index_<<"\n";
      if(types_=="as of") {//如果是时间点，则直接返回，也不需要遍历delted history的记录
        need_deleted_flag=false;
      }
    }
  }
  // std::cout<<"get dead info done\n";
  return std::make_pair(need_deleted_flag,dead_deltas);
}

//获取kv点或者边的属性
std::pair<bool,std::pair<std::vector<int>,std::vector<nlohmann::json>>> getHistoryInfo(uint64_t object_gid,std::map<uint64_t,std::vector<nlohmann::json>> &fiter_history_datas_,std::optional<query::VertexAccessor> current_vertex_,std::optional<storage::HistoryEdge*> current_edge_,uint64_t c_ts,uint64_t c_te,std::string types_,bool is_vertex){
  auto get_history_flag=false;
  auto [need_deleted_flag,dead_deltas]=getDeadInfo(current_vertex_,current_edge_,c_ts, c_te,types_,is_vertex);
  auto gid_history_deltas_=std::vector<nlohmann::json>();
  if(!dead_deltas.empty()) get_history_flag=true;
  if(need_deleted_flag){
    if(fiter_history_datas_.find(object_gid)!=fiter_history_datas_.end()){
      gid_history_deltas_=fiter_history_datas_[object_gid];
    }
    // if(current_vertex_){//节点，直接获取gid      
    //   if(fiter_history_datas_.find(vertex_gid)!=fiter_history_datas_.end()){
    //     gid_history_deltas_=fiter_history_datas_[vertex_gid];
    //   }
    // }else{//边
    //   if(fiter_history_datas_.find(vertex_gid)!=fiter_history_datas_.end()){
    //     auto vertex_history_info=fiter_history_datas_[vertex_gid];
    //     for(auto tmp:vertex_history_info){// "0":json "1":json
    //       auto edge_str=std::to_string(edge_gid);
    //       if( tmp.find(edge_str)!= tmp.end()){
    //         auto edge_data= tmp[edge_str];
    //         edge_data["TT_TS"]=tmp["TT_TS"];
    //         edge_data["TT_TE"]=tmp["TT_TE"];
    //         gid_history_deltas_.emplace_back(edge_data);
    //       }
    //     }
    //   }
    // }
  }
  if(!gid_history_deltas_.empty()) get_history_flag=true;
  return std::make_pair(get_history_flag,std::make_pair(dead_deltas,gid_history_deltas_));
}

const std::string kDeltaPrefix = "D:";
const std::string kRecreatePrefix = "R:";

const std::string kVertexDeltaPrefix = "VD:";
const std::string kVertexAnchorPrefix = "VA:";
const std::string kEdgeDeltaPrefix = "ED:";
const std::string kEdgeAnchorPrefix = "EA:";
const std::string kVertexEdgePrefix = "VE:";
/**
 * All data stored in the `Auth` storage is stored in an underlying
 * `kvstore::KVStore`. Because we are using a key-value store to store the data,
 * the data has to be encoded. The encoding used is as follows:
 *
 * User: key="gid:<username>", value="<json_encoded_members_of_user>"
 */

History_delta::History_delta(const std::string &storage_directory) : storage_(storage_directory) {}//"/home/hjm/memgraph/build/history_deltas"


void History_delta::GetDelta(const std::string &gid_orig) const {
  auto gid = utils::ToLowerCase(gid_orig);
  auto existing_gid = storage_.Get(kDeltaPrefix + gid);
  if (!existing_gid) {
    std::cout<<"not get delta"<<std::endl;
    return ;//std::nullop
  }

  //获取值，解码
  nlohmann::json data;
  try {
    data = nlohmann::json::parse(*existing_gid);
  } catch (const nlohmann::json::parse_error &e) {
   // throw AuthException("Couldn't load gid data!");//重写exception
  }
  std::cout<<"get delta here:gid#"<<gid<<" Delta_Action#"<<data["Delta_Action"]<<" start_timestamp#"<<data["start_timestamp"]<<" commit_timestamp#"<<data["commit_timestamp"]<<" property#"<<data["property"]<<" value#"<<data["property_value"]<<std::endl;
 
  //对delta重新加载成可以被利用
  // auto user = User::Deserialize(data);
}


void History_delta::GetAll() const {
  auto kDeltaPrefix="";
  for (auto it = storage_.begin(kDeltaPrefix); it != storage_.end(kDeltaPrefix); ++it) {
    auto [gid,ts,te]=string_convert_to_uint(it->first);
    std::cout<<"ts:"<<ts<<" te:"<<te<<"\n";

    // auto split_info=splits(it->first,":");
    // auto prefix=split_info[0];//前缀信息
    // auto gid=std::stoi(split_info[1]);//顶点的id
    // auto object_ts=split_info[2];//版本的开始时间
    // auto object_te=split_info[3];//版本的结束时间
    // int num = *(int*) object_ts;
    // std::cout<<"test num:"<<num<<"\n";
    // std::cout<<"test here:"<<it->first<<" "<<it->second<<"\n";
  }

  // for (auto it = storage_.ends(kDeltaPrefix); it != storage_.begins(kDeltaPrefix); --it) {
  //   std::cout<<it->first<<"\n";
  //   // if(it == storage_.end(kgidPrefix)) continue;
  //   // auto split_info=splits(it->first,":");
  //   // auto gid=std::stoi(split_info[1]);
  //   // auto object_ts=(uint64_t)(-std::stoi(split_info[2]));
  //   // auto object_te=(uint64_t)(-std::stoi(split_info[3]));
  //   // auto existing_gid = it->second;
  //   // //获取值，解码
  //   // nlohmann::json data;
  //   // try {
  //   //   data = nlohmann::json::parse(existing_gid);
  //   // } catch (const nlohmann::json::parse_error &e) {
  //   // // throw AuthException("Couldn't load gid data!");//重写exception
  //   // }
  //   // std::cout<<"gid:"<<gid<<" ts:"<<object_ts<<" te:"<<object_te<<"\n";

  //   // std::cout<<"get delta all#key:"<<it->first;
  //   // for (auto its = data.begin(); its != data.end(); ++it) {
  //   //     auto it_key = its.key();
  //   //     auto it_value = its.value();//property_value json
  //   //     std::cout<<" save_key"<<it_key<<std::endl;
  //   // }
  //   // std::cout<<"get delta here#key:"<<it->first<<" property:"<<data["property"]<<" value:"<<data["property_value"]<<std::endl;
  // }

}

// std::pair<std::map<std::string,nlohmann::json>,std::map<int,std::vector<nlohmann::json>>> History_delta::GetAllDeltas(uint64_t c_ts,uint64_t c_te,std::string type){
//   std::map<int,std::vector<nlohmann::json>> fiter_history_datas_;
//   std::map<std::string,nlohmann::json> fiter_history_delete;
//   auto tmp_gid=-1;
//   auto tmp_info=nlohmann::json::object();
//   auto next_flag=false;
//   //收集被删除的节点的信息
//   auto tmp_gids=-1;
//   auto tmp_ts=-1;
//   auto tmp_te=-1;
//   for (auto it = storage_.ends(""); it != storage_.begins(""); --it){
//     auto split_info=splits(it->first,":");
//     auto prefix=split_info[0];
//     auto gid=std::stoi(split_info[1]);
//     auto object_ts=(uint64_t)std::stoi(split_info[2]);
//     auto object_te=(uint64_t)std::stoi(split_info[3]);
//     auto existing_vertex = it->second;
//     if(prefix=="R"){
//       fiter_history_delete[it->first]=nlohmann::json::parse(existing_vertex);
//       tmp_gids=gid;
//       tmp_ts=object_ts;
//       tmp_te=object_te;
//       continue;
//     }
//     //收集delta的信息
//     if(gid!=tmp_gid){//表示上一个的gid完成收集
//       tmp_info.clear();
//       next_flag=true;
//     }
//     if(next_flag){
//       auto curren_info=nlohmann::json::parse(existing_vertex);//当前节点的数据
//       //被删除的节点的delta信息合并
//       if(tmp_gids==gid & tmp_ts==object_ts & tmp_te==object_te){
//         std::string keys="R:"+split_info[1]+":"+split_info[2]+":"+split_info[3];
//         // combine(curren_info,fiter_history_delete[keys]);
//         tmp_gid=gid;
//         continue;
//       }
//       //其他节点的信息
//       // combine(tmp_info,curren_info);
//       tmp_info=curren_info;
//       if(TemporalCheck(object_ts,object_te,c_ts,c_te,type)){
//         if(type=="as of") {
//           next_flag=false;
//         }
//         auto iter = fiter_history_datas_.find(gid);
//         if(iter == fiter_history_datas_.end()){ 
//           auto info_lists_=std::vector<nlohmann::json>();
//           info_lists_.emplace_back(curren_info);
//           fiter_history_datas_[gid]=info_lists_;
//         }else{
//           fiter_history_datas_[gid].emplace_back(curren_info);
//         }
//       }
//     }
//     tmp_gid=gid;
//   }
//   return std::make_pair(fiter_history_delete,fiter_history_datas_);
// }

std::pair<std::map<int,nlohmann::json>,std::map<int,std::vector<nlohmann::json>>> History_delta::GetAllDeltas(uint64_t c_ts,uint64_t c_te,std::string type,std::string get_type){
  std::map<int,std::vector<nlohmann::json>> fiter_history_datas_;
  std::map<int,nlohmann::json> fiter_history_delete;
  auto tmp_gid=-1;
  auto tmp_info=nlohmann::json::object();
  auto next_flag=false;

  for (auto it = storage_.ends(""); it != storage_.begins(""); --it){
    auto split_info=splits(it->first,":");
    auto prefix=split_info[0];//前缀信息
    auto gid=std::stoi(split_info[1]);//顶点的id
    auto object_ts=(uint64_t)std::stoi(split_info[2]);//版本的开始时间
    auto object_te=(uint64_t)std::stoi(split_info[3]);//版本的结束时间
    auto existing_vertex = it->second;
    if((prefix+":")!=get_type) continue;//kedge
    break;
    // std::cout<<"after:"<<prefix<<"\n";
    //收集delta的信息
    if(gid!=tmp_gid){//表示上一个的gid完成收集
      tmp_info.clear();
      next_flag=true;
    }
    if(next_flag){
      auto curren_info=nlohmann::json::parse(existing_vertex);//当前节点的数据
      if(tmp_info.empty()){
        if(get_type!=kVertexEdgePrefix)combineVertex(tmp_info,curren_info);//ED+VD
        else combineEdge(tmp_info,curren_info);
        tmp_info=curren_info;
      }
      // if(filter_type==kEdgeDeltaPrefix)combineVertex(tmp_info,curren_info);
      // else combineEdge(tmp_info,curren_info);
      // tmp_info=curren_info;
      if(curren_info.find("R")!=curren_info.end()){//重构的被删除节点的信息
        fiter_history_delete[gid]=curren_info;
        tmp_info.clear();
      }
      if(TemporalCheck(object_ts,object_te,c_ts,c_te,type)){//非重构节点的信息
        if(curren_info.find("R")==curren_info.end()){
          if(type=="as of") next_flag=false;
          auto iter = fiter_history_datas_.find(gid);
          if(iter == fiter_history_datas_.end()){ 
            auto info_lists_=std::vector<nlohmann::json>();
            info_lists_.emplace_back(curren_info);
            fiter_history_datas_[gid]=info_lists_;
          }else{
            fiter_history_datas_[gid].emplace_back(curren_info);
          }
        }
      }
    }
    tmp_gid=gid;
  }
  return std::make_pair(fiter_history_delete,fiter_history_datas_);
}

// seek 符合时间条件的最开始的record
// auto iter_end=storage_.last(prefix);//null
// auto it=storage_.starts(prefix);//比当前时间大一个的指针
// if(it!=iter_end){//回溯
//   --it;
//   if(it==iter_end){
//     it=storage_.starts(prefix);
//   }
// } 

/**
 * @brief v2.0 获取所有顶点（删除+未被删除）的信息。首先根据hash_table找到符合时间条件的顶点，随后seek表找到顶点的信息
 * 
 * @param c_ts 条件开始时间
 * @param c_te 条件结束时间
 * @param type 查询的类型：as,from to ,between and 
 * @return std::pair<std::map<int,nlohmann::json>,std::map<int,std::vector<nlohmann::json>>> 被删除的顶点：gid，info；未被删除的顶点
 */
std::pair<std::map<uint64_t,nlohmann::json>,std::map<uint64_t,std::vector<nlohmann::json>>> History_delta::GetAllVertexDeltas(uint64_t c_ts,uint64_t c_te,std::string type){
  std::map<uint64_t,std::vector<nlohmann::json>> fiter_history_datas_;
  std::map<uint64_t,nlohmann::json> fiter_history_delete;

  for(auto [gids,value]:vertex_time_table_){
    auto min_ts=value.first;//顶点的历史最小时间
    auto max_te=value.second;//顶点的历史最大时间
    // std::cout<<"storag::2689 "<<gids.AsUint()<<" "<<min_ts<<" "<<max_te<<"\n";
    if(!((min_ts>=c_ts&min_ts<=c_te)||(max_te>=c_ts&max_te<=c_te))) continue; //历史数据中没有符合的范围
    // if(!TemporalCheck(min_ts,max_te,c_ts,c_te,type)) continue;//历史数据中没有符合的范围
    auto vertx_gid=gids.AsUint();//当前顶点的id
    auto prefixs="VD:"+std::to_string(vertx_gid);
    auto prefix=prefixs+":"+std::to_string(c_ts);//VD:gid:strat_time 
    
    //获取当前顶点的全部有关信息 当前+最后 
    std::vector<nlohmann::json> history_Delta;
    auto tmp_info=nlohmann::json::object(); 
    for (auto it=storage_.begin(prefixs); it!=storage_.end(prefixs); ++it){
      auto [gid,ts,te]=string_convert_to_uint(it->first);
      auto object_ts=(uint64_t)-ts;//版本的开始时间
      auto object_te=(uint64_t)-te;//版本的结束时间
      if(object_te<=c_ts) break;
      auto existing_vertex = it->second;
      auto curren_info=nlohmann::json::parse(existing_vertex);//当前节点的数据
      if(curren_info.find("R")!=curren_info.end()){//被删除的节点的信息
        fiter_history_delete[gid]=curren_info;
        continue;
      }
      combineVertex(tmp_info,curren_info);
      tmp_info=curren_info;
      if(TemporalCheck(object_ts,object_te,c_ts,c_te,type)){
        if(curren_info.find("R")==curren_info.end()){
          history_Delta.emplace_back(curren_info);
        }
        if(type=="as of") break;
      }
    }
    
    fiter_history_datas_[vertx_gid]=history_Delta;
  }
  
  return std::make_pair(fiter_history_delete,fiter_history_datas_);
}
/**
 * @brief v2.0 获取指定边（未被删除）id的信息，seek到边的位置，然后遍历获取数据
 * 
 * @param c_ts 条件开始时间
 * @param c_te 条件结束时间
 * @param type 查询的类型：as,from to ,between and 
 * @param gid 边的gid
 * @return std::map<int,std::vector<nlohmann::json>> 边
 */
std::map<uint64_t,std::vector<nlohmann::json>> History_delta::GetEdgeDelta(uint64_t c_ts,uint64_t c_te,std::string type,uint64_t gid){
  std::map<uint64_t,std::vector<nlohmann::json>> fiter_history_datas_;
  std::vector<nlohmann::json> history_Delta;
  auto tmp_info=nlohmann::json::object();
  auto next_flag=false;
  auto prefix="ED:"+std::to_string(gid);
  // std::cout<<"prefix:"<<prefix<<"\n";
  auto &[min_ts,max_te]=edge_time_table_[gid];
  // std::cout<<prefix<<" min_ts:"<<min_ts<<" max_te:"<<max_te<<"\n";
  if(!((min_ts>=c_ts&min_ts<=c_te)||(max_te>=c_ts&max_te<=c_te))) return fiter_history_datas_;
  // std::cout<<"here2   "<<prefix<<" min_ts:"<<min_ts<<" max_te:"<<max_te<<"\n";
  for (auto it=storage_.begin(prefix); it!=storage_.end(prefix); ++it){
    auto [gid,ts,te]=string_convert_to_uint(it->first);
    auto object_ts=(uint64_t)-ts;//版本的开始时间
    auto object_te=(uint64_t)-te;//版本的结束时间
    // std::cout<<"history_delta::589 "<<gid<<" "<<object_ts<<" "<<object_te<<"\n";
    if(object_te<=c_ts) break;
    auto existing_vertex = it->second;
    auto curren_info=nlohmann::json::parse(existing_vertex);//当前节点的数据
    combineVertex(tmp_info,curren_info);
    tmp_info=curren_info;
    if(TemporalCheck(object_ts,object_te,c_ts,c_te,type)){
      history_Delta.emplace_back(curren_info);
      if(type=="as of") break;
    }
  }
  fiter_history_datas_[gid]=history_Delta;
  return fiter_history_datas_;
}

/**
 * @brief v2.0 获取制定顶点（被删除）的边
 * 
 * @param c_ts 条件开始时间
 * @param c_te 条件结束时间
 * @param type 查询的类型：as,from to ,between and 
 * @param v_gid 边的id
 * @return std::map<int,std::vector<nlohmann::json>> 被删除的边
 */
std::map<uint64_t,std::vector<nlohmann::json>> History_delta::GetDeleteEdgeDeltas(uint64_t c_ts,uint64_t c_te,std::string type,uint64_t gid){
  std::map<uint64_t,std::vector<nlohmann::json>> fiter_history_datas_;
  std::vector<nlohmann::json> history_Delta;
  auto tmp_info=nlohmann::json::object();
  auto next_flag=false;
  auto prefix="VE:"+std::to_string(gid);
  // std::cout<<"prefix:"<<prefix<<"\n";
  for (auto it=storage_.begin(prefix); it!=storage_.end(prefix); ++it){
    auto [gid,ts,te]=string_convert_to_uint(it->first);
    auto object_ts=(uint64_t)-ts;//版本的开始时间
    auto object_te=(uint64_t)-te;//版本的结束时间
    // std::cout<<"history_delta::589 "<<gid<<" "<<object_ts<<" "<<object_te<<"\n";
    if(object_te<=c_ts) break;
    auto existing_vertex = it->second;
    auto curren_info=nlohmann::json::parse(existing_vertex);//当前节点的数据
    combineEdge(tmp_info,curren_info);
    tmp_info=curren_info;
    if((object_ts>=c_ts&object_ts<=c_te)||(object_te>=c_ts&object_te<=c_te)){
      // std::cout<<"history_delta::669 "<<gid<<" "<<object_ts<<" "<<object_te<<"\n";
      history_Delta.emplace_back(curren_info);
      if(type=="as of") break;
    }
    // if(TemporalCheck(object_ts,object_te,c_ts,c_te,type)){
    //   history_Delta.emplace_back(curren_info);
    //   if(type=="as of") break;
    // }
  }
  fiter_history_datas_[gid]=history_Delta;
  return fiter_history_datas_;
}

std::pair<std::map<int,nlohmann::json>,std::map<int,std::vector<nlohmann::json>>> History_delta::GetAllDeltas3(uint64_t c_ts,uint64_t c_te,std::string type,std::string prefix){
  std::map<int,std::vector<nlohmann::json>> fiter_history_datas_;
  std::map<int,nlohmann::json> fiter_history_delete;
  auto tmp_gid=-1;
  auto tmp_info=nlohmann::json::object();
  auto next_flag=false;
  
  for (auto it = storage_.begin(prefix); it != storage_.end(prefix); ++it){
    auto split_info=splits(it->first,":");
    auto prefix=split_info[0];//前缀信息
    auto gid=std::stoi(split_info[1]);//顶点的id
    auto object_ts=(uint64_t)std::stoi(split_info[2]);//版本的开始时间
    auto object_te=(uint64_t)std::stoi(split_info[3]);//版本的结束时间
    auto existing_vertex = it->second;
    //收集delta的信息
    if(gid!=tmp_gid){//表示上一个的gid完成收集
      tmp_info.clear();
      next_flag=true;
    }
    if(next_flag){
      auto curren_info=nlohmann::json::parse(existing_vertex);//当前节点的数据
      if(tmp_info.empty()){
        combineVertex(tmp_info,curren_info);
        tmp_info=curren_info;
      }
      if(TemporalCheck(object_ts,object_te,c_ts,c_te,type)){//非重构节点的信息
        if(curren_info.find("R")==curren_info.end()){
          if(type=="as of") next_flag=false;
          auto iter = fiter_history_datas_.find(gid);
          if(iter == fiter_history_datas_.end()){ 
            auto info_lists_=std::vector<nlohmann::json>();
            info_lists_.emplace_back(curren_info);
            fiter_history_datas_[gid]=info_lists_;
          }else{
            fiter_history_datas_[gid].emplace_back(curren_info);
          }
        }
      }
    }
    tmp_gid=gid;
  }
  return std::make_pair(fiter_history_delete,fiter_history_datas_);
}


std::tuple<std::map<int,nlohmann::json>,std::map<int,std::vector<nlohmann::json>>,std::map<int,std::vector<nlohmann::json>>> History_delta::GetAllDeltas2(uint64_t c_ts,uint64_t c_te,std::string type,std::string get_type){
  std::map<int,std::vector<nlohmann::json>> fiter_history_e_datas_;
  std::map<int,std::vector<nlohmann::json>> fiter_history_v_datas_;
  // std::map<int,std::vector<nlohmann::json>> fiter_history_datas_;
  std::map<int,nlohmann::json> fiter_history_v_delete;
  auto tmp_gid=-1;
  auto tmp_info=nlohmann::json::object();
  auto next_flag=false;
  // auto fiter_history_datas_= get_type=="VD:"?&fiter_history_v_datas_:&fiter_history_e_datas_;
  for (auto it = storage_.begin(get_type); it != storage_.end(get_type); ++it){
    auto split_info=splits(it->first,":");
    auto prefix=split_info[0];//前缀信息
    auto gid=std::stoi(split_info[1]);//顶点的id
    auto object_ts=(uint64_t)std::stoi(split_info[2]);//版本的开始时间
    auto object_te=(uint64_t)std::stoi(split_info[3]);//版本的结束时间
    auto existing_vertex = it->second;
    // if((prefix+":")!=get_type) continue;//kedge
    auto fiter_history_datas_= prefix=="VD"?&fiter_history_v_datas_:&fiter_history_e_datas_;
    if(gid!=tmp_gid){//表示上一个的gid完成收集
      next_flag=true;
    }
    if(next_flag){
      if(TemporalCheck(object_ts,object_te,c_ts,c_te,type)){
        auto curren_info=nlohmann::json::parse(existing_vertex);//当前节点的数据
        if(curren_info.find("R")==curren_info.end()){//非重构节点的信息
          auto iter = fiter_history_datas_->find(gid);
          if(iter == fiter_history_datas_->end()){ 
            auto info_lists_=std::vector<nlohmann::json>();
            info_lists_.emplace_back(curren_info);
            (*fiter_history_datas_)[gid]=info_lists_;
          }else{
            (*fiter_history_datas_)[gid].emplace_back(curren_info);
          }
        }else{//重构的被删除节点的信息
          fiter_history_v_delete[gid]=curren_info;
        }
        if(type=="as of") next_flag=false;
      }
    }
    tmp_gid=gid;
  }
  return std::make_tuple(fiter_history_v_delete,fiter_history_v_datas_,fiter_history_e_datas_);
}

std::pair<std::map<std::string,nlohmann::json>,std::map<int,std::vector<nlohmann::json>>> History_delta::GetAllEdgeDeltas(uint64_t c_ts,uint64_t c_te,std::string type){
  std::map<int,std::vector<nlohmann::json>> fiter_history_datas_;
  std::map<std::string,nlohmann::json> fiter_history_delete;
  auto tmp_gid=-1;
  auto tmp_info=nlohmann::json::object();
  auto next_flag=false;

  for (auto it = storage_.ends(""); it != storage_.begins(""); --it){
    auto split_info=splits(it->first,":");
    auto prefix=split_info[0];//前缀信息
    auto gid=std::stoi(split_info[1]);//顶点的id
    auto object_ts=(uint64_t)std::stoi(split_info[2]);//版本的开始时间
    auto object_te=(uint64_t)std::stoi(split_info[3]);//版本的结束时间
    auto existing_vertex = it->second;
    if(prefix==kEdgeDeltaPrefix) continue;
    //收集delta的信息
    if(gid!=tmp_gid){//表示上一个的gid完成收集
      tmp_info.clear();
      next_flag=true;
    }
    if(next_flag){
      auto curren_info=nlohmann::json::parse(existing_vertex);//当前节点的数据
      combineVertex(tmp_info,curren_info);
      tmp_info=curren_info;
      if(TemporalCheck(object_ts,object_te,c_ts,c_te,type)){
        if(type=="as of") next_flag=false;
        auto iter = fiter_history_datas_.find(gid);
        if(iter == fiter_history_datas_.end()){ 
          auto info_lists_=std::vector<nlohmann::json>();
          info_lists_.emplace_back(curren_info);
          fiter_history_datas_[gid]=info_lists_;
        }else{
          fiter_history_datas_[gid].emplace_back(curren_info);
        }
      }
    }
    tmp_gid=gid;
  }
  return std::make_pair(fiter_history_delete,fiter_history_datas_);
}


void History_delta::SaveDeltaAll() {
  bool success = false;
  if(gid_delta_.empty()) return;
  // std::ofstream ofs;
  // ofs.open("/home/hjm/memgraph/build/mg_data/history_info.txt",std::ios::app);
  for(auto [key,value]:gid_delta_){
    success=storage_.Put(key, value.dump());
    std::cout<<"save here "<<key<<" value info:"<<value.dump()<<std::endl;
    // ofs<<key+";"+value.dump()<<"\n";
    if (!success) {
      std::cout<<"Couldn't save delta!"<<std::endl;
    }
  }
  // ofs.clear();
  gid_delta_.clear();
}

void History_delta::SaveDelta(storage::Gid gid,const std::optional<storage::Gid> to_gid,const uint64_t start,const uint64_t commit,storage::Delta& delta,storage::NameIdMapper &name_id_mapper) {
  bool edge_flag=false;
  //get delta infomation encode delta to string
  nlohmann::json data = nlohmann::json::object();
  switch (delta.action) {
    case storage::Delta::Action::RECREATE_OBJECT: {
      data= delta.add_info;
      if(!to_gid)data["R"]="R";//排除边
      break;
    }
    case storage::Delta::Action::SET_PROPERTY: {
      auto property_name = name_id_mapper.IdToName(delta.property.key.AsUint());//delta.property.key.AsUint();//
      auto property_value = SerializePropertyValue(delta.property.value);//query::serialization::
      nlohmann::json data2 = nlohmann::json::object();
      data2[property_name] = property_value;
      data["SP"]=data2;
      break;
    }
    case storage::Delta::Action::ADD_LABEL:{
      auto add_label=std::vector<std::pair<std::string,std::string>>();
      add_label.emplace_back("AL",name_id_mapper.IdToName(delta.label.AsUint()));
      data["L"] = add_label;//"ADD:"+name_id_mapper.IdToName(delta.label.AsUint());
      break;
    }
    case storage::Delta::Action::REMOVE_LABEL: {
      auto remove_labels=std::vector<std::pair<std::string,std::string>>();
      // auto labels=std::vector<uint64_t>();
      // labels.emplace_back(delta.label.AsUint());
      remove_labels.emplace_back("RL",name_id_mapper.IdToName(delta.label.AsUint()));
      data["L"] = remove_labels;//"REMOVE:"+name_id_mapper.IdToName(delta.label.AsUint());
      break;
    }
    case storage::Delta::Action::ADD_OUT_EDGE:
    case storage::Delta::Action::ADD_IN_EDGE:{
      edge_flag=true;
      auto edge_id=std::to_string((delta.vertex_edge.edge.ptr->gid).AsUint());
      nlohmann::json edge_data = nlohmann::json::object();
      edge_data["Type"]=delta.action==storage::Delta::Action::ADD_OUT_EDGE?"AOE":"AIE";//ADD IN EDGE
      edge_data["edgeType"]=name_id_mapper.IdToName((delta.vertex_edge.edge_type).AsUint());
      edge_data["edgeId"]=(delta.vertex_edge.edge.ptr->gid).AsUint();
      edge_data["fromGid"]=(delta.vertex_edge.edge.ptr->from_gid).AsUint();
      edge_data["toGid"]=(delta.vertex_edge.edge.ptr->to_gid).AsUint();
      data[edge_id]=edge_data;
      break;
    }
    default:
      return;
  }
  if(to_gid) {
    data["Fid"]=(delta.from_gid)->AsUint();
    data["Tid"]=(delta.to_gid)->AsUint();
  }
  auto prefix=(to_gid)?kEdgeDeltaPrefix:(edge_flag?kVertexEdgePrefix:kVertexDeltaPrefix);
  
  std::string start_str="";
  uint_convert_to_string((int64_t)-start,start_str);
  std::string commit_str="";
  uint_convert_to_string((int64_t)-commit,commit_str);
  
  auto put_key=prefix + std::to_string(gid.AsUint()) +":"+(start_str)+":"+(commit_str); //std::to_string  std::to_string
  //union something
  data["TT_TS"]=start;
  data["TT_TE"]=commit;
  auto iter = gid_delta_.find(put_key);
  if(iter != gid_delta_.end()){ 
    auto before_value=gid_delta_[put_key];
    if(edge_flag){//VE
      combineEdge(before_value,data);
    }else{//ED+VD
      combineVertex(before_value,data);
    }
  }
  // auto put_keys=prefix +std::to_string(start)+":"+std::to_string(commit)+":"+ std::to_string(gid.AsUint()) ;
  gid_delta_[put_key]=data;
  // gid_delta_[put_keys]=data;

  //save hash index
  if(prefix=="VD:"){
    auto iter=vertex_time_table_.find(gid);
    if(iter==vertex_time_table_.end()){
      vertex_time_table_[gid]=std::make_pair(start,commit);
    }else{
      auto &value=vertex_time_table_[gid];
      value.second=commit;
    }
  }

  //save hash index
  if(prefix=="ED:"){
    auto vertex_gid=gid.AsUint();
    auto iter=edge_time_table_.find(vertex_gid);
    if(iter==edge_time_table_.end()){
      edge_time_table_[vertex_gid]=std::make_pair(start,commit);
    }else{
      auto &value=edge_time_table_[vertex_gid];
      value.second=commit;
    }
  }

  // auto prefix=delta.action==storage::Delta::Action::RECREATE_OBJECT?kRecreatePrefix:kDeltaPrefix;
  // if (data.empty()){
  //   //do nothing
  // }else{
  //   auto prefix=edge_flag?kEdgeDeltaPrefix:kVertexDeltaPrefix;
  //   auto put_key=prefix + std::to_string(gid.AsUint()) +":"+std::to_string(start)+":"+std::to_string(commit);  
  //   //find the before value, if find, add new value 
  //   if(to_gid){//边属性的改变
  //     //from vertex 出边
  //     auto tmp_data=data;
  //     auto edge_id=std::to_string(gid.AsUint());
  //     data["Type"]="AOE";
  //     nlohmann::json data2 = nlohmann::json::object();
  //     data2[edge_id]=data;
  //     data=data2;
  //     data["TT_TS"]=start;
  //     data["TT_TE"]=commit;
  //     put_key=kEdgeDeltaPrefix + std::to_string(delta.from_gid->AsUint()) +":"+std::to_string(start)+":"+std::to_string(commit);
  //     auto iter = gid_delta_.find(put_key);
  //     if(iter != gid_delta_.end()){ 
  //       auto before_value=gid_delta_[put_key];
  //       combineEdge(before_value,data);//合并同一个事务的几个delta
  //     }
  //     gid_delta_[put_key]=data;
  //     //入边
  //     tmp_data["Type"]="AIE";
  //     nlohmann::json data3 = nlohmann::json::object();
  //     data3[edge_id]=tmp_data;
  //     tmp_data=data3;
  //     tmp_data["TT_TS"]=start;
  //     tmp_data["TT_TE"]=commit;
  //     auto put_keys=kEdgeDeltaPrefix + std::to_string(to_gid->AsUint()) +":"+std::to_string(start)+":"+std::to_string(commit);  
  //     auto iters = gid_delta_.find(put_keys);
  //     if(iters != gid_delta_.end()){ 
  //       auto before_values=gid_delta_[put_keys];
  //       combineEdge(before_values,data);//合并同一个事务的几个delta
  //     }
  //     gid_delta_[put_keys]=data;
  //   }else{//顶点的标签和属性的改变，边的删除操作
  //     //union something
  //     data["TT_TS"]=start;
  //     data["TT_TE"]=commit;
  //     auto iter = gid_delta_.find(put_key);
  //     if(iter != gid_delta_.end()){ 
  //       auto before_value=gid_delta_[put_key];
  //       if(edge_flag){
  //         combineEdge(before_value,data);
  //       }else{
  //         combineVertex(before_value,data);
  //       }
  //     }
  //     gid_delta_[put_key]=data;
  //   }
  // }

}

bool History_delta::HasDeltas() const { return storage_.begin(kDeltaPrefix) != storage_.end(kDeltaPrefix); }

}  // namespace history_delta
