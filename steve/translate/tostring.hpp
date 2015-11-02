#ifndef TOSTRING_HPP
#define TOSTRING_HPP

#include "cxx/ast.hpp"
#include "cxx/decl.hpp"
#include "cxx/type.hpp"
#include "cxx/expr.hpp"
#include "cxx/stmt.hpp"

#include <string>

namespace cxx
{

// All things in C++ are expressions except for types
std::string const tostring(Expr const*);
// For turning types into strings
std::string const tostring(Type const*);
// For names
std::string const tostring(Name const*);

}

#endif