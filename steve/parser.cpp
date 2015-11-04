// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#include "steve/parser.hpp"
#include "steve/builder.hpp"
#include "steve/lookup.hpp"

namespace steve
{


// -------------------------------------------------------------------------- //
//                              File parser


namespace
{



// -------------------------------------------------------------------------- //
//                             Helper Functions

Expr const*
on_field_expr_access(Token const* tok, Field_expr const* field, Lookup_expr const* mem)
{
  // if the obj is a field expr then
  // it has record type
  if (Record_type const* rt = as<Record_type>(field->field_type())) {
    // find the member decl
    if (Member_decl const* member = find_member(as<Record_decl>(rt->decl()), mem->name()))
      return make_field_expr(tok->location(), field, id(member));
    else
      error(mem->location(), "Invalid member specifier '{}'.", mem);
  }
  else
    error(field->location(), "Expected object of record type. Found '{}' object of type '{}'.", field, field->type());
}


Expr const*
on_member_expr_access(Token const* tok, Member_expr const* obj, Lookup_expr const* mem)
{
  // if the obj is a member expr then
  // it has record type
  if (Record_type const* rt = as<Record_type>(obj->type())) {
    // find the member decl
    if (Member_decl const* member = find_member(as<Record_decl>(rt->decl()), mem->name()))
      return make_member_expr(tok->location(), obj, id(member));
    else
      error(mem->location(), "Invalid member specifier '{}'.", mem);
  }
  else
    error(obj->location(), "Expected object of record type. Found object of type '{}'.", obj->type());
}


Expr const*
on_identifier_access(Token const* tok, Id_expr const* ID, Lookup_expr const* mem)
{
  // if e1 is object type then it is a member-expr
  if (is_object_type(ID->type())) {

    // resolve the lookup expr now
    // if the obj is a field expr then
    // it has record type
    if (Record_type const* rt = as<Record_type>(ID->type())) {
      // find the member decl
      if (Member_decl const* member = find_member(as<Record_decl>(rt->decl()), mem->name()))
        return make_member_expr(tok->location(), ID, id(member));
      else
        error(mem->location(), "Invalid member specifier '{}'.", mem);
    }
    else
      error(ID->location(), "Expected object of record type. Found object '{}' of type '{}'.", ID, ID->type());
  }

  // if obj is of kind type then it is a field-expr
  // and obj is an identifier to a record decl
  if (ID->type() == get_kind_type()) {
    // resolve the lookup expr now
    // this is an identifier to a record decl
    if (Record_decl const* rd = as<Record_decl>(ID->decl())) {
      if (Member_decl const* member = find_member(rd, mem->name()))
        return make_field_expr(tok->location(), ID, id(member));
      else
        error(mem->location(), "Invalid member specifier '{}'.", mem);
    }
  }

  error(ID->location(), "Failed to parse identifier following '.'");
}

} // namespace


Stmt_seq
parse_file(Parser& p, Token_stream& ts)
{
  Stmt_seq stmts;
  while (!ts.eof()) {
    if (Required<Stmt> s = parse_stmt(p, ts))
      stmts.push_back(*s);
    else
      break;
  }
  return stmts;
}


Stmt_seq
parse_file(Token_stream& ts)
{
  Parser p;
  return parse_file(p, ts);
}



// -------------------------------------------------------------------------- //
//                              Name semantics

String const* 
Parser::on_name(Token const* tok)
{
  return tok->str();
}


// -------------------------------------------------------------------------- //
//                              Type semantics


Type const*
Parser::on_id_type(Token const* tok)
{
  Decl const* decl = lookup_decl(tok->str());
  if (!decl) {
    error("Invalid type identifier '{}'", tok->str());
    return get_error_type();
  }

  // TODO: Support type aliases.
  return get_user_defined_type(decl);
}


Type const*
Parser::on_void_type(Token const*)
{
  return get_void_type();
}


Type const*
Parser::on_boolean_type(Token const*)
{
  return get_boolean_type();
}


Type const*
Parser::on_integer_type(Token const*, int p, Integer_sign s, Integer_order o)
{
  return get_integer_type(p, s, o);
}


Type const*
Parser::on_constant_type(Token const*, Type const* t)
{
  return get_constant_type(t);
}


Type const*
Parser::on_reference_type(Token const*, Type const* t)
{
  return get_reference_type(t);
}


// -------------------------------------------------------------------------- //
//                            Expression semantics

Expr const*
Parser::on_id_expr(Token const* tok)
{
  Overload const* ovl = lookup(tok->str());
  if (ovl && ovl->is_singleton())
    return make_id_expr(tok->location(), ovl->front());
  else
    return make_lookup_expr(tok->location(), tok->str());
}


Expr const*
Parser::on_boolean_expr(Token const* tok)
{
  return make_bool_expr(tok->location(), as_bool(*tok));
}


Expr const*
Parser::on_integer_expr(Token const* tok)
{
  return make_int_expr(tok->location(), as_int(*tok));
}


Expr const*
Parser::on_tuple_expr(Token const* tok, Expr_seq const& elems)
{
  return nullptr;
}


Expr const*
Parser::on_call_expr(Token const* tok, Expr const* fn, Arg_seq const* args)
{
  // FIXME: If fn is a lookup-expr, then we need to perform
  // overload resolution.
  return make_call_expr(tok->location(), fn, *args);
}



// Parse a dot expression.
//
//    dot-expression ::= postfix-expression '.' postfix-expression
//
// A dot expr can either be a member-expr or a field-expr depending
// on the type if identifier on the left hand side of the '.'
//
// Member-expr if: lhs is an identifier to a declaration of object type OR
//                 lhs is a member-expr
//
// Field-expr if: lhs declaration is of kind type (i.e. record) OR
//                lhs is a field-expr
//
//
//    member-expression ::= obj-id '.' member-id
//                          member-expression '.' member-id
//
//    field-expression ::= record-id '.' member-id
//                         field-expression '.' member-id
//
//    index-expression ::= obj-id '.' integer-literal
//                         index-expr '.' integer-literal
//                         member-expr '.' integer-literal

Expr const*
Parser::on_dot_expr(Token const* tok, Expr const* obj, Expr const* mem)
{
  // FIXME: implement index expressions

  // The member expression should be an unresolved
  // lookup expr. Resolve the lookup expr here.
  lingo_assert(is<Lookup_expr>(mem));
  Lookup_expr const* lookup = as<Lookup_expr>(mem);

  // check if the obj is a member-expr
  if (Member_expr const* member = as<Member_expr>(obj)) {
    return on_member_expr_access(tok, member, lookup);
  }


  // Check if the obj is a field expr
  if (Field_expr const* field = as<Field_expr>(obj)) {
    return on_field_expr_access(tok, field, lookup);
  }


  // Check to see if the first element is an identifier
  if (Id_expr const* ID = as<Id_expr>(obj)) {
    return on_identifier_access(tok, ID, lookup);
  }

  error(obj->location(), "Invalid identifier found in dot expr.");
  return make_error_node<Expr>();
}


Expr const*
Parser::on_unary_expr(Token const* tok, Expr const* e)
{
  Location loc = tok->location();
  switch (tok->kind()) {
  case plus_tok: 
    return make_unary_expr(loc, num_pos_op, e);
  case minus_tok: 
    return make_unary_expr(loc, num_neg_op, e);
  case tilde_tok: 
    return make_unary_expr(loc, bit_not_op, e);
  case bang_tok: 
    return make_unary_expr(loc, log_not_op, e);
  default:
    break;
  }
  lingo_unreachable();
}


// FIXME: Implement me.
Expr const*
Parser::on_binary_expr(Token const* tok, Expr const* e1, Expr const* e2)
{
  Location loc = tok->location();
  switch (tok->kind()) {
  case plus_tok: 
    return make_binary_expr(loc, num_add_op, e1, e2);
  case minus_tok: 
    return make_binary_expr(loc, num_sub_op, e1, e2);
  case star_tok: 
    return make_binary_expr(loc, num_mul_op, e1, e2);
  case slash_tok: 
    return make_binary_expr(loc, num_div_op, e1, e2);
  case percent_tok: 
    return make_binary_expr(loc, num_mod_op, e1, e2);
  case eq_eq_tok: 
    return make_binary_expr(loc, rel_eq_op, e1, e2);
  case bang_eq_tok: 
    return make_binary_expr(loc, rel_ne_op, e1, e2);
  case lt_tok: 
    return make_binary_expr(loc, rel_lt_op, e1, e2);
  case gt_tok: 
    return make_binary_expr(loc, rel_gt_op, e1, e2);
  case lt_eq_tok: 
    return make_binary_expr(loc, rel_le_op, e1, e2);
  case gt_eq_tok: 
    return make_binary_expr(loc, rel_ge_op, e1, e2);
  case amp_tok: 
    return make_binary_expr(loc, bit_and_op, e1, e2);
  case caret_tok: 
    return make_binary_expr(loc, bit_xor_op, e1, e2);
  case bar_tok: 
    return make_binary_expr(loc, bit_or_op, e1, e2);
  case lt_lt_tok: 
    return make_binary_expr(loc, bit_lsh_op, e1, e2);
  case gt_gt_tok: 
    return make_binary_expr(loc, bit_rsh_op, e1, e2);
  case amp_amp_tok: 
    return make_binary_expr(loc, log_and_op, e1, e2);
  case bar_bar_tok: 
    return make_binary_expr(loc, log_or_op, e1, e2);
  default:
    break;
  }
  lingo_unreachable();
}


// Returns a new default initilizer. Note that the type
// of the initialized expression is  null. We need to adjust
// type to match the variable before creating it.
//
// The token is the ';'.
//
// TODO: This is almost like type deduction in reverse.
Expr const*
Parser::on_default_init(Token const* tok, Type const* t)
{
  return make_init_expr(default_init, make_default_expr(tok->location(), t));
}


// Returns a new direct initializer.
//
// The token is the '=' token. This is currently
// unused.
//
// TODO: If `e` is "default", then this should return a
// value initializer (performs zero initialization).
Expr const*
Parser::on_direct_init(Token const*, Expr const* e)
{
  return make_init_expr(direct_init, e);
}


// Declares a variable having the given name and type.
Decl const*
Parser::on_variable_decl(Token const* d, Token const* n, Type const* t)
{
  Decl const* var = make_variable_decl(d->location(), n->str(), t);
  declare(var);
  return var;
}


// Update a variable declaration wiht its initializer.
//
// TODO: Support type deduction for variables.
Decl const*
Parser::on_variable_init(Decl const* d, Expr const* e)
{
  Variable_decl const* var = cast<Variable_decl>(d);
  Init_expr const* init = cast<Init_expr>(e);

  // For direct initialization, convert the initializer
  // to the type of the variable. Adjust the initializer
  // as needed.
  if (init->init() == direct_init) {
    Expr const* c = convert(init->expr(), var->type());
    if (!c)
      return nullptr;
    modify(init)->set_expr(c);
  }
  modify(init)->set_type(var->type());

  // Update the variable.
  modify(var)->set_init(init);
  return var;
}


// Declares a variable having the given name and type.
Decl const*
Parser::on_function_decl(Token const* d, Token const* n, Decl_seq const& p, Type const* t)
{
  Decl const* fn = make_function_decl(d->location(), n->str(), p, t);
  declare(fn);
  return fn;
}


// Update a function declaration with its body.
//
// TODO: Support return type deduction.
Decl const*
Parser::on_function_def(Decl const* d, Stmt const* s)
{
  Function_decl const* fn = cast<Function_decl>(d);

  // Check that the function's body has an appropriate
  // return type.
  if (!check_function_decl(fn->ret_type(), s))
    return nullptr;

  // Update the function body.
  modify(fn)->set_body(s);
  return fn;
}


// Start the function definition by declaring all parameters. 
Decl const*
Parser::on_function_start(Decl const* d)
{
  Function_decl const* f = cast<Function_decl>(d);
  for (Decl const* p : f->parms()) {
    if (!declare(p))
      d = make_error_node<Decl>();
  }
  return d;
}


// Finish the function definitionby assigning the statement.
Decl const*
Parser::on_function_finish(Decl const* d, Stmt const* s)
{
  Function_decl const* f = cast<Function_decl>(d);
  if (check_function_decl(f->ret_type(), s)) {
    modify(f)->set_body(s);
    return f;
  }
  return make_error_node<Decl>();
}


// Create but do not declare parameter declaration.
Decl const*
Parser::on_parameter_decl(Token const* n, Type const* t)
{
  return make_parameter_decl(n->location(), n->str(), t);
}


Decl const*
Parser::on_record_decl(Token const* n, Decl_seq const& d)
{
  Decl const* decl = make_record_decl(n->location(), n->str(), d);
  declare(decl);
  return decl;
}


Decl const*
Parser::on_member_decl(Token const* n, Type const* t)
{
  return make_member_decl(n->location(), n->str(), t);
}


Decl const*
Parser::on_decode_decl(Token const* kw, Token const* n, Type const* t, Stmt const* s)
{
  Decl const* decl = make_decode_decl(kw->location(), n->str(), t, s);
  declare(decl);
  return decl;
} 



// ----------------------------------------------------------------- //
//                Statements


// Create a new declaration statement.
Stmt const*
Parser::on_declaration_stmt(Decl const* d)
{
  return make_decl_stmt(d);
}


// Make an empty stmt
Stmt const*
Parser::on_empty_stmt(Token const* tok)
{
  return make_empty_stmt(tok->location());
}


// Make a block stmt
Stmt const*
Parser::on_block_stmt(Token const* l, Token const* r, Stmt_seq const& s)
{
  return make_block_stmt(l->location(), r->location(), s);
}


// Create a new expression statement
Stmt const*
Parser::on_expr_stmt(Expr const* e)
{
  return make_expr_stmt(e);
}


// Create a new return statement.
Stmt const*
Parser::on_return_stmt(Expr const* e)
{
  return make_return_stmt(e);
}


// Install the grammar rule/name associations.
//
// TODO: Actually add grammar names.
void
init_grammar()
{
  
}


} // namespace steve

