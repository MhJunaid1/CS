#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;

class Receiver
{
    vector<queue<int>> sqn;

public:
    void addRequestforResource(int rid, int reqno)
    {
    }
    // adds a new quest with number reqno to the resource sqn[rid]
    // rid is between 0 and 4, as we have 5 resources
    void serviceRequestatResource(int rid)
    {
    }
    // services the request (dequeues) at front of sqn[rid]
    void printQueues()
    {
    }
    // prints all queues line by line, numbers separated by spaces
};

void SequenceCheck()
{
    string s1 = "001101";
    stack<char> stk;
    for (int i = 0; i < s1.size(); i++)
    {
        if (!stk.empty())
        {
            if ((stk.top() == '0' && s1[i] == '1') || (stk.top() == '1' && s1[i] == '0'))
            {
                stk.pop();
            }
            else
            {
                stk.push(s1[i]);
            }
        }
        else
        {
            stk.push(s1[i]);
        }
    }
    if (stk.empty())
    {
        cout << "Valid Sequence" << endl;
    }
    else
    {
        cout << "Not a valid sequence" << endl;
    }
}
int main()
{
    SequenceCheck();
}