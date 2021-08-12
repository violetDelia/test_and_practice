/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 *
 * https://leetcode-cn.com/problems/4sum/description/
 *
 * algorithms
 * Medium (40.60%)
 * Likes:    908
 * Dislikes: 0
 * Total Accepted:    198.3K
 * Total Submissions: 489K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c
 * + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
 * 
 * 注意：答案中不可以包含重复的四元组。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,0,-1,0,-2,2], target = 0
 * 输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [], target = 0
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * -10^9 
 * -10^9 
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
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        if (nums.size() < 4)
            return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; ++i)
        {
            for (int j = i + 1; j < nums.size() - 2; ++j)
            {
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right)
                {
                    long long sum = (long long)nums[left] + nums[right] + nums[i] + nums[j];
                    if (sum > target)
                        right--;
                    else if (sum < target)
                        left++;
                    else
                    {
                        vector<int> newres = {nums[i], nums[j], nums[left], nums[right]};
                        res.push_back(newres);
                        while (left < right && nums[left] == newres[2])
                            left++;
                        while (left < right && nums[right] == newres[3])
                            right--;
                    }
                }
                while (j + 1 < nums.size() - 2 && nums[j + 1] == nums[j])
                    ++j;
            }
            while (i + 1 < nums.size() - 3 && nums[i + 1] == nums[i])
                ++i;
        }
        return res;
    }
};
// @lc code=end
