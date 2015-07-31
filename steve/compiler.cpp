// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#include "steve/compiler.hpp"
#include "steve/token.hpp"
#include "steve/parser.hpp"


namespace steve
{

Compiler::Compiler()
{
  init_tokens();
  init_grammar();
}

Compiler::~Compiler()
{
}


} // namespace steve

