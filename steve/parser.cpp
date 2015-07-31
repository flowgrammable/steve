// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#include "steve/parser.hpp"
#include "steve/builder.hpp"
#include "steve/lookup.hpp"

#include "lingo/parsing.hpp"

namespace steve
{

namespace
{

// Indicates the presence of an error. Note that when an error
// occurs, a diagnostic has been emitted (unless suppressed)
// for the corresponding error.
//
// A parse function that returns a nullptr has simply failed
// to match a term. That may or may not indicate an error.
//
void* error_ = make_error_node<void>();


} // namespace


// The type of a parse function. Use to disambiguate
// overloads in certain cases.
using Parse_fn = Expr const* (*)(Parser&, Token_stream&);


// -------------------------------------------------------------------------- //
//                                Type parsers

Type const* parse_type(Parser&, Token_stream&);


// Parse a constant type.
//
//    constant-type ::= 'const' type
Type const*
parse_constant_type(Parser& p, Token_stream& ts)
{
  Token const* tok = require_token(ts, const_kw);
  if (Required<Type> t = parse_type(p, ts))
    return p.on_constant_type(tok, *t);
  else
    return *t;
}


// Parse a reference type.
//
//    reference-type ::= 'ref' type
Type const*
parse_reference_type(Parser& p, Token_stream& ts)
{
  Token const* tok = require_token(ts, ref_kw);
  if (Required<Type> t = parse_type(p, ts))
    return p.on_reference_type(tok, *t);
  else
    return *t;
}


Type const*
parse_if_type(Parser& p, Token_stream& ts)
{
  lingo_unreachable("not implemented");
}


Type const*
parse_match_type(Parser& p, Token_stream& ts)
{
  lingo_unreachable("not implemented");
}


Type const*
parse_seq_type(Parser& p, Token_stream& ts)
{
  lingo_unreachable("not implemented");
}


Type const*
parse_buffer_type(Parser& p, Token_stream& ts)
{
  lingo_unreachable("not implemented");
}


Type const*
parse_until_type(Parser& p, Token_stream& ts)
{
  lingo_unreachable("not implemented");
}



// Parse a type.
//
//    type ::= 'void' 
//           | 'bool' 
//           | integer-type 
//           | constant-type
//           | reference-type
//           | ...
//           | id-type
//
// TODO: Add a parser for function and tuple types.
Type const*
parse_type(Parser& p, Token_stream& ts)
{
  switch (next_token_kind(ts)) {
    case void_kw:
      return p.on_void_type(get_token(ts));
    case bool_kw:
      return p.on_boolean_type(get_token(ts));
    case short_kw:
      return p.on_integer_type(get_token(ts), 16, signed_int, native_order);
    case ushort_kw:
      return p.on_integer_type(get_token(ts), 16, unsigned_int, native_order);
    case int_kw:
      return p.on_integer_type(get_token(ts), 32, signed_int, native_order);
    case uint_kw:
      return p.on_integer_type(get_token(ts), 32, unsigned_int, native_order);
    case long_kw:
      return p.on_integer_type(get_token(ts), 64, signed_int, native_order);
    case ulong_kw:
      return p.on_integer_type(get_token(ts), 64, unsigned_int, native_order);
    case const_kw:
      return parse_constant_type(p, ts);
    case ref_kw:
      return parse_reference_type(p, ts);
    case if_kw:
      return parse_if_type(p, ts);
    case match_kw:
      return parse_match_type(p, ts);
    case seq_kw:
      return parse_seq_type(p, ts);
    case buffer_kw:
      return parse_buffer_type(p, ts);
    case until_kw:
      return parse_until_type(p, ts);
    case identifier_tok:
      return p.on_id_type(get_token(ts));
    default:
      break;
  }
  
  // FIXME: Improve diagnostics?
  error(ts.location(), "invalid type");
  return get_error_type();
}


// -------------------------------------------------------------------------- //
//                            Expression parsers
//
// There are a number of different expression parsers.


Expr const* parse_primary_expr(Parser&, Token_stream&);
Expr const* parse_postfix_expr(Parser&, Token_stream&);
Expr const* parse_prefix_expr(Parser&, Token_stream&);
Expr const* parse_binary_expr(Parser&, Token_stream&);
Expr const* parse_expr(Parser&, Token_stream&);


// -------------------------------------------------------------------------- //
//                            Primary expressions

// Parse a tuple expression.
//
//    nested-expression ::= '{' argument-list '}'
//
// TODO: There is an ambiguity with expression statements whose
// expression is a tuple and a block statement. Choose the block
// statement.
Expr const*
parse_tuple_expr(Parser& p, Token_stream& ts)
{
  lingo_unreachable("not implemented");
}


// Parse a nested sub-expression.
//
//    nested-expression ::= '(' expression ')'
Expr const*
parse_nested_expr(Parser& p, Token_stream& ts)
{
  Parse_fn parse = parse_expr;
  return parse_paren_enclosed(p, ts, parse);
}


// Parse a primary expression.
//
//    primary-expression ::= literal 
//                         | id-expression 
//                         | tuple-expression
//                         | nested-expression
//
//    literal ::= boolean-literal | integer-literal
Expr const*
parse_primary_expr(Parser& p, Token_stream& ts)
{
  switch (next_token_kind(ts)) {
    case boolean_tok:
      return p.on_boolean_expr(get_token(ts));
    
    case binary_integer_tok:
    case octal_integer_tok:
    case decimal_integer_tok: 
    case hexadecimal_integer_tok:
      return p.on_integer_expr(get_token(ts));
    
    case identifier_tok:
      return p.on_id_expr(get_token(ts));
    
    case lparen_tok:
      return parse_nested_expr(p, ts);

    case lbrace_tok:
      return parse_tuple_expr(p, ts);
    
    default:
      break;
  }
  error(ts.location(), "invalid primary-expression");
  return get_error_expr();
}


// -------------------------------------------------------------------------- //
//                            Postfix expressions


// Parse a function argument.
//
//    function-argument ::= expression
//
// This is a placeholder that would allow us to accept
// non-expression arguments in the future.
inline Expr const*
parse_argument(Parser& p, Token_stream& ts)
{
  return parse_expr(p, ts);
}


// Parse an argument list.
//
//    function-argument-list ::= list(function-argument)
inline Expr_seq
parse_argument_list(Parser& p, Token_stream& ts)
{
  return parse_list(p, ts, parse_argument);
}


// Parse a call expression.
//
//    call-expression ::= postfix-expression '(' argument-list ')'
//
// TODO: This is copying the argument vector. We should be
// moving it.
Expr const*
parse_call_expr(Parser& p, Token_stream& ts, Expr const* expr) 
{
  Token const* tok = ts.begin(); 
  if (Optional<Expr_seq> args = parse_paren_enclosed(p, ts, parse_argument_list))
    return p.on_call_expr(tok, expr, *args);
  else
    return get_error_expr();
}


// Parse a dot expression.
//
//    dot-expression ::= postfix-expression '.' postfix-expression
Expr const*
parse_member_expr(Parser& p, Token_stream& ts, Expr const* e1) 
{
  Token const* tok = require_token(ts, dot_tok);
  if (Required<Expr> e2 = parse_primary_expr(p, ts))
    return p.on_member_expr(tok, e1, *e2);
  else
    return *e2;
}


// Parse a postfix expression. This is the entry point to all
// binary or n-ary expressions parsed at this precedence.
//
//    postfix-expression ::= call-expression
//                         | member-expression
//                         | primary-expression
//
// TODO: Add subscript expressions. Other stuff?
Expr const*
parse_postfix_expr(Parser& p, Token_stream& ts) {
  if (Expr const* e1 = parse_primary_expr(p, ts)) {
    while (e1) {
      Expr const* e2;
      switch (next_token_kind(ts)) {
      case lparen_tok: 
        e2 = parse_call_expr(p, ts, e1);
        break;

      case dot_tok:
        e2 = parse_member_expr(p, ts, e1);
        break;

      default:
        e2 = nullptr;
        break;
      }

      if (not e2)
        break;

      e1 = e2;
    }
    return e1;
  }
  return {};
}


// -------------------------------------------------------------------------- //
//                           Prefix expressions

// Parse a prefix operator.
//
//    prefix-operator ::= '+' | '-' | '!'
Token const*
parse_unary_op(Parser& p, Token_stream& ts)
{
  switch (next_token_kind(ts)) {
  case plus_tok:
  case minus_tok:
  case bang_tok:
  case tilde_tok:
    return get_token(ts);

  default:
    return nullptr;
  }
}


// Parse a unary expression.
//
//    unary-expression ::= postfix-expression
//                       | unary-operator unary-expression
inline Expr const*
parse_unary_expr(Parser& p, Token_stream& ts)
{
  Token const* tok = ts.begin();
  if (Required<Expr> e = parse_prefix_term(p, ts, parse_unary_op, parse_postfix_expr))
    return p.on_unary_expr(tok, *e);
  else {
    // FIXME: This isn't right. If e is an error, then
    // return that error.
    return nullptr;
  }
}


Expr const*
parse_expr(Parser& p, Token_stream& ts)
{
  return parse_postfix_expr(p, ts);
}



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
  if (!decl)
    return get_error_type();

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
  return make_bool_expr(tok->location(), as_boolean(*tok));
}


Expr const*
Parser::on_integer_expr(Token const* tok)
{
  return make_int_expr(tok->location(), as_integer(*tok));
}


Expr const*
Parser::on_tuple_expr(Token const* tok, Expr_seq const& elems)
{
  return nullptr;
}


Expr const*
Parser::on_call_expr(Token const* tok, Expr const* fn, Expr_seq const& args)
{
  // FIXME: If fn is a lookup-expr, then we need to perform
  // overload resolution.
  return make_call_expr(tok->location(), fn, args);
}


Expr const*
Parser::on_member_expr(Token const* tok, Expr const* obj, Expr const* mem)
{
  // FIXME: The member could be either an id-expr, a field expr,
  // or an integer expression. Determine what's actually meant.

  // FIXME: If we use '.' for nested name specifiers, this could also
  // be part of a nested name specifier.
  return make_member_expr(tok->location(), obj, mem);
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


// -------------------------------------------------------------------------- //
//                              Error handling


void*
Parser::on_expected(char const* what)
{
  error("expected '{}'", what);
  return make_error_node<void>();
}


void*
Parser::on_expected(Location loc, char const* what)
{
  error(loc, "expected '{}'", what);
  return make_error_node<void>();
}


void*
Parser::on_expected(Location loc, char const* what, Token const& tok)
{
  error(loc, "expected '{}' but got '{}'", what, tok.token_spelling());
  return make_error_node<void>();
}


void*
Parser::on_error()
{
  return make_error_node<void>();
}


// Install the grammar rule/name associations.
void
init_grammar()
{
  
}


} // namespace steve

