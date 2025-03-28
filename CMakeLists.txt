cmake_minimum_required(VERSION 3.20)

project(pb_utils)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

option(PB_UTILS_BUILD_TESTS "Build tests for pb_utils" ${PROJECT_IS_TOP_LEVEL})

add_subdirectory(pb_utils)

if(PB_UTILS_BUILD_TESTS)
  add_subdirectory(tests)
endif()
