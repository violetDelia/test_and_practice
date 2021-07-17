#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class MyQueue
{
public:
    stack<int> front;
    stack<int> rear;
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        rear.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        if (front.empty())
        {
            while (!rear.empty())
            {
                front.push(rear.top());
                rear.pop();
            }
        }
        int out = front.top();
        front.pop();
        return out;
    }

    /** Get the front element. */
    int peek()
    {
        if (front.empty())
        {
            while (!rear.empty())
            {
                front.push(rear.top());
                rear.pop();
            }
        }
        return front.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return front.empty() && rear.empty();
    }
};
int main()
{
    std::system("pause");
    return 0;
}