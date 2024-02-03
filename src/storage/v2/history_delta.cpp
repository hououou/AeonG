#include "storage/v2/history_delta.hpp"
#include "query/db_accessor.hpp"
#include <cstring>
#include <fmt/format.h>

#include <stdlib.h>
#include "utils/flag_validation.hpp"
#include "utils/settings.hpp"
#include <json/json.hpp>
#include "query/serialization/property_value.hpp"
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


//help functions
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
    auto size=sizeof(time);
    char *buffer = (char *)std::malloc(size);
    auto test=swap64(time);
    std::memcpy(buffer, &test, size);
    std::string start_str(buffer,size);
    std::free(buffer);
    return start_str;
}

std::tuple<uint64_t,int64_t,int64_t> string_convert_to_uint(std::string res,bool realTimeFlagConstant){
    auto size=sizeof(int64_t);
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
    auto ts = *(int64_t*) redo2;// redo_str;
    auto te = *(int64_t*) redo;
    ts=swap64(ts);
    te=swap64(te);
    return std::make_tuple(gid,ts,te);
}

void combineVertex(nlohmann::json before_data,nlohmann::json &current_data){
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
      combineVertex(before_data[edge_id],current_data[edge_id]);
    }
  }
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


History_delta::History_delta(const std::string &storage_directory) : storage_(storage_directory) {}

History_delta::History_delta(const std::string &storage_directory,bool realTimeFlag) : storage_(storage_directory) {
  realTimeFlagConstant=realTimeFlag;
}



std::pair<std::vector<nlohmann::json>,bool> History_delta::GetEdgeInfo(uint64_t c_ts,uint64_t c_te,std::string type,uint64_t gid){
  std::vector<nlohmann::json> history_Delta;
  bool anchor_flag=false;
  auto tmp_info=nlohmann::json::object();
  //1、在VA段查找最邻近的record
  auto anchor_prefix=kEdgeAnchorPrefix+std::to_string(gid)+":"+uint_convert_to_string((int64_t)c_te,realTimeFlagConstant);
  auto iter_begin=storage_.starts(anchor_prefix);
  auto iter_end=storage_.last(anchor_prefix);

  auto prefixs=kEdgeDeltaPrefix+std::to_string(gid);
  auto vd_iter_begin=storage_.starts(prefixs);
  auto vd_iter_end=storage_.last(prefixs);//null
  bool need_combine=true;

  while(iter_begin!=iter_end){//1.2. VA中找到了，筛选VD数据段
    auto key=iter_begin->first;
    auto parts = splits(key, ":");
    if(parts[1] != std::to_string(gid)){
      ++iter_begin;
      break;
    }
    anchor_flag=true;
    tmp_info=nlohmann::json::parse(iter_begin->second);
    auto va_ts=(int64_t)(std::get<1>(string_convert_to_uint(key,realTimeFlagConstant)));
    if(va_ts>=c_te){
      va_ts=va_ts>0?-va_ts:va_ts;
      auto va_ts_str=uint_convert_to_string(va_ts,realTimeFlagConstant);
      auto delta_prefix=kEdgeDeltaPrefix+std::to_string(gid)+":"+va_ts_str;
      vd_iter_begin=storage_.starts(delta_prefix);
      vd_iter_end=storage_.last(delta_prefix);
      break;
    }else  anchor_flag=false;
    ++iter_begin;
  }

  for(;vd_iter_begin!=vd_iter_end;++vd_iter_begin){
    auto [egde_gid,ts,te]=string_convert_to_uint(vd_iter_begin->first,realTimeFlagConstant);
    auto object_ts=(uint64_t)-ts;//版本的开始时间
    auto object_te=(uint64_t)-te;//版本的结束时间
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
      if(type=="as of") break;
    }
  } 
  return std::make_pair(history_Delta,anchor_flag);
}


void History_delta::GetTimeTableAll(){
  for(auto it=storage_.starts(kVertexTimePrefix);it!=storage_.last(kVertexTimePrefix);++it){
    auto gid=(uint64_t)std::stoi(it->first.substr(3));
    auto split_info=splits(it->second,":");
    auto min_ts=(uint64_t)std::stoi(split_info[0]);
    auto max_te=(uint64_t)std::stoi(split_info[1]);
    vertex_time_table_[gid]=std::make_pair(min_ts,max_te);
  }
  //save edge time table
  for(auto it=storage_.starts(kEdgeTimePrefix);it!=storage_.last(kEdgeTimePrefix);++it){
    auto gid=(uint64_t)std::stoi(it->first.substr(3));
    auto split_info=splits(it->second,":");
    auto min_ts=(uint64_t)std::stoi(split_info[0]);
    auto max_te=(uint64_t)std::stoi(split_info[1]);
    edge_time_table_[gid]=std::make_pair(min_ts,max_te);
  }
}

std::pair<std::vector<nlohmann::json>,bool> History_delta::GetVertexInfo(storage::Gid gid,uint64_t c_ts,uint64_t c_te,std::string type){
    std::vector<nlohmann::json> history_Delta;
    bool anchor_flag=false;
    auto vertx_gid=gid.AsUint();//当前顶点的id
    auto tmp_info=nlohmann::json::object();
    auto anchor_prefix=kVertexAnchorPrefix+std::to_string(vertx_gid)+":"+uint_convert_to_string((int64_t)c_te,realTimeFlagConstant);
    auto iter_begin=storage_.starts(anchor_prefix);//seek 符合时间条件的最开始的record 比当前时间大一个的指针
    auto iter_end=storage_.last(anchor_prefix);//null

    //1.1. VA中找不到，从最新的VD找到数据
    auto prefixs=kVertexDeltaPrefix+std::to_string(vertx_gid)+":"+uint_convert_to_string((int64_t)-c_te,realTimeFlagConstant);
    auto vd_iter_begin=storage_.starts(prefixs);
    auto vd_iter_end=storage_.last(prefixs);//null
    bool need_combine=true;
    if(iter_begin!=iter_end){//1.2. VA中找到了，筛选VD数据段
        auto key=iter_begin->first;
        auto parts = splits(key, ":");
        if(parts[1] != std::to_string(vertx_gid)){
            anchor_flag=false;
        }else{
            anchor_flag=true;
            auto va_ts=(int64_t)(std::get<1>(string_convert_to_uint(key,realTimeFlagConstant)));
            if(va_ts>=c_te){
                tmp_info=nlohmann::json::parse(iter_begin->second);
                va_ts=va_ts>0?-va_ts:va_ts;
                auto va_ts_str=uint_convert_to_string(va_ts,realTimeFlagConstant);
                auto delta_prefix=kVertexDeltaPrefix+std::to_string(vertx_gid)+":"+va_ts_str;
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
        if(gid!=vertx_gid) break;
        if(object_te<c_ts) break;
        auto current_info=nlohmann::json::parse(vd_iter_begin->second);//当前节点的数据
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
    return std::make_pair(history_Delta,anchor_flag);
}


std::pair<std::vector< std::tuple< std::map<storage::PropertyId,storage::PropertyValue>,uint64_t,uint64_t> >,bool> getDeadInfo2(query::VertexAccessor current_vertex_,uint64_t c_ts,uint64_t c_te,std::string types_){
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
      res.emplace_back(std::make_tuple(maybe_properties,transaction_ts,transaction_te));
      if(types_=="as of") {//如果是时间点，则直接返回，也不需要遍历delted history的记录
        need_deleted_flag=false;
        break;
      }
    }
    // Move to the next delta.
    vertex_deltas = vertex_deltas->next.load(std::memory_order_acquire);    
  }
  return std::make_pair(res,need_deleted_flag);
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

    return history_Delta;
}

void History_delta::SaveDeltaAll() {
  bool success = false;
  if(gid_delta_.empty()) return;
  std::map<std::string,std::string> gid_data_tmp;
  for(auto [key,value]:gid_delta_){
    gid_data_tmp[key]=value.dump();
  }
  success=storage_.PutMultiple(gid_data_tmp);
  if (!success) {
    std::cout<<"Couldn't save delta!"<<std::endl;
  }
  gid_delta_.clear();
}


void History_delta::SaveAnchorAll(std::map<std::string, std::string> &value){
  bool success=storage_.PutMultiple(value);
  if (!success) {
    std::cout<<"Couldn't save delta!"<<std::endl;
  }
}


void History_delta::SaveEdgeAnchorAll(uint64_t tid,std::map<std::string, std::string>& data){
  if(!data.empty())edge_anchor_.emplace_back(data);
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
  auto put_key=prefix + std::to_string(gid.AsUint()) +":"+(start_str)+":"+(commit_str); //std::to_string  std::to_string
  // union something
  data["TT_TS"]=start;
  data["TT_TE"]=commit;
  auto iter =  gid_delta_.find(put_key);
  if(iter !=  gid_delta_.end()){ 
    auto before_value= gid_delta_[put_key];
    if(edge_flag){//VE
      combineEdge(before_value,data);
    }else{//ED+VD
      combineVertex(before_value,data);
    }
  }
   gid_delta_[put_key]=data;
}

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
  std::vector<std::string> delete_keys;
  for (auto it = storage_.begin(); it != storage_.end(); ++it) {
    auto [gid,ts,te]=string_convert_to_uint(it->first,realTimeFlagConstant);
    te=te>0?te:-te;
    if(te<=clean_timestamp){
      delete_keys.push_back(it->first);
    }
  }
  if (!storage_.DeleteMultiple(delete_keys)) {
    std::cout<<"Couldn't Remove Old History!\n";
  }
  return true;
}
}  // namespace history_delta
