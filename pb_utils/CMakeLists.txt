add_library(pb_utils STATIC bar.cpp timer.cpp)
target_link_libraries(pb_utils PRIVATE fmt::fmt)
target_include_directories(pb_utils PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>)
