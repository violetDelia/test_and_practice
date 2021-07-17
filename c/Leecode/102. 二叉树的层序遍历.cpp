#include <iostream>
#include <vector>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
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