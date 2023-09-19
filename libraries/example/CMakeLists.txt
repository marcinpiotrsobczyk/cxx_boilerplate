add_library(example tools.cpp)
target_link_libraries(example PUBLIC cxx_setup)
target_include_directories(example PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
