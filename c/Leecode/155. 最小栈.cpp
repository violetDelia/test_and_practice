#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class MinStack
{
    stack<int> min_stack;
    stack<int> stack;

public:
    /** initialize your data structure here. */

    MinStack()
    {
        min_stack.push(INT_MAX);
    }

    void push(int val)
    {
        stack.push(val);
        if (val < min_stack.top())
            min_stack.push(val);
        else
            min_stack.push(min_stack.top());
        return;
    }

    void pop()
    {
        stack.pop();
        min_stack.pop();
        return;
    }

    int top()
    {
        return stack.top();
    }

    int getMin()
    {
        return min_stack.top();
    }
};

int main()
{

    std::system("pause");
    return 0;
}