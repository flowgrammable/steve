// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#ifndef STEVE_LOOKUP_HPP
#define STEVE_LOOKUP_HPP

// The scope module provides a facility for managing the lexical
// scope of name bindings. This is currently a bit over-engineered
// for the purpose of future extensibility.

#include "steve/prelude.hpp"

#include "lingo/symbol.hpp"


namespace steve
{

using namespace lingo;


struct Decl;
struct Scope;


// The scope kind determines what kinds of "parts of a program"
// in which a name binding could be introduced. These are:
//
// - global -- anything not declared within a block or record
//   has global scope.
//
// - block -- any declarations within a block statement have
//   block scope. Parameters of a function definition are
//   declared in a block scope encloses its body.
//
// - record -- and declarations within the body of a record
//   declaration have declaration scope.
enum Scope_kind
{
  global_scope,
  block_scope,
  record_scope,
};


// A scope is a sequence of declartions that are visible
// within the same region of source (starting from their
// respective declarations).
struct Scope : std::vector<String const*>
{
  struct Entry;

  Scope(Scope_kind k)
    : kind_(k)
  { }

  ~Scope();

  Scope_kind kind() const  { return kind_; }
  
  void bind(String const*, Decl const*);
  
  Entry*       entry(String const*) const;
  Decl const*  lookup(String const*) const;

  Scope_kind kind_;
};


// A scope entry stores information information associated
// with an identifier. This includes the bound declration,
// it's declarative scope, and a reference to the previous
// bound entry for the identifier.
struct Scope::Entry
{
  Decl const* decl;  // the declarations
  Scope*      scope; // the declartive scope
  Entry*      prev;  // the previous scope entry
};


// ---------------------------------------------------------------------------//
//                            Scope management

Scope& current_scope();
Scope& enter_scope(Scope_kind);
void   leave_scope();


// ---------------------------------------------------------------------------//
//                            Lexical bindings

bool declare(String const*, Decl const*);
bool declare(Decl const*);

Decl const* lookup(String const*);
Decl const* lookup(String const&);
Decl const* lookup(char const*);


// -------------------------------------------------------------------------- //
//                              Tools

// The scope guard class pushes a new scope upon
// creation and pops that scope upon destruction.
struct Scope_guard
{
  Scope_guard(Scope_kind k)
    : scope(enter_scope(k))
  { }

  ~Scope_guard()
  {
    leave_scope();
  }

  Scope& scope;
};


} // namespace steve


#endif
