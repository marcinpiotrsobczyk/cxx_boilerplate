add_executable(example_allocator main.cpp)
target_link_libraries(example_allocator PRIVATE
  example example_header_only cxx_setup  cli::cli)
