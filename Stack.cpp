#include "Stack.hpp"

Stack::Stack()
{
    this->top = 0;
    this->count = 0;
}

void Stack::display()
{
    stackNode* currNode = this->top;
    while(currNode)
    {
        cout << currNode->getPayload();
        currNode = currNode->getNextNode();
    }
    cout << "\n";
}

void Stack::push(string s)
{
    stackNode* n = new stackNode(s);
    if(this->top)
    {
        n->setNextNode(this->top);
    }
    this->top = n;
    this->count++;
}

bool Stack::isEmpty()
{
    return this->count == 0;
}

string Stack::pop()
{
    if(this->top)
    {
        stackNode* temp = this->top;
        this->top = this->top->getNextNode();
        string payload2Return = temp->getPayload();
        delete temp;
        this->count--;
        return payload2Return;
    }
    return 0;
}

string Stack::peek()    //returns the payload at the top
{
    if(this->top)
    {
        return this->top->getPayload();
    }
    return 0;
}

int Stack::getCount()
{
    return this->count;
}