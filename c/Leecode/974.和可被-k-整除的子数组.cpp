/*
 * @lc app=leetcode.cn id=974 lang=cpp
 *
 * [974] 和可被 K 整除的子数组
 *
 * https://leetcode-cn.com/problems/subarray-sums-divisible-by-k/description/
 *
 * algorithms
 * Medium (46.52%)
 * Likes:    303
 * Dislikes: 0
 * Total Accepted:    36.3K
 * Total Submissions: 78K
 * Testcase Example:  '[4,5,0,-2,-3,1]\n5'
 *
 * 给定一个整数数组 A，返回其中元素之和可被 K 整除的（连续、非空）子数组的数目。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：A = [4,5,0,-2,-3,1], K = 5
 * 输出：7
 * 解释：
 * 有 7 个子数组满足其元素之和可被 K = 5 整除：
 * [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2,
 * -3]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= A.length <= 30000
 * -10000 <= A[i] <= 10000
 * 2 <= K <= 10000
 * 
 * 
 */

// @lc code=start
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
    int subarraysDivByK(vector<int> &nums, int k)
    {
        vector<int> dp(nums.size()+1, 0);
        for (int i = 0; i < nums.size(); ++i)
        {
            int sum = 0;
            for (int j = i; j < nums.size(); ++j)
            {
                sum += nums[j];
                if (sum % k == 0)
                {
                    dp[j+1] += dp[i] + 1;
                    break;
                }
            }
        }
        int res = 0;
        for (int n : dp)
        {
            res += n;
        }
        return res;
    }
};
// @lc code=end
