// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#include "utility.hpp"

#include "steve/lexer.hpp"
#include "steve/parser.hpp"

#include "lingo/file.hpp"

#include <iostream>


int
main(int argc, char **argv)
{
  Compiler compiler;
  
  if (argc < 2) {
    error("invalid arguments");
    return -1;
  }

  File& f = open_file(argv[1]);

  // FIXME: This is terrible. Find a more convenient
  // way of managing inputs (e.g., RAII).
  // Input_guard input(f);

  Token_list toks = lex(f);
  if (error_count())
    return -1;

  Token_stream ts(toks);
  Stmt_seq stmts = parse_file(ts);
  if (error_count())
    return -1;

  for (Stmt const* s : stmts)
    print(s);

  return 0;
}


