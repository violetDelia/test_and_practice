#include <iostream>
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
    int max(int a, int b)
    {
        return a > b ? a : b;
    }
    int height(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
            return true;
        if (isBalanced(root->left) == false)
            return false;
        if (isBalanced(root->right) == false)
            return false;
        if (abs(height(root->left) - height(root->right)) > 1)
            return false;
        return true;
    }
};

int main()
{

    std::system("pause");
    return 0;
}