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
    int maxDepth(TreeNode *root)
    {
        if (root)
        {
            return max(1 + maxDepth(root->left), 1 + maxDepth(root->right));
        }
        return 0;
    }
};

int main()
{

    std::system("pause");
    return 0;
}