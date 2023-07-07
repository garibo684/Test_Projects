#include <gtest/gtest.h>
#include "queue.cc"

class QueueTest : public ::testing::Test {
 protected:
  void SetUp() override {}

  void TearDown() override {}
};

TEST_F(QueueTest, Empty) {
  Queue<int> queue;
  EXPECT_TRUE(queue.Empty());

  queue.Push(10);
  EXPECT_FALSE(queue.Empty());
}

TEST_F(QueueTest, Size) {
  Queue<int> queue;
  EXPECT_EQ(queue.Size(), 0);

  queue.Push(10);
  EXPECT_EQ(queue.Size(), 1);

  queue.Push(20);
  EXPECT_EQ(queue.Size(), 2);

  queue.Pop();
  EXPECT_EQ(queue.Size(), 1);
}

TEST_F(QueueTest, FrontAndPop) {
  Queue<int> queue;
  queue.Push(10);
  queue.Push(20);
  queue.Push(30);

  EXPECT_EQ(queue.Front(), 10);
  queue.Pop();
  EXPECT_EQ(queue.Front(), 20);
  queue.Pop();
  EXPECT_EQ(queue.Front(), 30);
  queue.Pop();

  EXPECT_THROW(queue.Front(), std::out_of_range);
  EXPECT_THROW(queue.Pop(), std::out_of_range);
}

TEST_F(QueueTest, Push) {
  Queue<int> queue;
  queue.Push(10);
  queue.Push(20);

  EXPECT_EQ(queue.Front(), 10);
  EXPECT_EQ(queue.Size(), 2);
}

TEST_F(QueueTest, PopEmptyQueue) {
  Queue<int> queue;
  EXPECT_THROW(queue.Pop(), std::out_of_range);
}
int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

