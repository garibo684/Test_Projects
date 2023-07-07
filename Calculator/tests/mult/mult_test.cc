#include "mult.h"
#include <gtest/gtest.h>

TEST(MultTest, MultOf4And2Is8) {
  EXPECT_EQ(Mult(4, 2), 8);
  EXPECT_EQ(Mult(2, 4), 8);
}
TEST(MultTest, MultOfN4And2IsN8) {
  EXPECT_EQ(Mult(-4, 2), -8);
  EXPECT_EQ(Mult(2, -4), -8);
}
TEST(MultTest, MultOf4AndN2IsN8) {
  EXPECT_EQ(Mult(4, -2), -8);
  EXPECT_EQ(Mult(-2, 4), -8);
}
TEST(MultTest, MultOfN4AndN2Is8) {
  EXPECT_EQ(Mult(-4, -2), 8);
  EXPECT_EQ(Mult(-2, -4), 8);
}

TEST(MultTest, MultOf2And0Is0) {
  EXPECT_EQ(Mult(2, 0), 0);
  EXPECT_EQ(Mult(0, 2), 0);
}
TEST(MultTest, MultOfN2And0Is0) {
  EXPECT_EQ(Mult(-2, 0), 0);
  EXPECT_EQ(Mult(0, -2), 0);
}

TEST(MultTest, MultOf0And0Is0) { EXPECT_EQ(Mult(0, 0), 0); }

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
