#include "gtest/gtest.h"
#include "../src/Stack.h"

TEST(StackTest, Initialize) {
  Stack* s = new Stack();

  EXPECT_EQ(0, s->size());
  delete s;
}

TEST(StackTest, Push) {
  Stack* s = new Stack();
  s->push(6);

  EXPECT_EQ(6, s->peek());
  EXPECT_EQ(1, s->size());
  delete s;
}

// test what happens when pushing exceeds stack capacity
TEST(StackTest, Extend) {
  Stack* s = new Stack(3);
  s->push(1);
  s->push(2);
  s->push(3);
  s->push(4);

  EXPECT_EQ(4, s->peek());
  EXPECT_EQ(4, s->size());
  delete s;
}
