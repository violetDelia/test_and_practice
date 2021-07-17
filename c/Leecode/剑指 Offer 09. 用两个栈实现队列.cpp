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
class CQueue
{
    stack<int> head, tail;

public:
    CQueue()
    {
    }

    void appendTail(int value)
    {
        tail.push(value);
        return;
    }

    int deleteHead()
    {
        if (head.size() != 0)
        {
            int res = head.top();
            head.pop();
            return res;
        }
        if (tail.size() == 0)
            return -1;
        while (!tail.empty())
        {
            head.push(tail.top());
            tail.pop();
        }
        int res = head.top();
        head.pop();
        return res;
    }
};
int main()
{
    CQueue *c = new CQueue();
    c->appendTail(3);
    c->deleteHead();
    c->deleteHead();
    std::system("pause");
    return 0;
}