cmake_minimum_required(VERSION 3.15)

project(StateMachine VERSION 1.0)

add_executable(sm main.cpp)
target_link_libraries(sm PUBLIC fsm)
add_subdirectory(lib)

message("CMAKE_CXX_FLAGS_DEBUG is ${CMAKE_CXX_FLAGS_DEBUG}")
#set(CMAKE_CXX_FLAGS "-ggdb -Wall")
message("CMAKE_CXX_FLAGS is ${CMAKE_CXX_FLAGS}")

include_directories(${CMAKE_SOURCE_DIR}/lib) # avoid writting #include "lib/fsm.hpp" in main.cpp
message("CMAKE_SOURCE_DIR ${CMAKE_SOURCE_DIR}")
