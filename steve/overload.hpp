// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#ifndef STEVE_OVERLOAD_HPP
#define STEVE_OVERLOAD_HPP

// The overload module provides facilities for overloading
// declarations.

#include "steve/prelude.hpp"


namespace steve
{

// An overload set is a set of declarations having the
// same name and scope, but different types or constraints.
//
// An overload set always has at least one member.
struct Overload : std::vector<Decl const*> 
{
  using std::vector<Decl const*>::vector;

  bool is_singleton() const { return size() == 1; }
  
  String const* name() const;
};


// -------------------------------------------------------------------------- //
//                               Declarations

bool overload_declaration(Overload*, Decl const*);


void print(Printer&, Overload const*);
void debug(Printer&, Overload const*);


} // namespace steve


#endif

