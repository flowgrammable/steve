// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#ifndef STEVE_COMPILER_HPP
#define STEVE_COMPILER_HPP

#include "steve/prelude.hpp"


namespace steve
{

// The compiler class provides centralized access to the
// various resources required to compile a Steve program.
// It is also responsible for performing initialization
// and cleanup of those resources.
struct Compiler
{
  Compiler();
  ~Compiler();
};


} // namespace steve


#endif
