# Require Boost C++ Libraries.
find_package(Boost 1.55.0 REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(wire-driver wire.cpp)
add_executable(learn-driver learn.cpp)
add_executable(generic-driver generic.cpp)

target_link_libraries(wire-driver flowpath-rt ${CMAKE_DL_LIBS})
target_link_libraries(learn-driver flowpath-rt ${CMAKE_DL_LIBS})
target_link_libraries(generic-driver flowpath-rt ${CMAKE_DL_LIBS} pcap)
