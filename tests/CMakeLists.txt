if(BUILD_TESTING)
    add_subdirectory(test_tools)

    set(BOOST_COMPONENTS)
    list(APPEND BOOST_COMPONENTS
        atomic
        chrono
        date_time
        filesystem
        program_options
        system)
    find_package( Boost 1.74 REQUIRED COMPONENTS ${BOOST_COMPONENTS} )



    link_libraries(cxx_setup GTest::gtest_main)

    add_executable(example_test example_test.cpp)
    target_link_libraries(example_test PUBLIC example)
    target_link_libraries(example_test PUBLIC example_header_only)

    add_executable(example2_test example2_test.cpp)
    target_link_libraries(example2_test PUBLIC test_tools)

    add_executable(example3_test example3_test.cpp)

    add_executable(address_invalid_test address_invalid_test.cpp)
    target_link_libraries(address_invalid_test PUBLIC example)
    target_link_libraries(address_invalid_test PUBLIC example_header_only)

    add_executable(threading_test threading_test.cpp)
    target_link_libraries(threading_test PUBLIC test_tools)

    add_executable(coverage_test coverage_test.cpp)
    target_link_libraries(coverage_test PUBLIC example)

    add_executable(profiling_test profiling_test.cpp)
    target_link_libraries(profiling_test PUBLIC example)

    add_executable(benchmarking_test benchmarking_test.cpp)
    target_link_libraries(benchmarking_test PUBLIC example)
    target_link_libraries(benchmarking_test PUBLIC test_tools)

    add_executable(allocator_test allocator_test.cpp)
    target_link_libraries(allocator_test PUBLIC example)
    target_link_libraries(allocator_test PUBLIC Boost::filesystem)

    add_test(
        NAME example.Test
        COMMAND date
    )

endif()
