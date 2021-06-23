#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
    int max(int a, int b)
    {
        return a >= b ? a : b;
    }

public:
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1));
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;
        for (int i = 0; i < group.size(); i++)
            for (int members = n; members >= group[i]; members--)
                for (int sum = minProfit; sum >= 0; sum--)
                    dp[members][sum] = (dp[members][sum] + dp[members - group[i]][max(0, sum - profit[i])]) % (int)(1e9 + 7);
        return dp[n][minProfit];
    }
};

int main()
{
    std::system("pause");
    return 0;
}