add_executable(parse parse.cpp)
target_link_libraries(parse PRIVATE glaze_glaze cxx_setup)

configure_file(example.json ${CMAKE_BINARY_DIR}/example.json COPYONLY)
