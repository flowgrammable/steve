// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#include "steve/token.hpp"

namespace steve
{

char const*
get_token_name(Token_kind k)
{
  switch (k) {
    case alias_kw: return "alias_kw";
    case bool_kw: return "bool_kw";
    case buffer_kw: return "buffer_kw";
    case const_kw: return "const_kw";
    case do_kw: return "do_kw";
    case decode_kw: return "decode_kw";
    case def_kw: return "def_kw";
    case default_kw: return "default_kw";
    case else_kw: return "else_kw";
    case enum_kw: return "enum_kw";
    case extract_kw: return "extract_kw";
    case for_kw: return "for_kw";
    case if_kw: return "if_kw";
    case int_kw: return "int_kw";
    case import_kw: return "import_kw";
    case long_kw: return "long_kw";
    case match_kw: return "match_kw";
    case ref_kw: return "ref_kw";
    case record_kw: return "record_kw";
    case requires_kw: return "requires_kw";
    case seq_kw: return "seq_kw";
    case short_kw: return "short_kw";
    case table_kw: return "table_kw";
    case uint_kw: return "uint_kw";
    case ulong_kw: return "ulong_kw";
    case until_kw: return "until_kw";
    case ushort_kw: return "ushort_kw";
    case using_kw: return "using_kw";
    case var_kw: return "var_kw";
    case variant_kw: return "variant_kw";
    case void_kw: return "void_kw";
    case while_kw: return "while_kw";
    case insert_kw: return "insert_kw";
    case into_kw: return "into_kw";
    case delete_kw: return "delete_kw";
    case from_kw: return "from_kw";
    case as_kw: return "as_kw";

    case intn_tok: return "intn_tok";
    case uintn_tok: return "uintn_tok";
    case msbfn_tok: return "msbfn_tok";
    case umsbfn_tok: return "umsbfn_tok";
    case lsbfn_tok: return "lsbfn_tok";
    case ulsbfn_tok: return "ulsbfn_tok";
  }
  lingo_unreachable("unhandled token kind ({})", (int)k);
}


char const*
get_token_spelling(Token_kind k)
{
  switch (k) {
    case alias_kw: return "alias";
    case bool_kw: return "bool";
    case buffer_kw: return "buffer";
    case const_kw: return "const";
    case do_kw: return "do";
    case decode_kw: return "decode";
    case def_kw: return "def";
    case default_kw: return "default";
    case else_kw: return "else";
    case enum_kw: return "enum";
    case extract_kw: return "extract";
    case if_kw: return "if";
    case int_kw: return "int";
    case import_kw: return "import";
    case long_kw: return "long";
    case match_kw: return "match";
    case ref_kw: return "ref";
    case record_kw: return "record";
    case requires_kw: return "requires";
    case seq_kw: return "seq";
    case short_kw: return "short";
    case table_kw: return "table";
    case uint_kw: return "uint";
    case ulong_kw: return "ulong";
    case until_kw: return "until";
    case ushort_kw: return "ushort";
    case using_kw: return "using";
    case var_kw: return "var";
    case variant_kw: return "variant";
    case void_kw: return "void";
    case while_kw: return "while";
    case insert_kw: return "insert";
    case into_kw: return "into_kw";
    case delete_kw: return "delete";
    case from_kw: return "from";
    case as_kw: return "as";
    default: break;
  }
  lingo_unreachable("unhandled token kind ({})", (int)k);
}


namespace 
{

// The extended token set.
Extended_token_set toks_;


using Token_entry = std::pair<char const*, Token_kind>;


// The tokens actually used in the language.
Token_entry token_list_[] {
  // Tokens
  {"(", lparen_tok},
  {")", rparen_tok},
  {"{", lbrace_tok},
  {"}", rbrace_tok},
  {"[", rbrack_tok},
  {"]", lbrack_tok},
  
  {".", dot_tok},
  {",", comma_tok},
  {";", semicolon_tok},
  {":", colon_tok},
  {"=", equal_tok},
  {"+", plus_tok},
  {"-", minus_tok},
  {"*", star_tok},
  {"/", slash_tok},
  {"%", percent_tok},
  {"&", amp_tok},
  {"|", bar_tok},
  {"^", caret_tok},
  {"~", tilde_tok},
  {"!", bang_tok},
  {"<", lt_tok},
  {">", gt_tok},

  {"->", minus_gt_tok},
  {"=>", eq_gt_tok},
  {"<<", lt_lt_tok},
  {">>", gt_gt_tok},
  {"==", eq_eq_tok},
  {"!=", bang_eq_tok},
  {"<=", lt_eq_tok},
  {">=", gt_eq_tok},
  {"&&", amp_amp_tok},
  {"||", bar_bar_tok},
  {"..", dot_dot_tok},

  // Keywords
  {"alias", alias_kw},
  {"bool", bool_kw},
  {"do", do_kw},
  {"decode", decode_kw},
  {"def", def_kw},
  {"default", default_kw},
  {"else", else_kw},
  {"enum", enum_kw},
  {"extract", extract_kw},
  {"if", if_kw},
  {"int", int_kw},
  {"import", import_kw},
  {"long", long_kw},
  {"match", match_kw},
  {"record", record_kw},
  {"requires", requires_kw},
  {"short", short_kw},
  {"table", table_kw},
  {"uint", uint_kw},
  {"ulong", ulong_kw},
  {"ushort", ushort_kw},
  {"using", using_kw},
  {"var", var_kw},
  {"variant", variant_kw},
  {"void", void_kw},
  {"insert", insert_kw},
  {"into", into_kw},
  {"delete", delete_kw},
  {"from", from_kw},
  {"as", as_kw},
  
  // Named values
  {"true", boolean_tok},
  {"false", boolean_tok}
};

} // namespace


// Initialize language tokens.
void
init_tokens()
{
  install_token_set(toks_);
  for (Token_entry ent : token_list_)
    install_token(ent.first, ent.second);
}


} // namespace steve
