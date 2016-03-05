# Libraries requried for executable targets.

add_executable(steve-compile pipeline-compiler.cpp)
target_link_libraries(steve-compile
beaker
lingo
${CMAKE_DL_LIBS}
${CMAKE_THREAD_LIBS_INIT}
${Boost_SYSTEM_LIBRARIES}
${Boost_FILESYSTEM_LIBRARIES}
${LLVM_LIBRARIES})
