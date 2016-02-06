// Copyright (c) 2015 Andrew Sutton
// All rights reserved

#include "beaker/token.hpp"


// TODO: This could be unified with the token so
// that I'd only have to write the spelling once.
char const*
spelling(Token_kind k)
{
  switch (k) {
    case lbrace_tok: return "{";
    case rbrace_tok: return "}";
    case lparen_tok: return "(";
    case rparen_tok: return ")";
    case lbrack_tok: return "[";
    case rbrack_tok: return "]";
    case squote_tok: return "''";
    case dquote_tok: return "\"";
    case comma_tok: return ",";
    case colon_tok: return ":";
    case semicolon_tok: return ";";
    case dot_tok: return ".";
    case equal_tok: return "=";
    case plus_tok: return "+";
    case minus_tok: return "-";
    case star_tok: return "*";
    case slash_tok: return "/";
    case percent_tok: return "%";
    case eq_tok: return "==";
    case ne_tok: return "!=";
    case lt_tok: return "<";
    case gt_tok: return ">";
    case le_tok: return "<=";
    case ge_tok: return ">=";
    case and_tok: return "&&";
    case or_tok: return "||";
    case not_tok: return "!";
    case amp_tok: return "&";
    case bor_tok: return "|";
    case bxor_tok: return "^";
    case lshift_tok: return "<<";
    case rshift_tok: return ">>";
    case arrow_tok: return "->";
    case scope_tok: return "::";

    case abstract_kw: return "abstract";
    case bool_kw: return "bool";
    case break_kw: return "break";
    case char_kw: return "char";
    case continue_kw: return "continue";
    case def_kw: return "def";
    case else_kw: return "else";
    case foreign_kw: return "foreign";
    case meta_kw: return "meta";
    case if_kw: return "if";
    case int_kw: return "int";
    case uint_kw: return "uint";
    case return_kw: return "return";
    case struct_kw: return "struct";
    case this_kw: return "this";
    case var_kw: return "var";
    case virtual_kw: return "virtual";
    case while_kw: return "while";
    case match_kw: return "match";
    case case_kw: return "case";

    // network specific
    case layout_kw: return "layout";
    case decoder_kw: return "decoder";
    case decode_kw: return "decode";
    case start_kw: return "start";
    case extract_kw: return "extract";
    case as_kw: return "as";
    case exact_table_kw: return "exact_table";
    case prefix_table_kw: return "prefix_table";
    case wild_table_kw: return "wildcard_table";
    case requires_kw: return "requires";
    case miss_kw: return "miss";
    case action_kw: return "action_set";
    case port_kw: return "Port";
    case goto_kw: return "goto";
    case output_kw: return "output";
    case write_kw: return "write";
    case drop_kw: return "drop";
    case flood_kw: return "flood";
    case clear_kw: return "clear";
    case set_kw: return "set";
    case copy_kw: return "copy";
    case add_kw: return "add";
    case rmv_kw: return "remove";
    case into_kw: return "into";
    case from_kw: return "from";
    case event_kw: return "event";
    case raise_kw: return "raise";
    case properties_kw: return "properies";
    case inport_kw: return "in_port";
    case inphysport_kw: return "in_phys_port";
    case egress_kw: return "egress";

    default: return "<unspecified>";
  }
}

// Initialize the symbols of the language.
void
init_symbols(Symbol_table& syms)
{
  // Create the symbol table and install all of the
  // default tokens.
  syms.put<Symbol>("{", lbrace_tok);
  syms.put<Symbol>("}", rbrace_tok);
  syms.put<Symbol>("(", lparen_tok);
  syms.put<Symbol>(")", rparen_tok);
  syms.put<Symbol>("[", lbrack_tok);
  syms.put<Symbol>("]", rbrack_tok);
  syms.put<Symbol>("'", squote_tok);
  syms.put<Symbol>("\"", dquote_tok);
  syms.put<Symbol>(",", comma_tok);
  syms.put<Symbol>(":", colon_tok);
  syms.put<Symbol>(";", semicolon_tok);
  syms.put<Symbol>(".", dot_tok);
  syms.put<Symbol>("=", equal_tok);
  syms.put<Symbol>("+", plus_tok);
  syms.put<Symbol>("-", minus_tok);
  syms.put<Symbol>("*", star_tok);
  syms.put<Symbol>("/", slash_tok);
  syms.put<Symbol>("%", percent_tok);
  syms.put<Symbol>("==", eq_tok);
  syms.put<Symbol>("!=", ne_tok);
  syms.put<Symbol>("<", lt_tok);
  syms.put<Symbol>(">", gt_tok);
  syms.put<Symbol>("<=", le_tok);
  syms.put<Symbol>(">=", ge_tok);
  syms.put<Symbol>("&&", and_tok);
  syms.put<Symbol>("||", or_tok);
  syms.put<Symbol>("!", not_tok);
  syms.put<Symbol>("&", amp_tok);
  syms.put<Symbol>("|", bor_tok);
  syms.put<Symbol>("^", bxor_tok);
  syms.put<Symbol>("<<", lshift_tok);
  syms.put<Symbol>(">>", rshift_tok);
  syms.put<Symbol>("->", arrow_tok);
  syms.put<Symbol>("::", scope_tok);

  // Keywords
  syms.put<Symbol>("abstract", abstract_kw);
  syms.put<Symbol>("bool", bool_kw);
  syms.put<Symbol>("break", break_kw);
  syms.put<Symbol>("char", char_kw);
  syms.put<Symbol>("continue", continue_kw);
  syms.put<Symbol>("def", def_kw);
  syms.put<Symbol>("else", else_kw);
  syms.put<Symbol>("foreign", foreign_kw);
  syms.put<Symbol>("meta", meta_kw);
  syms.put<Symbol>("if", if_kw);
  syms.put<Symbol>("int", int_kw);
  syms.put<Symbol>("uint", uint_kw);
  syms.put<Symbol>("while", while_kw);
  syms.put<Symbol>("return", return_kw);
  syms.put<Symbol>("struct", struct_kw);
  syms.put<Symbol>("this", this_kw);
  syms.put<Symbol>("var", var_kw);
  syms.put<Symbol>("virtual", virtual_kw);
  syms.put<Symbol>("while", while_kw);

  syms.put<Symbol>("match", match_kw);
  syms.put<Symbol>("case", case_kw);

  // network specific keywords
  syms.put<Symbol>("layout", layout_kw);
  syms.put<Symbol>("decoder", decoder_kw);
  syms.put<Symbol>("decode", decode_kw);
  syms.put<Symbol>("start", start_kw);
  syms.put<Symbol>("extract", extract_kw);
  syms.put<Symbol>("as", as_kw);
  syms.put<Symbol>("exact_table", exact_table_kw);
  syms.put<Symbol>("prefix_table", prefix_table_kw);
  syms.put<Symbol>("wildcard_table", wild_table_kw);
  syms.put<Symbol>("requires", requires_kw);
  syms.put<Symbol>("miss", miss_kw);
  syms.put<Symbol>("Port", port_kw);
  syms.put<Symbol>("goto", goto_kw);
  syms.put<Symbol>("output", output_kw);
  syms.put<Symbol>("write", write_kw);
  syms.put<Symbol>("drop", drop_kw);
  syms.put<Symbol>("flood", flood_kw);
  syms.put<Symbol>("clear", clear_kw);
  syms.put<Symbol>("set", set_kw);
  syms.put<Symbol>("copy", copy_kw);
  syms.put<Symbol>("add", add_kw);
  syms.put<Symbol>("remove", rmv_kw);
  syms.put<Symbol>("into", into_kw);
  syms.put<Symbol>("from", from_kw);
  syms.put<Symbol>("event", event_kw);
  syms.put<Symbol>("raise", raise_kw);
  syms.put<Symbol>("properties", properties_kw);
  syms.put<Symbol>("in_port", inport_kw);
  syms.put<Symbol>("in_phys_port", inphysport_kw);
  syms.put<Symbol>("egress", egress_kw);

  // Reserved names.
  syms.put<Boolean_sym>("true", boolean_tok, true);
  syms.put<Boolean_sym>("false", boolean_tok, false);

  // Common identifiers
  syms.put<Symbol>("main", identifier_tok);
  syms.put<Symbol>("vptr", identifier_tok);
}
