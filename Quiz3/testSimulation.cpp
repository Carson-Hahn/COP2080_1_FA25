#include "Stack.h"
#include "Queue.h"

#include <cstdlib>
#include <iostream>
#include <ctime>

void init(Queue& q, Stack& s);
void print(Queue& q, Stack& s);
void feed_students(Queue& q, Stack& s);

int main() {
    srand(time(0));
    Queue students;
    Stack sandwiches;
    init(students, sandwiches);
    std::cout << "Students came to cafeteria\n";
    print(students, sandwiches);

    feed_students(students, sandwiches);

    return 0;
}

void init(Queue& q, Stack& s) {
    for (int i = 0; i < 6; i++) {
        q.enqueue(rand() % 2);
        s.push(rand() % 2);
    }
}

void print(Queue& q, Stack& s) {
    std::cout << "Stud: ";
    q.print();
    std::cout << "Sndw: ";
    s.print();
}

void feed_students(Queue& q, Stack& s) {
    while (!s.empty()) { //there are students in line
        if () { //student wants sandwitch
            cout << "Student took sandwitch and left." << endl;
            s.pop();
            q.dequeue();
            print();
        } else if () { // student does not want sandwitch
            cout << "Student did not take sandwitch and went back in line." << endl;
            q.enqueue(q.front());
            print();
        }
    }
    cout << "Every student has recieved sandwitch" << endl;
}