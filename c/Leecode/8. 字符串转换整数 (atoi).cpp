#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution
{
public:
    int myAtoi(string s)
    {
        bool flag = false;
        char *p = &s[0];
        int res = 0;
        while (*p == ' ')
            p++;
        if (*p == '+' || *p == '-')
        {
            if (*p == '-')
                flag = true;
            ++p;
        }
        while (isdigit(*p))
        {
            if (flag)
            {
                if (res > INT_MAX / 10)
                    return INT_MIN;
                if (res == INT_MAX / 10 && *p - '0' >= INT_MAX % 10 + 1)
                    return INT_MIN;
            }
            else
            {
                if (res > INT_MAX / 10)
                    return INT_MAX;
                if (res == INT_MAX / 10 && *p - '0' >= INT_MAX % 10)
                    return INT_MAX;
            }
            res = res * 10 + (*p - '0');
            p++;
        }
        if (flag)
            return -res;
        return res;
    }
};
int main()
{
    std::system("pause");
    return 0;
}