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

#include <gflags/gflags.h>

#include <algorithm>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <optional>
#include <regex>
#include <unordered_map>
#include <chrono>

#include "helpers.hpp"
#include "query/frontend/ast/ast.hpp"
#include "query/plan/operator.hpp"
#include "query/serialization/property_value.hpp"
#include "storage/v2/history_delta.hpp"
#include "storage/v2/storage.hpp"
#include "utils/exceptions.hpp"
#include "utils/logging.hpp"
#include "utils/message.hpp"
#include "utils/string.hpp"
#include "utils/timer.hpp"
#include "version.hpp"


// Memgraph flags.
// NOTE: These flags must be identical as the flags in the main Memgraph binary.
// They are used to automatically load the same configuration as the main
// Memgraph binary so that the flags don't need to be specified when importing a
// CSV file on a correctly set-up Memgraph installation.

// DEFINE_string(data_directory, "memgrapht_1m/memgraph", "Path to directory in which to save all permanent data.");
// DEFINE_string(data_directory, "memgrapht_t_delta100/memgraph", "Path to directory in which to save all permanent data.");
DEFINE_string(data_directory, "/data/hjm/0_pokec/update_frequency/small/tgdb/update_num10000_avg1000/memgraph", "Path to directory in which to save all permanent data.");
DEFINE_bool(storage_properties_on_edges, true, "Controls whether relationships have properties.");//hjm begin

// IS1:: MATCH (n:Person {id:"32985348838034"})-[:IS_LOCATED_IN]->(p:Place) TT AS 44419347
// IS3:: MATCH (n:Person {id:"24189255819196"})-[r:KNOWS]-(friend)
// IS4:: MATCH (m:Message {id:"1236954879921"})
// IS5:: MATCH(m:Message {id:"687194996911"})-[:HAS_CREATOR]->(p:Person)
// IS7:: MATCH (m:Message {id:"687197816725"})<-[:REPLY_OF]-(c:Comment)-[:HAS_CREATOR]->(p:Person)
// enum class Direction { IN, OUT, BOTH };

// double avg_duration = 0.0;
std::vector<double> avg_duration;

bool check_edges(std::vector<storage::EdgeTypeId> edge_types,storage::EdgeTypeId type){
  bool flag=false;
  if(edge_types.size()!=0){
    auto it = std::find(edge_types.begin(), edge_types.end(), type);
    if (it != edge_types.end())flag=true;
  }else flag=true;
  return flag;
}

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

void getSearchCtx(std::string path, std::vector<int>& ids, std::vector<uint64_t>& time_s, std::vector<uint64_t>& time_e){
  std::ifstream in(path);
  std::string line;
  if(in){
    while(getline(in, line)){
      line = line.substr(1);
      // std::cout<<line<<std::endl;
      auto st = line.find_first_of(' ');
      auto ed = line.find_last_of(' ');
      auto sid = line.substr(0, st);
      ids.push_back(std::stoi(sid));
      std::string ts;
      std::string te;
      if(st == ed){
        ts = line.substr(st + 1);
        auto num = std::stoi(ts);
        time_s.push_back(num);
        time_e.push_back(num);
      }else{
        ts = line.substr(st + 1, ed - st - 1);
        te = line.substr(ed + 1);
        time_s.push_back(std::stoi(ts));
        time_e.push_back(std::stoi(te));
      }
    }
  }else{
    std::cout<<"No Such File!"<<std::endl;
  }
  for(int i = 0; i < time_s.size(); ++i){
    std::cout<<ids[i]<<" "<<time_s[i]<<" "<<time_e[i]<<std::endl;
  }
}

void vertexNow(storage::Storage::Accessor &dba, storage::VertexAccessor &vertex){
  auto props = vertex.Properties(storage::View::OLD);
    if(props->begin() == props->end()){
      std::cout<<"prop: null"<<std::endl;
    }else{
      for(auto prop : *props){
        if(prop.second.IsString()){
          std::cout<<dba.PropertyToName(prop.first)<<" property value : "<<prop.second.ValueString()<<std::endl;
        }else if(prop.second.IsInt()){
          std::cout<<dba.PropertyToName(prop.first)<<" property value : "<<prop.second.ValueInt()<<std::endl;
        }else if(prop.second.IsDouble()){
          std::cout<<dba.PropertyToName(prop.first)<<" property value : "<<prop.second.ValueDouble()<<std::endl;
        }
      }
    }
}

void edgeNow(storage::Storage::Accessor &dba, storage::EdgeAccessor &edge){
  auto props = edge.Properties(storage::View::OLD);
    if(props->begin() == props->end()){
      std::cout<<"edge prop: null"<<std::endl;
    }else{
      for(auto prop : *props){
        if(prop.second.IsString()){
          std::cout<<dba.PropertyToName(prop.first)<<" property value : "<<prop.second.ValueString()<<std::endl;
        }else if(prop.second.IsInt()){
          std::cout<<dba.PropertyToName(prop.first)<<" property value : "<<prop.second.ValueInt()<<std::endl;
        }else if(prop.second.IsDouble()){
          std::cout<<dba.PropertyToName(prop.first)<<" property value : "<<prop.second.ValueDouble()<<std::endl;
        }
      }
    }
}

bool vertexHistory(storage::Storage::Accessor &dba, storage::Gid &gid, uint ts, uint te, std::string &types){
  std::cout<<"v_gid:"<<gid.AsUint()<<"\n";
  // std::cout<<"query type: "<<types<<"\n";
  // auto vertex_find=dba.FindHistoryVertex(gid.AsUint(),ts,te);
  auto [gid_history_deltas_,flag]=dba.GetHistoryDelta()->GetVertexInfo(gid,ts,te,types);
  //中间可能会输出delta_prefix:-43821725 VD:1177119:
  std::cout<<"vertex_flag:"<<flag<<"\n";
  for(auto gid_delta_:gid_history_deltas_){
    std::cout<<gid_delta_.dump()<<"\n";
  }
  return flag;
}

void edgeHistory(storage::Storage::Accessor &dba, storage::VertexAccessor &vertex, std::vector<storage::EdgeTypeId>& edge_types, storage::LabelId &to_label, uint ts, uint te, std::string &types){
    // 查找目标节点连接的边
  auto edges = vertex.OutEdges(storage::View::OLD, edge_types);
  if(edges->begin() == edges->end()){
    std::cout<<"edge: null"<<std::endl;
  }else{
    for(auto edge : *edges){
      auto et_id = edge.EdgeType();
      // storage::Gid
      auto from_gid = edge.fromGid();
      auto to_gid = edge.toGid();
      auto e_gid = edge.Gid();
      std::cout<<"edge type : "<<dba.EdgeTypeToName(et_id)<<std::endl;

      // 查找边的历史
      auto [gid_edge_deltas_,flag]=dba.GetHistoryDelta()->GetEdgeInfo(ts,te,types,e_gid.AsUint());
      std::cout<<"edge_flag:"<<flag<<"\n";
      for(auto gid_delta_:gid_edge_deltas_){
        std::cout<<gid_delta_.dump()<<"\n";
      }
      if(!flag){
        edgeNow(dba, edge);
      }
      bool v_flag = vertexHistory(dba, to_gid, ts, te, types);
      if(!v_flag){
        //FindVertex(Gid gid, View view);
        auto vertex = dba.FindVertex(to_gid, storage::View::OLD);
        if(vertex){
          auto to_node = *vertex;
          uint64_t obj_ts = to_node.transaction_st();
          uint64_t obj_te = to_node.tt_te();
          if(obj_ts >= te || obj_ts < te){
            vertexNow(dba, to_node);
          }else{
            std::cout<<" node not need!"<<std::endl;
          }
        }else{
          std::cout<<" node not found!"<<std::endl;
        }
        
        
      }
    }
  }
}

void delEdge(storage::Storage::Accessor &dba, storage::Gid &gid, std::vector<storage::EdgeTypeId>& edge_types, uint ts, uint te, std::string &types){
  // 查找历史数据中，节点在时间范围内被删掉的边
  // 获取kv中被删除的所有边 ve:
  auto deleted_edges_vec = dba.GetHistoryDelta()->GetDeleteEdgeInfo(ts,te,types,gid.AsUint());
  auto direction = query::EdgeAtom::Direction::BOTH;
  if(deleted_edges_vec.empty()){
    std::cout<<"no deleted edges!"<<std::endl;
  }
  //还原kv中那些被删除的边
  for(auto &deleted_edges:deleted_edges_vec){
    for (auto it = deleted_edges.begin(); it != deleted_edges.end(); ++it) {
      std::cout<<"yes deleted edges!"<<std::endl;
      auto edge_id = it.key();
      if(edge_id=="TT_TS" || edge_id=="TT_TE" ||edge_id=="Type"||edge_id=="Fid"||edge_id=="Tid") continue;
      auto edge_jsons=it.value();
      auto edge_type = dba.NameToEdgeType(edge_jsons["edgeType"].get<std::string_view>());
      auto ie_type=edge_jsons["Type"];
      auto from_gid=dba.IdToGid((uint64_t)edge_jsons["fromGid"]);
      auto to_gid=dba.IdToGid((uint64_t)edge_jsons["toGid"]);

      auto edge_ie_flag=direction == query::EdgeAtom::Direction::IN?ie_type=="AIE":ie_type=="AOE";//判断是否是需要的入边或者出边
      if(!edge_ie_flag)continue;
      if(!check_edges(edge_types,edge_type)) continue;//判断边的类型是否是需要的

      //加入数据库中的顶点
      auto expand_vid = direction==query::EdgeAtom::Direction::IN?from_gid:to_gid;//需要expand的节点，判断历史数据
      storage::View view = storage::View::OLD;
      auto expand_vertex=dba.FindVertex(expand_vid, view);
      // VertexAccessor expand_vertex;
      if(!expand_vertex) break;
      //还原边 只需要还原kv中被删除的边即可
      std::string tmp(edge_id);
      auto gid=(uint64_t)std::stoi(tmp);
      auto current_edge1=storage::HistoryEdge(dba.IdToGid(gid),from_gid,to_gid,edge_type,nullptr);//hjm edit new 
      bool history_flag=false;
      auto before_flag=dba.FindHistoryEdgeFlag(gid,ts,te);
      auto edge_vector=dba.FindHistoryEdge(gid,ts,te);
    }
  }
}

void edgeHistory2(storage::Storage::Accessor &dba, storage::VertexAccessor &vertex, std::vector<storage::EdgeTypeId>& edge_types, storage::LabelId &to_label, std::vector<storage::EdgeTypeId> &edge_types_2, storage::LabelId &to_label_2, uint ts, uint te, std::string &types){
    // 查找目标节点连接的边
  auto edges = vertex.InEdges(storage::View::OLD, edge_types);
  if(edges->begin() == edges->end()){
    std::cout<<"edge: null"<<std::endl;
  }else{
    for(auto edge : *edges){
      auto et_id = edge.EdgeType();
      auto from_gid = edge.fromGid();
      auto to_gid = edge.toGid();
      auto e_gid = edge.Gid();
      std::cout<<"edge type : "<<dba.EdgeTypeToName(et_id)<<std::endl;

      // 查找边的历史
      auto [gid_edge_deltas_,flag]=dba.GetHistoryDelta()->GetEdgeInfo(ts,te,types,e_gid.AsUint());
      std::cout<<"edge_flag:"<<flag<<"\n";
      for(auto gid_delta_:gid_edge_deltas_){
        std::cout<<gid_delta_.dump()<<"\n";
      }

      if(!flag){
        edgeNow(dba, edge);
      }
      auto vertex = dba.FindVertex(from_gid, storage::View::OLD);
      if(!vertex) break;
      bool v_flag = vertexHistory(dba, from_gid, ts, te, types);
      if(!v_flag){
        //FindVertex(Gid gid, View view);
        if(vertex){
          auto to_node = *vertex;
          uint64_t obj_ts = to_node.transaction_st();
          uint64_t obj_te = to_node.tt_te();
          if(obj_ts >= te){
            vertexNow(dba, to_node);
          }else{
            std::cout<<"to node not needed!"<<std::endl;
            continue;
          }
        }else{
            std::cout<<"to node not found!"<<std::endl;
            continue;
        }
      }
      edgeHistory(dba, *vertex, edge_types_2, to_label_2, ts, te, types);
      delEdge(dba, from_gid, edge_types_2, ts, te, types);
    }
  }
}



void vertexEdgeHistory(storage::Storage::Accessor &dba, storage::LabelId &label_id, storage::PropertyId &property_id, int &property_value, std::vector<storage::EdgeTypeId>& edge_types, storage::LabelId &to_label, uint ts, uint te, std::string &types){
  auto vertex_it= dba.Vertices(label_id, property_id, storage::PropertyValue(property_value), storage::View::OLD);
  for(auto vertex : vertex_it){
    // 查找节点的历史
    auto gid = vertex.Gid();
    bool flag = vertexHistory(dba, gid, ts, te, types);
    if(!flag){
      uint64_t obj_ts = vertex.transaction_st();
      uint64_t obj_te = vertex.tt_te();
      if(obj_ts >= te || obj_ts < te){
        vertexNow(dba, vertex);
      }else{
        std::cout<<"node not found!"<<std::endl;
        return;
      }
    }
    edgeHistory(dba, vertex, edge_types, to_label, ts, te, types);
    delEdge(dba, gid, edge_types, ts, te, types);
  }

}

void IS7(storage::Storage::Accessor &dba, std::string &label_name, std::string &property_name, std::string &property_value, std::vector<storage::EdgeTypeId> &edge_types, std::string &to_label, std::vector<storage::EdgeTypeId> &edge_types_2, std::string &to_label_2, uint ts, uint te){
  auto start = std::chrono::steady_clock::now();
  std::string types = ts == te ? "as of" : "from to";
  storage::LabelId label_id=dba.NameToLabel(label_name);
  std::cout<<label_name<<" label id:"<<label_id.AsUint()<<"\n";
  storage::PropertyId property_id=dba.NameToProperty(property_name);
  std::cout<<property_name<<" property id:"<<property_id.AsUint()<<"\n";
  storage::LabelId tolabel_id=dba.NameToLabel(to_label);
  std::cout<<to_label<<" label id:"<<tolabel_id.AsUint()<<"\n";
  storage::LabelId tolabel_id_2=dba.NameToLabel(to_label_2);
  std::cout<<to_label_2<<" label id:"<<tolabel_id.AsUint()<<"\n";

  auto vertex_it= dba.Vertices(label_id, property_id, storage::PropertyValue(property_value), storage::View::OLD);
  for(auto vertex : vertex_it){
    // 查找节点的历史
    auto gid = vertex.Gid();
    bool flag = vertexHistory(dba, gid, ts, te, types);
    if(!flag){
      uint64_t obj_ts = vertex.transaction_st();
      uint64_t obj_te = vertex.tt_te();
      if(obj_ts >= te){
        vertexNow(dba, vertex);
        flag = true;
      }else{
        std::cout<<"node not found!"<<std::endl;
      }
    }
    if(flag) edgeHistory2(dba, vertex, edge_types, tolabel_id, edge_types_2, tolabel_id_2, ts, te, types);
    if(flag) delEdge(dba, gid, edge_types, ts, te, types);
  }
  auto end = std::chrono::steady_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count();
  // avg_duration += duration;
  avg_duration.push_back(duration);
  std::cout<<"running time: "<<duration<<"ms"<<std::endl;
}


void RuntestPath(storage::Storage::Accessor &dba, std::string &label_name, std::string &property_name, int &property_value, std::vector<storage::EdgeTypeId> &edge_types, std::string &to_label, uint ts, uint te){
  auto start = std::chrono::steady_clock::now();
  std::string types = ts == te ? "as of" : "from to";
  storage::LabelId label_id=dba.NameToLabel(label_name);
  std::cout<<label_name<<" label id:"<<label_id.AsUint()<<"\n";
  storage::PropertyId property_id=dba.NameToProperty(property_name);
  std::cout<<property_name<<" property id:"<<property_id.AsUint()<<"\n";
  storage::LabelId tolabel_id=dba.NameToLabel(to_label);
  std::cout<<to_label<<" label id:"<<tolabel_id.AsUint()<<"\n";
  vertexEdgeHistory(dba, label_id, property_id, property_value, edge_types, tolabel_id, ts, te, types);
  auto end = std::chrono::steady_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count();
  // avg_duration += duration;
  avg_duration.push_back(duration);
  std::cout<<"running time: "<<duration<<"ms"<<std::endl;
}

void RuntestPoint(storage::Storage::Accessor &dba, std::string &label_name, std::string &property_name, int &property_value, uint ts, uint te){
  auto start = std::chrono::steady_clock::now();
  std::string types = ts == te ? "as of" : "from to";
  storage::LabelId label_id=dba.NameToLabel(label_name);
  std::cout<<label_name<<" label id:"<<label_id.AsUint()<<"\n";
  storage::PropertyId property_id=dba.NameToProperty(property_name);
  std::cout<<property_name<<" property id:"<<property_id.AsUint()<<"\n";
  auto vertex_it= dba.Vertices(label_id, property_id, storage::PropertyValue(property_value), storage::View::OLD);
  // uint64_t obj_ts = (*vertex_it.begin()).transaction_st();
  // uint64_t obj_te = (*vertex_it.begin()).tt_te();
  for(auto vertex : vertex_it){
    // std::cout<<"here!"<<std::endl;
    auto gid = vertex.Gid();
    bool flag = vertexHistory(dba, gid, ts, te, types);
    if(!flag){
      uint64_t obj_ts = vertex.transaction_st();
      uint64_t obj_te = vertex.tt_te();
      if(obj_ts >= te){
        vertexNow(dba, vertex);
      }else{
        std::cout<<"node not found!"<<std::endl;
      }
      
    }
  }

  auto end = std::chrono::steady_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count();
  // avg_duration += duration;
  avg_duration.push_back(duration);
  std::cout<<"running time: "<<duration<<"ms"<<std::endl;
}

int main(int argc, char *argv[]) {

  gflags::SetUsageMessage("Create a Memgraph test direct to the db!.");
  gflags::SetVersionString(version_string);

  std::vector<double> result;
  std::vector<int> avgRatio = {1, 10, 100, 1000};
  for(auto r : avgRatio){
    auto dataDir = "/data/hjm/0_pokec/update_frequency/small/tgdb/update_num10000_avg" + std::to_string(r)+ "/memgraph"
    storage::Storage store{{
      .items = {.properties_on_edges = FLAGS_storage_properties_on_edges},
      .durability = {.storage_directory = dataDir,
                      .recover_on_startup = true,
                      .snapshot_wal_mode = storage::Config::Durability::SnapshotWalMode::DISABLED,
                      .snapshot_on_exit = false},
    }};

    auto dba = store.Access();

    //vertex信息
    std::string label_name="User"; //PERSON->52
    // storage::LabelId label_id=dba.NameToLabel(label_name);
    std::string property_name="id"; //id->28


    std::vector<storage::EdgeTypeId> edge_types;
    edge_types.emplace_back(dba.NameToEdgeType("Friend"));

    std::vector<int> ids_s;
    std::vector<uint64_t> ts_s;
    std::vector<uint64_t> te_e;
    std::string path = "/home/hjm/memgraph/tests/mgbench/prepare_pock/benchmark/update_frequency/csv/Q1_TGDB_asof_update_small_Num10000_Avg"+ std::to_string(r) +"_R1.txt";
    getSearchCtx(path, ids_s, ts_s, te_e);

    double avg_d = 0.0;

    RuntestPoint(dba, label_name, property_name, ids_s[0], ts_s[0], te_e[0]);
    avg_duration.clear();
    for(int i = 0; i < ids_s.size(); ++i){
      std::cout<<ids_s[i]<<std::endl;
      // RuntestPath(dba, label_name, property_name, ids_s[i], edge_types, label_name, ts_s[i], te_e[i]);
      RuntestPoint(dba, label_name, property_name, ids_s[i], ts_s[i], te_e[i]);
    }
    for(auto d : avg_duration){
      avg_d += d;
      std::cout<<d<<std::endl;
    }
    result.push_back(avg_d / ids_s.size());

    ids_s.clear();
    ts_s.clear();
    te_e.clear();
    path = "/home/hjm/memgraph/tests/mgbench/prepare_pock/benchmark/update_frequency/csv/Q2_TGDB_asof_update_small_Num10000_Avg"+ std::to_string(r) +"_R1.txt";
    getSearchCtx(path, ids_s, ts_s, te_e);

    avg_d = 0.0;

    RuntestPath(dba, label_name, property_name, ids_s[0], edge_types, label_name, ts_s[0], te_e[0]);
    avg_duration.clear();
    for(int i = 0; i < ids_s.size(); ++i){
      std::cout<<ids_s[i]<<std::endl;
      RuntestPath(dba, label_name, property_name, ids_s[i], edge_types, label_name, ts_s[i], te_e[i]);
      // RuntestPoint(dba, label_name, property_name, ids_s[i], ts_s[i], te_e[i]);
    }
    for(auto d : avg_duration){
      avg_d += d;
      std::cout<<d<<std::endl;
    }
    result.push_back(avg_d / ids_s.size());

  }

  for(auto res : result){
    std::cout<<res<<std::endl;
  }

  // storage::Storage store{{
  //     .items = {.properties_on_edges = FLAGS_storage_properties_on_edges},
  //     .durability = {.storage_directory = FLAGS_data_directory,
  //                     .recover_on_startup = true,
  //                     .snapshot_wal_mode = storage::Config::Durability::SnapshotWalMode::DISABLED,
  //                     .snapshot_on_exit = false},
  // }};

  // auto dba = store.Access();
  
  
  // //vertex信息
  // std::string label_name="User"; //PERSON->52
  // // storage::LabelId label_id=dba.NameToLabel(label_name);
  // std::string property_name="id"; //id->28


  // std::vector<storage::EdgeTypeId> edge_types;
  // edge_types.emplace_back(dba.NameToEdgeType("Friend"));

  // std::vector<int> ids_s;
  // std::vector<uint64_t> ts_s;
  // std::vector<uint64_t> te_e;
  // std::string path = "/home/hjm/memgraph/tests/mgbench/prepare_pock/benchmark/update_frequency/csv/Q1_TGDB_asof_update_small_Num10000_Avg1000_R1.txt";
  // getSearchCtx(path, ids_s, ts_s, te_e);

  // double avg_d = 0.0;

  // RuntestPoint(dba, label_name, property_name, ids_s[0], ts_s[0], te_e[0]);
  // // RuntestPath(dba, label_name, property_name, ids_s[0], edge_types, label_name, ts_s[0], te_e[0]);
  // avg_duration.pop_back();
  // for(int i = 0; i < ids_s.size(); ++i){
  //   std::cout<<ids_s[i]<<std::endl;
  //   RuntestPath(dba, label_name, property_name, ids_s[i], edge_types, label_name, ts_s[i], te_e[i]);
  //   // RuntestPoint(dba, label_name, property_name, ids_s[i], ts_s[i], te_e[i]);
  // }
  // for(auto d : avg_duration){
  //   avg_d += d;
  //   std::cout<<d<<std::endl;
  // }

  // std::cout<<"Q1 type-from avg100_num100000 duration: "<<avg_d / ids_s.size()<<std::endl<<std::endl;

  return 0;
}
