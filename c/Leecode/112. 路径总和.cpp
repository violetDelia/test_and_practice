#include <iostream>
#include <vector>
using namespace std;
class Solution
{
private:
    struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

public:
    void issame(TreeNode *root, int target, int sum, bool &flag)
    {
        sum += root->val;
        if (sum > target)
            return;
        if (sum == target && root->right == nullptr && root->left == nullptr)
        {
            flag = true;
            return;
        }
        if (root->left)
            issame(root->left, target, sum, flag);
        if (root->right)
            issame(root->right, target, sum, flag);
        return;
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        bool flag = false;
        if (root)    
            issame(root, targetSum, 0, flag);
        return flag;
    }
};

int main()
{

    std::system("pause");
    return 0;
}