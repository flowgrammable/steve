// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#include "steve/print.hpp"
#include "steve/type.hpp"
#include "steve/expr.hpp"
#include "steve/decl.hpp"
#include "steve/stmt.hpp"


namespace steve
{

namespace
{

// -------------------------------------------------------------------------- //
//                             Operator precedence

// Determine the precedence of a binary expression
// according to the values below.
int 
precedence(Binary_expr const* e)
{
  lingo_assert(is_valid_node(e));
  switch (e->op()) {
    case num_mul_op:
    case num_div_op:
    case num_mod_op:
      return 3;

    case num_add_op:
    case num_sub_op:
      return 4;

    case bit_lsh_op:
    case bit_rsh_op:
      return 5;

    case rel_lt_op:
    case rel_gt_op:
    case rel_le_op:
    case rel_ge_op:
      return 6;

    case rel_eq_op:
    case rel_ne_op:
      return 7;

    case bit_and_op:
      return 8;

    case bit_xor_op:
      return 9;
    
    case bit_or_op:
      return 10;

    case log_and_op: 
      return 11;
    
    case log_or_op:
      return 12;
  }
  lingo_unreachable("invalid binary operator ({})", (int)e->op());
}


struct Precedence_fn
{
  int operator()(Value_expr const* t1) const { return 0; }
  int operator()(Id_expr const* t1) const { return 0; }
  int operator()(Lookup_expr const* t1) const { return 0; }
  int operator()(Constant_expr const* t1) const { return 0; }
  int operator()(Default_expr const* t1) const { return 0; }
  int operator()(Tuple_expr const* t1) const { return 0; }
  int operator()(Insert_expr const* t1) const { return 0; }
  int operator()(Delete_expr const* t1) const { return 0; }
  int operator()(Unary_expr const* t1) const { return 1; }
  int operator()(Lengthof_expr const* t1) const { return 1; }
  int operator()(Offsetof_expr const* t1) const { return 1; }
  int operator()(Headerof_expr const* t1) const { return 1; }
  int operator()(Do_expr const* t1) const { return 1; }
  int operator()(Call_expr const* t1) const { return 2; }
  int operator()(Init_expr const* t1) const { return 2; }
  int operator()(Index_expr const* t1) const { return 2; }
  int operator()(Member_expr const* t1) const { return 2; }
  int operator()(Field_expr const* t1) const { return 2; }
  int operator()(Convert_expr const* t1) const { return 2; }
  int operator()(Field_idx_expr const* t1) const { return 2; }
  int operator()(Header_idx_expr const* t1) const { return 2; }
  int operator()(Binary_expr const* t1) const { return precedence(t1); }
};


// Returns the precendence of the term e. The precedence of terms
// is given by the following table:
//
//    0   primary expressions
//    1   prefix expressions
//    2   postfix expressions
//    3   multiplicative expressions
//    4   additive expressions
//    5   shift expressions
//    6   ordering expressions
//    7   equality expressions
//    8   bitwise and
//    9   bitwise xor
//    10  bitwise or
//    11  logical and
//    12  logical or
int 
precedence(Expr const* e)
{
  lingo_assert(is_valid_node(e));
  return apply(e, Precedence_fn());
}


// A subexpression needs parens only when its prcedence is
// greater than that of the subexpression. This function
// returns true when the precedence of the subexpression
// is greater than or equal to that of its parent. This
// causes us to print parens when not strictly required,
// but the result looks better.
inline bool
needs_parens(Expr const* expr, Expr const* sub)
{
  return precedence(expr) <= precedence(sub);
}


} // namespace


// -------------------------------------------------------------------------- //
//                              Printing

namespace
{

// The print function dispatches to an appropriate overload.
struct Print_fn
{
  Print_fn(Printer& p)
    : p(p)
  { }

  template<typename T>
  void operator()(T const* t) { print(p, t); }

  Printer& p;
};


// Apply the print funciton to the given term.
template<typename T>
inline void 
print_term(Printer& p, T const* t)
{
  Print_fn fn(p);
  apply(t, fn);
}


} // namespace


void 
print(Printer& p, Type const* t)
{
  print_term(p, t);
}


void
print(Printer& p, Kind_type const*)
{
  print(p, "kind");
}


void
print(Printer& p, Void_type const*)
{
  print(p, "void");
}


void
print(Printer& p, Boolean_type const*)
{
  print(p, "bool");
}


void
print(Printer& p, Integer_type const* t)
{
  std::stringstream ss;

  // Write out the core type based on order and sign.
  if (t->is_native_order())
    ss << (t->is_signed() ? "int" : "uint");
  else if (t->is_msbf_order())
    ss << (t->is_signed() ? "imsbf" : "umsbf");
  else if (t->is_lsbf_order())
    ss << (t->is_signed() ? "ilsbf" : "ulsbf");

  // Append the precision.
  ss << t->precision();
  print(p, ss.str());
}


void
print(Printer& p, Constant_type const* t)
{
  print(p, "const ");
  print(p, t->type());
}


void
print(Printer& p, Reference_type const* t)
{
  print(p, "ref ");
  print(p, t->type());
}


void
print(Printer& p, Function_type const* t)
{
  print(p, '(');
  print_list(p, t->parm_types());
  print(p, ')');
  print(p, "->");
  print(p, t->ret_type());
}


void
print(Printer& p, Array_type const* t)
{
  print(p, t->type());
  print(p, '[');
  print(p, t->extent());
  print(p, ']');
}


void
print(Printer& p, Tuple_type const* t)
{
  print(p, '{');
  print_list(p, t->types());
  print(p, '}');
}


// When printing a record type, we only print it
// the name. This is generally because we're assumed
// to be in non-definition context.
void
print(Printer& p, Record_type const* t)
{
  print(p, t->decl()->name());
}


void
print(Printer& p, Variant_type const* t)
{
  print(p, t->decl()->name());
}


void
print(Printer& p, Enum_type const* t)
{
  print(p, t->decl()->name());
}


void
print(Printer& p, Table_type const* t)
{
  print(p, "table<");
  for (auto d : t->key_fields()) {
    print(p, d);
  }
  print(p, ">");
}


void
print(Printer& p, Flow_type const* t)
{
  for (auto type : t->key_types())
    print(p, type);
}


void
print(Printer& p, Match_term const* t)
{
  print(p, t->cond());
  print(p, " : ");
  print(p, t->type());
  print(p, ';');
}


void
print_match_discriminator(Printer& p, Match_type const* t)
{
  print(p, '(');
  print(p, t->disc());
  print(p, ')');
}


void
print_match_body(Printer& p, Match_type const* t)
{
  print(p, '{');
  print_nested(p, t->members());
  print(p, '}');
}


void
print(Printer& p, Match_type const* t)
{
  print(p, "match ");
  print_match_discriminator(p, t);
  print_space(p);
  print_match_body(p, t);
}


void
print(Printer& p, If_type const* t)
{
  print(p, "if");
  print(p, '(');
  print(p, t->cond());
  print(p, ')');
  print_space(p);
  print(p, t->type());
}


void
print(Printer& p, Seq_type const* t)
{
  print(p, "seq");
  print_space(p);
  print(p, t->type());
  print(p, '(');
  print(p, t->elems());
  print(p, ')');
}


void
print(Printer& p, Buffer_type const* t)
{
  print(p, "buffer");
  print_space(p);
  print(p, t->type());
  print(p, '(');
  print(p, t->length());
  print(p, ')');
}


void
print(Printer& p, Until_type const* t)
{
  print(p, "until");
  print(p, '(');
  print(p, t->cond());
  print(p, ')');
  print_space(p);
  print(p, t->type());
}


void
print(Printer& p, Expr const* e)
{
  print_term(p, e);
}


void
print(Printer& p, Id_expr const* e)
{
  print(p, e->name());
}


void
print(Printer& p, Lookup_expr const* e)
{
  print(p, e->name());
}


// Explicitly write out the literals `true` and `false`.
inline void
print_boolean(Printer& p, Value const& v)
{
  if (v.get_boolean())
    print(p, "true");
  else
    print(p, "false");
}


void
print(Printer& p, Value_expr const* e)
{
  if (is_boolean_expr(e))
    print_boolean(p, e->value());
  else
    print(p, e->value());
}


// Print a subexpression of an outer expression. This will 
// automatically add parentheses if they are needed.
inline void
print_subexpr(Printer& p, Expr const* expr, Expr const* sub)
{
  if (needs_parens(expr, sub))
    print_paren_enclosed(p, sub);
  else
    print(p, sub);
}


void
print(Printer& p, Unary_expr const* e)
{
  print(p, e->op());
  print_subexpr(p, e, e->arg());
}


void
print(Printer& p, Binary_expr const* e)
{
  print_subexpr(p, e, e->left());
  print_space(p);
  print(p, e->op());
  print_space(p);
  print_subexpr(p, e, e->right());
}


static void
print_argument_list(Printer& p, Call_expr const* e)
{
  print(p, '(');
  print_list(p, e->args());
  print(p, ')');
}


void
print(Printer& p, Call_expr const* e)
{
  print(p, e->fn());
  print_argument_list(p, e);
}


void
print(Printer& p, Tuple_expr const* e)
{
  print(p, '{');
  print_list(p, e->exprs());
  print(p, '}');

}


// A member expression is a postfix expression. We
// need to consider parens for these kinds of things.
void 
print(Printer& p, Index_expr const* e)
{
  print_subexpr(p, e, e->object());
  print(p, '.');
  print_subexpr(p, e, e->index());
}


// A member expression is a postfix expression. We
// need to consider parens for these kinds of things.
void 
print(Printer& p, Member_expr const* e)
{
  print_subexpr(p, e, e->object());
  print(p, '.');
  print_subexpr(p, e, e->selector());
}


void
print(Printer& p, Field_expr const* e)
{
  print(p, e->record());
  print(p, '.');
  print(p, e->field());
}


// Conversions are implicit, so just print the source
// argument.
void
print(Printer& p, Convert_expr const* e)
{
  print(p, e->arg());
}


void
print(Printer& p, Lengthof_expr const* e)
{
  print(p, "lengthof");
  print_paren_enclosed(p, e->arg());
}


void
print(Printer& p, Offsetof_expr const* e)
{
  print(p, "offsetof");
  print(p, '(');
  print(p, e->object());
  print(p, ", ");
  // FIXME: We should be printing the qualified name.
  print(p, e->member()->name());
  print(p, ')');
}


void
print(Printer& p, Insert_expr const* e)
{
  print(p, "insert ");
  print(p, e->flow()->name());
  print(p, " into ");
  print(p, e->table());
}


void
print(Printer& p, Delete_expr const* e)
{
  print(p, "delete ");
  print(p, e->flow()->name());
  print(p, " from ");
  print(p, e->table());
}


void
print(Printer& p, Do_expr const* e)
{
  print(p, "do ");
  switch(e->do_what()) {
  case decode: print(p, "decode "); break;
  case table: print(p, "table "); break;
  }
  print(p, e->target());
}


void
print(Printer& p, Field_idx_expr const* e)
{
  print(p, "_fields_[");
  print(p, e->field());
  print("]");
}


void
print(Printer& p, Header_idx_expr const* e)
{
  print(p, "_header_[");
  print(p, e->header());
  print(p, "]");
}


void
print(Printer& p, Decl const* d)
{
  print_term(p, d);
}


// Print an object type clause.
static void
print_type_clause(Printer& p, Decl const* d)
{
  print(p, " : ");
  print(p, d->type());
}


// Print an object initializer.
//
// NOTE: This could be used to print default arguments.
template<typename T>
static void
print_initializer_clause(Printer& p, T const* d)
{
  if (d->has_impl()) {
    print(p, " = ");
    print(p, d->init());
  }
}


template<typename T>
static void
print_object_decl(Printer& p, T const* d)
{
  print(p, d->name());
  print_type_clause(p, d);
}


void
print(Printer& p, Variable_decl const* d)
{
  print(p, "var ");
  print_object_decl(p, d);
  print_initializer_clause(p, d);
  print(p, ';');
}


// TODO: The printing of constants depends entirely
// upon its declaration context. If the declaration
// context is an enumeration, then this needs to be
// printed as an enumeraiton constant. Otherwise,
// we could print it as a normal constant. For now,
// we always print as a top-level declaration.
void
print(Printer& p, Constant_decl const* d)
{
  print(p, "const ");
  print_object_decl(p, d);
  print_initializer_clause(p, d);
  print(p, ';');
}


static void
print_parameter_list(Printer& p, Function_decl const* d)
{
  print(p, '(');
  print_list(p, d->parms());
  print(p, ')');
}


static void
print_return_clause(Printer& p, Function_decl const* d)
{
  print(p, " -> ");
  print(p, d->ret_type());
}


void
print(Printer& p, Function_decl const* d)
{
  print(p, "def ");
  print(p, d->name());
  print_parameter_list(p, d);
  print_return_clause(p, d);
  print_space(p);
  if (d->has_impl())
    print(p, d->body());
}


void
print(Printer& p, Parameter_decl const* d)
{
  print_object_decl(p, d);
}


void 
print(Printer& p, Record_decl const* d)
{
  print(p, "record ");
  print(p, d->name());
  print_space(p);
  print(p, '{');
  print_nested(p, d->members());
  print(p, '}');
}


void
print(Printer& p, Member_decl const* d)
{
  print_object_decl(p, d);
  print(p, ';');
}


void
print_enum_base(Printer& p, Enum_decl const* d)
{
  print(p, '(');
  print(p, d->base());
  print(p, ')');
}


void
print_enum_body(Printer& p, Enum_decl const* d)
{
  print(p, '{');
  print_nested(p, d->members());
  print(p, '}');
}


void 
print(Printer& p, Enum_decl const* d)
{
  print(p, "enum ");
  print(p, d->name());
  print_enum_base(p, d);
  print_space(p);
  print_enum_body(p, d);
}


void
print(Printer& p, Decode_decl const* d)
{
  print(p, "decode ");
  print(p, d->name());
  print(p, "(");
  print(p, d->header());
  print(p, ")");
  print_space(p);
  if (d->has_impl())
    print(p, d->body());
}


void
print_table_conditions(Printer& p, Table_decl const* d)
{
  print(p, "<");
  for (auto it = d->conditions().begin(); it < d->conditions().end() - 1; ++it) {
    print(p, *it);
    print(p, ", ");
  }
  print(p, *(d->conditions().end() - 1));
  print(p, ">");
}


void
print_table_initializer(Printer& p, Table_decl const* d)
{
  print(p, "{");
  print_nested(p, d->body());
  print(p, "}");
}


void
print(Printer& p, Table_decl const* d)
{
  print(p, "table ");
  print(p, d->name());
  print_table_conditions(p, d);
  print_table_initializer(p, d);
}


void
print_flow_key(Printer& p, Expr_seq const& e)
{
  for (auto it = e.begin(); it < e.end() - 1; it++) {
    print(p, *it);
    print(p, ", ");
  }
  print(p, *(e.end() - 1));
}

void
print(Printer& p, Flow_decl const* d)
{
  print(p, d->priority());
  print(p, ". {");
  print_flow_key(p, d->conditions());
  print(p, "} -> ");
  print(p, d->instructions());
}


void
print_variant_body(Printer& p, Variant_decl const* d)
{
  print(p, '{');
  print_nested(p, d->types());
  print(p, '}');
}


void
print(Printer& p, Variant_decl const* d)
{
  print(p, "variant ");
  print(p, d->name());
  print_space(p);
  print_variant_body(p, d);
}


void
print(Printer& p, Stmt const* s)
{
  print_term(p, s);
}


void
print(Printer& p, Empty_stmt const* s)
{
  print(p, ';');
}


void
print(Printer& p, Expr_stmt const* s)
{
  print(p, s->expr());
  print(p, ';');
}


void
print(Printer& p, Decl_stmt const* s)
{
  print(p, s->decl());
  print(p, ';');
}


void
print(Printer& p, Block_stmt const* s)
{
  print(p, '{');
  print_nested(p, *s);
  print(p, '}');
}


void
print(Printer& p, Return_stmt const* s)
{
  print(p, "return ");
  print(p, s->result());
  print(p, ';');
}


void
print(Printer &p, Case_stmt const* s)
{
  print(p, "case ");
  print(p, s->label());
  print(p, ": ");
  print(p, s->stmt());
}


void
print_match_body(Printer& p, Match_stmt const* s)
{
  print(p, "{");
  print_nested(p, s->cases());
  print(p, "}");
}


void
print(Printer& p, Match_stmt const* s)
{
  print(p, "match (");
  print(p, s->cond());
  print(p, ")");
  print_match_body(p, s);
}


void
print(Printer& p, Extracts_decl const* s)
{
  print(p, "extracts ");
  print(p, s->field());
}

} // namespace steve
