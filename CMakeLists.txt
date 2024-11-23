cmake_minimum_required(VERSION 3.20)

project(pb_utils)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_subdirectory(pb_utils)

add_subdirectory(tests)
