add_library(pb_utils INTERFACE)
# for later once i start getting more complicated add_library(pb_utils::math
# ALIAS math)
target_include_directories(pb_utils
                           INTERFACE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>)
# need to add an install interface but i dont understand install all that well
# yet
