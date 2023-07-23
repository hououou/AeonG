
// Generated from /home/hjm/memgraph/src/query/frontend/opencypher/grammar/MemgraphCypher.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "MemgraphCypherVisitor.h"


namespace antlropencypher {

/**
 * This class provides an empty implementation of MemgraphCypherVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  MemgraphCypherBaseVisitor : public MemgraphCypherVisitor {
public:

  virtual antlrcpp::Any visitMemgraphCypherKeyword(MemgraphCypher::MemgraphCypherKeywordContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSymbolicName(MemgraphCypher::SymbolicNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuery(MemgraphCypher::QueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAuthQuery(MemgraphCypher::AuthQueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReplicationQuery(MemgraphCypher::ReplicationQueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTriggerQuery(MemgraphCypher::TriggerQueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClause(MemgraphCypher::ClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStreamQuery(MemgraphCypher::StreamQueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSettingQuery(MemgraphCypher::SettingQueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLoadCsv(MemgraphCypher::LoadCsvContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCsvFile(MemgraphCypher::CsvFileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDelimiter(MemgraphCypher::DelimiterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuote(MemgraphCypher::QuoteContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRowVar(MemgraphCypher::RowVarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUserOrRoleName(MemgraphCypher::UserOrRoleNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCreateRole(MemgraphCypher::CreateRoleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDropRole(MemgraphCypher::DropRoleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowRoles(MemgraphCypher::ShowRolesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCreateUser(MemgraphCypher::CreateUserContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSetPassword(MemgraphCypher::SetPasswordContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDropUser(MemgraphCypher::DropUserContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowUsers(MemgraphCypher::ShowUsersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSetRole(MemgraphCypher::SetRoleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClearRole(MemgraphCypher::ClearRoleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGrantPrivilege(MemgraphCypher::GrantPrivilegeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDenyPrivilege(MemgraphCypher::DenyPrivilegeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRevokePrivilege(MemgraphCypher::RevokePrivilegeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrivilege(MemgraphCypher::PrivilegeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrivilegeList(MemgraphCypher::PrivilegeListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowPrivileges(MemgraphCypher::ShowPrivilegesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowRoleForUser(MemgraphCypher::ShowRoleForUserContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowUsersForRole(MemgraphCypher::ShowUsersForRoleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDumpQuery(MemgraphCypher::DumpQueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSetReplicationRole(MemgraphCypher::SetReplicationRoleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowReplicationRole(MemgraphCypher::ShowReplicationRoleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReplicaName(MemgraphCypher::ReplicaNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSocketAddress(MemgraphCypher::SocketAddressContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRegisterReplica(MemgraphCypher::RegisterReplicaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDropReplica(MemgraphCypher::DropReplicaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowReplicas(MemgraphCypher::ShowReplicasContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLockPathQuery(MemgraphCypher::LockPathQueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFreeMemoryQuery(MemgraphCypher::FreeMemoryQueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTriggerName(MemgraphCypher::TriggerNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTriggerStatement(MemgraphCypher::TriggerStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEmptyVertex(MemgraphCypher::EmptyVertexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEmptyEdge(MemgraphCypher::EmptyEdgeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCreateTrigger(MemgraphCypher::CreateTriggerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDropTrigger(MemgraphCypher::DropTriggerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowTriggers(MemgraphCypher::ShowTriggersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIsolationLevel(MemgraphCypher::IsolationLevelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIsolationLevelScope(MemgraphCypher::IsolationLevelScopeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIsolationLevelQuery(MemgraphCypher::IsolationLevelQueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCreateSnapshotQuery(MemgraphCypher::CreateSnapshotQueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStreamName(MemgraphCypher::StreamNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSymbolicNameWithMinus(MemgraphCypher::SymbolicNameWithMinusContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSymbolicNameWithDotsAndMinus(MemgraphCypher::SymbolicNameWithDotsAndMinusContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSymbolicTopicNames(MemgraphCypher::SymbolicTopicNamesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTopicNames(MemgraphCypher::TopicNamesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCommonCreateStreamConfig(MemgraphCypher::CommonCreateStreamConfigContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCreateStream(MemgraphCypher::CreateStreamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConfigKeyValuePair(MemgraphCypher::ConfigKeyValuePairContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConfigMap(MemgraphCypher::ConfigMapContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitKafkaCreateStreamConfig(MemgraphCypher::KafkaCreateStreamConfigContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitKafkaCreateStream(MemgraphCypher::KafkaCreateStreamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPulsarCreateStreamConfig(MemgraphCypher::PulsarCreateStreamConfigContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPulsarCreateStream(MemgraphCypher::PulsarCreateStreamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDropStream(MemgraphCypher::DropStreamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStartStream(MemgraphCypher::StartStreamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStartAllStreams(MemgraphCypher::StartAllStreamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStopStream(MemgraphCypher::StopStreamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStopAllStreams(MemgraphCypher::StopAllStreamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowStreams(MemgraphCypher::ShowStreamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCheckStream(MemgraphCypher::CheckStreamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSettingName(MemgraphCypher::SettingNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSettingValue(MemgraphCypher::SettingValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSetSetting(MemgraphCypher::SetSettingContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowSetting(MemgraphCypher::ShowSettingContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowSettings(MemgraphCypher::ShowSettingsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVersionQuery(MemgraphCypher::VersionQueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSnapshotQuery(MemgraphCypher::SnapshotQueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCypher(MemgraphCypher::CypherContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(MemgraphCypher::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstraintQuery(MemgraphCypher::ConstraintQueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstraint(MemgraphCypher::ConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstraintPropertyList(MemgraphCypher::ConstraintPropertyListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStorageInfo(MemgraphCypher::StorageInfoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIndexInfo(MemgraphCypher::IndexInfoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstraintInfo(MemgraphCypher::ConstraintInfoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInfoQuery(MemgraphCypher::InfoQueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExplainQuery(MemgraphCypher::ExplainQueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProfileQuery(MemgraphCypher::ProfileQueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCypherQuery(MemgraphCypher::CypherQueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIndexQuery(MemgraphCypher::IndexQueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSingleQuery(MemgraphCypher::SingleQueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCypherUnion(MemgraphCypher::CypherUnionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCypherMatch(MemgraphCypher::CypherMatchContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTt(MemgraphCypher::TtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVt(MemgraphCypher::VtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnwind(MemgraphCypher::UnwindContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMerge(MemgraphCypher::MergeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMergeAction(MemgraphCypher::MergeActionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCreate(MemgraphCypher::CreateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSet(MemgraphCypher::SetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSetItem(MemgraphCypher::SetItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCypherDelete(MemgraphCypher::CypherDeleteContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRemove(MemgraphCypher::RemoveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRemoveItem(MemgraphCypher::RemoveItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWith(MemgraphCypher::WithContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCypherReturn(MemgraphCypher::CypherReturnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCallProcedure(MemgraphCypher::CallProcedureContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProcedureName(MemgraphCypher::ProcedureNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitYieldProcedureResults(MemgraphCypher::YieldProcedureResultsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMemoryLimit(MemgraphCypher::MemoryLimitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQueryMemoryLimit(MemgraphCypher::QueryMemoryLimitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProcedureMemoryLimit(MemgraphCypher::ProcedureMemoryLimitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProcedureResult(MemgraphCypher::ProcedureResultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReturnBody(MemgraphCypher::ReturnBodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReturnItems(MemgraphCypher::ReturnItemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReturnItem(MemgraphCypher::ReturnItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOrder(MemgraphCypher::OrderContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSkip(MemgraphCypher::SkipContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLimit(MemgraphCypher::LimitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSortItem(MemgraphCypher::SortItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhere(MemgraphCypher::WhereContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPattern(MemgraphCypher::PatternContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPatternPart(MemgraphCypher::PatternPartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAnonymousPatternPart(MemgraphCypher::AnonymousPatternPartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPatternElement(MemgraphCypher::PatternElementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNodePattern(MemgraphCypher::NodePatternContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPatternElementChain(MemgraphCypher::PatternElementChainContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelationshipPattern(MemgraphCypher::RelationshipPatternContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLeftArrowHead(MemgraphCypher::LeftArrowHeadContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRightArrowHead(MemgraphCypher::RightArrowHeadContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDash(MemgraphCypher::DashContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelationshipDetail(MemgraphCypher::RelationshipDetailContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelationshipLambda(MemgraphCypher::RelationshipLambdaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableExpansion(MemgraphCypher::VariableExpansionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProperties(MemgraphCypher::PropertiesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelationshipTypes(MemgraphCypher::RelationshipTypesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNodeLabels(MemgraphCypher::NodeLabelsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNodeLabel(MemgraphCypher::NodeLabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLabelName(MemgraphCypher::LabelNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelTypeName(MemgraphCypher::RelTypeNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression(MemgraphCypher::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression12(MemgraphCypher::Expression12Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression11(MemgraphCypher::Expression11Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression10(MemgraphCypher::Expression10Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression9(MemgraphCypher::Expression9Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression8(MemgraphCypher::Expression8Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression7(MemgraphCypher::Expression7Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression6(MemgraphCypher::Expression6Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression5(MemgraphCypher::Expression5Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression4(MemgraphCypher::Expression4Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression3a(MemgraphCypher::Expression3aContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStringAndNullOperators(MemgraphCypher::StringAndNullOperatorsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression3b(MemgraphCypher::Expression3bContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitListIndexingOrSlicing(MemgraphCypher::ListIndexingOrSlicingContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression2a(MemgraphCypher::Expression2aContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression2b(MemgraphCypher::Expression2bContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAtom(MemgraphCypher::AtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteral(MemgraphCypher::LiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBooleanLiteral(MemgraphCypher::BooleanLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitListLiteral(MemgraphCypher::ListLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPartialComparisonExpression(MemgraphCypher::PartialComparisonExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParenthesizedExpression(MemgraphCypher::ParenthesizedExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelationshipsPattern(MemgraphCypher::RelationshipsPatternContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFilterExpression(MemgraphCypher::FilterExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReduceExpression(MemgraphCypher::ReduceExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExtractExpression(MemgraphCypher::ExtractExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdInColl(MemgraphCypher::IdInCollContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionInvocation(MemgraphCypher::FunctionInvocationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionName(MemgraphCypher::FunctionNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitListComprehension(MemgraphCypher::ListComprehensionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPatternComprehension(MemgraphCypher::PatternComprehensionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPropertyLookup(MemgraphCypher::PropertyLookupContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCaseExpression(MemgraphCypher::CaseExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCaseAlternatives(MemgraphCypher::CaseAlternativesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable(MemgraphCypher::VariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumberLiteral(MemgraphCypher::NumberLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMapLiteral(MemgraphCypher::MapLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameter(MemgraphCypher::ParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPropertyExpression(MemgraphCypher::PropertyExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPropertyKeyName(MemgraphCypher::PropertyKeyNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIntegerLiteral(MemgraphCypher::IntegerLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCreateIndex(MemgraphCypher::CreateIndexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDropIndex(MemgraphCypher::DropIndexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDoubleLiteral(MemgraphCypher::DoubleLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCypherKeyword(MemgraphCypher::CypherKeywordContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace antlropencypher
