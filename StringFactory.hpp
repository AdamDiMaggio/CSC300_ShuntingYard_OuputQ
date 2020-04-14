#ifndef StringFactory_hpp
#include "Queue.hpp"
#include "Stack.hpp"
#include <iostream>

using namespace std;

class StringFactory
{
    public:
        static Queue* split(string s, string delims);
        static Queue* outputQ(Queue* inputQ, string delims);
        static void checkPrecedence(Queue* inputQ, Queue* outputQ, Stack* opStack);
};
#endif