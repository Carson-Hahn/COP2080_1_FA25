#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>

struct QueueNode {
    int        value;
    QueueNode* next;
    explicit QueueNode(int value);
};

// Integer queue backed by a singly linked list.
// enqueue at tail, dequeue from head — both O(1). No STL.
class Queue {
public:
    Queue();
    ~Queue();

    void enqueue(int value);
    int  dequeue();
    int  front()   const;
    bool isEmpty() const;
    int  size()    const;

private:
    QueueNode* head;
    QueueNode* tail;
    int        count;
};

#endif // QUEUE_H
