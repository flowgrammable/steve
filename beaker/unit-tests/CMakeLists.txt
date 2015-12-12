# Libraries requried for executable targets.
set(libs
  beaker
  lingo
  ${CMAKE_DL_LIBS}
  ${CMAKE_THREAD_LIBS_INIT}
  ${Boost_SYSTEM_LIBRARIES}
  ${Boost_FILESYSTEM_LIBRARIES}
  ${LLVM_LIBRARIES})


macro(add_test_driver target)
  add_executable(${target} ${ARGN})
  target_link_libraries(${target} ${libs})
endmacro()


add_test_driver(test-pipeline	pipeline.cpp)

add_test(test-pipeline test-pipeline)
