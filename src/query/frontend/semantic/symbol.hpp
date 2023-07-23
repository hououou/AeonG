// -*- buffer-read-only: t; -*-
// vim: readonly
// DO NOT EDIT! Generated using LCP from '/home/wzy/memgraph/src/query/frontend/semantic/symbol.lcp'

#pragma once

#include <string>

#include "utils/typeinfo.hpp"

namespace query {

class Symbol {
 public:
  static const utils::TypeInfo kType;
  const utils::TypeInfo &GetTypeInfo() const { return kType; }

  enum class Type { ANY, VERTEX, EDGE, PATH, NUMBER, EDGE_LIST };

  // TODO: Generate enum to string conversion from LCP. Note, that this is
  // displayed to the end user, so we may want to have a pretty name of each
  // value.
  static std::string TypeToString(Type type) {
    const char *enum_string[] = {"Any", "Vertex", "Edge", "Path", "Number", "EdgeList"};
    return enum_string[static_cast<int>(type)];
  }

  Symbol() {}
  Symbol(const std::string &name, int position, bool user_declared, Type type = Type::ANY, int token_position = -1)
      : name_(name), position_(position), user_declared_(user_declared), type_(type), token_position_(token_position) {}

  bool operator==(const Symbol &other) const {
    return position_ == other.position_ && name_ == other.name_ && type_ == other.type_;
  }
  bool operator!=(const Symbol &other) const { return !operator==(other); }

  // TODO: Remove these since members are public
  const auto &name() const { return name_; }
  int position() const { return position_; }
  Type type() const { return type_; }
  bool user_declared() const { return user_declared_; }
  int token_position() const { return token_position_; }

  std::string name_;
  int64_t position_;
  bool user_declared_{true};
  query::Symbol::Type type_{Type::ANY};
  int64_t token_position_{-1};
};

}  // namespace query
namespace std {

template <>
struct hash<query::Symbol> {
  size_t operator()(const query::Symbol &symbol) const {
    size_t prime = 265443599u;
    size_t hash = std::hash<int>{}(symbol.position());
    hash ^= prime * std::hash<std::string>{}(symbol.name());
    hash ^= prime * std::hash<int>{}(static_cast<int>(symbol.type()));
    return hash;
  }
};

}  // namespace std
