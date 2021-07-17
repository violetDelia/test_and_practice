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
public:
    vector<int> count;
    bool addcount(TreeNode *node)
    {
        count.push_back(node->val);
        return true;
    }
    void traveTree(TreeNode *root)
    {
        if (!root)
            return;
        if (root->left)
            traveTree(root->left);
        addcount(root);
        if (root->right)
            traveTree(root->right);
        return;
    }
    bool isordered(vector<int> nums)
    {
        long long last = (long long)INT_MIN - 1;
        for (int n : nums)
        {
            if (last >= n)
                return false;
            last = (long long)n;
        }
        return true;
    }
    bool isValidBST(TreeNode *root)
    {
        traveTree(root);
        return isordered(count);
    }
};

int main()
{

    std::system("pause");
    return 0;
}