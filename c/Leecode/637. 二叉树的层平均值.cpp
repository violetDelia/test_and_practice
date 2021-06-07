#include <iostream>
#include <queue>
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
    vector<double>
    averageOfLevels(TreeNode *root)
    {
        queue<TreeNode *> count;
        vector<double> res;
        if (root == nullptr)
            return res;
        count.push(root);
        while (!count.empty())
        {
            double sum = 0;
            int l = count.size();
            for (int i = 0; i < l; ++i)
            {
                sum += count.front()->val;
                if (count.front()->left != nullptr)
                    count.push(count.front()->left);
                if (count.front()->right != nullptr)
                    count.push(count.front()->right);
                count.pop();
            }
            res.push_back((double)sum/l);
        }
        return res;
    }
};

int main()
{

    std::system("pause");
    return 0;
}