#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution
{
    struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

public:
    TreeNode *maketree(vector<int> &nums, int left, int right)
    {
        if(left > right)
            return NULL;
        int mid = left + (right - left) / 2;
        TreeNode *out = new TreeNode(nums[mid]);
        if (left < mid)
            out->left = maketree(nums, left, mid - 1);
        if (right > mid)
            out->right = maketree(nums, mid + 1, right);
        return out;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return maketree(nums, 0, nums.size() - 1);
    }
};
int main()
{
    vector<int> test = {1, 2, 3, 4, 5, 6};
    Solution a;
    a.sortedArrayToBST(test);
    std::system("pause");
    return 0;
}