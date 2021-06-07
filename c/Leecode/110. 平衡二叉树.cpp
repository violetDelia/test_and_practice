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
    int max(int a, int b)
    {
        return a >= b ? a : b;
    }
    int height(TreeNode *root)
    {
        if (root)
        {
            int leftheight = height(root->left);
            int rightheight = height(root->right);
            if (leftheight == -1 || rightheight == -1 || abs(leftheight - rightheight) > 1)
                return -1;
            else
                return max(leftheight, rightheight) + 1;
        }
        return 0;
    }
    bool isBalanced(TreeNode *root)
    {
        return height(root) > -1;
    }
};

int main()
{

    std::system("pause");
    return 0;
}