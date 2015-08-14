// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#include "steve/decl.hpp"
#include "steve/expr.hpp"
#include "steve/type.hpp"
#include "steve/stmt.hpp"
#include "steve/debug.hpp"

#include "lingo/memory.hpp"
#include "lingo/symbol.hpp"
#include "lingo/token.hpp"
#include "lingo/error.hpp"


namespace steve
{

// Returns a textual representation of the node's name.
char const*
get_decl_name(Decl_kind k)
{
  switch (k) {
    case variable_decl: return "variable_decl";
    case constant_decl: return "constant_decl";
    case function_decl: return "function_decl";
    case parameter_decl: return "parameter_decl";
    case record_decl: return "record_decl";
    case member_decl: return "member_decl";
    case variant_decl: return "variant_decl";
    case enum_decl: return "enum_decl";
    case decode_decl: return "decode_decl";
    case table_decl: return "table_decl";
    case flow_decl: return "ofpentry_decl";
  }
  lingo_unreachable("unhandled node kind ({})", (int)k);
}


// -------------------------------------------------------------------------- //
//                             Node definitions


Function_decl::Function_decl(Location loc, String const* n, Type const* t, Decl_seq const& a, Stmt const* b)
  : Decl(node_kind, loc, n, t), first(a), second(b)
{ 
  lingo_assert(lingo::is<Function_type>(t)); // FIXME: Why is this qualified?
}


Function_type const* 
Function_decl::type() const
{
  return cast<Function_type>(Decl::type());
}


Type const*
Function_decl::ret_type() const
{
  return type()->ret_type();
}


// -------------------------------------------------------------------------- //
//                             Declaration builders

// Create an identifier and return it. This updates the symbol
// table.
String const*
get_identifier(String const& str)
{
  Symbol& sym = lingo::get_symbol(str);
  if (sym.desc.kind == identifier_sym) {
    // Sanity check... make sure that we've got the right
    // token kind.
    lingo_assert(sym.desc.token == identifier_tok);
    return &sym.str;
  }

  // Make sure we aren't trying to say that '(' is an identifier.
  if (sym.desc.kind != unspecified_sym)
    lingo_unreachable("symbol '{}' is bound to another kind of symbol", sym.str);

  // Initialize symbol and its binding.
  sym.desc.kind = identifier_sym;
  sym.desc.token = identifier_tok;
  return &sym.str;
}


// Partially construct a variable. The declaration must be
// adjusted later to set the initializer.
//
// This allows a variable to be declared prior to analyzing
// the initializer.
Variable_decl* 
make_variable_decl(Location loc, String const* n, Type const* t)
{
  return gc().make<Variable_decl>(loc, n, t, nullptr);
}


// Make a new variable declaration. The type of the initializer shall
// be convertible to the type of the declaration.
Variable_decl* 
make_variable_decl(Location loc, String const* n, Type const* t, Expr const* e)
{
  Expr const* c = convert(e, t);
  if (!c)
    return nullptr;
  return gc().make<Variable_decl>(loc, n, t, c);
}


// Make a new constant declaration. 
//
// FIXME: Verify that the initializer is constant?
Constant_decl* 
make_constant_decl(Location loc, String const* n, Type const* t, Expr const* e)
{
  Expr const* c = convert(e, t);
  if (!c)
    return nullptr;
  return gc().make<Constant_decl>(loc, n, t, c);
}


// Returns the parameter type for a sequence of paramteers.
static Type_seq
get_parameter_types(Decl_seq const& p)
{
  Type_seq t;
  t.reserve(p.size());
  for (Decl const* d : p) {
    t.push_back(d->type());
  }
  return t;
}


// Partially construct a new function. Note that the function 
// must be adjusted later to set the definition.
Function_decl* 
make_function_decl(Location loc, String const* n, Decl_seq const& p, Type const* r)
{
  Type const* t = get_function_type(get_parameter_types(p), r);
  return gc().make<Function_decl>(loc, n, t, p, nullptr);
}


// Make a new function declaration.
Function_decl* 
make_function_decl(Location loc, String const* n, Decl_seq const& p, Type const* r, Stmt const* s)
{
  if (!check_function_decl(r, s))
    return nullptr;

  Type const* t = get_function_type(get_parameter_types(p), r);
  return gc().make<Function_decl>(loc, n, t, p, s);
}


// Make a new parameter declaration.
Parameter_decl*
make_parameter_decl(Location loc, String const* n, Type const* t)
{
  return gc().make<Parameter_decl>(loc, n, t);
}


// Make a new member declaration.
Member_decl*
make_member_decl(Location loc, String const* n, Type const* t)
{
  return gc().make<Member_decl>(loc, n, t);
}


// Make a new member declaration.
Record_decl*
make_record_decl(Location loc, String const* n, Decl_seq const& m)
{
  return gc().make<Record_decl>(loc, n, get_kind_type(), m);
}


// Make a new enumeration declaration.
Enum_decl*
make_enumeration_decl(Location loc, String const* n, Type const* b, Decl_seq const& m)
{
  Enum_decl* decl = gc().make<Enum_decl>(loc, n, get_kind_type(), b, m);

  // Adjust the types of all members to the type
  // of the enumeration declaration.
  Enum_type const* t = get_enum_type(decl);
  for (Decl const* d : decl->members()) {
    // Each member had best be a constant. We also need 
    // to remove the const in order to modify the declaration.
    lingo_assert(is<Constant_decl>(d)); // Must be constant
    lingo_assert(d->type() == b);       // Must be the underlying type
    Constant_decl* c = const_cast<Constant_decl*>(cast<Constant_decl>(d));

    // Reset the type of the enumerator.
    c->type_ = t;
  }

  return decl;
}


// Make a new variant declaration.
Variant_decl*
make_variant_decl(Location loc, String const* n, Type_seq const& t)
{
  return gc().make<Variant_decl>(loc, n, get_kind_type(), t);
}



// Check the decode declaration confirm that the match 
// decision member is a member of the decoded type.
//
// Confirm each stmt in the match stmt has the same
// key type as the decision member.
//
// Confirm that the type of the length expression is an int.
//
// TODO: Move this into a different module.
static bool
check_decode_decl(Type const* t, Stmt const* s, Expr const* e)
{
  // FIXME: Check all statements within the decoder, not
  // just a match statement.

  // if (Match_stmt const* ms = as<Match_stmt>(s)) {
  //   if (as<Record_type>(t))
  //     if (check_match_stmt(ms->decision(), ms->branches())) {
  //       return true;
  //     }
  // }

  return true;
}


// make a decode declaration
Decode_decl*
make_decode_decl(Location loc, String const* n, Stmt const* m, Type const* h, Expr const* l)
{
  if (!check_decode_decl(h, m, l)) {
    return nullptr;
  }

  return gc().make<Decode_decl>(loc, n, get_kind_type(), m, h, l);
}


// -------------------------------------------------------------------------- //
//                             Garbage collection

void
mark(Decl const* d)
{
  lingo_assert(is_valid_node(d));
  switch (d->kind()) {
    case variable_decl: return mark(cast<Variable_decl>(d));
    case constant_decl: return mark(cast<Constant_decl>(d));
    case function_decl: return mark(cast<Function_decl>(d));
    case parameter_decl: return mark(cast<Parameter_decl>(d));
    case member_decl: return mark(cast<Member_decl>(d));
    case record_decl: return mark(cast<Record_decl>(d));
    case variant_decl: return mark(cast<Variant_decl>(d));
    case enum_decl: return mark(cast<Enum_decl>(d));
    case decode_decl: return mark(cast<Decode_decl>(d));
    case table_decl: return mark(cast<Table_decl>(d));
    case flow_decl: return mark(cast<Flow_decl>(d));
  }
  lingo_unreachable("unevaluated node '{}'", d->node_name());
}


} // namespace steve

