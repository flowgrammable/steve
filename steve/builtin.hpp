#ifndef BUILTIN_HPP
#define BUILTIN_HPP

#include "steve/type.hpp"
#include "steve/expr.hpp"
#include "steve/decl.hpp"
#include "steve/stmt.hpp"

namespace steve
{

// ----------------------------------------------------------- //
//            Builtin expressions

// Builtin header cast expr
// This expr simulates a function with the signature
//
// def header_cast() -> T { return x : T }
//
struct Header_cast_expr : Expr 
{
  Header_cast_expr(Type const* t)
    : Expr(Location::none, t)
  { }

  void accept(Expr_visitor& v) const { v.visit(this); }
};


// Define a set of global names for each builtin
String const __bind_header  = "__bind_header";
String const __bind_offset  = "__bind_offset";
String const __advance      = "__advance";
String const __get_context  = "__get_context";
String const __match        = "__match";
String const __decode       = "__decode";
String const __header_cast  = "__header_cast";
String const __lookup_hdr   = "__lookup_hdr";
String const __lookup_fld   = "__lookup_fld";
String const __context_type = "App_cxt";

std::unordered_multimap<String, Function_decl const*> builtin_functions();

Function_decl const* builtin_function(String const);
Record_type const* builtin_type(String const);

Function_decl const* make_match_fn(Type const*);
Function_decl const* get_match_fn(Type const*);

Function_decl const* make_decode_fn(Type const*);
Function_decl const* get_decode_fn(Type const*);

Expr const* make_header_cast(Type const*);

void init_builtins();

} // namespace steve


#endif
