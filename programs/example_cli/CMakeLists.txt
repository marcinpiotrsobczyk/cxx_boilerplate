add_executable(example_cli main.cpp)
target_link_libraries(example_cli PRIVATE
  example example_header_only cxx_setup  cli::cli)
