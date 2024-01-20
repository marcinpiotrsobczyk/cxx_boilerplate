add_executable(example_benchmark main.cpp)
target_include_directories(example_benchmark PRIVATE
  ${PROJECT_SOURCE_DIR}/external/benchmark/include)
target_link_libraries(example_benchmark PRIVATE
  example example_header_only cxx_setup benchmark)
