add_library(example_header_only INTERFACE)
target_link_libraries(example_header_only INTERFACE cxx_setup)
target_include_directories(example_header_only INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}/include")
