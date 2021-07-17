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
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int res = 1001000;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            int left = i + 1;
            int right = nums.size() - 1;
            while (right > left)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == target)
                    return target;
                else if (sum > target)
                    right--;
                else
                    left++;
                if (abs(sum - target) < abs(res - target))
                    res = sum;
            }
        }
        return res;
    }
};
int main()
{
    vector<int> a = {-1, 2, 1, -4};
    Solution b;
    b.threeSumClosest(a, 1);
    std::system("pause");
    return 0;
}