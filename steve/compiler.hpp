// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#ifndef STEVE_COMPILER_HPP
#define STEVE_COMPILER_HPP

// The compiler module provides a simple interface for
// constructing pograms that parse the Steve language.

#include "steve/prelude.hpp"
#include "steve/lexer.hpp"
#include "steve/parser.hpp"
#include "steve/lookup.hpp"

namespace steve
{

// The compiler class provides centralized access to the
// various resources required to compile a Steve program.
// It is also responsible for performing initialization
// and cleanup of those resources.
//
// When constructed, the compiler will implicitly declare
// the global scope and value store for constants.
struct Compiler
{
  Compiler();
  ~Compiler();

  Global_scope global;
};


} // namespace steve


#endif
