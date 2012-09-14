#include "Stack.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>

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
  // create new stack twice as big
  // copy all elements to new stack
  // delete old stack
  // point old stack pointer to new stack
  if (capacity == top) {
    capacity = capacity*2;
    int* newStack = new int[capacity];
    memcpy(newStack, theStack, top);
    delete[] theStack;
    theStack = newStack;
  }

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
