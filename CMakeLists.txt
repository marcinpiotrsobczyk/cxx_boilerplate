cmake_minimum_required(VERSION 3.16)
project(cxx_boilerplate VERSION 0.0.1
                    DESCRIPTION "cxx project boilerplate"
                    LANGUAGES CXX)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "" FORCE)
endif()
message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

add_library(cxx_setup INTERFACE)
target_compile_options(cxx_setup INTERFACE -Wall -Wpedantic -Wextra -mshstk)
target_compile_features(cxx_setup INTERFACE cxx_std_17)

if(SANITIZE_ADDRESS)
    add_compile_options(-fsanitize=address)
    add_link_options(-fsanitize=address)
endif()

if(SANITIZE_THREAD)
    add_compile_options(-fsanitize=thread)
    add_link_options(-fsanitize=thread)
endif()

if(ENABLE_COVERAGE)
    target_compile_options(
        cxx_setup INTERFACE
        -fPIC -fprofile-arcs -ftest-coverage -O0 -g
    )
    target_link_options(cxx_setup INTERFACE --coverage)
endif()

if(USE_PERF)
    target_compile_options(
        cxx_setup INTERFACE
        -pg
    )
    target_link_options(cxx_setup INTERFACE --coverage)
endif()

include(cmake/UpdateSubmodules.cmake)
include(CTest)

add_subdirectory(libraries)
add_subdirectory(programs)
add_subdirectory(external)
add_subdirectory(tests)
