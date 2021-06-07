#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> shortestToChar(string s, char c)
    {
        int l = s.length();
        vector<int> res(l, INT_MAX);
        for (int i = 0; i < l; ++i)
        {
            if (s[i] == c)
                res[i] = 0;
        }
        int count = 0;
        for (int i; i < l; ++i)
        {
            if (res[i] == 0)
            {
                count = i;
                break;
            }
        }
        for (int i = count; i < l; ++i)
        {
            if (res[i] == 0)
                count = i;
            else
                res[i] = i - count;
        }
        for (int i = l - 1; i >= 0; --i)
        {
            if (res[i] == 0)
            {
                count = i;
                break;
            }
        }
        for (int i = count; i >= 0; --i)
        {
            if (res[i] == 0)
                count = i;
            else
            {
                int n = count -i;
                if (n < res[i])
                    res[i] = n;
            }
        }
        return res;
    }
};

int main()
{
    Solution a;
    a.shortestToChar("loveleetcode", 'o');

        std::system("pause");
    return 0;
}