# Require Boost C++ Libraries.
find_package(Boost 1.55.0 REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(wire-driver wire.cpp)
target_link_libraries(wire-driver flowpath-rt ${CMAKE_DL_LIBS})
