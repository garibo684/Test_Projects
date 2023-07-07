#include "subs.h"
#include <gtest/gtest.h>
#include <limits.h>

TEST(SubsTest, Subof4And2Is2) { EXPECT_EQ(Subs(4, 2), 2); }
TEST(SubsTest, Subof4AndN2Is6) { EXPECT_EQ(Subs(4, -2), 6); }
TEST(SubsTest, SubofN4And2IsN6) { EXPECT_EQ(Subs(-4, 2), -6); }
TEST(SubsTest, SubofN4AndN2IsN2) { EXPECT_EQ(Subs(-4, -2), -2); }

TEST(SubTest, SubOf2And0Is2) { EXPECT_EQ(Subs(2, 0), 2); }
TEST(SubTest, SubOfN2And0IsN2) { EXPECT_EQ(Subs(-2, 0), -2); }
TEST(SubTest, SubOf0AndN2Is2) { EXPECT_EQ(Subs(0, -2), 2); }
TEST(SubTest, SubOf0And2IsN2) { EXPECT_EQ(Subs(0, 2), -2); }

TEST(SubTest, SubOf0And0Is0) { EXPECT_EQ(Subs(0, 0), 0); }

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
