// -*- buffer-read-only: t; -*-
// vim: readonly
// DO NOT EDIT! Generated using LCP from
// '/home/hjm/vldb/memgraph/src/query/frontend/ast/ast.lcp'

#include "/home/hjm/vldb/memgraph/src/query/frontend/ast/ast.hpp"

const utils::TypeInfo query::LabelIx::kType{0x7D41C2BCFA52D96AULL, "LabelIx",
                                            nullptr};

const utils::TypeInfo query::PropertyIx::kType{0x59320A2F810B5BC3ULL,
                                               "PropertyIx", nullptr};

const utils::TypeInfo query::EdgeTypeIx::kType{0x624FF737710DF737ULL,
                                               "EdgeTypeIx", nullptr};

const utils::TypeInfo query::Tree::kType{0x59ADB3E4FB58934FULL, "Tree",
                                         nullptr};

const utils::TypeInfo query::Expression::kType{
    0xC4F75F0C6DAEB6C5ULL, "Expression", &query::Tree::kType};

const utils::TypeInfo query::Where::kType{0x39448BD33A0696DAULL, "Where",
                                          &query::Tree::kType};

const utils::TypeInfo query::Tt::kType{0xFFD39EFC73DCC623ULL, "Tt",
                                       &query::Tree::kType};

const utils::TypeInfo query::BinaryOperator::kType{
    0x9233B629DA1AFE3EULL, "BinaryOperator", &query::Expression::kType};

const utils::TypeInfo query::UnaryOperator::kType{
    0xFEA89FF40FEB5D4AULL, "UnaryOperator", &query::Expression::kType};

const utils::TypeInfo query::OrOperator::kType{
    0xED0E47AF469BDD62ULL, "OrOperator", &query::BinaryOperator::kType};

const utils::TypeInfo query::XorOperator::kType{
    0x52B315DCACF48728ULL, "XorOperator", &query::BinaryOperator::kType};

const utils::TypeInfo query::AndOperator::kType{
    0xBAE2B7776B250C54ULL, "AndOperator", &query::BinaryOperator::kType};

const utils::TypeInfo query::AdditionOperator::kType{
    0xC3A9F56055DB6F2FULL, "AdditionOperator", &query::BinaryOperator::kType};

const utils::TypeInfo query::SubtractionOperator::kType{
    0x2789195498739623ULL, "SubtractionOperator",
    &query::BinaryOperator::kType};

const utils::TypeInfo query::MultiplicationOperator::kType{
    0x366556031269EC1DULL, "MultiplicationOperator",
    &query::BinaryOperator::kType};

const utils::TypeInfo query::DivisionOperator::kType{
    0x4F9B5A2C8666D014ULL, "DivisionOperator", &query::BinaryOperator::kType};

const utils::TypeInfo query::ModOperator::kType{
    0x9DAEA7DD7011A6F9ULL, "ModOperator", &query::BinaryOperator::kType};

const utils::TypeInfo query::NotEqualOperator::kType{
    0xB687BA299B65D16CULL, "NotEqualOperator", &query::BinaryOperator::kType};

const utils::TypeInfo query::EqualOperator::kType{
    0x9486E68E65DE9C21ULL, "EqualOperator", &query::BinaryOperator::kType};

const utils::TypeInfo query::LessOperator::kType{
    0x3326026D1CCDC636ULL, "LessOperator", &query::BinaryOperator::kType};

const utils::TypeInfo query::GreaterOperator::kType{
    0x6A752D4B473A2E37ULL, "GreaterOperator", &query::BinaryOperator::kType};

const utils::TypeInfo query::LessEqualOperator::kType{
    0xDBFDCDB0F01B8FAULL, "LessEqualOperator", &query::BinaryOperator::kType};

const utils::TypeInfo query::GreaterEqualOperator::kType{
    0xB3B8422A2358AF5ULL, "GreaterEqualOperator",
    &query::BinaryOperator::kType};

const utils::TypeInfo query::InListOperator::kType{
    0xD09999B50D0EECD8ULL, "InListOperator", &query::BinaryOperator::kType};

const utils::TypeInfo query::SubscriptOperator::kType{
    0xC066346FBDEAAF20ULL, "SubscriptOperator", &query::BinaryOperator::kType};

const utils::TypeInfo query::NotOperator::kType{
    0xD61FF805B30783D4ULL, "NotOperator", &query::UnaryOperator::kType};

const utils::TypeInfo query::UnaryPlusOperator::kType{
    0xB35FE36D31E589AEULL, "UnaryPlusOperator", &query::UnaryOperator::kType};

const utils::TypeInfo query::UnaryMinusOperator::kType{
    0x3523058D59D002A6ULL, "UnaryMinusOperator", &query::UnaryOperator::kType};

const utils::TypeInfo query::IsNullOperator::kType{
    0xF2F8F017009366FAULL, "IsNullOperator", &query::UnaryOperator::kType};

const utils::TypeInfo query::Aggregation::kType{
    0xBD6C5917C1AAA70FULL, "Aggregation", &query::BinaryOperator::kType};

const utils::TypeInfo query::ListSlicingOperator::kType{
    0xF9AE8839525BF784ULL, "ListSlicingOperator", &query::Expression::kType};

const utils::TypeInfo query::IfOperator::kType{
    0x7348D24365329C28ULL, "IfOperator", &query::Expression::kType};

const utils::TypeInfo query::BaseLiteral::kType{
    0xEFD7B15834BE6475ULL, "BaseLiteral", &query::Expression::kType};

const utils::TypeInfo query::PrimitiveLiteral::kType{
    0xC3F9F780E8B43C7FULL, "PrimitiveLiteral", &query::BaseLiteral::kType};

const utils::TypeInfo query::ListLiteral::kType{
    0xFCD408E99786FF0AULL, "ListLiteral", &query::BaseLiteral::kType};

const utils::TypeInfo query::MapLiteral::kType{
    0x90D4E54E7C8631F2ULL, "MapLiteral", &query::BaseLiteral::kType};

const utils::TypeInfo query::Identifier::kType{
    0xC51BD3CF7662C188ULL, "Identifier", &query::Expression::kType};

const utils::TypeInfo query::PropertyLookup::kType{
    0x7DC1479199DF849CULL, "PropertyLookup", &query::Expression::kType};

const utils::TypeInfo query::LabelsTest::kType{
    0xA84F10101F4197BCULL, "LabelsTest", &query::Expression::kType};

const utils::TypeInfo query::Function::kType{0x66976BFAFD663B13ULL, "Function",
                                             &query::Expression::kType};

const utils::TypeInfo query::Reduce::kType{0x7B25728351B92715ULL, "Reduce",
                                           &query::Expression::kType};

const utils::TypeInfo query::Coalesce::kType{0xF43244F91E491098ULL, "Coalesce",
                                             &query::Expression::kType};

const utils::TypeInfo query::Extract::kType{0x6A1A00442F852350ULL, "Extract",
                                            &query::Expression::kType};

const utils::TypeInfo query::All::kType{0xEFB136F9154D4A06ULL, "All",
                                        &query::Expression::kType};

const utils::TypeInfo query::Single::kType{0xF75ADDC6788DAA4BULL, "Single",
                                           &query::Expression::kType};

const utils::TypeInfo query::Any::kType{0xEFAA3FF915473AA3ULL, "Any",
                                        &query::Expression::kType};

const utils::TypeInfo query::None::kType{0xB139839D4B4F9025ULL, "None",
                                         &query::Expression::kType};

const utils::TypeInfo query::ParameterLookup::kType{
    0xED1B77350220CC1CULL, "ParameterLookup", &query::Expression::kType};

const utils::TypeInfo query::RegexMatch::kType{
    0x34AC8EEE54408263ULL, "RegexMatch", &query::Expression::kType};

const utils::TypeInfo query::NamedExpression::kType{
    0x9D127380EDF1AC6ULL, "NamedExpression", &query::Tree::kType};

const utils::TypeInfo query::PatternAtom::kType{
    0xF3E56AD8A7B28F7AULL, "PatternAtom", &query::Tree::kType};

const utils::TypeInfo query::NodeAtom::kType{0x68F4F69232438D02ULL, "NodeAtom",
                                             &query::PatternAtom::kType};

const utils::TypeInfo query::EdgeAtom::Lambda::kType{0x76F70C7413EDBDD4ULL,
                                                     "Lambda", nullptr};

const utils::TypeInfo query::EdgeAtom::kType{0xDBD9363AD8603DC3ULL, "EdgeAtom",
                                             &query::PatternAtom::kType};

const utils::TypeInfo query::Pattern::kType{0x892C7AABCCA7791BULL, "Pattern",
                                            &query::Tree::kType};

const utils::TypeInfo query::Clause::kType{0x8B672C24832C1666ULL, "Clause",
                                           &query::Tree::kType};

const utils::TypeInfo query::SingleQuery::kType{
    0x2B930B2D4BB12739ULL, "SingleQuery", &query::Tree::kType};

const utils::TypeInfo query::CypherUnion::kType{
    0xBC144CED20CA897FULL, "CypherUnion", &query::Tree::kType};

const utils::TypeInfo query::Query::kType{0xF5A2301B914E2E01ULL, "Query",
                                          &query::Tree::kType};

const utils::TypeInfo query::CypherQuery::kType{
    0x78D0CAAF9ABECB0CULL, "CypherQuery", &query::Query::kType};

const utils::TypeInfo query::ExplainQuery::kType{
    0x4057CE2081B80E66ULL, "ExplainQuery", &query::Query::kType};

const utils::TypeInfo query::ProfileQuery::kType{
    0xD8BCA4CC09F6D498ULL, "ProfileQuery", &query::Query::kType};

const utils::TypeInfo query::IndexQuery::kType{
    0xC775A604790E725FULL, "IndexQuery", &query::Query::kType};

const utils::TypeInfo query::Create::kType{0xB0095F73FEFBA983ULL, "Create",
                                           &query::Clause::kType};

const utils::TypeInfo query::CallProcedure::kType{
    0xF67725CF0876FB58ULL, "CallProcedure", &query::Clause::kType};

const utils::TypeInfo query::Match::kType{0x3F10B45C5278D464ULL, "Match",
                                          &query::Clause::kType};

const utils::TypeInfo query::SortItem::kType{0x3B738BD1181F9ECULL, "SortItem",
                                             nullptr};

const utils::TypeInfo query::ReturnBody::kType{0x95322F7DFFD5181ULL,
                                               "ReturnBody", nullptr};

const utils::TypeInfo query::Return::kType{0x3BE95A06DEA432D1ULL, "Return",
                                           &query::Clause::kType};

const utils::TypeInfo query::With::kType{0xCD0EF5CCB9549A5BULL, "With",
                                         &query::Clause::kType};

const utils::TypeInfo query::Delete::kType{0x77B6C6B2AF51F410ULL, "Delete",
                                           &query::Clause::kType};

const utils::TypeInfo query::SetProperty::kType{
    0x1744FE9EC412A36CULL, "SetProperty", &query::Clause::kType};

const utils::TypeInfo query::SetProperties::kType{
    0xC8462A6F8449E3B8ULL, "SetProperties", &query::Clause::kType};

const utils::TypeInfo query::SetLabels::kType{
    0xF3EE342882C211FEULL, "SetLabels", &query::Clause::kType};

const utils::TypeInfo query::RemoveProperty::kType{
    0xA55A9355597ADCEULL, "RemoveProperty", &query::Clause::kType};

const utils::TypeInfo query::RemoveLabels::kType{
    0xD6786568CCE203FCULL, "RemoveLabels", &query::Clause::kType};

const utils::TypeInfo query::Merge::kType{0x5A9E637B2EF2CF21ULL, "Merge",
                                          &query::Clause::kType};

const utils::TypeInfo query::Unwind::kType{0xF1AAA3D0306D3FAULL, "Unwind",
                                           &query::Clause::kType};

const utils::TypeInfo query::AuthQuery::kType{
    0x35E6F8E87671F8EBULL, "AuthQuery", &query::Query::kType};

const utils::TypeInfo query::InfoQuery::kType{
    0x101E45E5B8A86CADULL, "InfoQuery", &query::Query::kType};

const utils::TypeInfo query::Constraint::kType{0x353D4609B40D10ULL,
                                               "Constraint", nullptr};

const utils::TypeInfo query::ConstraintQuery::kType{
    0xAAEF9541224EAE74ULL, "ConstraintQuery", &query::Query::kType};

const utils::TypeInfo query::DumpQuery::kType{
    0x1CA3E491842B0F43ULL, "DumpQuery", &query::Query::kType};

const utils::TypeInfo query::ReplicationQuery::kType{
    0xE7926C503E78F571ULL, "ReplicationQuery", &query::Query::kType};

const utils::TypeInfo query::LockPathQuery::kType{
    0xE5C63040F1B75829ULL, "LockPathQuery", &query::Query::kType};

const utils::TypeInfo query::LoadCsv::kType{0x38D70E20C3C6DF7DULL, "LoadCsv",
                                            &query::Clause::kType};

const utils::TypeInfo query::FreeMemoryQuery::kType{
    0x9822C94364A510BEULL, "FreeMemoryQuery", &query::Query::kType};

const utils::TypeInfo query::TriggerQuery::kType{
    0x2904D628D8A52B7BULL, "TriggerQuery", &query::Query::kType};

const utils::TypeInfo query::IsolationLevelQuery::kType{
    0x72D37B05E02C69B7ULL, "IsolationLevelQuery", &query::Query::kType};

const utils::TypeInfo query::CreateSnapshotQuery::kType{
    0xDEC7B8E6DF62491ULL, "CreateSnapshotQuery", &query::Query::kType};

const utils::TypeInfo query::StreamQuery::kType{
    0xAA5B7C4687B34669ULL, "StreamQuery", &query::Query::kType};

const utils::TypeInfo query::SettingQuery::kType{
    0x2843EBAFDB57008FULL, "SettingQuery", &query::Query::kType};

const utils::TypeInfo query::VersionQuery::kType{
    0x389D42D2629FF12BULL, "VersionQuery", &query::Query::kType};

const utils::TypeInfo query::SnapshotQuery::kType{
    0x6BABD81EA8CF62C1ULL, "SnapshotQuery", &query::Query::kType};
