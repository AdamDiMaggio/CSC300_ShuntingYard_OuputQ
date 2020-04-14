#include "stackNode.hpp"

 stackNode::stackNode(string payload)
{
    this->payload = payload;
    this->nextNode = 0;
}

string stackNode::getPayload()
{
    return this->payload;
}

 stackNode* stackNode::getNextNode()
{
    return this->nextNode;
}

void stackNode::setNextNode(stackNode* n)
{
    this->nextNode = n;
}