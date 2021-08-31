/*
 * @lc app=leetcode.cn id=834 lang=cpp
 *
 * [834] 树中距离之和
 *
 * https://leetcode-cn.com/problems/sum-of-distances-in-tree/description/
 *
 * algorithms
 * Hard (52.97%)
 * Likes:    298
 * Dislikes: 0
 * Total Accepted:    13.1K
 * Total Submissions: 24.8K
 * Testcase Example:  '6\n[[0,1],[0,2],[2,3],[2,4],[2,5]]'
 *
 * 给定一个无向、连通的树。树中有 N 个标记为 0...N-1 的节点以及 N-1 条边 。
 * 
 * 第 i 条边连接节点 edges[i][0] 和 edges[i][1] 。
 * 
 * 返回一个表示节点 i 与其他所有节点距离之和的列表 ans。
 * 
 * 示例 1:
 * 
 * 
 * 输入: N = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
 * 输出: [8,12,6,10,10,10]
 * 解释: 
 * 如下为给定的树的示意图：
 * ⁠ 0
 * ⁠/ \
 * 1   2
 * ⁠  /|\
 * ⁠ 3 4 5
 * 
 * 我们可以计算出 dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5) 
 * 也就是 1 + 1 + 2 + 2 + 2 = 8。 因此，answer[0] = 8，以此类推。
 * 
 * 
 * 说明: 1 <= N <= 10000
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
    vector<vector<int>> v;
    vector<int> count, res;
    void dfs(int i, int p = -1)
    {
        for (int node : v[i])
        {
            if (node == p)
                continue;
            dfs(node, i);
            count[i] += count[node];
            res[i] += res[node] + count[node];
        }
        count[i]++;
    }
    void dfs2(int i, int n, int p = -1)
    {
        for (int node : v[i])
        {
            if (node == p)
                continue;
            res[node] = res[i] - count[node] + n - count[node];
            dfs2(node, n, i);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        v.resize(n);
        for (vector<int> line : edges)
        {
            int a = line[0];
            int b = line[1];
            v[a].push_back(b);
            v[b].push_back(a);
        }
        count.resize(n);
        res.resize(n);
        dfs(0);
        dfs2(0, n);
        return res;
    }
};
// @lc code=end
