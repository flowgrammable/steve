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
//   declared in a block scope that encloses its body.
//
// - record -- and declarations within the body of a record
//   declaration have declaration scope.
//
// - enum -- names declared within the body of an enum declaration.
enum Scope_kind
{
  global_scope,
  local_scope,
  record_scope,
  enum_scope,
};


// A scope is a sequence of declartions that are visible
// within the same region of source (starting from their
// respective declarations).
//
// Note that constructing a scope object places it on the
// scope stack.
struct Scope : std::vector<String const*>
{
  struct Binding;

  Scope(Scope_kind k);
  ~Scope();

  Scope_kind kind() const  { return kind_; }
  
  void bind(String const*, Decl const*);
  
  Binding*     entry(String const*) const;
  Decl const*  lookup(String const*) const;

  Scope_kind kind_;
};


// A name binding stores information information associated
// with an identifier. In particular, a name is always bound 
// to a type, and may be bound to a constant value (constants,
// and enumerators).
struct Scope::Binding
{
  Decl const* decl;  // The bound declaration
  Scope*      scope; // Scope in which the declaration's name is visible
  Binding*    prev;  // The previous binding
};


// ---------------------------------------------------------------------------//
//                            Scope management

Scope& current_scope();


// ---------------------------------------------------------------------------//
//                            Lexical bindings

bool declare(String const*, Decl const*);
bool declare(Decl const*);

Decl const* lookup(String const*);
Decl const* lookup(String const&);
Decl const* lookup(char const*);


} // namespace steve


#endif
