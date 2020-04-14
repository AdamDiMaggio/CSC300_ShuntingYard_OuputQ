#include<iostream>
using namespace std;

class stackNode
{
    public:
        stackNode(string payload);
        string getPayload();
        stackNode* getNextNode();
        void setNextNode(stackNode* n);

    private:
        string payload;
        stackNode* nextNode;
};