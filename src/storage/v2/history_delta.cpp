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

#include <stdlib.h>

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
#include <arpa/inet.h>
#include "storage/v2/replication/config.hpp"

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

int64_t swap64(const int64_t &v)
{
  return (v >> 56 & 0x00000000000000ff)
    | ((v & 0x00ff000000000000) >> 40 & 0x0000000000ffffff)
    | ((v & 0x0000ff0000000000) >> 24 & 0x000000ffffffffff)
    | ((v & 0x000000ff00000000) >> 8 & 0x00ffffffffffffff)
    | ((v & 0x00000000ff000000) << 8)
    | ((v & 0x0000000000ff0000) << 24)
    | ((v & 0x000000000000ff00) << 40)
    | (v << 56);
}

std::string uint_convert_to_string(const int64_t time,bool realTimeFlagConstant){
   if(false){//realTimeFlagConstant
    if(time>0){
      return std::to_string(std::numeric_limits<uint64_t>::max()-time);
    }else{
      return std::to_string(-std::numeric_limits<uint64_t>::max()+time);
    }
  }else{
    auto size=sizeof(time);
    char *buffer = (char *)std::malloc(size);
    auto test=swap64(time);
    std::memcpy(buffer, &test, size);
    std::string start_str(buffer,size);
    std::free(buffer);
    return start_str;
  }
}

// return std::to_string(time);

std::tuple<uint64_t,int64_t,int64_t> string_convert_to_uint(std::string res,bool realTimeFlagConstant){
  auto size=sizeof(int64_t);

  if(false){//realTimeFlagConstant
    auto split_info=splits(res,":");
    auto gid=(uint64_t)std::stoi(split_info[1]);
    auto ts=-(std::numeric_limits<uint64_t>::max()+std::stoll(split_info[2]));
    auto te=-(std::numeric_limits<uint64_t>::max()+std::stoll(split_info[3]));
    // std::cout<<"string_convert_to_uint gid:"<<res<<" gid:"<<gid<<" ts:"<<ts<<" te:"<<te<<"\n";
    return std::make_tuple(gid,ts,te);
  }else{
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
    // auto ts = *(int*) redo2;// redo_str;
    // auto te = *(int*) redo;
    auto ts = *(int64_t*) redo2;// redo_str;
    auto te = *(int64_t*) redo;
    ts=swap64(ts);
    te=swap64(te);
    // std::cout<<"string_convert_to_uint gid:"<<res<<" gid:"<<gid<<" ts:"<<ts<<" te:"<<te<<"\n";
    return std::make_tuple(gid,ts,te);
  }
  // std::cout<<"string_convert_to_int: "<<ts<<" "<<te<<"\n";
  // std::cout<<htonl(ts)<<" "<<htonl(te)<<"\n";
  // auto split_info=splits(res,":");
  // auto gid=(uint64_t)std::stoi(split_info[1]);
  // auto ts=std::stoi(split_info[2]);
  // auto te=std::stoi(split_info[3]);
  // return std::make_tuple(gid,ts,te);
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

const std::string kVertexTimePrefix="VT:";
const std::string kEdgeTimePrefix="ET:";
/**
 * All data stored in the `Auth` storage is stored in an underlying
 * `kvstore::KVStore`. Because we are using a key-value store to store the data,
 * the data has to be encoded. The encoding used is as follows:
 *
 * User: key="gid:<username>", value="<json_encoded_members_of_user>"
 */

History_delta::History_delta(const std::string &storage_directory) : storage_(storage_directory) {}//"/home/hjm/memgraph/build/history_deltas"

History_delta::History_delta(const std::string &storage_directory,bool realTimeFlag) : storage_(storage_directory) {
  realTimeFlagConstant=realTimeFlag;
}


void History_delta::GetAll() const {
  auto kDeltaPrefixs="ED:131361";
  int i =0;
  // std::cout<<"get all start here\n";
  // for (auto it = storage_.starts(kDeltaPrefixs); it != storage_.last(kDeltaPrefixs); ++it) {
  //   auto [gid,ts,te]=string_convert_to_uint(it->first);
  //   std::cout<<"ts:"<<ts<<" te:"<<te<<it->second<<"\n";GetVertexInfo
  //   i+=1;
  //   if(i>5) break;
  // }
  // i=0;
  // std::cout<<"get all begin here\n";
  // for (auto it = storage_.begin(kDeltaPrefixs); it != storage_.end(kDeltaPrefixs); ++it) {
  //   auto [gid,ts,te]=string_convert_to_uint(it->first);
  //   std::cout<<"ts:"<<ts<<" te:"<<te<<" "<<it->second<<"\n";
  //   i+=1;
  //   if(i>5) break;
  // }
  i=0;
  std::cout<<"get noprefix begin here\n";
  for (auto it = storage_.begin(); it != storage_.end(); ++it) {
    auto [gid,ts,te]=string_convert_to_uint(it->first,realTimeFlagConstant);
    std::cout<<"ts:"<<ts<<" te:"<<te<<" "<<it->second<<"\n";
    i+=1;
    // if(i>5) break;
  }
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
  std::map<uint64_t,std::vector<nlohmann::json>> fiter_anchor_datas_;//可以直接由kv中获取数据 gid,(data_json,anchor_flag)
  std::map<uint64_t,nlohmann::json> fiter_history_delete;

  for(auto [vertx_gid,value]:vertex_time_table_){
    auto min_ts=value.first;//顶点的历史最小时间
    auto max_te=value.second;//顶点的历史最大时间
    if(!((min_ts>=c_ts&min_ts<=c_te)||(max_te>=c_ts&max_te<=c_te))) continue; //历史数据中没有符合的范围
    // auto vertx_gid=gids.AsUint();//当前顶点的id
    std::string c_ts_str=uint_convert_to_string((int64_t)c_ts,realTimeFlagConstant);

    //1、在VA段查找最邻近的record
    auto anchor_prefix=kVertexAnchorPrefix+std::to_string(vertx_gid)+":"+c_ts_str;
    auto iter_end=storage_.last(anchor_prefix);//null
    auto iter_begin=storage_.starts(anchor_prefix);//seek 符合时间条件的最开始的record 比当前时间大一个的指针  
    std::vector<nlohmann::json> history_Delta;
    auto tmp_info=nlohmann::json::object(); 

    //1.1. VA中找不到，从最新的VD找到数据
    auto prefixs=kVertexDeltaPrefix+std::to_string(vertx_gid);
    auto vd_iter_end=storage_.end(prefixs);//null
    auto vd_iter_begin=storage_.begin(prefixs);
    bool need_combine=true;
    if(iter_begin!=iter_end){//1.2. VA中找到了，筛选VD数据段
      auto key=iter_begin->first;
      tmp_info=nlohmann::json::parse(iter_begin->second);
      if(tmp_info.find("R")!=tmp_info.end())fiter_history_delete[vertx_gid]=tmp_info;
      //VD段数据查找 第一个record 是anchor随后都是delta
      auto va_ts=std::get<1>(string_convert_to_uint(key,realTimeFlagConstant));
      auto va_ts_str=uint_convert_to_string((int64_t)-va_ts,realTimeFlagConstant);
      auto delta_prefix=kVertexDeltaPrefix+std::to_string(vertx_gid)+":"+va_ts_str;
      vd_iter_end=storage_.last(delta_prefix);//null
      vd_iter_begin=storage_.starts(delta_prefix);
    }
    //2、获取数据
    for(;vd_iter_begin!=vd_iter_end;++vd_iter_begin){
      auto [gid,ts,te]=string_convert_to_uint(vd_iter_begin->first,realTimeFlagConstant);
      auto object_ts=(uint64_t)-ts;//版本的开始时间
      auto object_te=(uint64_t)-te;//版本的结束时间
      if(object_te<=c_ts) break;
      auto current_info=nlohmann::json::parse(vd_iter_begin->second);//当前节点的数据
      if(current_info.find("R")!=current_info.end())fiter_history_delete[gid]=current_info;
      if(need_combine){
        combineVertex(tmp_info,current_info);
        tmp_info=current_info;
      }
      if(TemporalCheck(object_ts,object_te,c_ts,c_te,type)){
        need_combine=false;
        history_Delta.emplace_back(current_info);
        if(type=="as of") break;
      }
    }
    fiter_anchor_datas_[vertx_gid]=history_Delta;
  }
  
  return std::make_pair(fiter_history_delete,fiter_anchor_datas_);
}

/**
 * @brief v3.0获取指定顶点的信息
 * 
 * @param gid 顶点的id
 * @param c_ts 
 * @param c_te 
 * @param type 
 * @return std::pair<std::vector<nlohmann::json>,bool> 历史数据，是否可以从kv中直接得到数据
 */
std::pair<std::vector<nlohmann::json>,bool> History_delta::GetVertexInfo(storage::Gid gid,uint64_t c_ts,uint64_t c_te,std::string type){
  std::cout<<"get delete info here\n";
  std::vector<nlohmann::json> history_Delta;
  //simple imple
  bool anchor_flag=false;
  // auto return_info=nlohmann::json::parse("info");
  // history_Delta.emplace_back(return_info);
  // return std::make_pair(history_Delta,anchor_flag);
  //simple imple
  auto vertx_gid=gid.AsUint();//当前顶点的id
  auto tmp_info=nlohmann::json::object(); 
  // auto current_info=nlohmann::json::object(); 
  //1、在VA段查找最邻近的record
  auto anchor_prefix=kVertexAnchorPrefix+std::to_string(vertx_gid)+":"+uint_convert_to_string((int64_t)c_te,realTimeFlagConstant);
  // auto anchor_prefix=kVertexAnchorPrefix+std::to_string(vertx_gid)+":";
  std::cout<<"v anchor_prefix:"<<c_te<<" "<<anchor_prefix<<"\n";
  auto iter_begin=storage_.starts(anchor_prefix);//seek 符合时间条件的最开始的record 比当前时间大一个的指针  
  auto iter_end=storage_.last(anchor_prefix);//null

  //1.1. VA中找不到，从最新的VD找到数据
  auto prefixs=kVertexDeltaPrefix+std::to_string(vertx_gid)+":"+uint_convert_to_string((int64_t)-c_te,realTimeFlagConstant);
  auto vd_iter_begin=storage_.starts(prefixs);
  auto vd_iter_end=storage_.last(prefixs);//null
  bool need_combine=true;
  // wzy edit 0510 if->while
  if(iter_begin!=iter_end){//1.2. VA中找到了，筛选VD数据段
    auto key=iter_begin->first;
    auto parts = splits(key, ":");
    if(parts[1] != std::to_string(vertx_gid)){
      anchor_flag=false;
    }else{
      anchor_flag=true;
      auto va_ts=(int64_t)(std::get<1>(string_convert_to_uint(key,realTimeFlagConstant)));
      std::cout<<"get anchor key here:"<<va_ts<<" "<<c_te<<"\n";
      if(va_ts>=c_te){
        // hjm info 
        tmp_info=nlohmann::json::parse(iter_begin->second);
         // hjm info 
        // std::cout<<"get va here2:"<<va_ts<<"\n";
        va_ts=va_ts>0?-va_ts:va_ts;
        auto va_ts_str=uint_convert_to_string(va_ts,realTimeFlagConstant);
        auto delta_prefix=kVertexDeltaPrefix+std::to_string(vertx_gid)+":"+va_ts_str;
        std::cout<<"set delta_prefix:"<<va_ts<<" "<<delta_prefix<<"\n";
        vd_iter_begin=storage_.starts(delta_prefix);
        vd_iter_end=storage_.last(delta_prefix);//null
      }
    }
  }

  //2、获取delta数据
  for(;vd_iter_begin!=vd_iter_end;++vd_iter_begin){
    auto [gid,ts,te]=string_convert_to_uint(vd_iter_begin->first,realTimeFlagConstant);
    auto object_ts=(uint64_t)-ts;//版本的开始时间
    auto object_te=(uint64_t)-te;//版本的结束时间
    std::cout<<"delta $$$$$$$$$$$$$$$test:"<<gid<<" "<<object_ts<<" "<<object_te<<" "<<c_ts<<" "<<c_te<<"\n";
    if(gid!=vertx_gid) break;
    if(object_te<c_ts) break;
    auto current_info=nlohmann::json::parse(vd_iter_begin->second);//当前节点的数据
    if(need_combine){
      combineVertex(tmp_info,current_info);
      tmp_info=current_info;
    }
    if(TemporalCheck(object_ts,object_te,c_ts,c_te,type)){
      need_combine=false;
      std::cout<<"get vertex delta info:"<<object_ts<<" "<<object_te<<"\n";
      history_Delta.emplace_back(current_info);
      if(type=="as of") break;
    }
  } 
  return std::make_pair(history_Delta,anchor_flag);
}

/**
 * @brief v3.0 获取制定边的信息
 * 
 * @param c_ts 
 * @param c_te 
 * @param type 
 * @param gid 
 * @return std::pair<std::vector<nlohmann::json>,bool> 历史数据，是否可以从kv中直接得到数据
 */
std::pair<std::vector<nlohmann::json>,bool> History_delta::GetEdgeInfo(uint64_t c_ts,uint64_t c_te,std::string type,uint64_t gid){
  std::vector<nlohmann::json> history_Delta;
  bool anchor_flag=false;
  uint64_t gid_tmp=1595;
  // if(edge_time_table_.find(gid)==edge_time_table_.end()) return std::make_pair(history_Delta,anchor_flag); 
  // auto &[min_ts,max_te]=edge_time_table_[gid];
  // if(!TemporalCheck(min_ts,max_te,c_ts,c_te,type)) return std::make_pair(history_Delta,anchor_flag); //历史数据中没有符合的范围
  
  auto tmp_info=nlohmann::json::object(); 
  //1、在VA段查找最邻近的record
  auto anchor_prefix=kEdgeAnchorPrefix+std::to_string(gid)+":"+uint_convert_to_string((int64_t)c_te,realTimeFlagConstant);
  std::cout<<"e anchor_prefix:"<<c_te<<" "<<anchor_prefix<<"\n";
  auto iter_begin=storage_.starts(anchor_prefix);
  auto iter_end=storage_.last(anchor_prefix);

  //1.1. VA中找不到，从最新的VD找到数据
  auto prefixs=kEdgeDeltaPrefix+std::to_string(gid);
  // if(gid==gid_tmp)std::cout<<"get ed here:"<<prefixs<<"\n";
  auto vd_iter_begin=storage_.starts(prefixs);
  auto vd_iter_end=storage_.last(prefixs);//null
  bool need_combine=true;

  while(iter_begin!=iter_end){//1.2. VA中找到了，筛选VD数据段
    auto key=iter_begin->first;
    // wzy begin
    auto parts = splits(key, ":");
    // auto va_ts=(int64_t)(std::get<1>(string_convert_to_uint(key)));
    // std::cout<<parts[1]<<" "<<va_ts<<std::endl;
    if(parts[1] != std::to_string(gid)){
      ++iter_begin;
      break;
    }
    anchor_flag=true;
    tmp_info=nlohmann::json::parse(iter_begin->second);
    // std::cout<<"VA here! "<<tmp_info.dump()<<std::endl;
    //VD段数据查找 第一个record 是anchor随后都是delta
    auto va_ts=(int64_t)(std::get<1>(string_convert_to_uint(key,realTimeFlagConstant)));
    // va_ts=va_ts>0?-va_ts:va_ts;
    // if(gid==gid_tmp)std::cout<<"get va here"<<va_ts<<"\n";
    // auto va_ts_str=uint_convert_to_string(va_ts);
    // auto delta_prefix=kEdgeDeltaPrefix+std::to_string(gid)+":"+va_ts_str;
    // vd_iter_begin=storage_.starts(delta_prefix);
    // vd_iter_end=storage_.last(delta_prefix);//null
    //double check
    if(va_ts>=c_te){
      // if(gid==gid_tmp)std::cout<<"get va here2"<<va_ts<<"\n";
      va_ts=va_ts>0?-va_ts:va_ts;
      auto va_ts_str=uint_convert_to_string(va_ts,realTimeFlagConstant);
      auto delta_prefix=kEdgeDeltaPrefix+std::to_string(gid)+":"+va_ts_str;
      std::cout<<"e delta_prefix:"<<va_ts<<" "<<delta_prefix<<"\n";
      vd_iter_begin=storage_.starts(delta_prefix);
      vd_iter_end=storage_.last(delta_prefix);//null
      break; //wzy edit 0510
    }else  anchor_flag=false;
    ++iter_begin; //wzy edit 0510
  }
  //2、获取数据
  // std::cout<<"get here:"<<gid<<"\n";
  for(;vd_iter_begin!=vd_iter_end;++vd_iter_begin){
    auto [egde_gid,ts,te]=string_convert_to_uint(vd_iter_begin->first,realTimeFlagConstant);
    auto object_ts=(uint64_t)-ts;//版本的开始时间
    auto object_te=(uint64_t)-te;//版本的结束时间
    // if(gid==gid_tmp)std::cout<<"get here2:"<<object_ts<<" "<<object_te<<"\n";
    if(gid!=egde_gid) break;
    if(object_te<c_ts) break;
    auto current_info=nlohmann::json::parse(vd_iter_begin->second);//当前节点的数据
    if(need_combine){
      combineVertex(tmp_info,current_info);
      tmp_info=current_info;
    }
    if(TemporalCheck(object_ts,object_te,c_ts,c_te,type)){
      need_combine=false;
      history_Delta.emplace_back(current_info);
      // std::cout<<"get edge info:"<<object_ts<<" "<<object_te<<"\n";
      if(type=="as of") break;
    }
  } 
  return std::make_pair(history_Delta,anchor_flag);
}

std::vector<nlohmann::json> History_delta::GetDeleteEdgeInfo(uint64_t c_ts,uint64_t c_te,std::string type,uint64_t vertex_gid){
  std::vector<nlohmann::json> history_Delta;
  bool anchor_flag=false;
  //1. VD找到数据
  auto prefixs=kVertexEdgePrefix+std::to_string(vertex_gid);
  auto vd_iter_begin=storage_.starts(prefixs);
  auto vd_iter_end=storage_.last(prefixs);//null
  bool need_combine=true;
  auto tmp_info=nlohmann::json::object(); 

  //2、获取数据
  for(;vd_iter_begin!=vd_iter_end;++vd_iter_begin){
    auto [gid,ts,te]=string_convert_to_uint(vd_iter_begin->first,realTimeFlagConstant);
    auto object_ts=(uint64_t)-ts;//版本的开始时间
    auto object_te=(uint64_t)-te;//版本的结束时间
    // if(gid==gid_tmp)std::cout<<"get here2:"<<object_ts<<" "<<object_te<<"\n";
    if(gid!=vertex_gid) break;
    if(object_te<c_ts) break;
    auto current_info=nlohmann::json::parse(vd_iter_begin->second);//当前节点的数据
    if(need_combine){
      combineEdge(tmp_info,current_info);
      tmp_info=current_info;
    }
    if(TemporalCheck(object_ts,object_te,c_ts,c_te,type)){
      need_combine=false;
      history_Delta.emplace_back(current_info);
      if(type=="as of") break;
    }
  } 

  return history_Delta;//std::make_pair(history_Delta,anchor_flag);
}

/**
 * @brief v3.0 获取time table index
 * 
 */
void History_delta::GetTimeTableAll(){
  bool success = false;
  //save vertex time table
  for(auto it=storage_.starts(kVertexTimePrefix);it!=storage_.last(kVertexTimePrefix);++it){
    auto gid=(uint64_t)std::stoi(it->first.substr(3));
    auto split_info=splits(it->second,":");
    auto min_ts=(uint64_t)std::stoi(split_info[0]);
    auto max_te=(uint64_t)std::stoi(split_info[1]);
    // std::cout<<"historydelra::598 "<<gid<<" "<<min_ts<<" "<<max_te<<"\n";
    vertex_time_table_[gid]=std::make_pair(min_ts,max_te);
  }
  //save edge time table
  for(auto it=storage_.starts(kEdgeTimePrefix);it!=storage_.last(kEdgeTimePrefix);++it){
    auto gid=(uint64_t)std::stoi(it->first.substr(3));
    auto split_info=splits(it->second,":");
    auto min_ts=(uint64_t)std::stoi(split_info[0]);
    auto max_te=(uint64_t)std::stoi(split_info[1]);
    // std::cout<<"historydelra::607 "<<gid<<" "<<min_ts<<" "<<max_te<<"\n";
    edge_time_table_[gid]=std::make_pair(min_ts,max_te);
  }
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
  if(!TemporalCheck(min_ts,max_te,c_ts,c_te,type)) return fiter_history_datas_;
  // std::cout<<"here2   "<<prefix<<" min_ts:"<<min_ts<<" max_te:"<<max_te<<"\n";
  for (auto it=storage_.begin(prefix); it!=storage_.end(prefix); ++it){
    auto [gid,ts,te]=string_convert_to_uint(it->first,realTimeFlagConstant);
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
    auto [gid,ts,te]=string_convert_to_uint(it->first,realTimeFlagConstant);
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

/**
 * @brief 获取delta顶点或者边的属性
 * 
 * @param vertex_deltas 
 * @param c_ts 
 * @param c_te 
 * @param types_ 
 * @param is_vertex 
 * @return std::pair<bool,std::vector<int>> 
 */
// std::pair<bool,std::vector<int>> History_delta::getDeadInfo(storage::Delta* vertex_deltas,uint64_t c_ts,uint64_t c_te,std::string types_,bool is_vertex){
//   //dead info 属性 label和边 不需要考虑
//   std::cout<<"get dead info\n";
//   auto dead_deltas=std::vector<int>();//记住delta的下标
//   auto tmp_ts=0;
//   auto tmp_te=0;
//   int index_=0;
//   auto need_deleted_flag=true;
//   bool delta_is_edge=false;
//   while (vertex_deltas != nullptr) {
//     delta_is_edge=false;
//     switch (vertex_deltas->action) {
//       case storage::Delta::Action::ADD_OUT_EDGE:
//       case storage::Delta::Action::REMOVE_OUT_EDGE: 
//       case storage::Delta::Action::ADD_IN_EDGE:
//       case storage::Delta::Action::REMOVE_IN_EDGE:{
//         delta_is_edge=true;
//         break;
//       }
//       default:break;
//     }
//     auto transaction_ts=vertex_deltas->transaction_st;
//     auto transaction_te=vertex_deltas->commit_timestamp!=0?vertex_deltas->commit_timestamp:std::numeric_limits<uint64_t>::max();
//     std::cout<<"get dead info here2:"<<transaction_ts<<" "<<transaction_te<<"\n";
//     if(transaction_ts>= transaction_te){//节点刚创建的状态，直接跳过
//       break;
//     }
//     if(is_vertex & delta_is_edge & transaction_te!=(uint64_t)std::numeric_limits<int64_t>::max()) {
//       vertex_deltas = vertex_deltas->next.load(std::memory_order_acquire);    
//       index_++;
//       continue;
//     }//需要顶点的数据 delta是边
    
//     //如果是下一个事务的操作,并且上一个事务通过约束条件的判断，则创建新的点
//     if((transaction_ts!=tmp_ts || transaction_te!=tmp_te) & history_delta::TemporalCheck(tmp_ts,tmp_te,c_ts,c_te,types_)){//&TemporalCheck(tmp_ts,tmp_te,c_ts,c_te,types)
//       std::cout<<"get indeed delta:"<<tmp_ts<<" "<<tmp_te<<"\n";
//       dead_deltas.emplace_back(index_);
//       if(types_=="as of") {//如果是时间点，则直接返回，也不需要遍历delted history的记录
//         need_deleted_flag=false;
//         break;
//       }
//     }
//     tmp_ts=transaction_ts;
//     tmp_te=transaction_te;
//     // Move to the next delta.
//     vertex_deltas = vertex_deltas->next.load(std::memory_order_acquire);    
//     index_++;
//   }

//   //最后一个事务的数据
//   if(need_deleted_flag){
//     if((tmp_ts!=tmp_te) & history_delta::TemporalCheck(tmp_ts,tmp_te,c_ts,c_te,types_)){//&TemporalCheck(tmp_ts,tmp_te,c_ts,c_te,types)
//       dead_deltas.emplace_back(index_);
//       if(types_=="as of") {//如果是时间点，则直接返回，也不需要遍历delted history的记录
//         need_deleted_flag=false;
//       }
//     }
//   }
//   return std::make_pair(need_deleted_flag,dead_deltas);
// }


std::pair<bool,std::vector<int>> History_delta::getDeadInfo(storage::Delta* vertex_deltas,uint64_t c_ts,uint64_t c_te,std::string types_,bool is_vertex){
  //dead info 属性 label和边 不需要考虑
  std::cout<<"get dead info\n";
  std::map<storage::PropertyId, storage::PropertyValue> dead_properties;
  auto dead_deltas=std::vector<int>();//记住delta的下标
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
    auto transaction_ts=vertex_deltas->transaction_st;
    auto transaction_te=vertex_deltas->commit_timestamp!=0?vertex_deltas->commit_timestamp:std::numeric_limits<uint64_t>::max();
    // std::cout<<"get dead info here2:"<<transaction_ts<<" "<<transaction_te<<"\n";
    if(transaction_ts>= transaction_te){//节点刚创建的状态，直接跳过
      vertex_deltas = vertex_deltas->next.load(std::memory_order_acquire);    
      index_++;
      continue;
    }
    //跳过未提交的节点
    if(is_vertex & delta_is_edge & transaction_te!=std::numeric_limits<uint64_t>::max()) {
      vertex_deltas = vertex_deltas->next.load(std::memory_order_acquire);    
      index_++;
      continue;
    }//需要顶点的数据 delta是边

    //just for test 
    std::cout<<"get indeed delta here:"<<transaction_ts<<" "<<transaction_te<<"\n";
    dead_deltas.emplace_back(index_);
    need_deleted_flag=false;
    break;
    
    if(history_delta::TemporalCheck(transaction_ts,transaction_te,c_ts,c_te,types_)){//&TemporalCheck(tmp_ts,tmp_te,c_ts,c_te,types)
      std::cout<<"get indeed delta here:"<<transaction_ts<<" "<<transaction_te<<"\n";
      dead_deltas.emplace_back(index_);
      // if(vertex_deltas->action==storage::Delta::Action::SET_PROPERTY){
      //   auto property_value=vertex_deltas->property.value;
      //   if(property_value.type()!=storage::PropertyValue::Type::Null) dead_properties[vertex_deltas->property.key]=property_value;
      //   else{
      //     dead_properties[vertex_deltas->property.key]=storage::PropertyValue("NULL");;
      //   }
      // }
      // auto property_id = storage::PropertyId::FromUint(storage_.name_id_mapper_.NameToId("transaction_ts"));
      // auto property_id2 = storage::PropertyId::FromUint(storage_->name_id_mapper_.NameToId("transaction_te"));
      // auto property_value = storage::PropertyValue((int64_t)tt_ts);
      // dead_properties[property_id]=property_value;
      // auto property_value2 = storage::PropertyValue((int64_t)tt_te);
      // dead_properties[property_id2]=property_value2;

      if(types_=="as of") {//如果是时间点，则直接返回，也不需要遍历delted history的记录
        need_deleted_flag=false;
        break;
      }
    }
    // Move to the next delta.
    vertex_deltas = vertex_deltas->next.load(std::memory_order_acquire);    
    index_++;
  }
  return std::make_pair(need_deleted_flag,dead_deltas);
}

std::pair<std::vector< std::tuple< std::map<storage::PropertyId,storage::PropertyValue>,uint64_t,uint64_t> >,bool> getDeadInfo2(query::VertexAccessor current_vertex_,uint64_t c_ts,uint64_t c_te,std::string types_){
  //dead info 属性 label和边 不需要考虑
  std::cout<<"get dead info\n";
  std::vector<std::tuple< std::map<storage::PropertyId,storage::PropertyValue>,uint64_t,uint64_t>> res;
  auto vertex_deltas=current_vertex_.getDeltas();
  auto need_deleted_flag=true;
  if(vertex_deltas==nullptr){
    return std::make_pair(res,need_deleted_flag);
  }
  auto maybe_properties=current_vertex_.impl_.getProperties();
  bool delta_is_edge=false;
  uint64_t transaction_ts=0;
  uint64_t transaction_te=0;
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
      case storage::Delta::Action::SET_PROPERTY:{
        auto property_value=vertex_deltas->property.value;
        auto property_key=vertex_deltas->property.key;
        if(property_value.type()!=storage::PropertyValue::Type::Null) {
          maybe_properties[property_key]=property_value;
        }else{
          maybe_properties[property_key]=storage::PropertyValue("NULL");
        }
      }
      default:break;
    }
    auto transaction_ts=vertex_deltas->transaction_st;
    auto transaction_te=vertex_deltas->commit_timestamp!=0?vertex_deltas->commit_timestamp:std::numeric_limits<uint64_t>::max();
    //跳过未提交的节点 一开始构建的节点
    if(transaction_ts> transaction_te &&  delta_is_edge && transaction_te!=std::numeric_limits<uint64_t>::max()) {
      vertex_deltas = vertex_deltas->next.load(std::memory_order_acquire);    
      continue;
    }//需要顶点的数据 delta是边

    if(history_delta::TemporalCheck(transaction_ts,transaction_te,c_ts,c_te,types_)){//&TemporalCheck(tmp_ts,tmp_te,c_ts,c_te,types)
      std::cout<<"get indeed delta here:"<<transaction_ts<<" "<<transaction_te<<"\n";
      res.emplace_back(std::make_tuple(maybe_properties,transaction_ts,transaction_te));
      if(types_=="as of") {//如果是时间点，则直接返回，也不需要遍历delted history的记录
        need_deleted_flag=false;
        break;
      }
    }
    // Move to the next delta.
    vertex_deltas = vertex_deltas->next.load(std::memory_order_acquire);    
  }
  // if(res.size()==0 && transaction_ts!=0){
  //   res.emplace_back(std::make_tuple(maybe_properties,transaction_ts,transaction_te));
  // }
  return std::make_pair(res,need_deleted_flag);
}

/**
 * @brief v3.0删除的顶点另外存储成anchor信息
 * 
 */
void History_delta::SaveDeltaAll() {
  bool success = false;
  if(gid_delta_.empty()) return;
  // std::cout<<"SaveDeltaAll\n";
  //save VD ED
  std::map<std::string,std::string> gid_data_tmp;
  // std::ofstream ofs_edge;
  // std::ofstream ofs_vertex;
  for(auto [key,value]:gid_delta_){
    gid_data_tmp[key]=value.dump();
    // auto [gid,ts,te]=string_convert_to_uint(key,realTimeFlagConstant);
    // std::cout<<"save delta here "<<gid<<" "<<ts<<" "<<te<<" value info:"<<value.dump()<<std::endl;
  //   //被删除的节点的信息
  //   if(value.find("R")!=value.end()){
  //     auto put_key=kVertexAnchorPrefix + key.substr(3);
  //     gid_delta_[put_key]=value.dump();
  //   }
  //   success=storage_.Put(key, value.dump());
  //   if (!success) {
  //     std::cout<<"Couldn't save delta!"<<std::endl;
  //   }
  //   //输出信息
  //   // auto prefix=key.substr(0,3);
  //   // auto [gid,ts,te]=string_convert_to_uint(key);
  //   // if(prefix==kEdgeDeltaPrefix) ofs_edge<<std::to_string(gid)<<"####"<<std::to_string(-ts)<<"####"<<std::to_string(-te)<<"\n";
  //   // if(prefix==kVertexDeltaPrefix) ofs_vertex<<std::to_string(gid)<<"####"<<std::to_string(-ts)<<"####"<<std::to_string(-te)<<"\n";
  //   // std::cout<<"save here "<<prefix<<" "<<gid<<" "<<ts<<" "<<te<<" value info:"<<value.dump()<<std::endl;
  //   // std::cout<<"save here "<<key<<" value info:"<<value.dump()<<std::endl;
  }
  success=storage_.PutMultiple(gid_data_tmp);
  if (!success) {
    std::cout<<"Couldn't save delta!"<<std::endl;
  }
  gid_delta_.clear();
  // success=storage_.PutMultiple(gid_data_tmp_);
  // if (!success) {
  //   std::cout<<"Couldn't save delta!"<<std::endl;
  // }
}

// void History_delta::SaveDeltaAll() {
//   bool success = false;
//   if(gid_delta_delta_.empty()) return;
//   std::cout<<"SaveDeltaAll\n";
//   std::map<std::string, std::string> final_res;
//   //save VD ED
//   std::map<uint64_t,uint64_t> before_gid_commit_;
//   // auto before_gid=(uint64_t)0;
//   // auto before_commit=(uint64_t)0;
//   for(auto [key,value]:gid_delta_delta_){
//     auto prefix=std::get<0>(key);
//     auto gid=std::get<1>(key);
//     auto commit=std::get<2>(key);
//     auto start=commit;
//     auto before_commit=before_gid_commit_.find(gid)!=before_gid_commit_.end()?before_gid_commit_[gid]:commit;
//     // std::cout<<"start12:"<<before_commit<<" "<<before_gid_commit[gid]<<"\n";
//     if(commit!=before_commit){
//       start=before_commit;
//       // std::cout<<"start2:"<<start<<"\n";
//     }else{
//       auto find_prefix=prefix+std::to_string(gid);
//       // std::cout<<"prefix"<<find_prefix<<"\n";
//       auto it=storage_.starts(find_prefix); 
//       if(it!=storage_.last(find_prefix)){
//         // std::cout<<"find here:"<<it->first<<"\n";
//         auto gets=std::get<2>(string_convert_to_uint(it->first));
//         start=-gets;
//         // std::cout<<"start3:"<<start<<"\n";
//       }
//     }
//     // if(gid==before_gid){
//     //   if(commit!=before_commit){
//     //     start=before_commit;
//     //     std::cout<<"start2:"<<start<<"\n";
//     //   }else{
//     //     auto find_prefix=prefix+std::to_string(gid);
//     //     auto it=storage_.begin(find_prefix); 
//     //     if(it!=storage_.end(find_prefix)){
//     //       start=std::get<2>(string_convert_to_uint(it->first));
//     //       std::cout<<"start3:"<<start<<"\n";
//     //     }
//     //   }
//     // }else{
//     //   auto find_prefix=prefix+std::to_string(gid);
//     //   auto it=storage_.begin(find_prefix); 
//     //   if(it!=storage_.end(find_prefix)){
//     //     start=std::get<2>(string_convert_to_uint(it->first));
//     //     std::cout<<"start4:"<<start<<"\n";
//     //   }
//     // }
    
//     value["TT_TS"]=start;
//     value["TT_TE"]=commit;
//     std::string start_str=uint_convert_to_string((int64_t)-start);
//     std::string commit_str=uint_convert_to_string((int64_t)-commit);
//     auto prefix_key=prefix+std::to_string(gid)+":"+(start_str)+":"+(commit_str);
//     final_res[prefix_key]=value.dump();
//     if(value.find("R")!=value.end()){
//       auto put_key=kVertexAnchorPrefix + prefix_key.substr(3);
//       success=storage_.Put(put_key,value.dump());
//       // final_res[put_key]=value.dump();
//     }
//     // std::cout<<"construct here:"<<prefix_key<<" start:"<<start<<" commit:"<<commit<<" "<<value.dump()<<" \n";
//     success=storage_.Put(prefix_key,value.dump());
//     if (!success) {
//       std::cout<<"Couldn't save delta!"<<std::endl;
//     }
//     before_gid_commit_[gid]=commit;
    
//     if(prefix=="VD:"){
//       auto iter=vertex_time_table_.find(gid);
//       if(iter==vertex_time_table_.end()){
//         vertex_time_table_[gid]=std::make_pair(start,commit);
//       }else{
//         auto &value=vertex_time_table_[gid];
//         value.second=commit;
//         if(value.first==0){
//           value.first=start;
//         }
//       }
//     }   
//     //save hash index
//     if(prefix=="ED:"){
//       auto iter=edge_time_table_.find(gid);
//       if(iter==edge_time_table_.end()){
//         edge_time_table_[gid]=std::make_pair(start,commit);
//       }else{
//         auto &value=edge_time_table_[gid];
//         value.second=commit;
//         if(value.first==0){
//           value.first=start;
//         }
//       }
//     }

//     // before_gid=gid;
//     // before_commit=commit;
//     //被删除的节点的信息
//     // if(value.find("R")!=value.end()){
//     //   auto put_key=kVertexAnchorPrefix + key.substr(3);
//     //   gid_delta_[put_key]=value;
//     // }
//     // success=storage_.Put(key, value.dump());
//     //输出信息
//     // auto prefix=key.substr(0,3);
//     // auto [gid,ts,te]=string_convert_to_uint(key);
//     // std::cout<<"save here "<<prefix<<" "<<gid<<" "<<ts<<" "<<te<<" value info:"<<value.dump()<<std::endl;
//   }
  
//   // success=storage_.PutMultiple(final_res);
//   // if (!success) {
//   //   std::cout<<"Couldn't save delta!"<<std::endl;
//   // }
//   gid_delta_.clear();
//   gid_delta_delta_.clear();

// }

void History_delta::SaveAnchorAll(std::map<std::string, std::string> &value){
  // std::cout<<"save anchor all here: "<<value.size()<<"\n";
  // for(auto [key1,value1]:value){
  //   auto [gid,ts,te]=string_convert_to_uint(key1);
  //   std::cout<<key1<<" value:"<<value1<<" gid:"<<gid<<" ts:"<<ts<<" te:"<<te<<"\n";
  // }
  bool success=storage_.PutMultiple(value);
  if (!success) {
    std::cout<<"Couldn't save delta!"<<std::endl;
  }
}
// void History_delta::SaveAnchorAll(){
//   // std::cout<<"SaveAnchorAll:"<<edge_anchor_.size()<<"\n";
//   bool success = false;
//   if(edge_anchor_.empty()) return;
//   std::cout<<"SaveAnchorAll:"<<edge_anchor_.size()<<"\n";
//   //save anchor info
//   // for(auto value:edge_anchor_){
//   //   std::cout<<"SaveAnchorAll:"<<value.size()<<"\n";
//   //   for(auto [key1,value1]:value){
//   //     std::cout<<key1<<" "<<value1<<"\n";
//   //   }
//   //   success=storage_.PutMultiple(value);
//   //   if (!success) {
//   //     std::cout<<"Couldn't save delta!"<<std::endl;
//   //   }
//   // } 
//   while(!edge_anchor_.empty()){
//     auto value= edge_anchor_.front();
//     for(auto [key1,value1]:value){
//       // std::cout<<key1<<" "<<value1<<"\n";
//       if(key1.find("131361")!=std::string::npos) storage_.Put(key1,value1);
//     }
//     // success=storage_.PutMultiple(value);
//     // if (!success) {
//     //   std::cout<<"Couldn't save delta!"<<std::endl;
//     // }
//     edge_anchor_.pop_front();
//   }
//   if(!edge_anchor_.empty())SaveAnchorAll();
//   //  std::cout<<"SaveAnchorAll done:"<<edge_anchor_.size()<<"\n";
//   // edge_anchor_.clear();
// }

void History_delta::SaveEdgeAnchorAll(uint64_t tid,std::map<std::string, std::string>& data){
  if(!data.empty())edge_anchor_.emplace_back(data);
  // std::cout<<"SaveEdgeAll:"<<data.size()<<"\n";
  //[tid]=data;
}

void History_delta::SaveTimeTableAll(){
  // if(vertex_time_tmp_.size()!=0 || edge_time_tmp_.size()!=0)std::cout<<"SaveTimeTableAl\n";
  // bool success = false;
  // //save vertex time table
  // for(auto [gids,value]:vertex_time_tmp_){
  //   auto min_ts=value.first;//顶点的历史最小时间
  //   auto max_te=value.second;//顶点的历史最大时间
  //   auto values=std::to_string(min_ts)+":"+std::to_string(max_te);
  //   success=storage_.Put(kVertexTimePrefix+std::to_string(gids), values);
  //   if (!success) {
  //     std::cout<<"Couldn't save delta!"<<std::endl;
  //   }
  // }
  // //save edge time table
  // for(auto [gids,value]:edge_time_tmp_){
  //   auto min_ts=value.first;//顶点的历史最小时间
  //   auto max_te=value.second;//顶点的历史最大时间
  //   auto values=std::to_string(min_ts)+":"+std::to_string(max_te);
  //   success=storage_.Put(kEdgeTimePrefix+std::to_string(gids), values);
  //   if (!success) {
  //     std::cout<<"Couldn't save delta!"<<std::endl;
  //   }
  // }
  // vertex_time_tmp_.clear();
  // edge_time_tmp_.clear();
}

void History_delta::SaveDelta(storage::Gid gid,const std::optional<storage::Gid> to_gid,const uint64_t start,const uint64_t commit,storage::Delta& delta,storage::NameIdMapper &name_id_mapper) {
  if(start>commit) return;
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
  //save hash index
  auto vertex_gid=gid.AsUint();
  if(prefix=="VD:"){
    auto iter=vertex_time_table_.find(vertex_gid);
    if(iter==vertex_time_table_.end()){
      vertex_time_table_[vertex_gid]=std::make_pair(start,commit);
    }else{
      auto &value=vertex_time_table_[vertex_gid];
      value.second=commit;
      if(value.first==0){
        value.first=start;
      }
    }
  }   
  // //save hash index
  if(prefix=="ED:"){
    auto iter=edge_time_table_.find(vertex_gid);
    if(iter==edge_time_table_.end()){
      edge_time_table_[vertex_gid]=std::make_pair(start,commit);
    }else{
      auto &value=edge_time_table_[vertex_gid];
      value.second=commit;
      if(value.first==0){
        value.first=start;
      }
    }
  }

  std::string start_str=uint_convert_to_string((int64_t)-start,realTimeFlagConstant);
  std::string commit_str=uint_convert_to_string((int64_t)-commit,realTimeFlagConstant);
  // auto put_key=std::make_tuple(prefix,(gid.AsUint()),commit);
  // auto iter =  gid_delta_delta_.find(put_key);
  // if(iter !=  gid_delta_delta_.end()){ 
  //   auto before_value= gid_delta_delta_[put_key];
  //   if(edge_flag){//VE
  //     combineEdge(before_value,data);
  //   }else{//ED+VD
  //     combineVertex(before_value,data);
  //   }
  // }
  // gid_delta_delta_[put_key]=data;
  // std::cout<<"save before:"<<
  auto put_key=prefix + std::to_string(gid.AsUint()) +":"+(start_str)+":"+(commit_str); //std::to_string  std::to_string
  // union something
  data["TT_TS"]=start;
  data["TT_TE"]=commit;
  auto iter =  gid_delta_.find(put_key);
  if(iter !=  gid_delta_.end()){ 
    auto before_value= gid_delta_[put_key];
    if(edge_flag){//VE
      // std::cout<<"combine edge here\n";
      combineEdge(before_value,data);
    }else{//ED+VD
      // std::cout<<"combine vertex here\n";
      combineVertex(before_value,data);
    }
  }
   gid_delta_[put_key]=data;
  //  if(gid.AsUint()==3514)std::cout<<"save delta:"<<start_str<<" "<<commit_str<<" "<<put_key<<"\n";

  //save realtional transaction's time_table to tmp; store to the kv storage 
  // vertex_time_tmp_[vertex_gid]=vertex_time_table_[vertex_gid];
  // edge_time_tmp_[vertex_gid]=edge_time_table_[vertex_gid];
}

// void History_delta::SaveVertexAnchor(storage::Gid gid,const uint64_t start,std::vector<storage::LabelId> &maybe_labels,std::map<storage::PropertyId, storage::PropertyValue> &maybe_properties,storage::NameIdMapper &name_id_mapper_) {
//   std::string start_str=uint_convert_to_string((int64_t)start);
//   auto key=kVertexAnchorPrefix + std::to_string(gid.AsUint()) +":"+(start_str)+":"+(start_str); //std::to_string  std::to_string
//   //save vertex to restore
//   nlohmann::json data = nlohmann::json::object();
//   //labels
//   auto add_labels=std::vector<std::pair<std::string,std::string>>();
//   for (const auto &label : maybe_labels) {
//     add_labels.emplace_back("AL",name_id_mapper_.IdToName(label.AsUint()));//name_id_mapper_.IdToName(label.AsUint())
//   }
//   data["L"] =add_labels;

//   //properties
//   nlohmann::json data2 = nlohmann::json::object();
//   for (const auto &prop : maybe_properties) {
//     auto property_name = name_id_mapper_.IdToName(prop.first.AsUint());//delta.property.key.AsUint();//
//     auto property_value = SerializePropertyValue(prop.second);//query::serialization::
//     data2[property_name] = property_value;
//   }
//   data["SP"]=data2;
//   gid_delta_[key]=data;
// }

// void History_delta::SaveEdgeAnchor(storage::Gid gid,const uint64_t start,std::map<storage::PropertyId, storage::PropertyValue> &maybe_properties,storage::NameIdMapper &name_id_mapper_) {
//   std::cout<<"SaveEdgeAnchor\n";
//   std::string start_str=uint_convert_to_string((int64_t)start);
//   auto key=kEdgeAnchorPrefix + std::to_string(gid.AsUint()) +":"+(start_str)+":"+(start_str); //std::to_string  std::to_string
//   //properties
//   nlohmann::json data = nlohmann::json::object();
//   nlohmann::json data2 = nlohmann::json::object();
//   for (const auto &prop : maybe_properties) {
//     auto property_name = name_id_mapper_.IdToName(prop.first.AsUint());//delta.property.key.AsUint();//
//     auto property_value = SerializePropertyValue(prop.second);//query::serialization::
//     data2[property_name] = property_value;
//   }
//   data["SP"]=data2;
//   gid_delta_[key]=data;
// }


// void History_delta::SaveVertexAnchor(storage::Gid gid,const uint64_t start,nlohmann::json data) {
//   std::string start_str=uint_convert_to_string((int64_t)start);
//   auto key=kVertexAnchorPrefix + std::to_string(gid.AsUint()) +":"+(start_str)+":"+(start_str); //std::to_string  std::to_string
//   gid_time_tables_[key]=data.dump();
//   // bool success=false;
//   // success=storage_.Put(key, data.dump());
//   // //输出信息
//   // auto prefix=key.substr(0,3);
//   // auto [gids,ts,te]=string_convert_to_uint(key);
//   // std::cout<<"save here "<<prefix<<" "<<gids<<" "<<ts<<" "<<te<<" value info:"<<data<<std::endl;
//   // if (!success) {
//   //   std::cout<<"Couldn't save delta!"<<std::endl;
//   // }
// }

// void History_delta::SaveEdgeAnchor(storage::Gid gid,const uint64_t start,nlohmann::json data) {
//   std::cout<<"SaveEdgeAnchor\n";
//   std::string start_str=uint_convert_to_string((int64_t)start);
//   auto key=kEdgeAnchorPrefix + std::to_string(gid.AsUint()) +":"+(start_str)+":"+(start_str); //std::to_string  std::to_string
//   gid_time_tables_[key]=data.dump();
//   // bool success=false;
//   // success=storage_.Put(key, data.dump());
//   // //输出信息
//   // auto prefix=key.substr(0,3);
//   // auto [gids,ts,te]=string_convert_to_uint(key);
//   // std::cout<<"save here "<<prefix<<" "<<gids<<" "<<ts<<" "<<te<<" value info:"<<data<<std::endl;
//   // if (!success) {
//   //   std::cout<<"Couldn't save delta!"<<std::endl;
//   // }
// }

std::string History_delta::getPrefix(storage::Gid gid,const uint64_t start,bool vertex){
  std::string start_str=uint_convert_to_string((int64_t)start,realTimeFlagConstant);
  auto prefix=vertex?kVertexAnchorPrefix:kEdgeAnchorPrefix;
  auto key=prefix + std::to_string(gid.AsUint()) +":"+(start_str)+":"+(start_str); //std::to_string  std::to_string
  return key;
}
bool History_delta::HasDeltas() const { return storage_.begin(kDeltaPrefix) != storage_.end(kDeltaPrefix); }


bool History_delta::RemoveOldHistory(const std::chrono::milliseconds &retention_period) {
  //TODO find old history and delete them
  auto now_time = std::chrono::system_clock::now();
  auto now_time_milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(now_time.time_since_epoch()).count();
  int64_t clean_timestamp = now_time_milliseconds-retention_period.count() ;
  std::cout<<"remove history here:"<<clean_timestamp<<"\n";
  std::vector<std::string> delete_keys;
  int i=0;
  for (auto it = storage_.begin(); it != storage_.end(); ++it) {
    auto [gid,ts,te]=string_convert_to_uint(it->first,realTimeFlagConstant);
    te=te>0?te:-te;
    if(te<=clean_timestamp){
      delete_keys.push_back(it->first);
    }
    i+=1;
    if(i<5){
      std::cout<<"ts:"<<ts<<" te:"<<te<<" "<<it->second<<"\n";
    }
  }
  if (!storage_.DeleteMultiple(delete_keys)) {
    std::cout<<"Couldn't Remove Old History!\n";
  }else{
    std::cout<<"clean "<<i<<" history delata\n";
    // if(i>=100){
    //   bool status=storage_.CompactRange("","");
    //   std::cout<<"compact:truely delete:"<<status<<"\n";
    // }
  }
  return true;
}
}  // namespace history_delta
