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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        queue<TreeNode *> q;
        if (!root)
        {
            return res;
        }
        q.push(root);
        for (int c = 0; !q.empty(); ++c)
        {
            vector<int> thisc;
            for (int size = q.size(); size > 0; --size)
            {
                TreeNode *f = q.front();
                thisc.push_back(f->val);
                q.pop();
                if (f->left)
                    q.push(f->left);
                if (f->right)
                    q.push(f->right);
            }
            res.push_back(thisc);
        }
        return res;
    }
};
int main()
{
    std::system("pause");
    return 0;
}