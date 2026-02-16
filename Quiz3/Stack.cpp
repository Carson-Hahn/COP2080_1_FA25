#include "Stack.h"
#include <iostream>

Stack::Stack() {
    front = nullptr;
}

Stack::~Stack() {
    while (!empty()) {
        pop();
    }
}

void Stack::push(int val) {
    front = new Node(val, front);
}

void Stack::pop() {
    if (!empty()) {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

int Stack::top() const {
    if (empty()) {
        throw std::string("Empty stack");
    }
    return front->data;
}

bool Stack::empty() const {
    return (front == nullptr);
}

void Stack::print() const {
    Node* cur = front;
    std::cout << '[';
    while (cur) {
        std::cout << cur->data;
        cur = cur->next;
        if (cur) std::cout << ", ";
    }
    std::cout << "]\n";
}
