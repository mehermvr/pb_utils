# pretty bad utils

A repository to keep all my dirty C++ utility functions and stuff for easy inclusion
in other projects.

The python version of this is currently locked in a private GitLab instance.

## Usage

To include in your projects, use fetch content like so

```cmake
include(FetchContent)
FetchContent_Declare(
  pb_utils
  GIT_REPOSITORY https://github.com/mehermvr/pb_utils.git
  GIT_TAG main)
FetchContent_MakeAvailable(pb_utils)
```

Then linking against `pb_utils` is simply

```cmake
target_link_libraries(your_target PRIVATE pb_utils)
```
