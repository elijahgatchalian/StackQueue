// Eli Gatchalian
// stack.h
// May 28, 2014
// Purpose: This class holds all the necessary functions and variables to
//  properly add to a list like a Stack (Last in First Out)

#include <cassert>

using namespace std;

#ifndef STACK_H
#define STACK_H

class Stack
{
 public:
  Stack(int s);
  
  Stack(const Stack& aStack);
  
  Stack& operator = (const Stack& rhs);

  ~Stack();
  
  bool push(int val);
  // postconditions: Adds a number to the top of the Stack
  
  bool pop(int& val);
  // postcondtions: Removes top number from the Stack
  
  bool isEmpty() const;
  // Checks if Stack is empty
  
 private:
  int top, size;
  int *arr;
  static const int MIN = 3;
  static const int MAX = 50;
  static constexpr const double HALF_SIZE = 1.5;
  bool isFull() const;
  bool resize();
};

#endif
