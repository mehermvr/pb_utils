add_library(pb_utils STATIC)
target_sources(pb_utils PRIVATE numbers.cpp)
target_include_directories(pb_utils PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>)
target_compile_features(pb_utils PUBLIC cxx_std_20)
