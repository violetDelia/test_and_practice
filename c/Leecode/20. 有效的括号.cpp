#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        int n = s.length();
        if (n % 2)
            return false;
        stack<char> count;
        for (char c : s)
        {
            if (c == '(' || c == '[' || c == '{')
                count.push(c);
            else if (count.empty())
                return false;
            else if (c == ')' && count.top() == '(')
                count.pop();
            else if (c == ']' && count.top() == '[')
                count.pop();
            else if (c == '}' && count.top() == '{')
                count.pop();
            else
                return false;
        }
        return count.empty();
    }
};

int main()
{
    string s = "]";
    Solution a;
    a.isValid(s);

    std::system("pause");
    return 0;
}