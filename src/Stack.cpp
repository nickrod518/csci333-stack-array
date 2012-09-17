#include "Stack.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

Stack::Stack(int initialSize) {
  theStack = new int[initialSize];
  top = 0;
  capacity = initialSize;
}

Stack::~Stack() {
  delete[] theStack;
}

void Stack::push(int value) {
  // if theStack is full
  if (capacity == top) {
    // create new stack twice as big
    capacity = capacity*2;
    int* newStack = new int[capacity];
    // copy all elements to new stack
    memcpy(newStack, theStack, top);
    // delete old stack
    delete[] theStack;
    // point old stack pointer to new stack
    theStack = newStack;
  }
  assert(capacity != top);

  theStack[top] = value;
  top++;
}

int Stack::pop() {
  top--;
  return theStack[top];
}

int Stack::peek() {
  return theStack[top-1];
}

int Stack::size() {
  return top;
}
