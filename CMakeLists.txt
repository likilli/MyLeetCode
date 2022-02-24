cmake_minimum_required(VERSION 3.16)

project(LeetCode)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_INSTALL_NAME_DIR ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION OFF)

add_compile_options(
    -Wall
    -Wextra
    -Wreorder
)

add_library(base STATIC "")
target_sources(base PRIVATE
    base/list.h
    base/list.cc)
target_include_directories(base PUBLIC ${CMAKE_SOURCE_DIR}/base)


add_executable(leetcode main.cpp)
target_link_libraries(leetcode base)
