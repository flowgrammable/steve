# Copyright (c) 2015 Flowgrammable.org
# All rights reserved

# Build the core library.
add_library(steve STATIC
  prelude.cpp
  op.cpp
  value.cpp
  type.cpp
  prop.cpp
  expr.cpp
  stmt.cpp
  decl.cpp
  builder.cpp
  relation.cpp
  convert.cpp
  lookup.cpp
  overload.cpp
  evaluate.cpp
  print.cpp
  debug.cpp
  net.cpp
  length.cpp
  builtin.cpp
  lower.cpp
  token.cpp
  lexer.cpp
  parser.cpp
  parse-type.cpp
  parse-expr.cpp
  parse-decl.cpp
  parse-stmt.cpp
  compiler.cpp)


add_subdirectory(tests)
