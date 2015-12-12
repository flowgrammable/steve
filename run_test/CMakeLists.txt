set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pedantic -Wall -pthread -Wl,--no-as-needed -ldl")

add_executable(run_test
  main.cpp
  interface.cpp
)
