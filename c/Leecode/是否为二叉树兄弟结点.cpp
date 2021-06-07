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
    bool isCousins(TreeNode *root, int x, int y)
    {
        if (!root)
            return false;
        if (root->right->val == x)
        {
            if (root->left->val == y)
                return true;
            return false;
        }
        if (root->right->val == y)
        {
            if (root->left->val == x)
                return true;
            return false;
        }
        return isCousins(root->right, x, y) ||
               isCousins(root->left, x, y);
    }
};

int main()
{

    std::system("pause");
    return 0;
}