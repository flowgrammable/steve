macro(add_test_driver target)
  add_executable(${target} ${ARGN})
  target_link_libraries(${target} steve lingo metal-cxx steve-translate)
endmacro()

add_test_driver(test-trans-pipe		test-trans-pipe.cpp)
add_test_driver(test-trans-fn		test-trans-fn.cpp)
add_test_driver(test-trans-record   test-trans-record.cpp)

add_test(test-trans-pipe	test-trans-pipe)
add_test(test-trans-fn		test-trans-fn)
add_test(test-trans-record  test-trans-record)