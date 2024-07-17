cmake_minimum_required(VERSION 3.16..3.24)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_EXTENSIONS OFF)

project(cnn VERSION 0.1.0)

add_compile_options(-fopenmp)
add_link_options(-fopenmp)

include_directories(/usr/local/include)

AUX_SOURCE_DIRECTORY(src SRC_FILES)

set(PROJECT_SOURCE_DIR "src")
set(PROJECT_INCLUDE_DIR "include/cnn") 

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(third_party)
add_subdirectory(include)
add_subdirectory(src)

option(BUILD_TESTS "Build library tests" ON)
option(BUILD_EXAMPLES "Build example executables" ON)


if (BUILD_TESTS)
    message(STATUS "Building tests...")
    add_subdirectory(tests)
endif()

if (BUILD_EXAMPLES)
    message(STATUS "Building examples...")
    add_subdirectory(example)
endif()
