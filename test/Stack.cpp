#include "gtest/gtest.h"
#include "../src/Stack.h"

TEST(StackTest, Push) {
  Stack* s = new Stack();
  s->push(6);

  EXPECT_EQ(6, s->peek());
  delete s;
}

// test what happens when pushing exceeds stack capacity
TEST(ResizeTest, Push) {
  Stack* s = new Stack(3);
  s->push(1);
  s->push(2);
  s->push(3);
  s->push(4);

  EXPECT_EQ(4, s->peek());
  delete s;
}
