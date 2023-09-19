#include <example/tools.hpp>
#include <example_header_only/tools.hpp>
#include <test_tools/tools.hpp>

#include <gtest/gtest.h>

#include <memory>


namespace {
    int GetMeaningOfLife() { return 42; }
}

TEST(SecondExampleTest, ExampleTest) {
    EXPECT_EQ(GetMeaningOfLife(), 42);
}

TEST(SecondExampleTest, IsNullTest)
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

TEST(SecondExampleTest, ExceptionTest)
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

TEST(SecondExampleTest, ExampleLibraryTest)
{
    EXPECT_EQ(example::GetNumber(), 13);
}

TEST(SecondExampleTest, ExampleHeaderOnlyLibraryTest)
{
    EXPECT_EQ(example_header_only::GetNumber(), 14);
}

TEST(SecondExampleTest, ExampleHTestToolsTest)
{
    EXPECT_EQ(test_tools::GetNumber(), 15);
}

TEST(SecondExampleTest, ExampleThreadedFunctionTest)
{
    EXPECT_EQ(test_tools::ThreadedFunction(), 16);
}

TEST(SecondExampleTest, ExampleThreadedFunction2Test)
{
    EXPECT_EQ(test_tools::ThreadedFunction(), 16);
}

TEST(SecondExampleTest, ExampleThreadedFunction3Test)
{
    EXPECT_EQ(test_tools::ThreadedFunction(), 16);
}

TEST(SecondExampleTest, ExampleThreadedFunction4Test)
{
    EXPECT_EQ(test_tools::ThreadedFunction(), 16);
}
