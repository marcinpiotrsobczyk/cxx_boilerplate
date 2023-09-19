if(BUILD_TESTING)
    add_subdirectory(test_tools)

    add_executable(example_test example_test.cpp)
    target_link_libraries(example_test PUBLIC cxx_setup)
    target_link_libraries(example_test PUBLIC example)
    target_link_libraries(example_test PUBLIC example)
    target_link_libraries(example_test PRIVATE GTest::gtest_main)

    include(GoogleTest)
    gtest_discover_tests(example_test)

    add_executable(second_example_test second_example_test.cpp)
    target_link_libraries(second_example_test PUBLIC cxx_setup)
    target_link_libraries(second_example_test PUBLIC example)
    target_link_libraries(second_example_test PUBLIC test_tools)
    target_link_libraries(second_example_test PRIVATE GTest::gtest_main)

    include(GoogleTest)
    gtest_discover_tests(second_example_test)

    # add_test(basic_example_test example_test
    #          example_test)
endif()
