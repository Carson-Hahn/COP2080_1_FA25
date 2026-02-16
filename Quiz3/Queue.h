#ifndef QUEUE_H
#define QUEUE_H

class Queue {
public:
    Queue(unsigned capacity = 10);
    ~Queue();

    unsigned size() const;
    bool empty() const;
    bool full() const;

    void clear();
    void enqueue(int val);
    void dequeue();
    int front() const;
    void print() const;

private:
    int* data;
    unsigned queueSize; // the actual number of elements in the queue
    unsigned capacity;  // the max number of elements
    int frnt;  // the index of the first element in the queue
    int bck;   // the index of the last element in the queue
};

#endif
