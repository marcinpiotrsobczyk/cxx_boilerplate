add_executable(show_version show_version.cpp)
target_link_libraries(show_version cxx_setup)

add_executable(crash crash.cpp)
target_link_libraries(crash cxx_setup)
