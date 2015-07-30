# Copyright (c) 2015 Flowgrammable.org
# All rights reserved

cmake_minimum_required(VERSION 3.0)
project(steve CXX)
enable_testing()


# GMP Dependencies
find_path(GMP_INCLUDE_DIR NAMES gmp.h)
find_library(GMP_LIBRARIES NAMES gmp libgmp)
MESSAGE(STATUS "GMP libs: " ${GMP_LIBRARIES})


# Boost dependencies
find_package(Boost 1.55.0 REQUIRED COMPONENTS 
  system
  filesystem)


# Compiler configuration.
set(CMAKE_CXX_FLAGS "-Wall -std=c++11")
include_directories(
  .
  ${CMAKE_SOURCE_DIR}/lingo
  ${Boost_INCLUDE_DIRS} 
  ${GMP_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIRS})


# Build artefacts
add_subdirectory(lingo)
add_subdirectory(steve)
