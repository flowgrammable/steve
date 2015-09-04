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

enum Token_kind 
{
  alias_kw   , // alias
  bool_kw    , // bool
  buffer_kw  , // buffer
  const_kw   , // const
  do_kw      , // do
  decode_kw  , // decode
  def_kw     , // def
  default_kw , // default
  else_kw    , // else
  enum_kw    , // enum
  extract_kw , // extract
  for_kw     , // for
  if_kw      , // if
  include_kw , // include
  int_kw     , // int
  import_kw  , // import
  long_kw    , // long
  match_kw   , // match
  ref_kw     , // ref
  record_kw  , // record
  requires_kw, // requires
  seq_kw     , // seq
  short_kw   , // short
  table_kw   , // table
  uint_kw    , // uint
  ulong_kw   , // ulong
  until_kw   , // until
  ushort_kw  , // ushort
  using_kw   , // using
  var_kw     , // var
  variant_kw , // variant
  void_kw    , // void
  while_kw   , // while
  insert_kw  , // insert
  into_kw    , // into
  delete_kw  , // delete
  from_kw    , // from
  as_kw      , // as

  // Integer specification.
  intn_tok   , // intN
  uintn_tok  , // uintN
  msbfn_tok  , // msbfN
  umsbfn_tok , // umsbfN
  lsbfn_tok  , // lsbfN
  ulsbfn_tok , // ulsbfN
};

String const* get_identifier(char const*);
String const* get_identifier(String const&);

Value as_bool(Token const&);
Value as_int(Token const&);

void init_tokens();

} // namespace steve


#endif
