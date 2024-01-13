#include <example/tools.hpp>
#include <example_header_only/tools.hpp>

#include <gtest/gtest.h>

#include <memory>
#include <string>

namespace {} // namespace

TEST(ExampleTest, ExampleTest) {
  const char *names[] = {"bob", "fred"};
  std::string last_arg = names[2];
}

TEST(ExampleTest, ExampleLibraryTest) { EXPECT_EQ(example::GetNumber(), 13); }

TEST(ExampleTest, ExampleHeaderOnlyLibraryTest) {
  EXPECT_EQ(example_header_only::GetNumber(), 14);
}
