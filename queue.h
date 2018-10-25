// Eli Gatchalian
// queue.h
// May 28, 2014
// Purpose: This class holds all the necessary functions and variables to
//  properly add to a list like a Queue (First in First out)

#include <cassert>

using namespace std;

#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
 public:
  Queue();
  
  Queue(const Queue& aQueue);
  
  Queue& operator = (const Queue& rhs);
  
  ~Queue();
  
  bool enqueue(int val);
  // postconditions: Adds a number to the end of the Queue
  
  bool dequeue(int& val);
  // postconditions: Removes last number at the end of the Queue

  bool isEmpty();
  // Checks to see if Queue is empty
  
 private:
  struct Node{
	int data;
	Node* next;
  };
  
  Node* front;
  Node* tail;
  
};

#endif
