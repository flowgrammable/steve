// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#ifndef STEVE_PROP_HPP
#define STEVE_PROP_HPP

// The proposition module defines the logical terms of the 
// constraint language and theorem proving facilities.
//
// FIXME: Actually implement this.

#include "steve/prelude.hpp"


namespace steve
{

// -------------------------------------------------------------------------- //
//                            Proposition kinds

// Different kinds of propositions in the core language.
enum Prop_kind
{
  and_prop,
  or_prop,
  predicate_prop,
  extract_prop,
};


char const* get_prop_name(Prop_kind);


// Adapt the generic node-kinding template to this node type.
template<Prop_kind K>
using Prop_impl = lingo::Kind_base<Prop_kind, K>;


// -------------------------------------------------------------------------- //
//                                Expressions

struct Type;
struct Expr;


// The Prop class is the base class of all declarations in
// the language. A declaration introduces a name binding for
// some kind of program entity.
//
// A declaration can be constrained by a logical proposition.
// These constraints are evaluated to deterimine if the declaration
// is valid, or if it can be used, depending on the kind of
// declaration.
struct Decl
{
  Decl(Prop_kind k)
    : kind_(k)
  { }

  virtual ~Decl()
  { }

  char const* node_name() const { return get_prop_name(kind_); }
  Prop_kind   kind() const      { return kind_; }

  Prop_kind kind_;
};


// -------------------------------------------------------------------------- //
//                                  Facilities

// Garbage collection
void mark(Prop const*);


} // namespace steve

#endif
