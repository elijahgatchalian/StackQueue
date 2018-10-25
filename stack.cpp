// Eli Gatchalian
// stack.cpp
// May 28, 2014
// Purpose: Implementation file for the Last in First Out method described in
//  stack.h

#include "stack.h"
using namespace std;

Stack::Stack(int s) {
    if (s < MIN) size = MAX;
    else size = s;

    arr = new int[size];

    assert(arr != NULL);
    top = 0;
}

Stack::Stack(const Stack& aStack) {
    if (aStack.size < MIN) arr = new int[MAX];
    else arr = new int[aStack.size];

    size = aStack.size;

    for (int i = 0; i < size; i++)
        arr[i] = aStack.arr[i];

    top = aStack.top;
}

Stack& Stack::operator = (const Stack& rhs) {
    if (this != &rhs){
        top = rhs.top;
        size = rhs.size;
        arr = new int[size];

        for (int i = 0; i < size; i++){
            arr[i] = rhs.arr[i];
        }
    }
    return *this;
}

Stack::~Stack() {
    delete [] arr;
}

bool Stack::push(int val) {
    if (isFull()){
        if (!resize()) return false;
    }
    arr[top] = val;
    top++;
    return true;
}

bool Stack::pop(int& val) {
    if (isEmpty()) return false;
    else{
        val = arr[top - 1];
        top--;
    }
    return true;
}

bool Stack::isEmpty() const {
    return (top == 0);
}

bool Stack::isFull() const {
    return (top == size);
}

bool Stack::resize() {
    int* temp;
    int tempSize = size * HALF_SIZE;

    temp = new int[tempSize];
    if (temp == NULL) return false;

    for (int i = 0; i < top; i++)
        temp[i] = arr[i];

    delete [] arr;
    size = tempSize;
    arr = temp;

    return true;
}
