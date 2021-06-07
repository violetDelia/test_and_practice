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
    bool issame(TreeNode *root1, TreeNode *root2)
    {
        if (root1 && root2)
            if (root1->val == root2->val)
                return issame(root1->left, root2->right) && issame(root1->right, root2->left);
            else
                return false;
        if (!root1 && !root2)
            return true;
        return false;
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root)
            return issame(root->right, root->left);
        return true;
    }
};

int main()
{

    std::system("pause");
    return 0;
}