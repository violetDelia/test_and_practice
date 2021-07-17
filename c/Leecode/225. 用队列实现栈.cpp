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
class MyStack
{
public:
    queue<int> first;
    queue<int> second;
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        if (!second.empty())
        {
            first.push(second.front());
            second.pop();
        }
        second.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int out;
        if (!second.empty())
        {
            out = second.front();
            second.pop();
            return out;
        }
        out = first.back();
        while (first.size() > 1)
        {
            second.push(first.front());
            first.pop();
        }
        first.pop();
        while (second.size() > 1)
        {
            first.push(second.front());
            second.pop();
        }
        return out;
    }

    /** Get the top element. */
    int top()
    {
        if (second.empty())
            return first.back();
        return second.front();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return first.empty() && second.empty();
    }
};
int main()
{
    std::system("pause");
    return 0;
}