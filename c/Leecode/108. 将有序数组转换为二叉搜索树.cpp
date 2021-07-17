#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return makeTree(nums, 0, nums.size() - 1);
    }
    TreeNode *makeTree(vector<int> nums, int l, int r)
    {
        if (l > r)
            return nullptr;
        int mid = l + ((r - l) / 2);
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = makeTree(nums, l, mid - 1);
        node->right = makeTree(nums, mid + 1, r);
        return node;
    }
};

int main()
{

    std::system("pause");
    return 0;
}