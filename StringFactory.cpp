
#include "StringFactory.hpp"

Queue* StringFactory::split(string s, string delims)
{
    Queue* q = new Queue();
    int stringLength = s.length();
    int delimsLength = delims.length();
    //cout << "delimsLength: "<<delimsLength <<"\n";
    string token = "";
    string letters = "";

    for(int i = 0; i<stringLength;i++)  //runs through whole string
    {
        for(int j = 0; j< delimsLength;j++)  //checks each character in string against the delims
        {
            if(s[i] != delims[j])  //if the string element is not equal
            {
                //option 1: we've checked all delims against the current string element and should add it to the substring
                if(j == delimsLength - 1)
                {
                    letters = letters + s[i];
                    if(i == stringLength - 1)
                    {
                        q->enqueue(letters);
                    }
                    break;
                }
                //option 2: we haven't checked all delims and need to check the next one
                else
                {
                    continue;   //increment j and check the next delim                 
                }
            }
            else    //if the current string element is equal to a delim
            {
                int holder = letters.length();
                //substring is empty
                if(holder == 0) 
                {
                    token = delims[j];
                    q->enqueue(token);
                    break;
                }
                //substring isn't empty
                else
                {
                    q->enqueue(letters);
                    letters = "";
                    token = delims[j];
                    q->enqueue(token);
                    break;
                }
            }

        }
    }
    return q;
}

Queue* StringFactory::outputQ(Queue* inputQ, string delims)
{
    Queue* outputQ = new Queue();
    Stack* opStack = new Stack();
    int delimsLength = delims.length();
    //cout << delimsLength <<"\n";
    
    //runs through whole inputQ, checking the head each time
    while(inputQ->getCount() != 0)  
    {
        string s = inputQ->getHead()->getPayload(); //this is the queue value we are trying to push
        cout << "Checking " << s <<" against the delims.\n";
        for(int j = 0; j< delimsLength;j++)
        {
            if(s[0] != delims[j])  //not equal to delim
            {
                if(j == delimsLength - 1)
                {
                    cout <<"all delims checked." << "\n";
                    outputQ->enqueue(s);
                    cout << "Added " << s << " to the outputQ.\n";
                    inputQ->dequeue();
                    break;
                }
                else    
                {
                    continue;               
                }
            }
            else    //equal to a delim
            {
                if(opStack->getCount() == 0) //nothing on the stack yet
                {
                    string dq = inputQ->dequeue();
                    opStack->push(dq);
                    cout << "Nothing on stack yet. Pushed "<< dq<<" to the opStack.\n";
                    break;
                }
                else if(s == "(")   //trying to push a "("
                {
                    opStack->push(inputQ->dequeue());
                    cout << "Pushed '('\n";
                    break;
                }
                else if(s == ")")   //trying to push ")"
                {   
                    inputQ->dequeue();  //burn the )
                    cout <<"')' has been burned.\n";
                    while(opStack->peek() != "(")
                    {
                        string pop = opStack->pop();
                        outputQ->enqueue(pop);
                        cout<<"Popped "<< pop<< " from opstack and moved it to outputQ.\n";
                    }
                    string pop = opStack->pop();
                    cout << "Have now removed the " << pop << " from opStack.\n";
                    break;
                }
                else
                {
                    checkPrecedence(inputQ, outputQ, opStack);
                    break;
                }
            }
        }
    }
    cout<<"InputQ is empty. Now popping all nodes of opStack to ouputQ.\n";
    while(opStack->getCount() != 0)
    {
        string lastStep = opStack->pop();
        outputQ->enqueue(lastStep);
        cout<< lastStep << " has been added to ouputQ.\n";
    }

    return outputQ;
}

void StringFactory::checkPrecedence(Queue* inputQ, Queue* outputQ, Stack* opStack)
{
    cout << "**Precedence Check**\n";
    string head = inputQ->getHead()->getPayload();
    cout<< "Head = " << head <<"\n";
    string top = opStack->peek();
    cout<< "Top = " << top <<"\n";

    int headPriority;
    if(head == "+")
    {
        headPriority = 2;
    }
    else if(head == "-")
    {
        headPriority = 2;
    }
    else if(head == "*")
    {
        headPriority = 3;
    }
    else if(head == "/")
    {
        headPriority = 3;
    }

    int topPriority;

    if(top == "+")
    {
        topPriority = 2;
    }
    else if(top == "-")
    {
        topPriority = 2;
    }
    else if(top == "*")
    {
        topPriority = 3;
    }
    else if(top == "/")
    {
        topPriority = 3;
    }


    if(headPriority <= topPriority) //the input op is <= top so we don't push it onto the op stack
    {
        string pop = opStack->pop();
        outputQ->enqueue(pop);
        cout << head << " is not a higher priority than " << top <<". Trying again.\n";
    }
    else if(headPriority > topPriority) //input op is higher than the top so we will push it onto op stack
    {
        string pop = inputQ->dequeue();
        opStack->push(pop);
        cout << head << " has a higher priority than " << top <<". Pushed " << head << " to opStack.\n";
    }
}
