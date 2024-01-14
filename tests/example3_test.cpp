#include <gtest/gtest.h>

namespace {
int GetMeaningOfLife() { return 42; }
} // namespace

TEST(Example3Test, ExampleTest) { EXPECT_EQ(GetMeaningOfLife(), 42); }

TEST(Example3Test, ExampleFailingTest) { EXPECT_EQ(GetMeaningOfLife(), 43); }

TEST(Example3Test, ExampleFailing2Test) {
  EXPECT_EQ(GetMeaningOfLife(), 43);
  EXPECT_EQ(GetMeaningOfLife(), 44);
}

TEST(Example3Test, ExampleFailing3Test) {
  EXPECT_EQ(GetMeaningOfLife(), 43);
  ASSERT_EQ(GetMeaningOfLife(), 44);
}

TEST(Example3Test, ExampleFailing4Test) {
  ASSERT_EQ(GetMeaningOfLife(), 44);
  EXPECT_EQ(GetMeaningOfLife(), 43);
}
