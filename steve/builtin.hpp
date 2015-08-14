#ifndef BUILTIN_HPP
#define BUILTIN_HPP

#include "steve/type.hpp"
#include "steve/expr.hpp"
#include "steve/decl.hpp"
#include "steve/stmt.hpp"

namespace steve
{

// Define a set of global names for each builtin
String const __bind_header  = "__bind_header";
String const __bind_offset  = "__bind_offset";
String const __advance      = "__advance";
String const __get_context  = "__get_context";
String const __context_type = "Context";

std::unordered_map<String, Function_decl const*> builtin_functions();

Function_decl const* lookup_function(String const);
Type const* lookup_type(String const);

} // namespace steve


#endif
