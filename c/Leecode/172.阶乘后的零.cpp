/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 *
 * https://leetcode-cn.com/problems/factorial-trailing-zeroes/description/
 *
 * algorithms
 * Easy (43.43%)
 * Likes:    485
 * Dislikes: 0
 * Total Accepted:    82.3K
 * Total Submissions: 189.4K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，返回 n! 结果尾数中零的数量。
 * 
 * 示例 1:
 * 
 * 输入: 3
 * 输出: 0
 * 解释: 3! = 6, 尾数中没有零。
 * 
 * 示例 2:
 * 
 * 输入: 5
 * 输出: 1
 * 解释: 5! = 120, 尾数中有 1 个零.
 * 
 * 说明: 你算法的时间复杂度应为 O(log n) 。
 * 
 */

// @lc code=start
class Solution
{
public:
    int trailingZeroes(int n)
    {
        int res = 0;
        int base = 5;
        while (base <= n)
        {
            res += n / base;
            base *= 5;
        }
        return res;
    }
};
// @lc code=end
