// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#ifndef STEVE_TOKEN_HPP
#define STEVE_TOKEN_HPP

// This module defines the set of tokens used by the language.

#include "steve/prelude.hpp"

#include "lingo/token.hpp"

namespace steve
{

using namespace lingo;


// -------------------------------------------------------------------------- //
//                              Token kinds


// Keywords
constexpr Token_kind alias_kw    = 101; // alias
constexpr Token_kind bool_kw     = 102; // bool
constexpr Token_kind do_kw       = 103; // do
constexpr Token_kind decode_kw   = 104; // decode
constexpr Token_kind def_kw      = 105; // def
constexpr Token_kind default_kw  = 106; // default
constexpr Token_kind else_kw     = 107; // else
constexpr Token_kind enum_kw     = 108; // enum
constexpr Token_kind extract_kw  = 109; // extract
constexpr Token_kind if_kw       = 110; // if
constexpr Token_kind int_kw      = 111; // int
constexpr Token_kind import_kw   = 112; // import
constexpr Token_kind long_kw     = 113; // long
constexpr Token_kind match_kw    = 114; // match
constexpr Token_kind record_kw   = 115; // record
constexpr Token_kind requires_kw = 116; // requires
constexpr Token_kind short_kw    = 117; // short
constexpr Token_kind table_kw    = 118; // table
constexpr Token_kind uint_kw     = 119; // uint
constexpr Token_kind ulong_kw    = 120; // ulong
constexpr Token_kind ushort_kw   = 121; // ushort
constexpr Token_kind using_kw    = 122; // using
constexpr Token_kind var_kw      = 123; // var
constexpr Token_kind variant_kw  = 124; // variant
constexpr Token_kind void_kw     = 125; // void

// Integer specification.
constexpr Token_kind intn_tok    = 200; // intN
constexpr Token_kind uintn_tok   = 201; // uintN
constexpr Token_kind msbfn_tok   = 202; // msbfN
constexpr Token_kind umsbfn_tok  = 203; // umsbfN
constexpr Token_kind lsbfn_tok   = 204; // lsbfN
constexpr Token_kind ulsbfn_tok  = 205; // ulsbfN


char const* get_token_name(Token_kind);
char const* get_token_spelling(Token_kind);


// The extended token set.
struct Extended_token_set : Token_set
{
  char const* token_name(Token_kind k) const override
  { 
    return steve::get_token_name(k); 
  }

  char const* token_spelling(Token_kind k) const override
  { 
    return steve::get_token_spelling(k); 
  }
};


void init_tokens();


} // namespace steve


#endif
