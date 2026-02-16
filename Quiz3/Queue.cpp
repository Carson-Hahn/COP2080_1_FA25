#include "Queue.h"
#include <iostream>

Queue::Queue(unsigned capacity) {
    data = new int[capacity];
    frnt = bck = 0;
    this->capacity = capacity;
    queueSize = 0;
}

Queue::~Queue() {
    delete[] data;
}

void Queue::dequeue() {
    if (!empty()) {
        frnt = (frnt + 1) % capacity;
        queueSize--;
    }
}

unsigned Queue::size() const {
    return queueSize;
}

bool Queue::empty() const {
    return (queueSize == 0);
}

bool Queue::full() const {
    return (queueSize == capacity);
}

void Queue::enqueue(int val) {
    if (!full()) {
        data[bck] = val;
        bck = (bck + 1) % capacity;
        queueSize++;
    }
}

void Queue::clear() {
    frnt = bck = 0;
    queueSize = 0;
}

void Queue::print() const {
    if (empty()) {
        std::cout << "Empty queue\n";
        return;
    }
    std::cout << '[';
    for (unsigned i = 0, index = frnt; i < queueSize; i++, index = (index + 1) % capacity) {
        std::cout << data[index];
        if (i < queueSize - 1) std::cout << ", ";
    }
    std::cout << "]\n";
}

int Queue::front() const {
    if (empty()) {
        throw std::string("Empty queue");
    }
    return data[frnt];
}
