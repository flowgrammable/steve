// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#include "steve/parser.hpp"
#include "steve/builder.hpp"
#include "steve/lookup.hpp"

namespace steve
{

namespace
{

// -------------------------------------------------------------------------- //
//                                Type parsers

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


Type const*
parse_uint_type(Parser& p, Token_stream& ts)
{
  Token const* int_kind = get_token(ts);

  // check for the bit length specifier
  if (next_token_kind(ts) == lparen_tok) {
    // consume paren
    get_token(ts);
    if (next_token_kind(ts) == integer_tok) {
      Token const* i = get_token(ts);
      int precision = stoi(*i->str());

      if (next_token_kind(ts) == rparen_tok) {
        get_token(ts);
        return p.on_integer_type(int_kind, precision, unsigned_int, native_order);
      }
      else
        return get_error_type();
    }
    else
      error("Expected integer token after '(' in uint length specifier.");
  }
  
  return p.on_integer_type(int_kind, 32, unsigned_int, native_order);
}


} // namesapce


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
      return parse_uint_type(p, ts);
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


Type const*
parse_type(Token_stream& ts)
{
  Parser p;
  return parse_type(p, ts);
}


} // namespace steve

