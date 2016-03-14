set(CMAKE_CXX_FLAGS "-Wall -std=c++1y -fPIC")

add_library(steve-helper STATIC
  action.cpp
  binding.cpp
  buffer.cpp
  context.cpp
  packet.cpp
  types.cpp
  endian.cpp
  libsteve.cpp
)
