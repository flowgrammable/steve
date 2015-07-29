// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#include "steve/debug.hpp"
#include "steve/type.hpp"
#include "steve/expr.hpp"
#include "steve/decl.hpp"
#include "steve/stmt.hpp"
#include "steve/print.hpp"

namespace steve
{

namespace
{

// The print funciton dispatches to an appropriate
// overload.
struct Debug_fn
{
  Debug_fn(Printer& p)
    : p(p)
  { }

  template<typename T>
  void operator()(T const* t) { return debug(p, t); }

  Printer& p;
};


// Print the type of an expression as an attribute
// within the s-expr.
void
debug_expr_type(Printer& p, Type const* t)
{
  debug(p, "type:");
  debug(p, t);
}


// Common implementation of debug printing for
// the different root classes. This handles both
// null and error terms.
template<typename T>
void
debug_term(Printer& p, T const* t)
{
  if (!t) {
    debug(p, "<null>");
    return;
  }

  if (is_error_node(t)) {
    debug(p, "<error>");
    return;
  }

  Debug_fn fn(p);
  apply(t, fn);
}


} // namespace


// Debug a type by printing it.
void 
debug(Printer& p, Type const* t)
{
  debug_term(p, t);
}


void
debug(Printer& p, Integer_type const* t)
{
  print(p, t);
}


void
debug(Printer& p, Function_type const* t)
{
  sexpr<Function_type> _(p, t);
  debug_flat_list(p, t->parm_types());
  print_space(p);
  debug(p, t->ret_type());
}


// Emit a debug representation of the given expression.
void 
debug(Printer& p, Expr const* e)
{
  debug_term(p, e);
}


// Write out the type of the value as an attriute
void
debug(Printer& p, Value_expr const* e)
{
  sexpr<Value_expr> s(p, e);
  debug_expr_type(p, e->type());
  print_space(p);
  debug(p, e->first);
}


static char const*
conversion_name(Conversion_kind k)
{
  switch (k) {
    case boolean_prom: return "boolean_prom";
    case enumeration_prom: return "enumeration_prom";
    case boolean_conv: return "boolean_conv";
    case integer_conv: return "integer_conv";
    case record_conv: return "record_conv";
    case integer_xform: return "integer_xform";
  }
  lingo_unreachable();
}


// Specialized so that we can print the name of the
// conversion.
void 
debug(Printer& p, Convert_expr const* e)
{
  sexpr<Convert_expr> s(p, e);
  print(p, conversion_name(e->conv()));
  print_space(p);
  debug(p, e->second);
}


void
debug(Printer& p, Id_expr const* e)
{
  sexpr<Id_expr> s(p, e);
  debug(p, e->name());
}


// Emit a debug represnetation of the given declaration.
void 
debug(Printer& p, Decl const* d)
{
  debug_term(p, d);
}


// Specialized debugging for variable declarations.
void
debug(Printer& p, Variable_decl const* d)
{
  sexpr<Variable_decl> s(p, d);
  debug_space(p, d->name());
  debug_space(p, d->type());
  debug(p, d->init());
}


// FIXME: This omits both the return type and the body.
void
debug(Printer& p, Function_decl const* d)
{
  sexpr<Function_decl> s(p, d);
  debug_space(p, d->name());
  debug_space(p, d->type());
  debug(p, d->parms());
}


void
debug(Printer& p, Parameter_decl const* d)
{
  sexpr<Parameter_decl> s(p, d);
  debug_space(p, d->name());
  debug(p, d->type());
}


void
debug(Printer& p, Member_decl const* d)
{
  sexpr<Member_decl> s(p, d);
  debug_space(p, d->name());
  debug(p, d->type());
}


void
debug(Printer& p, Record_decl const* d)
{
  sexpr<Record_decl> s(p, d);
  debug_space(p, d->name());
  debug_space(p, d->type());
  debug_nested_list(p, d->members());
}


// Emit a debug represnetation of the given statement.
void 
debug(Printer& p, Stmt const* s)
{
  debug_term(p, s);
}


// Specialized debugging for variable declarations.
void
debug(Printer& p, Block_stmt const* s)
{
  sexpr<Block_stmt> _(p, s);
  debug_nested_list(p, *s);
}


} // namespace steve