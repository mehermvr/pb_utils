add_library(pb_utils STATIC numbers.cpp bar.cpp timer.cpp)
target_include_directories(pb_utils PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>)
target_compile_features(pb_utils PUBLIC cxx_std_23)
