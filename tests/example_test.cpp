#include <example/tools.hpp>
#include <example_header_only/tools.hpp>

#include <gtest/gtest.h>

#include <memory>


namespace {
    int GetMeaningOfLife() { return 42; }
}

TEST(ExampleTest, ExampleTest) {
    EXPECT_EQ(GetMeaningOfLife(), 42);
}

TEST(ExampleTest, IsNullTest)
{
    int* nullPtr = nullptr;
    int* notNullPtr = new int;
    std::unique_ptr<int> uniqueInt = std::make_unique<int>(1);
    std::shared_ptr<int> sharedInt = nullptr;
    EXPECT_FALSE(nullPtr);
    ASSERT_TRUE(uniqueInt);
    *uniqueInt += 1;
    EXPECT_FALSE(sharedInt);
    ASSERT_TRUE(notNullPtr);
    delete notNullPtr;
}

TEST(ExampleTest, ExceptionTest)
{
    auto lambda = [](int i = 0)
    {
        if (i == 0)
        {
            throw std::exception();
        }
        else if (i == 1)
        {
            throw std::overflow_error("overflow");
        }
    };
    EXPECT_THROW(lambda(), std::exception);
    EXPECT_THROW(lambda(1), std::overflow_error);
}

TEST(ExampleTest, ExampleLibraryTest)
{
    EXPECT_EQ(example::GetNumber(), 13);
}

TEST(ExampleTest, ExampleHeaderOnlyLibraryTest)
{
    EXPECT_EQ(example_header_only::GetNumber(), 14);
}
