add_executable(example_allocator main.cpp)
target_include_directories(example_allocator PRIVATE
  ${PROJECT_SOURCE_DIR}/external/benchmark/include)
target_link_libraries(example_allocator PRIVATE
  example example_header_only cxx_setup benchmark)
