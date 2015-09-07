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

namespace
{

// Keep track of all table and flow declarations made in the program
// and assign them numbers in the order with which they are declared
//
// Table count is necessary to contrain gotos
// Flow count is used to assign internal names to otherwise nameless flows
static int table_cnt = -1;
static int flow_cnt = -1;

} // namespace


// Returns the name of the node. This is the same
// as the class name.
String
Decl::node_name() const
{
  return type_str(*this);
}


// -------------------------------------------------------------------------- //
//                             Node definitions


Function_decl::Function_decl(Location loc, String const* n, Type const* t, Decl_seq const& a, Stmt const* b)
  : Decl(loc, n, t), first(a), second(b)
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


// Make a decode declaration
Decode_decl*
make_decode_decl(Location loc, String const* n, Type const* h, Stmt const* s)
{
  // Defer any checks until pipeline checking stage
  return gc().make<Decode_decl>(loc, n, get_void_type(), s, h);
}

// Make a table declaration.
// Defer any type/consistency checking of the table until it has been
// registered into the pipeline.
Table_decl*
make_table_decl(Location loc, String const* n, Expr_seq const& e, Decl_seq const& d)
{
  table_cnt++;

  return gc().make<Table_decl>(loc, n, get_kind_type(), table_cnt, e, d);
}


// Make a flow decl
Flow_decl*
make_flow_decl(Location loc, Expr_seq const& e, Value const v, Stmt const* s)
{
  flow_cnt++;

  String* n = new String("flow" + flow_cnt);

  return gc().make<Flow_decl>(loc, n, get_kind_type(), e, v, s);
}


Extracts_decl*
make_extracts_decl(Location loc, Expr const* e)
{
  lingo_assert(is<Field_expr>(e));
  Field_expr const* f = as<Field_expr>(e);
  return gc().make<Extracts_decl>(loc, f->name(), e->type(), e);
}


Rebind_decl*
make_rebind_decl(Location loc, Expr const* e1, Expr const* e2)
{
  lingo_assert(is<Field_expr>(e1));
  lingo_assert(is<Field_expr>(e2));
  lingo_assert(e1->type() == e2->type());

  Field_expr const* f = as<Field_expr>(e2);

  return gc().make<Rebind_decl>(loc, f->name(), e1->type(), e1, e2);
}


// -------------------------------------------------------------------------- //
//                             Define

void
define(Variable_decl* d, Expr const* e)
{
  d->set_init(e);
}


void
define(Function_decl* d, Stmt const* s)
{
  d->set_body(s);
}


void
define(Decode_decl* d, Stmt const* s)
{
  d->set_body(s);
}


// -------------------------------------------------------------------------- //
//                             Garbage collection

void
mark(Decl const* d)
{
  lingo_assert(is_valid_node(d));
  if (is<Variable_decl>(d)) return mark(cast<Variable_decl>(d));
  if (is<Constant_decl>(d)) return mark(cast<Constant_decl>(d));
  if (is<Function_decl>(d)) return mark(cast<Function_decl>(d));
  if (is<Parameter_decl>(d)) return mark(cast<Parameter_decl>(d));
  if (is<Member_decl>(d)) return mark(cast<Member_decl>(d));
  if (is<Record_decl>(d)) return mark(cast<Record_decl>(d));
  if (is<Variant_decl>(d)) return mark(cast<Variant_decl>(d));
  if (is<Enum_decl>(d)) return mark(cast<Enum_decl>(d));
  if (is<Decode_decl>(d)) return mark(cast<Decode_decl>(d));
  if (is<Table_decl>(d)) return mark(cast<Table_decl>(d));
  if (is<Flow_decl>(d)) return mark(cast<Flow_decl>(d));
  if (is<Extracts_decl>(d)) return mark(cast<Extracts_decl>(d));
  if (is<Rebind_decl>(d)) return mark(cast<Rebind_decl>(d));
  lingo_unreachable("unevaluated node '{}'", d->node_name());
}


} // namespace steve

