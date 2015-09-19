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
String const __match        = "__match";
String const __decode       = "__decode";
String const __lookup_hdr   = "__lookup_hdr";
String const __lookup_fld   = "__lookup_fld";
String const __context_type = "context";

std::unordered_multimap<String, Function_decl const*> builtin_functions();

Function_decl const* builtin_function(String const);
Record_type const* builtin_type(String const);

Function_decl const* make_match_fn(Type const*);
Function_decl const* get_match_fn(Type const*);

Function_decl const* make_decode_fn(Type const*);
Function_decl const* make_decode_fn(Type const*);

void init_builtins();

} // namespace steve


#endif
