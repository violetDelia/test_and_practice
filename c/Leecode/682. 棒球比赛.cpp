#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    int calPoints(vector<string> &ops)
    {
        stack<int> count;
        for (string &op : ops)
        {
            if (op == "+")
            {
                int n1 = count.top();
                count.pop();
                int n2 = count.top();
                count.push(n1);
                count.push(n1 + n2);
            }
            else if (op == "D")
            {
                count.push(count.top() * 2);
            }
            else if (op == "C")
            {
                count.pop();
            }
            else
            {
                count.push(stoi(op));
            }
        }
        int res = 0;
        while (!empty(count))
        {
            res += count.top();
            count.pop();
        }
        return res;
    }
};

int main()
{

    std::system("pause");
    return 0;
}