// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#ifndef STEVE_LEXER_HPP
#define STEVE_LEXER_HPP

#include "steve/prelude.hpp"
#include "steve/token.hpp"

#include "lingo/character.hpp"


namespace steve
{

// The Lexer is a function that maps a character stream into
// tokens. Each call to an object of this type returns the
// next token in the stream in the underlying character stream.
//
// Each successive token is cached by the lexer.
struct Lexer
{
  using argument_type = char;
  using result_type = Token;

  // Semantic actions.
  Token on_monograph(Location, char const*);
  Token on_digraph(Location, char const*);

  Token on_identifier(Location, char const*, char const*);
  Token on_binary_integer(Location, char const*, char const*);
  Token on_octal_integer(Location, char const*, char const*);
  Token on_decimal_integer(Location, char const*, char const*);
  Token on_hexadecimal_integer(Location, char const*, char const*);

  void on_comment(Location, char const*, char const*);

  Token on_expected(char const*);
  Token on_expected(Location, char const*);
  Token on_expected(Location, char const*, Token const&);

  Token_list tokens;
};


Token_list lex(Buffer&);


} // namespace steve


#endif
