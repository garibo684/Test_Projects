#include "square.h"
#include <gtest/gtest.h>
#include <limits.h>

TEST(SquareTest, SquareOf5Is25) { EXPECT_EQ(Square(5), 25); }
TEST(SquareTest, SquareOfN5Is25) { EXPECT_EQ(Square(-5), 25); }

TEST(SquareTest, SqruareOf1Is1) {EXPECT_EQ(Square(1), 1); }
TEST(SquareTest, SqruareOfN1Is1) {EXPECT_EQ(Square(-1), 1); }

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}