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
    long long maxAlternatingSum(vector<int> &nums)
    {
        long long max = 0;
        vector<vector<long long>> dp(nums.size(),vector<long long>(nums.size(),0));
        for(int i = 0; i < nums.size(); ++i){
            if(i&1)
                dp[i][i] -= nums[i];
            else
                dp[i][i] += nums[i];
            if (dp[i][i] > max)
                    max = dp[i][i];
        }
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            for (int j = i+1; j < nums.size(); ++j)
            {
                if (j & 1)
                    dp[i][j] = dp[i][j - 1] - (long long)nums[j];
                else
                    dp[i][j] = dp[i][j - 1] + (long long)nums[j];
                if (dp[i][j] > max)
                    max = dp[i][j];
            }
        }
        return max;
    }
};
int main()
{
    vector<int> a = {4,2,5,3};
    Solution b;
    b.maxAlternatingSum(a);
    std::system("pause");
    return 0;
}