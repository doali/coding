#include <gtest/gtest.h>

// Trick to stop C++ from name-mangling
extern "C" {
#include "main.c"
}

// TEST is a macro
// TEST(TestCaseName, TestName)
// (!) _ are forbidden for names !!
// (!) TestCaseName must be unique
// (!) TestName must be unique
TEST(TestCaseNameCompare, TestNameMaxInFirst) {
  //  EXPECT_EQ is a macro
  EXPECT_EQ(3, compare(3, 1, 2));
}

TEST(Compare, MaxInFirst) { EXPECT_EQ(3, compare(3, 2, 1)); }

TEST(Compare, MaxInSecond) { EXPECT_EQ(3, compare(1, 3, 2)); }

TEST(Compare, MaxInThree) { EXPECT_EQ(3, compare(1, 2, 3)); }

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
