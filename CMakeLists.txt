cmake_minimum_required(VERSION 3.16)
project(cxx_boilerplate VERSION 0.0.1
                    DESCRIPTION "cxx project boilerplate"
                    LANGUAGES CXX)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "" FORCE)
endif()
message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

add_library(cxx_setup INTERFACE)
target_compile_options(cxx_setup
    INTERFACE -Wall -Wpedantic -Wextra)
target_compile_features(cxx_setup INTERFACE cxx_std_17)
target_include_directories(cxx_setup
    INTERFACE ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/header_include)

include(cmake/UpdateSubmodules.cmake)
include(CTest)

add_subdirectory(src)
add_subdirectory(executables)
add_subdirectory(external)
add_subdirectory(tests)
