#include <example/tools.hpp>
#include <example/tools2.hpp>

#include <gtest/gtest.h>

namespace {} // namespace

TEST(CoverageTest, TwoTest) { EXPECT_EQ(example::NotFullyCovered(2), 4); }

TEST(CoverageTest, ThreeTest) { EXPECT_EQ(example::NotFullyCovered(3), 9); }

TEST(CoverageTest, FourTest) { EXPECT_EQ(example::NotFullyCovered(4), 16); }

TEST(CoverageTest, PassingTest) { EXPECT_EQ(example::NotFullyCovered2(2), 4); }

TEST(CoverageTest, FailingTest) { EXPECT_EQ(example::NotFullyCovered2(3), 8); }
