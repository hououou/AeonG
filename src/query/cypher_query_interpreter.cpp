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

#include "query/cypher_query_interpreter.hpp"
#include <iostream>
#include <string>

// NOLINTNEXTLINE (cppcoreguidelines-avoid-non-const-global-variables)
DEFINE_HIDDEN_bool(query_cost_planner, true, "Use the cost-estimating query planner.");
// NOLINTNEXTLINE (cppcoreguidelines-avoid-non-const-global-variables)
DEFINE_VALIDATED_int32(query_plan_cache_ttl, 60, "Time to live for cached query plans, in seconds.",
                       FLAG_IN_RANGE(0, std::numeric_limits<int32_t>::max()));

namespace query {
CachedPlan::CachedPlan(std::unique_ptr<LogicalPlan> plan) : plan_(std::move(plan)) {}

ParsedQuery ParseQuery(const std::string &query_string, const std::map<std::string, storage::PropertyValue> &params,
                       utils::SkipList<QueryCacheEntry> *cache, utils::SpinLock *antlr_lock,
                       const InterpreterConfig::Query &query_config) {
  // Strip the query for caching purposes. The process of stripping a query
  // "normalizes" it by replacing any literals with new parameters. This
  // results in just the *structure* of the query being taken into account for
  // caching.

  //wzy edit
  // std::cout<<"ParseQuery::34"<<std::endl;
  // std::string target_string = "FOR TT AS OF TIMESTAMP";
  // auto idx = query_string.find(target_string);
  // std::string query_string_test;
  // std::string query_string_addition;
  // std::string query_string_addition_l;
  // std::string query_string_addition_r;
  // if(idx != std::string::npos){
  //   query_string_test = query_string.substr(0, idx);
  //   query_string_addition = query_string.substr(idx, query_string.size()-idx);
  //   // std::cout<<"cypher_query_i::45: "<<query_string_addition<<std::endl;
  //   // std::cout<<query_string_test<<std::endl;
  //   // stripped_query{query_string_test};
  //   auto idx_from = query_string_addition.find("FROM");
  //   auto idx_to = query_string_addition.find("TO");
  //   if(idx_from != std::string::npos){
  //     int ft_len = idx_to - idx_from - 6;
  //     query_string_addition_l = query_string_addition.substr(idx_from + 5, ft_len);
  //     query_string_addition_r = query_string_addition.substr(idx_to + 3);
  //   }else{
  //     int idx_space = query_string_addition.find_last_of(" ");
  //     int len = query_string_addition.length();
  //     query_string_addition_l = query_string_addition.substr(idx_space + 1);
  //     query_string_addition_r = query_string_addition_l;
  //   }
    
  //   // std::cout<<"cypher_query_i::59_addi: "<<query_string_addition<<std::endl;
  //   // std::cout<<"cypher_query_i::60_left: "<<query_string_addition_l<<std::endl;
  //   // std::cout<<"cypher_query_i::61_right: "<<query_string_addition_r<<std::endl;
  // }else{
  //   query_string_test = query_string;
  //   // stripped_query{query_string};
  // }
  // frontend::StrippedQuery stripped_query{query_string_test};
  // if(idx != std::string::npos){
  //   stripped_query.addAddition(query_string_addition_l);
  //   stripped_query.addAddition_r(query_string_addition_r);
  // } 
  // frontend::StrippedQuery stripped_query{query_string};
  
  //wzy edit
  frontend::StrippedQuery stripped_query{query_string};
  // Copy over the parameters that were introduced during stripping.
  Parameters parameters{stripped_query.literals()};
   
  
  // Check that all user-specified parameters are provided.
  for (const auto &param_pair : stripped_query.parameters()) {
    auto it = params.find(param_pair.second);

    if (it == params.end()) {
      throw query::UnprovidedParameterError("Parameter ${} not provided.", param_pair.second);
    }

    parameters.Add(param_pair.first, it->second);
  }

  // Cache the query's AST if it isn't already.
  auto hash = stripped_query.hash();
  auto accessor = cache->access();
  auto it = accessor.find(hash);
  std::unique_ptr<frontend::opencypher::Parser> parser;

  // Return a copy of both the AST storage and the query.
  CachedQuery result;
  bool is_cacheable = true;

  auto get_information_from_cache = [&](const auto &cached_query) {
    result.ast_storage.properties_ = cached_query.ast_storage.properties_;
    result.ast_storage.labels_ = cached_query.ast_storage.labels_;
    result.ast_storage.edge_types_ = cached_query.ast_storage.edge_types_;

    result.query = cached_query.query->Clone(&result.ast_storage);
    result.required_privileges = cached_query.required_privileges;
  };

  if (it == accessor.end()) {
    {
      std::unique_lock<utils::SpinLock> guard(*antlr_lock);

      try {
        parser = std::make_unique<frontend::opencypher::Parser>(stripped_query.query());
      } catch (const SyntaxException &e) {
        // There is a syntax exception in the stripped query. Re-run the parser
        // on the original query to get an appropriate error messsage.
        parser = std::make_unique<frontend::opencypher::Parser>(query_string);

        // If an exception was not thrown here, the stripper messed something
        // up.
        LOG_FATAL("The stripped query can't be parsed, but the original can.");
      }
    }

    // Convert the ANTLR4 parse tree into an AST.
    AstStorage ast_storage;
    frontend::ParsingContext context{true};
    frontend::CypherMainVisitor visitor(context, &ast_storage);

    visitor.visit(parser->tree());
    
    if (visitor.GetQueryInfo().has_load_csv && !query_config.allow_load_csv) {
      throw utils::BasicException("Load CSV not allowed on this instance because it was disabled by a config.");
    }

    if (visitor.GetQueryInfo().is_cacheable) {
      CachedQuery cached_query{std::move(ast_storage), visitor.query(), query::GetRequiredPrivileges(visitor.query())};
      it = accessor.insert({hash, std::move(cached_query)}).first;

      get_information_from_cache(it->second);
    } else {
      result.ast_storage.properties_ = ast_storage.properties_;
      result.ast_storage.labels_ = ast_storage.labels_;
      result.ast_storage.edge_types_ = ast_storage.edge_types_;

      result.query = visitor.query()->Clone(&result.ast_storage);
      result.required_privileges = query::GetRequiredPrivileges(visitor.query());

      is_cacheable = false;
    }
  } else {
    get_information_from_cache(it->second);
  }
  //wzy edit query_string->query_string_test
  return ParsedQuery{query_string,
                     params,
                     std::move(parameters),
                     std::move(stripped_query),
                     std::move(result.ast_storage),
                     result.query,
                     std::move(result.required_privileges),
                     is_cacheable};
}

// TypedValue LiteralValue(Expression *expression) {
//   if (context_.is_query_cached) {
//     auto *param_lookup = dynamic_cast<ParameterLookup *>(expression);
//     return TypedValue(parameters_.AtTokenPosition(param_lookup->token_position_));
//   } else {
//     auto *literal = dynamic_cast<PrimitiveLiteral*>(expression);
//     return TypedValue(literal->value_);
//   }
// }

std::unique_ptr<LogicalPlan> MakeLogicalPlan(AstStorage ast_storage, CypherQuery *query, const Parameters &parameters,
                                             DbAccessor *db_accessor,
                                             const std::vector<Identifier *> &predefined_identifiers) {
  auto vertex_counts = plan::MakeVertexCountCache(db_accessor);
  auto symbol_table = MakeSymbolTable(query, predefined_identifiers);
  auto planning_context = plan::MakePlanningContext(&ast_storage, &symbol_table, query, &vertex_counts);
  auto [root, cost] = plan::MakeLogicalPlan(&planning_context, parameters, FLAGS_query_cost_planner);
  //hjm begin
  auto history_info=planning_context.history_info_;
  //hjm end
  return std::make_unique<SingleNodeLogicalPlan>(std::move(root), cost, std::move(ast_storage),
                                                 std::move(symbol_table),history_info);
}

std::shared_ptr<CachedPlan> CypherQueryToPlan(uint64_t hash, AstStorage ast_storage, CypherQuery *query,
                                              const Parameters &parameters, utils::SkipList<PlanCacheEntry> *plan_cache,
                                              DbAccessor *db_accessor,
                                              const std::vector<Identifier *> &predefined_identifiers) {
  std::optional<utils::SkipList<PlanCacheEntry>::Accessor> plan_cache_access;
  if (plan_cache) {
    plan_cache_access.emplace(plan_cache->access());
    auto it = plan_cache_access->find(hash);
    if (it != plan_cache_access->end()) {
      if (it->second->IsExpired()) {
        plan_cache_access->remove(hash);
      } else {
        return it->second;
      }
    }
  }

  auto plan = std::make_shared<CachedPlan>(
      MakeLogicalPlan(std::move(ast_storage), query, parameters, db_accessor, predefined_identifiers));
  if (plan_cache_access) {
    plan_cache_access->insert({hash, plan});
  }
  // auto history_infos=plan->getHistoryInfo();
  // if(history_infos){
  //   std::cout<<"123456789 history_infos:"<<history_infos->first<<"\n";
  // }
  return plan;
}
}  // namespace query
