// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

// Tests for unary and binary expression.

#include "utility.hpp"

#include "steve/lexer.hpp"
#include "lingo/file.hpp"

#include <iostream>


int
main(int argc, char* argv[])
{
  Compiler compiler;
  
  if (argc < 2) {
    error("invalid arguments");
    return -1;
  }

  File& f = open_file(argv[1]);

  // FIXME: This is terrible. Find a more convenient
  // way of managing inputs (e.g., RAII).
  Input_guard input(f);

  Token_list toks = lex(f);
  if (error_count())
    return -1;

  Printer p(std::cout);
  for (Token const& tok : toks) {
    print(p, tok);
    print_space(p);
  }

}
