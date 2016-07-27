// Copyright (c) 2015 Andrew Sutton
// All rights reserved

#ifndef BEAKER_LEXER_HPP
#define BEAKER_LEXER_HPP

#include <beaker/prelude.hpp>
#include <beaker/file.hpp>
#include <beaker/line.hpp>
#include <beaker/symbol.hpp>
#include <beaker/token.hpp>

#include <cassert>
#include <cctype>


// -------------------------------------------------------------------------- //
// Input buffer

// The Input_buffer class provides a stream abstraction on top
// of an underlying string buffer and also a lexical
// view of the file (i.e., a line map) and source file
// object.
//
// The stream buffer allows the position of a character to
// be returned, which allows a lexer to save the bounds of
// a symbol. An alternative would be to have the lexer
// buffer accepted characters. Note that truly buffered
// input streams would not be able to return an iterator
// to the current character.
//
// TODO: Allow the stream buffer to be shared by multiple
// streams?
//
// TODO: The character stream produces a lexical view of
// the input source (i.e., a mapping of character offsets
// to lines). It would be nice if that view were separate
// from the stream object so that it could be re-used by
// various compiler components (e.g., diagnostics). Because
// we don't do this now, the suorce location object is
// fairly large and maintains the full source context.
class Input_buffer
{
public:
  using Position = char const*;

  Input_buffer(String const&);
  Input_buffer(std::istream&);
  Input_buffer(File const&);

  bool eof() const;

  char peek() const;
  char peek(int) const;
  char get();

  File const* file() const     { return file_; }
  Position    position() const { return pos_; }
  int         offset() const   { return pos_ - buf_.begin(); }

  int         line_no() const;
  int         column_no() const;
  Location    location() const;

private:
  File const* file_;  // The file object, if any.
  Stringbuf   buf_;   // The buffer.
  Position    pos_;   // The current position.
  Position    last_;  // Start of the current line.
  Line_map    lines_; // Line offsets.
};


inline
Input_buffer::Input_buffer(String const& s)
  : file_(nullptr), buf_(s), pos_(buf_.begin()), last_(pos_)
{ }


inline
Input_buffer::Input_buffer(std::istream& is)
  : file_(nullptr), buf_(is), pos_(buf_.begin()), last_(pos_)
{ }


// Returns true if the stream is at the end
// of the file.
inline bool
Input_buffer::eof() const
{
  return pos_ == buf_.end();
}


// Returns the current character. If at the end
inline char
Input_buffer::peek() const
{
  if (eof())
    return 0;
  else
    return *pos_;
}


// Move n characters ahead and return that char
// peek(0) returns the current character.
// If at any point eof() is hit, 0 is returned
inline char
Input_buffer::peek(int n) const
{
  if (eof())
    return 0;
  else {
    Position p = pos_;
    while(n > 0) {
      // if at any time we hit eof, return 0
      if (p == buf_.end())
        return 0;
      // otherwise advance
      p++;
      n--;
    }
    // in case the character we land on is eof
    if (p == buf_.end())
      return 0;

    return *p;
  }
}


// Returns the current line number.
inline int
Input_buffer::line_no() const
{
  return lines_.size() + 1;
}


// Returns the current column.
inline int
Input_buffer::column_no() const
{
  return position() - last_;
}


// Returns the current location in the source text.
inline Location
Input_buffer::location() const
{
  return {file(), line_no(), column_no()};
}



// -------------------------------------------------------------------------- //
// Lexer

// The lexer is responsible for the transformation
// of a character stream into a list of tokens.
// FIXME: Maintain source code locations.
class Lexer
{
public:
  using State_flags = unsigned;
  static constexpr State_flags eof_flag   = 0x01;
  static constexpr State_flags error_flag = 0x02;

  Lexer(Symbol_table&, Input_buffer&);

  // Lexer state
  bool done() const;
  bool failed() const;

  // Lexing
  bool lex(Token_stream&);
  bool scan(Token_stream&);

  // Scanning
  Token scan();
  Token lbrace();
  Token rbrace();
  Token lparen();
  Token rparen();
  Token lbrack();
  Token rbrack();
  Token comma();
  Token colon();
  Token semicolon();
  Token dot();
  Token plus();
  Token minus();
  Token star();
  Token slash();
  Token percent();
  Token equal();
  Token bang();
  Token langle();
  Token rangle();
  Token ampersand();
  Token bar();
  Token hat();
  Token scope();
  Token ellipses();

  Token binary_integer();
  Token hexadecimal_integer();
  Token integer();
  Token word();
  Token character();
  Token string();

  Token eof();
  Token error();

private:
  // Semantic actions
  Token on_token();
  Token on_word();
  Token on_binary_integer();
  Token on_hexadecimal_integer();
  Token on_integer();
  Token on_character();
  Token on_string();

  // Lexing support
  char peek() const;
  char peek(int) const;
  char get();
  void get(int);
  void ignore();

  // Token constructors
  Token symbol0();
  Token symbol1();
  Token symbolN(int n);

  // Lexers
  void comment();
  void space();
  void digit();
  void letter();

  String_builder build_; // Cache characters during scan.
  State_flags    state_; // The lexer's state
  Symbol_table&  syms_;  // The symbol table
  Input_buffer&  in_;    // The input buffer
  Location       loc_;   // Start of the current token
};


inline
Lexer::Lexer(Symbol_table& s, Input_buffer& cs)
  : build_(), state_(0), syms_(s), in_(cs)
{ }


// Returns true if the lexer has finsihed processing
// the character stream.
inline bool
Lexer::done() const
{
  return state_ & eof_flag;
}


// Returns true if the lexer encountered errors while
// processing the character stream.
inline bool
Lexer::failed() const
{
  return state_ & error_flag;
}


// Lexically analyze the underlying character stream,
// and produce a sequence of tokens. Returns true if
// scanning succeeded.
inline bool
Lexer::lex(Token_stream& ts)
{
  while (!done())
    scan(ts);
  return !failed();
}


// Put the next token into the token stream. Returns
// true if scanning succeeded.
inline bool
Lexer::scan(Token_stream& ts)
{
  if (Token tok = scan()) {
    ts.put(tok);
    return true;
  }
  return false;
}


// Having already consumed all of the characters of
// a symbol, just invoke the semnatic action to
// construct the token.
inline Token
Lexer::symbol0()
{
  return on_token();
}


// Consume all 1-character symbols and call the
// corresponding semantic action.
inline Token
Lexer::symbol1()
{
  get();
  return on_token();
}


inline Token
Lexer::symbolN(int n)
{
  get(n);
  return on_token();
}


inline Token
Lexer::lbrace()
{
  return symbol1();
}


inline Token
Lexer::rbrace()
{
  return symbol1();
}


inline Token
Lexer::lparen()
{
  return symbol1();
}


inline Token
Lexer::rparen()
{
  return symbol1();
}


inline Token
Lexer::lbrack()
{
  return symbol1();
}


inline Token
Lexer::rbrack()
{
  return symbol1();
}


inline Token
Lexer::comma()
{
  return symbol1();
}


// Looking for ':'
// or the scope qualifier '::'
inline Token
Lexer::colon()
{
  get();
  if (peek() == ':')
    return symbol1();

  return symbol0();
}


inline Token
Lexer::semicolon()
{
  return symbol1();
}


inline Token
Lexer::dot()
{
  get();

  // Handle ellipses (...)
  if (peek() == '.') {
    get();
    if (peek() == '.')
      return symbol1();
    else
      throw std::runtime_error("Expected third '.' in ellipses.");
  }

  return symbol0();
}


inline Token
Lexer::plus()
{
  return symbol1();
}


// Lex one of '-' or '->'.
inline Token
Lexer::minus()
{
  assert(peek() == '-');
  get();
  if (peek() == '>')
    return symbol1();
  else
    return symbol0();
}


inline Token
Lexer::star()
{
  return symbol1();
}


inline Token
Lexer::slash()
{
  // We've already consumed the character,
  // while trying to parse for a comment start.
  return symbol0();
}


inline Token
Lexer::percent()
{
  return symbol1();
}


// Lex one of '=' or '=='.
inline Token
Lexer::equal()
{
  assert(peek() == '=');
  get();
  if (peek() == '=')
    return symbol1();
  else
    return symbol0();
}


inline Token
Lexer::bang()
{
  assert(peek() == '!');
  get();
  if (peek() == '=')
    return symbol1();
  else
    return symbol0();
}


inline Token
Lexer::langle()
{
  assert(peek() == '<');
  get();
  if (peek() == '=')
    return symbol1();
  else if (peek() == '<')
    return symbol1();
  else
    return symbol0();
}


inline Token
Lexer::rangle()
{
  assert(peek() == '>');
  get();
  if (peek() == '=')
    return symbol1();
  else if (peek() == '>')
    return symbol1();
  else
    return symbol0();
}


inline Token
Lexer::ampersand()
{
  assert(peek() == '&');
  get();
  if (peek() == '&')
    return symbol1();
  else
    return symbol0();
}


inline Token
Lexer::bar()
{
  assert(peek() == '|');
  get();
  if (peek() == '|')
    return symbol1();
  else
    return symbol0();
}


inline Token
Lexer::hat()
{
  assert(peek() == '^');
  get();
  return symbol0();
}


// Match a keyword or identifier in the language.
inline Token
Lexer::word()
{
  assert(std::isalpha(peek()) || (peek() == '_'));
  get();
  while (std::isalpha(peek()) || std::isdigit(peek()) || (peek() == '_')) {
    get();
  }
  return on_word();
}


namespace
{

inline bool
is_hexadecimal_char(char c)
{
  switch (c) {
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    case 'a': case 'b': case 'c': case 'd': case 'e':
    case 'f': case '_':
      return true;
    default:
      return false;
  }

  return false;
}


inline bool
is_binary_char(char c)
{
  if (c == '0' || c == '1' || c == '_')
    return true;
  return false;
}


} // namespace


// hexadecimal integer ::= 0x[a-f 0-9 _]+
//
// '_' can be placed within the sequence for
// readability but are otherwise ignored
// similar to P4.
inline Token
Lexer::hexadecimal_integer()
{
  // ignore the leading '0'
  assert(peek() == '0');
  get();
  // ignore the leading 'x'
  assert(peek() == 'x');
  get();

  // there should be a digit following the
  // 'x' always.
  if (!is_hexadecimal_char(peek()))
    throw std::runtime_error("Expected digit after 0x in hexadecimal literal.");

  while(is_hexadecimal_char(peek())) {
    // ignore all '_'
    if (peek() == '_')
      ignore();

    get();
  }

  return on_hexadecimal_integer();
}


// binary integer ::= 0b[0-1 _]+
//
// '_' can be placed within the sequence for
// readability but are otherwise ignored
// similar to P4.
inline Token
Lexer::binary_integer()
{
  // ignore the leading '0'
  assert(peek() == '0');
  get();
  // ignore the leading 'b'
  assert(peek() == 'b');
  get();

  // there should be a digit following the
  // 'x' always.
  if (!is_binary_char(peek()))
    throw std::runtime_error("Expected 0 or 1 after 0b in binary literal.");

  while(is_binary_char(peek())) {
    // ignore all '_'
    if (peek() == '_')
      ignore();

    get();
  }

  return on_binary_integer();
}


// integer ::= digit+
inline Token
Lexer::integer()
{
  assert(is_decimal_digit(peek()));
  digit();
  while (is_decimal_digit(peek()))
    digit();
  return on_integer();
}


// digit ::= [0-9]
inline void
Lexer::digit()
{
  assert(is_decimal_digit(peek()));
  get();
}


// Set the eof flag and return an invalid token.
inline Token
Lexer::eof()
{
  state_ |= eof_flag;
  return Token();
}


inline char
Lexer::peek() const
{
  return in_.peek();
}


inline char
Lexer::peek(int n) const
{
  return in_.peek(n);
}


inline char
Lexer::get()
{
  char c = in_.get();
  build_.put(c);
  return c;
}


inline void
Lexer::get(int n)
{
  while (n) {
    char c = get();
    --n;
    build_.put(c);
  }
}


inline void
Lexer::ignore()
{
  in_.get();
}


#endif
