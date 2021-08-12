/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (32.74%)
 * Likes:    3546
 * Dislikes: 0
 * Total Accepted:    573.4K
 * Total Submissions: 1.8M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0
 * 且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [-1,0,1,2,-1,-4]
 * 输出：[[-1,-1,2],[-1,0,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [0]
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * -10^5 
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
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        if (nums.size() < 3)
            return res;
        sort(nums.begin(), nums.end());
        for (int i = 3; i < nums.size();)
        {
            if (nums[i] == nums[i - 3])
                nums.erase(nums.begin() + i);
            else
                ++i;
        }
        for (int i = 2; i < nums.size();)
        {
            if (nums[i] != 0 && nums[i] == nums[i - 2])
                nums.erase(nums.begin() + i);
            else
                ++i;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i != 0 && nums[i - 1] == nums[i])
                continue;
            int left = i + 1,
                right = nums.size() - 1,
                target = -nums[i];
            while (left < right)
            {
                int sum = nums[left] + nums[right];
                if (sum > target)
                    right--;
                else if (sum < target)
                    left++;
                else
                {
                    vector<int> newres = {nums[i], nums[left], nums[right]};
                    res.push_back(newres);
                    while (left < right && nums[left] == newres[1])
                        left++;
                    while (left < right && nums[right] == newres[2])
                        right--;
                }
            }
        }
        return res;
    }
};

// @lc code=end
