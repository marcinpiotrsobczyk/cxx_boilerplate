add_executable(example_spdlog main.cpp)
target_link_libraries(example_spdlog PRIVATE
  example example_header_only cxx_setup spdlog)
