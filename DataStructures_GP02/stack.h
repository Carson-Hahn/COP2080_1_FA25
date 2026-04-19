#ifndef STACK_H
#define STACK_H

#include <stdexcept>

struct StackNode {
    int        data;
    StackNode* next;
    explicit StackNode(int data);
};

// Integer stack backed by a singly linked list.
// push and pop are both O(1). No STL.
class Stack {
public:
    Stack();
    ~Stack();

    void push(int data);
    int  pop();
    int  peek()    const;
    bool isEmpty() const;
    int  size()    const;

private:
    StackNode* top;
    int        count;
};

#endif // STACK_H
