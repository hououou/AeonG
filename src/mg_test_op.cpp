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
DEFINE_string(data_directory, "/data/hjm/datasets/tgdb_dataset/scale1_small_avg1000/memgraph", "Path to directory in which to save all permanent data.");
DEFINE_bool(storage_properties_on_edges, true, "Controls whether relationships have properties.");//hjm begin

// IS1:: MATCH (n:Person {id:"32985348838034"})-[:IS_LOCATED_IN]->(p:Place) TT AS 44419347
// IS3:: MATCH (n:Person {id:"24189255819196"})-[r:KNOWS]-(friend)
// IS4:: MATCH (m:Message {id:"1236954879921"})
// IS5:: MATCH(m:Message {id:"687194996911"})-[:HAS_CREATOR]->(p:Person)
// IS7:: MATCH (m:Message {id:"687197816725"})<-[:REPLY_OF]-(c:Comment)-[:HAS_CREATOR]->(p:Person)
// enum class Direction { IN, OUT, BOTH };

double avg_duration = 0.0;

bool check_edges(std::vector<storage::EdgeTypeId> edge_types,storage::EdgeTypeId type){
  bool flag=false;
  if(edge_types.size()!=0){
    auto it = std::find(edge_types.begin(), edge_types.end(), type);
    if (it != edge_types.end())flag=true;
  }else flag=true;
  return flag;
}

void vertexHistory(storage::Storage::Accessor &dba, storage::Gid &gid, uint ts, uint te, std::string &types){
  auto vertex_find=dba.FindHistoryVertex(gid.AsUint(),ts,te);
  auto [gid_history_deltas_,flag]=dba.GetHistoryDelta()->GetVertexInfo(gid,ts,te,types);
  //中间可能会输出delta_prefix:-43821725 VD:1177119:
  std::cout<<"vertex_flag:"<<flag<<"\n";
  for(auto gid_delta_:gid_history_deltas_){
    std::cout<<gid_delta_.dump()<<"\n";
  }
}

void edgeHistory(storage::Storage::Accessor &dba, storage::VertexAccessor &vertex, std::vector<storage::EdgeTypeId>& edge_types, storage::LabelId &to_label, uint ts, uint te, std::string &types){
    // 查找目标节点连接的边
  auto edges = vertex.OutEdges(storage::View::OLD, edge_types);
  if(edges->begin() == edges->end()){
    std::cout<<"edge: null"<<std::endl;
  }else{
    for(auto edge : *edges){
      auto et_id = edge.EdgeType();
      auto from_gid = edge.fromGid();
      auto to_gid = edge.toGid();
      auto e_gid = edge.Gid();
      std::cout<<"edge type : "<<dba.EdgeTypeToName(et_id)<<std::endl;

      auto props = *edge.Properties(storage::View::OLD);
      if(props.begin() == props.end()){
        std::cout<<"prop: null"<<std::endl;
      }else{
        for(auto prop : props){
          if(prop.second.IsString()){
            std::cout<<"property value : "<<prop.second.ValueString()<<std::endl;
          }else if(prop.second.IsInt()){
            std::cout<<"property value : "<<prop.second.ValueInt()<<std::endl;
          }else if(prop.second.IsDouble()){
            std::cout<<"property value : "<<prop.second.ValueDouble()<<std::endl;
          }
        }
      }
      // 查找边的历史
      auto [gid_edge_deltas_,flag]=dba.GetHistoryDelta()->GetEdgeInfo(ts,te,types,e_gid.AsUint());
      std::cout<<"edge_flag:"<<flag<<"\n";
      for(auto gid_delta_:gid_edge_deltas_){
        std::cout<<gid_delta_.dump()<<"\n";
      }

      vertexHistory(dba, to_gid, ts, te, types);
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

      auto props = *edge.Properties(storage::View::OLD);
      if(props.begin() == props.end()){
        std::cout<<"prop: null"<<std::endl;
      }else{
        for(auto prop : props){
          if(prop.second.IsString()){
            std::cout<<"property value : "<<prop.second.ValueString()<<std::endl;
          }else if(prop.second.IsInt()){
            std::cout<<"property value : "<<prop.second.ValueInt()<<std::endl;
          }else if(prop.second.IsDouble()){
            std::cout<<"property value : "<<prop.second.ValueDouble()<<std::endl;
          }
        }
      }
      // 查找边的历史
      auto [gid_edge_deltas_,flag]=dba.GetHistoryDelta()->GetEdgeInfo(ts,te,types,e_gid.AsUint());
      std::cout<<"edge_flag:"<<flag<<"\n";
      for(auto gid_delta_:gid_edge_deltas_){
        std::cout<<gid_delta_.dump()<<"\n";
      }

      auto vertex = dba.FindVertex(from_gid, storage::View::OLD);
      if(!vertex) break;
      vertexHistory(dba, from_gid, ts, te, types);
      edgeHistory(dba, *vertex, edge_types_2, to_label_2, ts, te, types);
      delEdge(dba, from_gid, edge_types_2, ts, te, types);
    }
  }
}



void vertexEdgeHistory(storage::Storage::Accessor &dba, storage::LabelId &label_id, storage::PropertyId &property_id, std::string &property_value, std::vector<storage::EdgeTypeId>& edge_types, storage::LabelId &to_label, uint ts, uint te, std::string &types){
  auto vertex_it= dba.Vertices(label_id, property_id, storage::PropertyValue(property_value), storage::View::OLD);
  for(auto vertex : vertex_it){
    // 查找节点的历史
    auto gid = vertex.Gid();
    vertexHistory(dba, gid, ts, te, types);
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
    vertexHistory(dba, gid, ts, te, types);
    edgeHistory2(dba, vertex, edge_types, tolabel_id, edge_types_2, tolabel_id_2, ts, te, types);
    delEdge(dba, gid, edge_types, ts, te, types);
  }
  auto end = std::chrono::steady_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count();
  avg_duration += duration;
  std::cout<<"running time: "<<duration<<"ms"<<std::endl;
}


void RuntestPath(storage::Storage::Accessor &dba, std::string &label_name, std::string &property_name, std::string &property_value, std::vector<storage::EdgeTypeId> &edge_types, std::string &to_label, uint ts, uint te){
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
  avg_duration += duration;
  std::cout<<"running time: "<<duration<<"ms"<<std::endl;
}

void RuntestPoint(storage::Storage::Accessor &dba, std::string &label_name, std::string &property_name, std::string &property_value, uint ts, uint te){
  auto start = std::chrono::steady_clock::now();
  std::string types = ts == te ? "as of" : "from to";
  storage::LabelId label_id=dba.NameToLabel(label_name);
  std::cout<<label_name<<" label id:"<<label_id.AsUint()<<"\n";
  storage::PropertyId property_id=dba.NameToProperty(property_name);
  std::cout<<property_name<<" property id:"<<property_id.AsUint()<<"\n";
  auto vertex_it= dba.Vertices(label_id, property_id, storage::PropertyValue(property_value), storage::View::OLD);
  for(auto vertex : vertex_it){
    auto gid = vertex.Gid();
    vertexHistory(dba, gid, ts, te, types);
  }
  auto end = std::chrono::steady_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count();
  avg_duration += duration;
  std::cout<<"running time: "<<duration<<"ms"<<std::endl;
}

int main(int argc, char *argv[]) {

  gflags::SetUsageMessage("Create a Memgraph test direct to the db!.");
  gflags::SetVersionString(version_string);

  storage::Storage store{{
      .items = {.properties_on_edges = FLAGS_storage_properties_on_edges},
      .durability = {.storage_directory = FLAGS_data_directory,
                      .recover_on_startup = true,
                      .snapshot_wal_mode = storage::Config::Durability::SnapshotWalMode::DISABLED,
                      .snapshot_on_exit = false},
  }};

  auto dba = store.Access();
  
  uint ts=41802046;
  uint te=41802046;
  
  
  //vertex信息
  std::string label_name="Message"; //PERSON->52
  std::string label_name_1="Comment";
  std::string label_name_2="Person";
  // storage::LabelId label_id=dba.NameToLabel(label_name);
  std::string property_name="id"; //id->28
  // std::string property_value="687194996911";
  // storage::PropertyValue property_;
  //edge信息
  // std::string edge_type = "HAS_CREATOR";
  // std::string edge_type_3 = "KNOWS";
  // std::string edge_type_1 = "IS_LOCATED_IN";
  // std::string to_label = "Person";
  // IS5 IS7
  // std::vector<std::string> ids = {"1786706539107", "4360764", "824638288448", "1236953299574", "1374395960097", 
  //                                 "962073024361", "412317236982", "274878318466", "1924149807325", "412316940061"
  //                                 };
  // std::vector<uint> times = {42124583,43612247,41625497,43131320,43593295,42836297,43841714,42653244,41816209,41867530};
  
  //IS3
  // std::vector<std::string> ids_3 = {"32985348843938", "10995116284543", "94", "32985348837457", "19791209301329", 
  //                                 "21990232565037", "10995116279887", "24189255820980", "8796093028403", "10995116284178"
  //                                 };
  // std::vector<uint> times_3 = {41232025,44049810,43155445,43781785,41150958,43076647,43054592,43288370,42397542,42845786};
  
  //IS1
  // std::vector<std::string> ids_1 = {"32985348843938", "10995116284543", "94", "32985348837457", "19791209301329", 
  //                                 "21990232565037", "10995116279887", "24189255820980", "8796093028403", "10995116284178"
  //                                 };
  // std::vector<uint> times_1 = {41232025,44049810,43155445,43781785,41150958,43076647,43054592,43288370,42397542,42845786};


  //IS7
  std::vector<std::string> ids_7 = {"824633799534", "1786706539101", "1099512182279", "1786707316142", "2061586453270", 
                                  "1374392059492", "1374392316399", "1511832798960", "1374394436196", "412321979326"
                                  };
  std::vector<uint> times_7 = {43209218,42645605,41042629,43827680,42499383,40979557,44039788,42266437,43095698,42537126};
  
  // std::string property_name="id";

//avg10
// std::vector<std::string> oids = {"19791209307908","4398046512267","17592186053582","9598","2061588776821","1924145605529","962077537134","1649267902051","1649267589637","1374390490622"};
// std::vector<std::string> labels = {"Person","Person","Person","Person","Comment","Comment","Comment","Post","Post","Post"};
// std::vector<uint> time_s = {5957,3379,5067,5389,1135,125,1325,9021,8965,9111};

//avg100
  // std::vector<std::string> oids = {"4398046519372","17592186047761","19791209310654","32985348842647","412319744321","687194994910","962077537134","824636732727","412317130345","1649267496872"};
  // std::vector<std::string> labels = {"Person","Person","Person","Person","Comment","Comment","Comment","Post","Post","Post"};
  // std::vector<uint> time_s = {5095,3241,5973,4453,871,103,1325,9293,8987,8945};

//avg1000
  // std::vector<std::string> oids = {"8796093031388","7480","10995116280436","15393162794654","1374390339053","1924149696580","2061588776821","687199027292","1649271897519","824636648879"};
  // std::vector<std::string> labels = {"Person","Person","Person","Person","Comment","Comment","Comment","Post","Post","Post"};
  // std::vector<uint> time_s = {4427,5755,3235,4207,379,1077,1135,9331,9363,9279};
  uint time_e = 2000000;
  uint time_st = 0;
  // auto start = std::chrono::steady_clock::now();
  // storage::EdgeTypeId ET_ID= dba.NameToEdgeType(edge_type);
  std::vector<storage::EdgeTypeId> edge_types;
  edge_types.emplace_back(dba.NameToEdgeType("REPLY_OF"));
  // edge_types.emplace_back(ET_ID);

  std::vector<storage::EdgeTypeId> edge_types_2;
  edge_types_2.emplace_back(dba.NameToEdgeType("HAS_CREATOR"));

  // avg_duration = 0.0;
  // edge_types.clear();
  // edge_types.emplace_back(dba.NameToEdgeType(edge_type_3));
  // for(int i = 0; i < 10; ++i){
    // RuntestPath(dba, label_name, property_name, ids_3[i], edge_types, to_label, times_3[i], times_3[i]);
    // RuntestPoint(dba, labels[i], property_name, oids[i], time_s[i], time_e);
    // IS7(dba, label_name, property_name, ids_7[i]);
  // }
  // std::cout<<"Avg_10 Point avg duration: "<<avg_duration / 10<<std::endl<<std::endl;

  // avg_duration = 0.0;
  // edge_types.clear();
  // edge_types.emplace_back(dba.NameToEdgeType(edge_type_1));
  // for(int i = 0; i < 10; ++i){
  //   RuntestPath(dba, label_name, property_name, ids_1[i], edge_types, to_label, times_1[i], times_1[i]);
  // }
  // std::cout<<"IS1 Path avg duration: "<<avg_duration / 10<<std::endl;
  //historical data
  avg_duration = 0.0;
  for(int i = 0; i < 10; ++i){
    IS7(dba, label_name, property_name, ids_7[i], edge_types, label_name_1, edge_types_2, label_name_2, time_st, time_e);
  }
  std::cout<<"IS7 Path avg1000 duration: "<<avg_duration / 10<<std::endl<<std::endl;
  


  // auto end = std::chrono::steady_clock::now();
  // auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count();

  // std::cout<<"running time: "<<duration<<"ms"<<std::endl;

  // The snapshot will be created in the storage destructor.

  return 0;
}
