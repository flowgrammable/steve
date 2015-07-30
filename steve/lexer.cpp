// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#include "steve/lexer.hpp"

#include "lingo/lexing.hpp"
#include "lingo/symbol.hpp"

#include <cassert>
#include <cctype>
#include <iostream>
#include <string>


using namespace lingo;

namespace steve
{

namespace
{

// A helper function to consume whitespace.
inline void
whitespace(Character_stream& cs)
{
  using namespace lingo;
  auto pred = [](Character_stream& s) { return next_element_if(s, is_space); };
  discard_if(cs, pred);
}


// Consume until the end of line.
void
comment(Lexer& lex, Character_stream& cs, Location loc)
{
  char const* init = cs.begin();
  while (next_element_is_not(cs, '\n'))
    cs.get();
  lex.on_comment(loc, init, cs.begin());
}


// Lexically analyze a single token.
Token
token(Lexer& lex, Character_stream& cs)
{
  while (!cs.eof()) {
    Location loc = cs.location();
    switch (cs.peek()) {
    case ' ':
    case '\t':
    case '\n':
      // Consume the WS and continue lexing.
      cs.get();
      break;

    case '(': return lex.on_monograph(loc, &cs.get());
    case ')': return lex.on_monograph(loc, &cs.get());

    case '{': return lex.on_monograph(loc, &cs.get());
    case '}': return lex.on_monograph(loc, &cs.get());
    case '[': return lex.on_monograph(loc, &cs.get());
    case ']': return lex.on_monograph(loc, &cs.get());
    case ';': return lex.on_monograph(loc, &cs.get());
    case ':': return lex.on_monograph(loc, &cs.get());
    case ',': return lex.on_monograph(loc, &cs.get());
    
    case '.':
      if (nth_element_is(cs, 1, '.'))
        return lex.on_digraph(loc, get_n(cs, 2));
      else
        return lex.on_monograph(loc, &cs.get());

    case '<': 
      if (nth_element_is(cs, 1, '='))
        return lex.on_digraph(loc, get_n(cs, 2));
      else if (nth_element_is(cs, 1, '<'))
        return lex.on_digraph(loc, get_n(cs, 2));
      else
        return lex.on_monograph(loc, &cs.get());

    case '>':
      if (nth_element_is(cs, 1, '='))
        return lex.on_digraph(loc, get_n(cs, 2));
      if (nth_element_is(cs, 1, '>'))
        return lex.on_digraph(loc, get_n(cs, 2));
      else
        return lex.on_monograph(loc, &cs.get());
    
    case '=': 
      if (nth_element_is(cs, 1, '='))
        return lex.on_digraph(loc, get_n(cs, 2));
      if (nth_element_is(cs, 1, '>'))
        return lex.on_digraph(loc, get_n(cs, 2));
      else
        return lex.on_monograph(loc, &cs.get());
    
    case '!': 
      if (nth_element_is(cs, 1, '='))
        return lex.on_digraph(loc, get_n(cs, 2));
      else
        return lex.on_monograph(loc, &cs.get());

    case '&': 
      if (nth_element_is(cs, 1, '&'))
        return lex.on_digraph(loc, get_n(cs, 2));
      else
        return lex.on_monograph(loc, &cs.get());
    
    case '|': 
      if (nth_element_is(cs, 1, '|'))
        return lex.on_digraph(loc, get_n(cs, 2));
      else
        return lex.on_monograph(loc, &cs.get());
    
    case '^': return lex.on_monograph(loc, &cs.get());
    case '~': return lex.on_monograph(loc, &cs.get());

    case '+': return lex.on_monograph(loc, &cs.get());
    case '*': return lex.on_monograph(loc, &cs.get());
    
    case '-': 
      if (nth_element_is(cs, 1, '>'))
        return lex.on_digraph(loc, get_n(cs, 2));
      else
        return lex.on_monograph(loc, &cs.get());
    
    case '/': 
      // For comments, consume the comment and loop.
      if (nth_element_is(cs, 1, '/')) {
        comment(lex, cs, loc);
        break;
      }
      return lex.on_monograph(loc, &cs.get());
    
    case '%': return lex.on_monograph(loc, &cs.get());
    
    default:
      // TODO: Expand cases.
      if (is_ident_head(cs.peek()))
        return lex_identifier(lex, cs, loc);
      
      // TODO: Expand to cases.
      if (is_decimal_digit(cs.peek()))
        return lex_number(lex, cs, loc);
      
      error(loc, "unrecognized character '{}'", cs.peek());
      cs.get();
    }
  }

  return {};
}


} // namespace


Token
Lexer::on_monograph(Location loc, char const* str)
{
  return Token(loc, str, 1);
}


Token
Lexer::on_digraph(Location loc, char const* str)
{
  return Token(loc, str, 2);
}


// FIXME: For all of the integer functions, associate the token's
// elaboration with the symbol.

Token
Lexer::on_binary_integer(Location loc, char const* first, char const* last)
{
  return Token(loc, binary_integer_tok, first, last);
}


Token
Lexer::on_octal_integer(Location loc, char const* first, char const* last)
{
  return Token(loc, octal_integer_tok, first, last);
}


Token
Lexer::on_decimal_integer(Location loc, char const* first, char const* last)
{
  return Token(loc, decimal_integer_tok, first, last);
}


Token
Lexer::on_hexadecimal_integer(Location loc, char const* first, char const* last)
{
  return Token(loc, hexadecimal_integer_tok, first, last);
}


// Return either a keyword or an identifier.
//
// TODO: Handle the lexing of intN tokens.
Token
Lexer::on_identifier(Location loc, char const* first, char const* last)
{
  Symbol& sym = get_symbol(first, last);
  if (sym.desc.kind == language_sym)
    return Token(loc, sym);
  else
    return Token::make_identifier(loc, sym);
}


// TODO: Cache comments for the purpose of doc association later.
void
Lexer::on_comment(Location, char const*, char const*)
{
}


Token
Lexer::on_expected(char const* what)
{
  error(Location::none, "expected '{}'", what);
  return {};
}


Token
Lexer::on_expected(Location loc, char const* what)
{
  error(loc, "expected '{}'", what);
  return {};
}


Token
Lexer::on_expected(Location loc, char const* what, Token const& tok)
{
  error(loc, "expected '{}' but got '{}'", what, tok.token_spelling());
  return {};
}




// Lex all tokens in the character stream.
Token_list 
lex(Buffer& buf)
{
  Character_stream cs(buf);
  Lexer lexer;
  Token_list toks;
  while (Token tok = token(lexer, cs))
    toks.push_back(tok);
  return toks;
}


} // namespace steve
