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
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        string res = "";
        for (int i = 0; i < numRows; ++i)
        {
            if (i == 0 || i == numRows - 1)
            {
                for (int p = 0 + i; p < s.size(); p += numRows * 2 - 2)
                {
                    res += s[p];
                }
            }
            else
            {
                int space = (numRows-(i%numRows)-1)*2;
                for (int p = 0 + i; p < s.size(); p += numRows * 2 - 2)
                {
                    res += s[p];
                    int other = p + space;
                    if (other < s.size())
                        res += s[other];
                }
            }
        }
        return res;
    }
};
int main()
{
    Solution a;
    a.convert("PAYPALISHIRING",
              4);
        std::system("pause");
    return 0;
}