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

class Solution
{
public:
    long long maxPoints(vector<vector<int>> &points)
    {
        vector<vector<long long>> dp(2, vector<long long>(points[0].size(), 0));
        int i = 0;
        for (; i < points.size(); ++i)
        {
            /*for (int k = 0; k < points[0].size(); ++k)
            {
                for (int j = 0; j < points[0].size(); ++j)
                    dp[i & 1][k] = max(dp[i & 1][k], dp[~i & 1][j] + points[i][k] - abs(k - j));
            }*/
            vector<long long> leftmax(points[0].size(), LLONG_MIN);
            vector<long long> rightmax(points[0].size(), LLONG_MIN);
            for (int j = 0; j < points[0].size(); ++j)
            {
                leftmax[j] = j == 0 ? dp[~i & 1][j] + j : max(leftmax[j - 1], dp[~i & 1][j] + j);
            }
            for (int j = points[0].size() - 1; j >= 0; --j)
            {
                rightmax[j] = j == points[0].size() - 1 ? dp[~i & 1][j] - j : max(rightmax[j + 1], dp[~i & 1][j] - j);
            }
            for (int k = 0; k < points[0].size(); ++k)
            {
                dp[i & 1][k] = max(points[i][k] - k + leftmax[k], points[i][k] + k + rightmax[k]);
            }
        }
        return *max_element(dp[~i & 1].begin(), dp[~i & 1].end());
    }
};
int main()
{
    vector<vector<int>> n = {{1, 2, 3}, {1, 5, 1}, {3, 1, 1}};
    Solution a;
    a.maxPoints(n);
    std::system("pause");
    return 0;
}