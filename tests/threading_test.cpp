#include <test_tools/tools.hpp>

#include <gtest/gtest.h>

#include <memory>
#include <string>

namespace {} // namespace

TEST(ThreadingTest, ExampleTest) {
  const char *names[] = {"bob", "fred"};
  std::string last_arg = names[2];
}

TEST(ThreadingTest, ExampleHTestToolsTest) {
  EXPECT_EQ(test_tools::GetNumber(), 15);
}
