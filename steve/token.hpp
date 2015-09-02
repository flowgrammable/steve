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

// FIXME: Make tokens less general. For example, making this
// an enum would be FANTASTIC. Maybe make Token a base class
// that operates on ints, and deriving this class to work on
// an enumerated set of tokens.

// Keywords
constexpr Token_kind alias_kw    = 101; // alias
constexpr Token_kind bool_kw     = 102; // bool
constexpr Token_kind buffer_kw   = 301; // buffer
constexpr Token_kind const_kw    = 307; // const
constexpr Token_kind do_kw       = 103; // do
constexpr Token_kind decode_kw   = 104; // decode
constexpr Token_kind def_kw      = 105; // def
constexpr Token_kind default_kw  = 106; // default
constexpr Token_kind else_kw     = 107; // else
constexpr Token_kind enum_kw     = 108; // enum
constexpr Token_kind extract_kw  = 109; // extract
constexpr Token_kind for_kw      = 304; // for
constexpr Token_kind if_kw       = 110; // if
constexpr Token_kind include_kw  = 111; // include
constexpr Token_kind int_kw      = 112; // int
constexpr Token_kind import_kw   = 113; // import
constexpr Token_kind long_kw     = 114; // long
constexpr Token_kind match_kw    = 115; // match
constexpr Token_kind ref_kw      = 305; // ref
constexpr Token_kind record_kw   = 116; // record
constexpr Token_kind requires_kw = 117; // requires
constexpr Token_kind seq_kw      = 300; // seq
constexpr Token_kind short_kw    = 118; // short
constexpr Token_kind table_kw    = 119; // table
constexpr Token_kind uint_kw     = 120; // uint
constexpr Token_kind ulong_kw    = 121; // ulong
constexpr Token_kind until_kw    = 302; // until
constexpr Token_kind ushort_kw   = 122; // ushort
constexpr Token_kind using_kw    = 123; // using
constexpr Token_kind var_kw      = 124; // var
constexpr Token_kind variant_kw  = 125; // variant
constexpr Token_kind void_kw     = 126; // void
constexpr Token_kind while_kw    = 303; // while
constexpr Token_kind insert_kw   = 127; // insert
constexpr Token_kind into_kw     = 128; // into
constexpr Token_kind delete_kw   = 129; // delete
constexpr Token_kind from_kw     = 130; // from
constexpr Token_kind as_kw       = 131; // as

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
