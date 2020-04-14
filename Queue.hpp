
#ifndef Queue_hpp
#define Queue_hpp
#include "Node.hpp"
class Queue
{
    private:
        Node* head;
        Node* tail;
        int count;

    public:
        Queue();
        void enqueue(string payload);
        string dequeue();
        void display();
        int getCount();
        Node* getHead();
        bool isEmpty();
};
#endif