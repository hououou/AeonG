
// Generated from /home/hjm/memgraph/src/query/frontend/opencypher/grammar/MemgraphCypher.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "MemgraphCypher.h"


namespace antlropencypher {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by MemgraphCypher.
 */
class  MemgraphCypherVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by MemgraphCypher.
   */
    virtual antlrcpp::Any visitMemgraphCypherKeyword(MemgraphCypher::MemgraphCypherKeywordContext *context) = 0;

    virtual antlrcpp::Any visitSymbolicName(MemgraphCypher::SymbolicNameContext *context) = 0;

    virtual antlrcpp::Any visitQuery(MemgraphCypher::QueryContext *context) = 0;

    virtual antlrcpp::Any visitAuthQuery(MemgraphCypher::AuthQueryContext *context) = 0;

    virtual antlrcpp::Any visitReplicationQuery(MemgraphCypher::ReplicationQueryContext *context) = 0;

    virtual antlrcpp::Any visitTriggerQuery(MemgraphCypher::TriggerQueryContext *context) = 0;

    virtual antlrcpp::Any visitClause(MemgraphCypher::ClauseContext *context) = 0;

    virtual antlrcpp::Any visitStreamQuery(MemgraphCypher::StreamQueryContext *context) = 0;

    virtual antlrcpp::Any visitSettingQuery(MemgraphCypher::SettingQueryContext *context) = 0;

    virtual antlrcpp::Any visitLoadCsv(MemgraphCypher::LoadCsvContext *context) = 0;

    virtual antlrcpp::Any visitCsvFile(MemgraphCypher::CsvFileContext *context) = 0;

    virtual antlrcpp::Any visitDelimiter(MemgraphCypher::DelimiterContext *context) = 0;

    virtual antlrcpp::Any visitQuote(MemgraphCypher::QuoteContext *context) = 0;

    virtual antlrcpp::Any visitRowVar(MemgraphCypher::RowVarContext *context) = 0;

    virtual antlrcpp::Any visitUserOrRoleName(MemgraphCypher::UserOrRoleNameContext *context) = 0;

    virtual antlrcpp::Any visitCreateRole(MemgraphCypher::CreateRoleContext *context) = 0;

    virtual antlrcpp::Any visitDropRole(MemgraphCypher::DropRoleContext *context) = 0;

    virtual antlrcpp::Any visitShowRoles(MemgraphCypher::ShowRolesContext *context) = 0;

    virtual antlrcpp::Any visitCreateUser(MemgraphCypher::CreateUserContext *context) = 0;

    virtual antlrcpp::Any visitSetPassword(MemgraphCypher::SetPasswordContext *context) = 0;

    virtual antlrcpp::Any visitDropUser(MemgraphCypher::DropUserContext *context) = 0;

    virtual antlrcpp::Any visitShowUsers(MemgraphCypher::ShowUsersContext *context) = 0;

    virtual antlrcpp::Any visitSetRole(MemgraphCypher::SetRoleContext *context) = 0;

    virtual antlrcpp::Any visitClearRole(MemgraphCypher::ClearRoleContext *context) = 0;

    virtual antlrcpp::Any visitGrantPrivilege(MemgraphCypher::GrantPrivilegeContext *context) = 0;

    virtual antlrcpp::Any visitDenyPrivilege(MemgraphCypher::DenyPrivilegeContext *context) = 0;

    virtual antlrcpp::Any visitRevokePrivilege(MemgraphCypher::RevokePrivilegeContext *context) = 0;

    virtual antlrcpp::Any visitPrivilege(MemgraphCypher::PrivilegeContext *context) = 0;

    virtual antlrcpp::Any visitPrivilegeList(MemgraphCypher::PrivilegeListContext *context) = 0;

    virtual antlrcpp::Any visitShowPrivileges(MemgraphCypher::ShowPrivilegesContext *context) = 0;

    virtual antlrcpp::Any visitShowRoleForUser(MemgraphCypher::ShowRoleForUserContext *context) = 0;

    virtual antlrcpp::Any visitShowUsersForRole(MemgraphCypher::ShowUsersForRoleContext *context) = 0;

    virtual antlrcpp::Any visitDumpQuery(MemgraphCypher::DumpQueryContext *context) = 0;

    virtual antlrcpp::Any visitSetReplicationRole(MemgraphCypher::SetReplicationRoleContext *context) = 0;

    virtual antlrcpp::Any visitShowReplicationRole(MemgraphCypher::ShowReplicationRoleContext *context) = 0;

    virtual antlrcpp::Any visitReplicaName(MemgraphCypher::ReplicaNameContext *context) = 0;

    virtual antlrcpp::Any visitSocketAddress(MemgraphCypher::SocketAddressContext *context) = 0;

    virtual antlrcpp::Any visitRegisterReplica(MemgraphCypher::RegisterReplicaContext *context) = 0;

    virtual antlrcpp::Any visitDropReplica(MemgraphCypher::DropReplicaContext *context) = 0;

    virtual antlrcpp::Any visitShowReplicas(MemgraphCypher::ShowReplicasContext *context) = 0;

    virtual antlrcpp::Any visitLockPathQuery(MemgraphCypher::LockPathQueryContext *context) = 0;

    virtual antlrcpp::Any visitFreeMemoryQuery(MemgraphCypher::FreeMemoryQueryContext *context) = 0;

    virtual antlrcpp::Any visitTriggerName(MemgraphCypher::TriggerNameContext *context) = 0;

    virtual antlrcpp::Any visitTriggerStatement(MemgraphCypher::TriggerStatementContext *context) = 0;

    virtual antlrcpp::Any visitEmptyVertex(MemgraphCypher::EmptyVertexContext *context) = 0;

    virtual antlrcpp::Any visitEmptyEdge(MemgraphCypher::EmptyEdgeContext *context) = 0;

    virtual antlrcpp::Any visitCreateTrigger(MemgraphCypher::CreateTriggerContext *context) = 0;

    virtual antlrcpp::Any visitDropTrigger(MemgraphCypher::DropTriggerContext *context) = 0;

    virtual antlrcpp::Any visitShowTriggers(MemgraphCypher::ShowTriggersContext *context) = 0;

    virtual antlrcpp::Any visitIsolationLevel(MemgraphCypher::IsolationLevelContext *context) = 0;

    virtual antlrcpp::Any visitIsolationLevelScope(MemgraphCypher::IsolationLevelScopeContext *context) = 0;

    virtual antlrcpp::Any visitIsolationLevelQuery(MemgraphCypher::IsolationLevelQueryContext *context) = 0;

    virtual antlrcpp::Any visitCreateSnapshotQuery(MemgraphCypher::CreateSnapshotQueryContext *context) = 0;

    virtual antlrcpp::Any visitStreamName(MemgraphCypher::StreamNameContext *context) = 0;

    virtual antlrcpp::Any visitSymbolicNameWithMinus(MemgraphCypher::SymbolicNameWithMinusContext *context) = 0;

    virtual antlrcpp::Any visitSymbolicNameWithDotsAndMinus(MemgraphCypher::SymbolicNameWithDotsAndMinusContext *context) = 0;

    virtual antlrcpp::Any visitSymbolicTopicNames(MemgraphCypher::SymbolicTopicNamesContext *context) = 0;

    virtual antlrcpp::Any visitTopicNames(MemgraphCypher::TopicNamesContext *context) = 0;

    virtual antlrcpp::Any visitCommonCreateStreamConfig(MemgraphCypher::CommonCreateStreamConfigContext *context) = 0;

    virtual antlrcpp::Any visitCreateStream(MemgraphCypher::CreateStreamContext *context) = 0;

    virtual antlrcpp::Any visitConfigKeyValuePair(MemgraphCypher::ConfigKeyValuePairContext *context) = 0;

    virtual antlrcpp::Any visitConfigMap(MemgraphCypher::ConfigMapContext *context) = 0;

    virtual antlrcpp::Any visitKafkaCreateStreamConfig(MemgraphCypher::KafkaCreateStreamConfigContext *context) = 0;

    virtual antlrcpp::Any visitKafkaCreateStream(MemgraphCypher::KafkaCreateStreamContext *context) = 0;

    virtual antlrcpp::Any visitPulsarCreateStreamConfig(MemgraphCypher::PulsarCreateStreamConfigContext *context) = 0;

    virtual antlrcpp::Any visitPulsarCreateStream(MemgraphCypher::PulsarCreateStreamContext *context) = 0;

    virtual antlrcpp::Any visitDropStream(MemgraphCypher::DropStreamContext *context) = 0;

    virtual antlrcpp::Any visitStartStream(MemgraphCypher::StartStreamContext *context) = 0;

    virtual antlrcpp::Any visitStartAllStreams(MemgraphCypher::StartAllStreamsContext *context) = 0;

    virtual antlrcpp::Any visitStopStream(MemgraphCypher::StopStreamContext *context) = 0;

    virtual antlrcpp::Any visitStopAllStreams(MemgraphCypher::StopAllStreamsContext *context) = 0;

    virtual antlrcpp::Any visitShowStreams(MemgraphCypher::ShowStreamsContext *context) = 0;

    virtual antlrcpp::Any visitCheckStream(MemgraphCypher::CheckStreamContext *context) = 0;

    virtual antlrcpp::Any visitSettingName(MemgraphCypher::SettingNameContext *context) = 0;

    virtual antlrcpp::Any visitSettingValue(MemgraphCypher::SettingValueContext *context) = 0;

    virtual antlrcpp::Any visitSetSetting(MemgraphCypher::SetSettingContext *context) = 0;

    virtual antlrcpp::Any visitShowSetting(MemgraphCypher::ShowSettingContext *context) = 0;

    virtual antlrcpp::Any visitShowSettings(MemgraphCypher::ShowSettingsContext *context) = 0;

    virtual antlrcpp::Any visitVersionQuery(MemgraphCypher::VersionQueryContext *context) = 0;

    virtual antlrcpp::Any visitSnapshotQuery(MemgraphCypher::SnapshotQueryContext *context) = 0;

    virtual antlrcpp::Any visitCypher(MemgraphCypher::CypherContext *context) = 0;

    virtual antlrcpp::Any visitStatement(MemgraphCypher::StatementContext *context) = 0;

    virtual antlrcpp::Any visitConstraintQuery(MemgraphCypher::ConstraintQueryContext *context) = 0;

    virtual antlrcpp::Any visitConstraint(MemgraphCypher::ConstraintContext *context) = 0;

    virtual antlrcpp::Any visitConstraintPropertyList(MemgraphCypher::ConstraintPropertyListContext *context) = 0;

    virtual antlrcpp::Any visitStorageInfo(MemgraphCypher::StorageInfoContext *context) = 0;

    virtual antlrcpp::Any visitIndexInfo(MemgraphCypher::IndexInfoContext *context) = 0;

    virtual antlrcpp::Any visitConstraintInfo(MemgraphCypher::ConstraintInfoContext *context) = 0;

    virtual antlrcpp::Any visitInfoQuery(MemgraphCypher::InfoQueryContext *context) = 0;

    virtual antlrcpp::Any visitExplainQuery(MemgraphCypher::ExplainQueryContext *context) = 0;

    virtual antlrcpp::Any visitProfileQuery(MemgraphCypher::ProfileQueryContext *context) = 0;

    virtual antlrcpp::Any visitCypherQuery(MemgraphCypher::CypherQueryContext *context) = 0;

    virtual antlrcpp::Any visitIndexQuery(MemgraphCypher::IndexQueryContext *context) = 0;

    virtual antlrcpp::Any visitSingleQuery(MemgraphCypher::SingleQueryContext *context) = 0;

    virtual antlrcpp::Any visitCypherUnion(MemgraphCypher::CypherUnionContext *context) = 0;

    virtual antlrcpp::Any visitCypherMatch(MemgraphCypher::CypherMatchContext *context) = 0;

    virtual antlrcpp::Any visitTt(MemgraphCypher::TtContext *context) = 0;

    virtual antlrcpp::Any visitVt(MemgraphCypher::VtContext *context) = 0;

    virtual antlrcpp::Any visitUnwind(MemgraphCypher::UnwindContext *context) = 0;

    virtual antlrcpp::Any visitMerge(MemgraphCypher::MergeContext *context) = 0;

    virtual antlrcpp::Any visitMergeAction(MemgraphCypher::MergeActionContext *context) = 0;

    virtual antlrcpp::Any visitCreate(MemgraphCypher::CreateContext *context) = 0;

    virtual antlrcpp::Any visitSet(MemgraphCypher::SetContext *context) = 0;

    virtual antlrcpp::Any visitSetItem(MemgraphCypher::SetItemContext *context) = 0;

    virtual antlrcpp::Any visitCypherDelete(MemgraphCypher::CypherDeleteContext *context) = 0;

    virtual antlrcpp::Any visitRemove(MemgraphCypher::RemoveContext *context) = 0;

    virtual antlrcpp::Any visitRemoveItem(MemgraphCypher::RemoveItemContext *context) = 0;

    virtual antlrcpp::Any visitWith(MemgraphCypher::WithContext *context) = 0;

    virtual antlrcpp::Any visitCypherReturn(MemgraphCypher::CypherReturnContext *context) = 0;

    virtual antlrcpp::Any visitCallProcedure(MemgraphCypher::CallProcedureContext *context) = 0;

    virtual antlrcpp::Any visitProcedureName(MemgraphCypher::ProcedureNameContext *context) = 0;

    virtual antlrcpp::Any visitYieldProcedureResults(MemgraphCypher::YieldProcedureResultsContext *context) = 0;

    virtual antlrcpp::Any visitMemoryLimit(MemgraphCypher::MemoryLimitContext *context) = 0;

    virtual antlrcpp::Any visitQueryMemoryLimit(MemgraphCypher::QueryMemoryLimitContext *context) = 0;

    virtual antlrcpp::Any visitProcedureMemoryLimit(MemgraphCypher::ProcedureMemoryLimitContext *context) = 0;

    virtual antlrcpp::Any visitProcedureResult(MemgraphCypher::ProcedureResultContext *context) = 0;

    virtual antlrcpp::Any visitReturnBody(MemgraphCypher::ReturnBodyContext *context) = 0;

    virtual antlrcpp::Any visitReturnItems(MemgraphCypher::ReturnItemsContext *context) = 0;

    virtual antlrcpp::Any visitReturnItem(MemgraphCypher::ReturnItemContext *context) = 0;

    virtual antlrcpp::Any visitOrder(MemgraphCypher::OrderContext *context) = 0;

    virtual antlrcpp::Any visitSkip(MemgraphCypher::SkipContext *context) = 0;

    virtual antlrcpp::Any visitLimit(MemgraphCypher::LimitContext *context) = 0;

    virtual antlrcpp::Any visitSortItem(MemgraphCypher::SortItemContext *context) = 0;

    virtual antlrcpp::Any visitWhere(MemgraphCypher::WhereContext *context) = 0;

    virtual antlrcpp::Any visitPattern(MemgraphCypher::PatternContext *context) = 0;

    virtual antlrcpp::Any visitPatternPart(MemgraphCypher::PatternPartContext *context) = 0;

    virtual antlrcpp::Any visitAnonymousPatternPart(MemgraphCypher::AnonymousPatternPartContext *context) = 0;

    virtual antlrcpp::Any visitPatternElement(MemgraphCypher::PatternElementContext *context) = 0;

    virtual antlrcpp::Any visitNodePattern(MemgraphCypher::NodePatternContext *context) = 0;

    virtual antlrcpp::Any visitPatternElementChain(MemgraphCypher::PatternElementChainContext *context) = 0;

    virtual antlrcpp::Any visitRelationshipPattern(MemgraphCypher::RelationshipPatternContext *context) = 0;

    virtual antlrcpp::Any visitLeftArrowHead(MemgraphCypher::LeftArrowHeadContext *context) = 0;

    virtual antlrcpp::Any visitRightArrowHead(MemgraphCypher::RightArrowHeadContext *context) = 0;

    virtual antlrcpp::Any visitDash(MemgraphCypher::DashContext *context) = 0;

    virtual antlrcpp::Any visitRelationshipDetail(MemgraphCypher::RelationshipDetailContext *context) = 0;

    virtual antlrcpp::Any visitRelationshipLambda(MemgraphCypher::RelationshipLambdaContext *context) = 0;

    virtual antlrcpp::Any visitVariableExpansion(MemgraphCypher::VariableExpansionContext *context) = 0;

    virtual antlrcpp::Any visitProperties(MemgraphCypher::PropertiesContext *context) = 0;

    virtual antlrcpp::Any visitRelationshipTypes(MemgraphCypher::RelationshipTypesContext *context) = 0;

    virtual antlrcpp::Any visitNodeLabels(MemgraphCypher::NodeLabelsContext *context) = 0;

    virtual antlrcpp::Any visitNodeLabel(MemgraphCypher::NodeLabelContext *context) = 0;

    virtual antlrcpp::Any visitLabelName(MemgraphCypher::LabelNameContext *context) = 0;

    virtual antlrcpp::Any visitRelTypeName(MemgraphCypher::RelTypeNameContext *context) = 0;

    virtual antlrcpp::Any visitExpression(MemgraphCypher::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitExpression12(MemgraphCypher::Expression12Context *context) = 0;

    virtual antlrcpp::Any visitExpression11(MemgraphCypher::Expression11Context *context) = 0;

    virtual antlrcpp::Any visitExpression10(MemgraphCypher::Expression10Context *context) = 0;

    virtual antlrcpp::Any visitExpression9(MemgraphCypher::Expression9Context *context) = 0;

    virtual antlrcpp::Any visitExpression8(MemgraphCypher::Expression8Context *context) = 0;

    virtual antlrcpp::Any visitExpression7(MemgraphCypher::Expression7Context *context) = 0;

    virtual antlrcpp::Any visitExpression6(MemgraphCypher::Expression6Context *context) = 0;

    virtual antlrcpp::Any visitExpression5(MemgraphCypher::Expression5Context *context) = 0;

    virtual antlrcpp::Any visitExpression4(MemgraphCypher::Expression4Context *context) = 0;

    virtual antlrcpp::Any visitExpression3a(MemgraphCypher::Expression3aContext *context) = 0;

    virtual antlrcpp::Any visitStringAndNullOperators(MemgraphCypher::StringAndNullOperatorsContext *context) = 0;

    virtual antlrcpp::Any visitExpression3b(MemgraphCypher::Expression3bContext *context) = 0;

    virtual antlrcpp::Any visitListIndexingOrSlicing(MemgraphCypher::ListIndexingOrSlicingContext *context) = 0;

    virtual antlrcpp::Any visitExpression2a(MemgraphCypher::Expression2aContext *context) = 0;

    virtual antlrcpp::Any visitExpression2b(MemgraphCypher::Expression2bContext *context) = 0;

    virtual antlrcpp::Any visitAtom(MemgraphCypher::AtomContext *context) = 0;

    virtual antlrcpp::Any visitLiteral(MemgraphCypher::LiteralContext *context) = 0;

    virtual antlrcpp::Any visitBooleanLiteral(MemgraphCypher::BooleanLiteralContext *context) = 0;

    virtual antlrcpp::Any visitListLiteral(MemgraphCypher::ListLiteralContext *context) = 0;

    virtual antlrcpp::Any visitPartialComparisonExpression(MemgraphCypher::PartialComparisonExpressionContext *context) = 0;

    virtual antlrcpp::Any visitParenthesizedExpression(MemgraphCypher::ParenthesizedExpressionContext *context) = 0;

    virtual antlrcpp::Any visitRelationshipsPattern(MemgraphCypher::RelationshipsPatternContext *context) = 0;

    virtual antlrcpp::Any visitFilterExpression(MemgraphCypher::FilterExpressionContext *context) = 0;

    virtual antlrcpp::Any visitReduceExpression(MemgraphCypher::ReduceExpressionContext *context) = 0;

    virtual antlrcpp::Any visitExtractExpression(MemgraphCypher::ExtractExpressionContext *context) = 0;

    virtual antlrcpp::Any visitIdInColl(MemgraphCypher::IdInCollContext *context) = 0;

    virtual antlrcpp::Any visitFunctionInvocation(MemgraphCypher::FunctionInvocationContext *context) = 0;

    virtual antlrcpp::Any visitFunctionName(MemgraphCypher::FunctionNameContext *context) = 0;

    virtual antlrcpp::Any visitListComprehension(MemgraphCypher::ListComprehensionContext *context) = 0;

    virtual antlrcpp::Any visitPatternComprehension(MemgraphCypher::PatternComprehensionContext *context) = 0;

    virtual antlrcpp::Any visitPropertyLookup(MemgraphCypher::PropertyLookupContext *context) = 0;

    virtual antlrcpp::Any visitCaseExpression(MemgraphCypher::CaseExpressionContext *context) = 0;

    virtual antlrcpp::Any visitCaseAlternatives(MemgraphCypher::CaseAlternativesContext *context) = 0;

    virtual antlrcpp::Any visitVariable(MemgraphCypher::VariableContext *context) = 0;

    virtual antlrcpp::Any visitNumberLiteral(MemgraphCypher::NumberLiteralContext *context) = 0;

    virtual antlrcpp::Any visitMapLiteral(MemgraphCypher::MapLiteralContext *context) = 0;

    virtual antlrcpp::Any visitParameter(MemgraphCypher::ParameterContext *context) = 0;

    virtual antlrcpp::Any visitPropertyExpression(MemgraphCypher::PropertyExpressionContext *context) = 0;

    virtual antlrcpp::Any visitPropertyKeyName(MemgraphCypher::PropertyKeyNameContext *context) = 0;

    virtual antlrcpp::Any visitIntegerLiteral(MemgraphCypher::IntegerLiteralContext *context) = 0;

    virtual antlrcpp::Any visitCreateIndex(MemgraphCypher::CreateIndexContext *context) = 0;

    virtual antlrcpp::Any visitDropIndex(MemgraphCypher::DropIndexContext *context) = 0;

    virtual antlrcpp::Any visitDoubleLiteral(MemgraphCypher::DoubleLiteralContext *context) = 0;

    virtual antlrcpp::Any visitCypherKeyword(MemgraphCypher::CypherKeywordContext *context) = 0;


};

}  // namespace antlropencypher
