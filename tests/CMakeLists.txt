cmake_minimum_required(VERSION 3.15)

# Enable testing
enable_testing()

# Include directories
include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/Headers)

# Platform-specific settings
if(WIN32)
    add_definitions(-DGTEST_DONT_DEFINE_FAIL_FAST=1)
    add_definitions(-D_UNICODE -DUNICODE)
endif()

# Add test for math functions
add_executable(math_test math_test.cpp)
if(WIN32)
    target_link_libraries(math_test PRIVATE gtest gtest_main)
else()
    target_link_libraries(math_test PRIVATE gtest gtest_main L_system_draw_core)
    target_compile_definitions(math_test PRIVATE -DLINUX_BUILD)
endif()
add_test(NAME MathTest COMMAND math_test)

# Add test for basic line properties
if(WIN32)
    add_executable(line_test line_test.cpp)
    target_link_libraries(line_test PRIVATE gtest gtest_main)
    add_test(NAME LineTest COMMAND line_test)
endif()