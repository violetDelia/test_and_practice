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
    void dfs(TreeNode *root, vector<int> &count)
    {
        if (root)
        {
            dfs(root->left, count);
            dfs(root->right, count);
            if (root->left == root->right)
                count.push_back(root->val);
        }
        return;
    }
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> count1;
        vector<int> count2;
        dfs(root1,count1);
        dfs(root2,count2);
        return count1 == count2;
    }
};

int main()
{

    std::system("pause");
    return 0;
}