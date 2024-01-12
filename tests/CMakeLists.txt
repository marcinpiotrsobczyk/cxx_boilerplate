if(BUILD_TESTING)
    add_subdirectory(test_tools)

    add_executable(example_test example_test.cpp)
    target_link_libraries(example_test PUBLIC cxx_setup)
    target_link_libraries(example_test PUBLIC example)
    target_link_libraries(example_test PUBLIC example_header_only)
    target_link_libraries(example_test PRIVATE GTest::gtest_main)

    include(GoogleTest)
    gtest_discover_tests(example_test)

    add_executable(example2_test example2_test.cpp)
    target_link_libraries(example2_test PUBLIC cxx_setup)
    target_link_libraries(example2_test PUBLIC example)
    target_link_libraries(example2_test PUBLIC example_header_only)
    target_link_libraries(example2_test PUBLIC test_tools)
    target_link_libraries(example2_test PRIVATE GTest::gtest_main)

    include(GoogleTest)
    gtest_discover_tests(example2_test)

    # add_test(basic_example_test example_test
    #          example_test)
endif()
