#include <example/tools.hpp>

#include <gtest/gtest.h>

namespace {} // namespace

TEST(CoverageTest, TwoTest) {
  EXPECT_EQ(example::NaiveFibonacci(40), 165580141);
}
