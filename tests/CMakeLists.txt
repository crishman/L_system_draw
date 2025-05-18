cmake_minimum_required(VERSION 3.15)

# Enable testing
enable_testing()

# Include directories
include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/Headers)

# Add test for math functions
add_executable(math_test math_test.cpp)
target_link_libraries(math_test PRIVATE gtest gtest_main)
add_test(NAME MathTest COMMAND math_test)

# Add test for basic line properties
add_executable(line_test line_test.cpp)
target_link_libraries(line_test PRIVATE gtest gtest_main)
add_test(NAME LineTest COMMAND line_test)