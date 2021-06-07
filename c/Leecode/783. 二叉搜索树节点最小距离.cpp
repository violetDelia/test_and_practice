#include <iostream>
#include <stack>
#include <vector>
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
    void inorder(TreeNode *root, vector<int> &res)
    {
        if (!root)
        {
            return;
        }
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    int minDiffInBST(TreeNode *root)
    {
        vector<int> res;
        inorder(root, res);
        int n = res.size();
        int ansmin = res[1] - res[0];
        for (int i = 1; i < n; i++)
        {
            if (res[i] - res[i - 1] < ansmin)
            {
                ansmin = res[i] - res[i - 1];
            }
        }
        return ansmin;
    }
};
int main()
{
    std::system("pause");
    return 0;
}