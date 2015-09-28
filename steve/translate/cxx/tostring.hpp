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
std::string const tostring(Expr const*);
// For turning types into strings
std::string const tostring(Type const*);
// For names
std::string const tostring(Name const*);

}

#endif