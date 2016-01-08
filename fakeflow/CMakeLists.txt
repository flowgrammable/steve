cmake_minimum_required(VERSION 3.2)

project(flowpath-rt CXX)

# C++ build flags.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pedantic -Wall -pthread")

# Require Boost C++ Libraries.
find_package(Boost 1.55.0 REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

# Allow includes to find from headers from this dir.
include_directories(.)

# The flowpath runtime library.
add_library(flowpath-rt SHARED
    application.cpp
    buffer.cpp
    action.cpp
    binding.cpp
    context.cpp
    dataplane.cpp
    flow.cpp
    packet.cpp
    port.cpp
    port_table.cpp
    port_tcp.cpp
    port_udp.cpp
    system.cpp
    table.cpp
    types.cpp)


add_subdirectory(drivers)
