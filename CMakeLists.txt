cmake_minimum_required(VERSION 3.16)
project(cxx_boilerplate VERSION 0.0.1
                    DESCRIPTION "cxx project boilerplate"
                    LANGUAGES CXX)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "" FORCE)
endif()
message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

add_library(cxx_setup INTERFACE)
target_compile_options(cxx_setup INTERFACE -Wall -Wpedantic -Wextra)
target_compile_features(cxx_setup INTERFACE cxx_std_17)

if(SANITIZE_ADDRESS)
    add_compile_options(-fsanitize=address)
    add_link_options(-fsanitize=address)
endif()

include(cmake/UpdateSubmodules.cmake)
include(CTest)

add_subdirectory(libraries)
add_subdirectory(programs)
add_subdirectory(external)
add_subdirectory(tests)
