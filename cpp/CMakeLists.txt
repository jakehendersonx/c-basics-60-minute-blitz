cmake_minimum_required(VERSION 3.14)
project(my_project)

# Include the Google Test library
add_subdirectory(path/to/googletest)
include_directories(path/to/googletest/include)

# Add the main project library
add_library(mylib src/myclass.cpp)
target_include_directories(mylib PUBLIC include/mylib)

# Add the test executable
add_executable(mytest tests/myclass_test.cpp)
target_link_libraries(mytest mylib gtest)