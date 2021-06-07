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
    void getres(TreeNode *root, int &min, int &last)
    {
        if (root!=nullptr)
        {
            getres(root->left, min, last);
            min = min < abs(root->val - last) ? min : abs(root->val - last);
            last = root->val;
            getres(root->right, min, last);
        }
        return;
    }

    int getMinimumDifference(TreeNode *root)
    {
        int res = INT_MAX;
        int p = INT_MAX;
        getres(root, res, p);
        return res;
    }
};

int main()
{

    std::system("pause");
    return 0;
}