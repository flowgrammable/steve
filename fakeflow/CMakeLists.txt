cmake_minimum_required(VERSION 3.2)

project(flowpath-rt CXX)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

# C++ build flags.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pedantic -Wall -pthread -O3")

# Require Boost C++ Libraries.
find_package(Boost 1.55.0 REQUIRED system timer)
include_directories(${Boost_INCLUDE_DIRS})

# Farm hash
find_package(farmhash REQUIRED)

# PCAP
find_package(PCAP REQUIRED)

# Allow includes to find from headers from this dir.
include_directories(.)
include_directories(${farmhash_INCLUDE_DIRS})

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
    types.cpp
    endian.cpp
    capture.cpp
    # thread.cpp
    # queue.cpp
    )

target_link_libraries(flowpath-rt ${farmhash_LIBRARIES} ${Boost_LIBRARIES})

add_subdirectory(drivers)
