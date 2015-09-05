// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#include "steve/token.hpp"

namespace steve
{

// Returns an identifer.
String const*
get_identifier(char const* str)
{
  return &lingo::get_symbol(str, identifier_tok).str;
}


// Returns an identifier.
String const*
get_identifier(String const& str)
{
  return &lingo::get_symbol(str, identifier_tok).str;
}


// Initialize language tokens.
void
init_tokens()
{
#define install(tok, txt) install_token(tok, #tok, txt)
  // Punctuators
  install(lbrace_tok,     "{");
  install(rbrace_tok,     "}");
  install(lparen_tok,     ")");
  install(rparen_tok,     "(");
  install(comma_tok,      ",");
  install(colon_tok,      ":");
  install(semicolon_tok,  ";");
  install(eq_tok,         "=");
  install(arrow_tok,      "->");
  // Opeators
  install(plus_tok,       "+");
  install(minus_tok,      "-");
  install(star_tok,       "*");
  install(slash_tok,      "/");
  install(percent_tok,    "%");
  install(amp_tok,        "&");
  install(bar_tok,        "|");
  install(caret_tok,      "^");
  install(tilde_tok,      "~");
  install(lt_lt_tok,      "<<");
  install(gt_gt_tok,      ">>");
  install(eq_eq_tok,      "==");
  install(bang_eq_tok,    "!=");
  install(lt_tok,         "<");
  install(gt_tok,         ">");
  install(lt_eq_tok,      "<=");
  install(gt_eq_tok,      ">=");
  install(amp_amp_tok,    "&&");
  install(bar_bar_tok,    "||");
  install(bang_tok,       "!");
  // Keywords
  install(alias_kw, "alias");
  install(bool_kw, "bool");
  install(do_kw, "do");
  install(decode_kw, "decode");
  install(def_kw, "def");
  install(default_kw, "default");
  install(else_kw, "else");
  install(enum_kw, "enum");
  install(extract_kw, "extract");
  install(if_kw, "if");
  install(int_kw, "int");
  install(import_kw, "import");
  install(long_kw, "long");
  install(match_kw, "match");
  install(record_kw, "record");
  install(requires_kw, "requires");
  install(short_kw, "short");
  install(table_kw, "table");
  install(uint_kw, "uint");
  install(ulong_kw, "ulong");
  install(ushort_kw, "ushort");
  install(using_kw, "using");
  install(var_kw, "var");
  install(variant_kw, "variant");
  install(void_kw, "void");
  install(insert_kw, "insert");
  install(into_kw, "into");
  install(delete_kw, "delete");
  install(from_kw, "from");
  install(as_kw, "as");
#undef install

  // Create symbol table entries for boolean values.
  //
  // Don't use install token because that doesn't let
  // register multiple values with the same token kind.
  //
  // TODO: We probably want a way of registering the
  // spelling of token names without values (e.g., integers,
  // booleans, and identifiers).
  get_symbol("true", boolean_tok);
  get_symbol("false", boolean_tok);
}

std::intmax_t
as_bool(Token const& tok)
{
  lingo_assert(tok.kind() == boolean_tok);
  return tok.symbol() == get_symbol("true");
}


std::intmax_t
as_int(Token const& tok)
{
  lingo_assert(tok.kind() == integer_tok);
  return std::stol(*tok.str());
}

} // namespace steve
