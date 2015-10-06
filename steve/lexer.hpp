// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#ifndef STEVE_LEXER_HPP
#define STEVE_LEXER_HPP

// The lexer module defines the lexical analysis phase of
// the steve compiler.

#include "steve/prelude.hpp"
#include "steve/token.hpp"

#include "lingo/character.hpp"


namespace steve
{

// The Lexer class defines the actions taken whenever
// a sequence of characters as a particular kind of token.
//
// TODO: Implement lexing for precise integer types.
struct Lexer
{
  using argument_type = char;
  using result_type = Token;

  // Semantic actions.
  Token on_monograph(Location, char const*);
  Token on_digraph(Location, char const*);

  Token on_identifier(Location, char const*, char const*);
  Token on_integer(Location loc, char const*, char const*, int);
  Token on_binary_integer(Location, char const*, char const*);
  Token on_octal_integer(Location, char const*, char const*);
  Token on_decimal_integer(Location, char const*, char const*);
  Token on_hexadecimal_integer(Location, char const*, char const*);

  void on_comment(Location, char const*, char const*);

  Token on_expected(char const*);
  Token on_expected(Location, char const*);
  Token on_expected(Location, char const*, Token const&);
};


Token_list lex(Buffer&);


} // namespace steve


#endif
