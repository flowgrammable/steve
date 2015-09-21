#ifndef TOSTRING_HPP
#define TOSTRING_HPP

#include "ast.hpp"
#include "decl.hpp"
#include "type.hpp"
#include "expr.hpp"
#include "stmt.hpp"

#include <string>

namespace cxx
{

// All things in C++ are expressions except for types
std::string tostring(Expr const*);
// For turning types into strings
std::string tostring(Type const*);
// For names
std::string tostring(Name const*);

}

#endif