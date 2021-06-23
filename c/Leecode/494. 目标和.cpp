#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = 0;
        for (int n : nums)
            sum += n;
        vector<vector<int>> count(nums.size(), vector<int>(sum * 2 + 1, 0));
        count[0][nums[0] + sum]++;
        count[0][-nums[0] + sum]++;
        for (int i = 1; i < nums.size(); i++)
        {
            for (int k = 0; k < sum * 2 + 1; ++k)
            {
                if (count[i - 1][k] != 0)
                {
                    count[i][k + nums[i]] += count[i - 1][k];
                    count[i][k - nums[i]] += count[i - 1][k];
                }
            }
        }
        return count[nums.size() - 1][target + sum];
    }
};
int main()
{
    vector<int> a = {1, 1, 1, 1, 1};
    Solution b;
    b.findTargetSumWays(a, 3);
    std::system("pause");
    return 0;
}