#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string.h>
using namespace std;
class Solution
{
    int mod = 1000000007;

public:
    int numberOfArrays(string s, int k)
    {
        int n = s.size();
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        for (int i = 0; i < s.size(); ++i)
        {
            long long num = 0;
            long long base = 1;
            for (int l = 0; i - l >= 0 && l < 10; ++l)
            {
                if (s[i - l] == '0')
                {
                    base *= 10;
                    continue;
                }
                num = (s[i - l] - '0') * base + num;
                base *= 10;
                if (num <= k)
                {
                    dp[i + 1] += dp[i - l];
                    dp[i + 1] %= mod;
                }
                else
                {
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
int main()
{
    Solution a;
    a.numberOfArrays("3422444313111132566283762260526810599185",
                     703);
    std::system("pause");
    return 0;
}