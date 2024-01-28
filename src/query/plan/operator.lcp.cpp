// -*- buffer-read-only: t; -*-
// vim: readonly
// DO NOT EDIT! Generated using LCP from '/home/wzy/temporalGDB/src/query/plan/operator.lcp'

#include "/home/hjm/memgraph/src/query/plan/operator.hpp"

const utils::TypeInfo query::plan::LogicalOperator::kType{0xCF6E3316FE845113ULL, "LogicalOperator", nullptr};

const utils::TypeInfo query::plan::Once::kType{0x606493B67B16FA69ULL, "Once", &query::plan::LogicalOperator::kType};

const utils::TypeInfo query::plan::NodeCreationInfo::kType{0x810769A7903C741DULL, "NodeCreationInfo", nullptr};

const utils::TypeInfo query::plan::CreateNode::kType{0x3BBF069F11AF3128ULL, "CreateNode",
                                                     &query::plan::LogicalOperator::kType};

const utils::TypeInfo query::plan::EdgeCreationInfo::kType{0xB4685405E9682390ULL, "EdgeCreationInfo", nullptr};

const utils::TypeInfo query::plan::CreateExpand::kType{0x9FFD75D9BC501E6CULL, "CreateExpand",
                                                       &query::plan::LogicalOperator::kType};

const utils::TypeInfo query::plan::ScanAll::kType{0xD573DBED40DA2388ULL, "ScanAll",
                                                  &query::plan::LogicalOperator::kType};

const utils::TypeInfo query::plan::ScanAllByLabel::kType{0xDA32A714F1EFD91DULL, "ScanAllByLabel",
                                                         &query::plan::ScanAll::kType};

const utils::TypeInfo query::plan::ScanAllByLabelPropertyRange::kType{
    0x93971E86FE699C55ULL, "ScanAllByLabelPropertyRange", &query::plan::ScanAll::kType};

const utils::TypeInfo query::plan::ScanAllByLabelPropertyValue::kType{
    0x9B5E3B478C415991ULL, "ScanAllByLabelPropertyValue", &query::plan::ScanAll::kType};

const utils::TypeInfo query::plan::ScanAllByLabelProperty::kType{0x461D30DE9D8A2D00ULL, "ScanAllByLabelProperty",
                                                                 &query::plan::ScanAll::kType};

const utils::TypeInfo query::plan::ScanAllById::kType{0x871151815F9E2E20ULL, "ScanAllById",
                                                      &query::plan::ScanAll::kType};

const utils::TypeInfo query::plan::ExpandCommon::kType{0xB464AF347ACE04F9ULL, "ExpandCommon", nullptr};

const utils::TypeInfo query::plan::Expand::kType{0x1BD909509FB91300ULL, "Expand", &query::plan::LogicalOperator::kType};

const utils::TypeInfo query::plan::ExpansionLambda::kType{0x800C4E625C0EB2C2ULL, "ExpansionLambda", nullptr};

const utils::TypeInfo query::plan::ExpandVariable::kType{0x83C9CE111CF1C0ULL, "ExpandVariable",
                                                         &query::plan::LogicalOperator::kType};

const utils::TypeInfo query::plan::ConstructNamedPath::kType{0x9109E22D0873E3D5ULL, "ConstructNamedPath",
                                                             &query::plan::LogicalOperator::kType};

const utils::TypeInfo query::plan::Filter::kType{0x4B7EC3668A57BADAULL, "Filter", &query::plan::LogicalOperator::kType};

const utils::TypeInfo query::plan::Produce::kType{0xC2FCFD7FBB02D294ULL, "Produce",
                                                  &query::plan::LogicalOperator::kType};

const utils::TypeInfo query::plan::Delete::kType{0x5DCC3F67B9798313ULL, "Delete", &query::plan::LogicalOperator::kType};

const utils::TypeInfo query::plan::SetProperty::kType{0xC5B0707442E71DB1ULL, "SetProperty",
                                                      &query::plan::LogicalOperator::kType};

const utils::TypeInfo query::plan::SetProperties::kType{0xF624BAC02F2D030DULL, "SetProperties",
                                                        &query::plan::LogicalOperator::kType};

const utils::TypeInfo query::plan::SetLabels::kType{0xAA750B5BD5B50ABFULL, "SetLabels",
                                                    &query::plan::LogicalOperator::kType};

const utils::TypeInfo query::plan::RemoveProperty::kType{0x5ADBB420B73F2D99ULL, "RemoveProperty",
                                                         &query::plan::LogicalOperator::kType};

const utils::TypeInfo query::plan::RemoveLabels::kType{0xEE4139637F3AC6C7ULL, "RemoveLabels",
                                                       &query::plan::LogicalOperator::kType};

const utils::TypeInfo query::plan::EdgeUniquenessFilter::kType{0xB457B814C0B48B77ULL, "EdgeUniquenessFilter",
                                                               &query::plan::LogicalOperator::kType};

const utils::TypeInfo query::plan::Accumulate::kType{0xD80E79E95C9E390EULL, "Accumulate",
                                                     &query::plan::LogicalOperator::kType};

const utils::TypeInfo query::plan::Aggregate::Element::kType{0xABA2C7F4FC650A5DULL, "Element", nullptr};

const utils::TypeInfo query::plan::Aggregate::kType{0xEA3F371351E8B31BULL, "Aggregate",
                                                    &query::plan::LogicalOperator::kType};

const utils::TypeInfo query::plan::Skip::kType{0xFB8DB85D475B3D5FULL, "Skip", &query::plan::LogicalOperator::kType};

const utils::TypeInfo query::plan::Limit::kType{0x9FEB7E40458A31FBULL, "Limit", &query::plan::LogicalOperator::kType};

const utils::TypeInfo query::plan::OrderBy::kType{0x9D5DE9E110025ACDULL, "OrderBy",
                                                  &query::plan::LogicalOperator::kType};

const utils::TypeInfo query::plan::Merge::kType{0x595FEB62B8EAA864ULL, "Merge", &query::plan::LogicalOperator::kType};

const utils::TypeInfo query::plan::Optional::kType{0x35044064C3943744ULL, "Optional",
                                                   &query::plan::LogicalOperator::kType};

const utils::TypeInfo query::plan::Unwind::kType{0x31CB12687A1B4E5DULL, "Unwind", &query::plan::LogicalOperator::kType};

const utils::TypeInfo query::plan::Distinct::kType{0xA9488A3A583BB068ULL, "Distinct",
                                                   &query::plan::LogicalOperator::kType};

const utils::TypeInfo query::plan::Union::kType{0x1E922FADEE4D97DFULL, "Union", &query::plan::LogicalOperator::kType};

const utils::TypeInfo query::plan::Cartesian::kType{0x8A485EE72E6BEEC6ULL, "Cartesian",
                                                    &query::plan::LogicalOperator::kType};

const utils::TypeInfo query::plan::OutputTable::kType{0x8F61EADFF2A5A29FULL, "OutputTable",
                                                      &query::plan::LogicalOperator::kType};

const utils::TypeInfo query::plan::OutputTableStream::kType{0xFC77C8BCDAC071FFULL, "OutputTableStream",
                                                            &query::plan::LogicalOperator::kType};

const utils::TypeInfo query::plan::CallProcedure::kType{0x285219EBC636514DULL, "CallProcedure",
                                                        &query::plan::LogicalOperator::kType};

const utils::TypeInfo query::plan::LoadCsv::kType{0xBEB6C0F0852BE5BCULL, "LoadCsv",
                                                  &query::plan::LogicalOperator::kType};
