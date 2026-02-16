#ifndef STACK_H
#define STACK_H

class Stack {
public:
    Stack();
    ~Stack();

    void push(int val);
    void pop();
    int top() const;
    bool empty() const;
    void print() const;

private:
    class Node {
    public:
        int data;
        Node* next;
        Node(int val = 0, Node* n = nullptr) : data(val), next(n) {};
    };
    Node* front;
};

#endif
