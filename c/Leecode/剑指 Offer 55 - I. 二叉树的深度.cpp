#include <iostream>
#include <vector>
using namespace std;
class Solution
{
private:
    int max(int a, int b)
    {
        return a >= b ? a : b;
    }
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
    int maxDepth(TreeNode *root)
    {
        if (root == 0)
            return 0;
        else
            return 1+max(maxDepth(root->left), maxDepth(root->right));
    }
};

int main()
{

    std::system("pause");
    return 0;
}