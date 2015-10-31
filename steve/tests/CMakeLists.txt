# Copyright (c) 2015 Flowgrammable.org
# All rights reserved

macro(add_test_driver target)
  add_executable(${target} ${ARGN})
  target_link_libraries(${target} steve lingo)
endmacro()

add_test_driver(test-int        int.cpp)
add_test_driver(test-record     record.cpp)
add_test_driver(test-tuple      tuple.cpp)
add_test_driver(test-match-type match-type.cpp)
add_test_driver(test-enum       enum.cpp)
add_test_driver(test-value      value.cpp)
add_test_driver(test-convert    convert.cpp)
add_test_driver(test-common     common.cpp)
add_test_driver(test-expr       expr.cpp)
add_test_driver(test-call       call.cpp)
add_test_driver(test-overload   overload.cpp)
add_test_driver(test-lookup     lookup.cpp)
add_test_driver(test-forward-decl forward-decl.cpp)
add_test_driver(test-name name.cpp)

add_test_driver(test-field      field.cpp)
add_test_driver(test-ofp        ofp.cpp)
add_test_driver(test-decode     decode.cpp)
add_test_driver(test-length     length.cpp)
add_test_driver(test-table      table.cpp)

add_test_driver(test-lex        lex.cpp)
add_test_driver(test-parse      parse.cpp)

# Actual unit tests.

add_test(test-int        test-int)
add_test(test-record     test-record)
add_test(test-tuple      test-tuple)
add_test(test-enum       test-enum)
add_test(test-match-type test-match-type)
add_test(test-value      test-value)
add_test(test-convert    test-convert)
add_test(test-common     test-common)
add_test(test-expr       test-expr)
add_test(test-call       test-call)
add_test(test-overload   test-overload)
add_test(test-lookup     test-lookup)
add_test(test-forward-decl test-forward-decl)
add_test(test-name test-name)

add_test(test-field      test-field)
add_test(test-ofp        test-ofp)
add_test(test-decode     test-decode)
add_test(test-table      test-table)