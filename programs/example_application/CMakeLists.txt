add_executable(example_appbase main.cpp)
target_link_libraries(example_appbase PRIVATE
  example example_header_only cxx_setup)
