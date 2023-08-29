cmake_minimum_required(VERSION 3.16..3.24)
project(c_nn
        LANGUAGES CXX)

add_subdirectory(libs)
add_subdirectory(include)
add_subdirectory(src)

option(BUILD_TESTS "" ON)
option(BUILD_EXAMPLES "" ON)


if (BUILD_TESTS)
    message(STATUS "Building tests...")
    add_subdirectory(tests)
endif()

if (BUILD_EXAMPLES)
    message(STATUS "Building examples...")
    add_subdirectory(example)
endif()