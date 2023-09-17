if(BUILD_TESTING)
    add_executable(example_test example_test.cpp)
    target_link_libraries(example_test PUBLIC cxx_setup)
    target_link_libraries(example_test PUBLIC example)
    target_link_libraries(example_test PRIVATE GTest::gtest_main)

    include(GoogleTest)
    gtest_discover_tests(example_test)

    # add_test(basic_example_test example_test
    #          example_test)
endif()
