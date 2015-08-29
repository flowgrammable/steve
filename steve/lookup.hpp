// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#ifndef STEVE_LOOKUP_HPP
#define STEVE_LOOKUP_HPP

// The scope module provides a facility for managing the lexical
// scope of name bindings. This is currently a bit over-engineered
// for the purpose of future extensibility.

#include "steve/prelude.hpp"
#include "steve/overload.hpp"

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
  Overload const* bind(String const*, Decl const*);
  Overload const* lookup(String const*) const;

  // Should be private?
  Binding* binding(String const*) const;

  Scope_kind kind_;
  std::vector<String const*> pending_;
};


// A name binding stores information information associated
// with an identifier. Note that, inside a single scope, a
// name may be bound to multiple declarations, represented
// by an overload set. Each declaration associates a type,
// and other information with the value.
struct Scope::Binding
{
  Overload* ovl;   // A set of declraratoins for the name
  Scope*    scope; // Scope in which the declaration's name is visible
  Binding*  prev;  // The previous binding
};


// Represents the global scope.
struct Global_scope : Scope
{
  Global_scope()
    : Scope(global_scope)
  { }
};


// Represents a local scope.
struct Local_scope : Scope
{
  Local_scope()
    : Scope(local_scope)
  { }
};


// Represents the scope of a record declration.
struct Record_scope : Scope
{
  Record_scope()
    : Scope(record_scope)
  { }
};


// Represents the scope of an enumeration declaration.
struct Enum_scope : Scope
{
  Enum_scope()
    : Scope(enum_scope)
  { }
};


// ---------------------------------------------------------------------------//
//                            Scope management

Scope& current_scope();


// ---------------------------------------------------------------------------//
//                            Lexical bindings

Overload const* declare(String const*, Decl const*);
Overload const* declare(Decl const*);
bool            declare(Decl_seq const&);

Overload const* lookup(String const*);
Overload const* lookup(char const*);

Decl const* lookup_decl(String const*);


// ---------------------------------------------------------------------------//
//                            Printing

void print(Printer& p, Scope const*);

void print_name_bindings();
void print_name_bindings(Printer& p);


} // namespace steve


#endif
