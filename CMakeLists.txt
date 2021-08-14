cmake_policy(SET CMP0048 NEW)

project(susolver)
cmake_minimum_required(VERSION 3.13)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 17)

option(BUILD_TESTS "Build tests" ON)
option(COVERAGE "Enable measuring coverage" ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "DEBUG")
endif()

find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
endif(CCACHE_FOUND)
message("--- CCACHE_FOUND: " ${CCACHE_FOUND})

message("--- CMAKE_BUILD_TYPE: " ${CMAKE_BUILD_TYPE})
if(CMAKE_BUILD_TYPE STREQUAL "DEBUG")
    add_compile_options(-g -O0)
elseif(CMAKE_BUILD_TYPE STREQUAL "RELEASE")
    add_compile_options(-O3 -DNDEBUG)
elseif(CMAKE_BUILD_TYPE STREQUAL "RELWITHDEBINFO")
    add_compile_options(-g -O2)
elseif(CMAKE_BUILD_TYPE STREQUAL "MINSIZEREL")
    add_compile_options(-Os -DNDEBUG)
endif()

if(COVERAGE)
    add_compile_options(-fprofile-arcs -ftest-coverage -fPIC -O0)
    add_link_options("--coverage")
    include(cmake/coverage.cmake)
endif()

if(BUILD_TESTS)
    enable_testing()
    find_package(GTest REQUIRED)
    include(CTest)
    add_subdirectory(tests)
endif()

find_package(Boost COMPONENTS program_options REQUIRED)
add_subdirectory(susolver)

include(cmake/format.cmake)
