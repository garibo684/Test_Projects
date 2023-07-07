#include "div.h"
#include <gtest/gtest.h>

TEST(DivTest, DivOf4And2Is2) { EXPECT_EQ(Div(4, 2), 2); }
TEST(DivTest, DivOfN4And2IsN2) { EXPECT_EQ(Div(-4, 2), -2); }
TEST(DivTest, DivOf4AndN2IsN2) { EXPECT_EQ(Div(4, -2), -2); }
TEST(DivTest, DivOfN4AndN2Is2) { EXPECT_EQ(Div(-4, -2), 2); }

TEST(DivTest, DivOf0And2Is0) { EXPECT_EQ(Div(0, 2), 0); }
TEST(DivTest, DivOf0AndN2Is0) { EXPECT_EQ(Div(0, -2), 0); }

TEST(DicTest, DivOf5And0IsU) { EXPECT_EQ(Div(5,0), NULL); }
TEST(DicTest, DivOfN5And0IsU) { EXPECT_EQ(Div(-5,0), NULL); }

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}