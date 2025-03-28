cmake_minimum_required(VERSION 3.28)

project(pb_utils)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include(FetchContent)
FetchContent_Declare(fmt GIT_REPOSITORY https://github.com/fmtlib/fmt GIT_TAG 11.1.4 SYSTEM EXCLUDE_FROM_ALL)
FetchContent_MakeAvailable(fmt)

option(PB_UTILS_BUILD_TESTS "Build tests for pb_utils" ${PROJECT_IS_TOP_LEVEL})

add_subdirectory(pb_utils)

if(PB_UTILS_BUILD_TESTS)
  add_subdirectory(tests)
endif()
