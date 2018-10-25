// Eli Gatchalian
// queue.cpp
// May 28, 2014
// Purpose: Implementation file for the First in First Out method described in
//  queue.h

#include "queue.h"
#include <iostream>
using namespace std;

Queue::Queue() {
    front = NULL;
    tail = NULL;
}

Queue::Queue(const Queue& aQueue) {
    Node* temp;
    if (aQueue.front == NULL) front = NULL;
    else {
        front = new Node;
        assert(front != NULL);
        front->data = aQueue.front->data;
        tail = front;
        temp = aQueue.front->next;
        while (temp != NULL){
            tail->next = new Node;
            assert(tail->next != NULL);
            tail = tail->next;
            tail->data = temp->data;
            temp = temp->next;
        }
    }
}

Queue& Queue::operator = (const Queue& rhs) {
    Node* temp;
    if (this != &rhs){
        while (front != NULL){
            temp = front;
            front = front->next;
            delete temp;
        }
        if (rhs.front == NULL) front = NULL;
        else{
            front = new Node;
            assert(front != NULL);
            front->data = rhs.front->data;
            tail = front;
            temp = rhs.front->next;
            while (temp != NULL){
                tail->next = new Node;
                assert(tail->next != NULL);
                tail = tail->next;
                tail->data = temp->data;
                temp = temp->next;
            }
            tail->next = NULL;
        }
    }
    return *this;
}

Queue::~Queue() {
    Node* delPtr;
    while (!isEmpty()){
        delPtr = front;
        front = front->next;
        delete delPtr;
    }
}

bool Queue::enqueue(int val) {
    if (isEmpty()){
        front = new Node;
        if (front == NULL) return false;
        front->data = val;
        front->next = NULL;
        tail = front;
    }else{
        tail->next = new Node;
        if (tail->next == NULL) return false;
        tail = tail->next;
        tail->data = val;
        tail->next = NULL;
    }
    return true;
}

bool Queue::dequeue(int& val) {
    if (isEmpty()) return false;
    
    Node *temp;
    val = front->data;
    temp = front;
    front = front->next;
    delete temp;
    return true;
}

bool Queue::isEmpty() {
    return front == NULL;
}
