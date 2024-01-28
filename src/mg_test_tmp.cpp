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

#include "helpers.hpp"
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
DEFINE_string(data_directory, "memgrapht_t_delta100/memgraph", "Path to directory in which to save all permanent data.");
DEFINE_bool(storage_properties_on_edges, true, "Controls whether relationships have properties.");//hjm begin


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
  int vertices_num_check = 0;
  // for(int i = 0; i < 5; ++i){
  //   auto vertex_accessor = dba.CreateVertex();
  //   std::cout<<"create done!\n";
  // }
  // dba.AdvanceCommand();

  for(int i = 0; i < 52; ++i){
    std::string test = dba.LabelToName(storage::LabelId::FromUint(i));
    std::cout<<"label name "<<i<<": "<<test<<"\n";
  }

  for(int i = 0; i < 100; ++i){
    std::string prop = dba.PropertyToName(storage::PropertyId::FromUint(i));
    std::cout<<"prop name "<<i<<": "<<prop<<"\n";
  }

  std::string label_name="PERSON"; //PERSON->52
  storage::LabelId label_id=dba.NameToLabel(label_name);
  std::cout<<"label id:"<<label_id.AsUint()<<"\n";
  //storage::PropertyId NameToProperty(const std::string_view &name) { return accessor_->NameToProperty(name); }
  std::string property_name="id"; //id->28
  storage::PropertyId property_id=dba.NameToProperty(property_name);

  std::string property_value="0";
  storage::PropertyValue property_;

  // bool flag = store.CreateIndex(label_id, property_id);
  // dba.AdvanceCommand();

  // if(flag){
  //   std::cout<<"true:"<<"\n";
  // }

  //index scan is1
  //storage.hpp
  auto vertex_it= dba.Vertices(label_id, property_id, storage::PropertyValue(property_value), storage::View::OLD);
  for(auto vertex : vertex_it){
    //iterable 是一个vertexaccessor
    auto gid = vertex.Gid();
    // std::cout<<"person_gid:"<<gid.AsUint()<<"\n";
    
    uint ts=41802046;
    uint te=41802046;

    // 查找节点的历史
    auto vertex_find=dba.FindHistoryVertex(gid.AsUint(),ts,te);
    auto [gid_history_deltas_,flag]=dba.GetHistoryDelta()->GetVertexInfo(gid,ts,te,"as of");
    //中间可能会输出delta_prefix:-43821725 VD:1177119:
    std::cout<<"vertex_flag:"<<flag<<"\n";
    for(auto gid_delta_:gid_history_deltas_){
      std::cout<<gid_delta_.dump()<<"\n";
    }

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
            std::cout<<"property value : "<<prop.second.ValueString()<<std::endl;
          }
        }
        // 查找边的历史
        auto [gid_edge_deltas_,flag]=dba.GetHistoryDelta()->GetEdgeInfo(ts,te,"as of",e_gid.AsUint());
        std::cout<<"edge_flag:"<<flag<<"\n";
        for(auto gid_delta_:gid_edge_deltas_){
          std::cout<<gid_delta_.dump()<<"\n";
        }
      }
    }

  //historical data


  std::string edge_type = "HAS_TAG";
  storage::EdgeTypeId ET_ID= dba.NameToEdgeType(edge_type);
  std::vector<storage::EdgeTypeId> edge_types;
  edge_types.emplace_back(ET_ID);

  //extends
  //std::vector<std::tuple<storage::EdgeTypeId, storage::Vertex *, storage::EdgeRef>> getOutEdges
  //auto OutEdges(storage::View view, const std::vector<storage::EdgeTypeId> &edge_types)
  // auto edges = 

  // std::ofstream outFile;
  // outFile.open("idSet.txt");

  //GetDeleteEdgeInfo获取被删除的边的信息

  for (auto vertex : dba.Vertices(storage::View::OLD)) {
    vertices_num_check++;
    //current
    auto gid=vertex.Gid();
    // outFile<<gid.AsUint()<<std::endl;
    if(gid.AsUint()!=0) continue;
    // historical
    // auto edges = UnwrapEdgesResult(vertex.OutEdges(storage::View::OLD));
    auto edges = vertex.OutEdges(storage::View::OLD, edge_types);
    if(edges->begin() == edges->end()){
      std::cout<<"edge: null"<<std::endl;
    }
    for(auto edge : *edges){
      // auto etID = edge.edge_type_;
      auto from_gid = edge.fromGid();
      auto e_gid = edge.Gid();

      // std::string eName = dba.EdgeTypeToName(etID);
      std::cout<<"from vertex: "<<from_gid.AsUint()<<std::endl;
      std::cout<<"edge: "<<e_gid.AsUint()<<std::endl;
      // std::cout<<"type name: "<<eName<<std::endl;
    }
    uint ts=0;
    uint te=156789;
    auto vertex_find=dba.FindHistoryVertex(gid.AsUint(),ts,te);
    auto [gid_history_deltas_,flag]=dba.GetHistoryDelta()->GetVertexInfo(gid,ts,te,"from to");
    std::cout<<"flag:"<<flag<<"\n";
    for(auto gid_delta_:gid_history_deltas_){
      std::cout<<gid_delta_.dump()<<"\n";
    }
  }
  
  std::cout<<vertices_num_check<<std::endl;


// 查找历史数据中，节点在时间范围内被删掉的边
// addHistoryDeleteEdges
    // 获取kv中被删除的所有边 ve:
    auto deleted_edges_vec = dba.GetHistoryDelta()->GetDeleteEdgeInfo(ts,te,"as of",gid.AsUint());
    //还原kv中那些被删除的边
    for(auto &deleted_edges:deleted_edges_vec){
      for (auto it = deleted_edges.begin(); it != deleted_edges.end(); ++it) {
        auto edge_id = it.key();
        if(edge_id=="TT_TS" || edge_id=="TT_TE" ||edge_id=="Type"||edge_id=="Fid"||edge_id=="Tid") continue;
        auto edge_jsons=it.value();
        auto edge_type = dba.NameToEdgeType(edge_jsons["edgeType"].get<std::string_view>());
        auto ie_type=edge_jsons["Type"];
        auto from_gid=dba.IdToGid((uint64_t)edge_jsons["fromGid"]);
        auto to_gid=dba.IdToGid((uint64_t)edge_jsons["toGid"]);

        auto edge_ie_flag=direction == EdgeAtom::Direction::IN?ie_type=="AIE":ie_type=="AOE";//判断是否是需要的入边或者出边
        if(!edge_ie_flag)continue;
        if(!check_edges(edge_types,edge_type)) continue;//判断边的类型是否是需要的

        //加入数据库中的顶点
        auto expand_vid = direction==EdgeAtom::Direction::IN?from_gid:to_gid;//需要expand的节点，判断历史数据
        storage::View view = storage::View::OLD;
        auto expand_vertex=dba.FindVertex(expand_vid, view);
        // VertexAccessor expand_vertex;
        if(!expand_vertex)return;
        //还原边 只需要还原kv中被删除的边即可
        std::string tmp(edge_id);
        auto gid=(uint64_t)std::stoi(tmp);
        auto current_edge1=storage::HistoryEdge(dba.IdToGid(gid),from_gid,to_gid,edge_type,nullptr);//hjm edit new 
        bool history_flag=false;
        auto before_flag=dba.FindHistoryEdgeFlag(gid,historyContext_.c_ts,historyContext_.c_te);
        auto edge_vector=dba.FindHistoryEdge(gid,historyContext_.c_ts,historyContext_.c_te);
        if(before_flag){
          // std::cout<<"do not need get edge info\n";
          if(edge_vector){
            for(auto[edge,ts,te]:*edge_vector){
              auto edge1=*edge;
              pull_nodes_current_history(context,*expand_vertex, ts, te,TypedValue(edge1),history_add_,historyContext_);
              history_flag=true;
            }
          }
        }else{
          //delete info
          auto [gid_history_deltas_,flag]=dba.GetHistoryDelta()->GetEdgeInfo(historyContext_.c_ts,historyContext_.c_te,historyContext_.types,gid);
          if(!flag){//不能直接从kv中得到数据
            for(auto gid_delta_:gid_history_deltas_){
              current_edge1=dba.CreateHistoryEdgeFromKV(current_edge1,gid_delta_);
              pull_nodes_current_history(context,*expand_vertex, current_edge1.tt_ts, current_edge1.tt_te,TypedValue(current_edge1),history_add_,historyContext_);
              if(!history_add_.empty())dba.saveHistoryEdge(gid,historyContext_.c_ts,historyContext_.c_te,&current_edge1,current_edge1.tt_ts, current_edge1.tt_te);
            }
          }else{//可以直接从kv中恢复数据
            for(int i=0;i<gid_history_deltas_.size();i++){
              auto gid_delta_=gid_history_deltas_[i];
              current_edge1=dba.CreateHistoryEdgeFromKV(current_edge1,gid_delta_);
              pull_nodes_current_history(context,*expand_vertex, current_edge1.tt_ts, current_edge1.tt_te,TypedValue(current_edge1),history_add_,historyContext_);
              if(!history_add_.empty())dba.saveHistoryEdge(gid,historyContext_.c_ts,historyContext_.c_te,&current_edge1,current_edge1.tt_ts, current_edge1.tt_te);
            }
          }
        }
      }
    }


  // The snapshot will be created in the storage destructor.

  return 0;
}
