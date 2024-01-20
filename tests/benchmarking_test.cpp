#include <example/tools.hpp>

#include <test_tools/tools.hpp>

#include <gtest/gtest.h>

namespace {} // namespace

TEST(BenchmarkingTest, ExampleTest) { EXPECT_EQ(test_tools::GetNumber(), 15); }

TEST(BenchmarkingTest, Example2Test) {
  EXPECT_EQ(example::NaiveFibonacci(40), 165580141);
}
