
#include<iostream>
#include "StringFactory.hpp"

using namespace std;

int main()
{
    string s = "4+3*2*(3*1)";
    string delims = "+-*/()";

    Queue* inputQ = StringFactory::split(s,delims); 
    inputQ->display();
    Queue* outputQ = StringFactory::outputQ(inputQ, delims);
    outputQ->display();
}