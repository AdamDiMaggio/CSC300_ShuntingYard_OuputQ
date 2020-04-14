#ifndef Stack_hpp
#define Stack_hpp

#include "stackNode.hpp"

class Stack
{
    private:
        stackNode* top;
        int count;
    
    public:
        Stack();
        void push(string s);
        string pop();
        string peek();
        int getCount(); 
        bool isEmpty();
        void display();
};
#endif