#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int l = nums.size();
        for (int i = 0; i < l - 1; ++i)
        {
            for (int k = i + 1; k < l; ++k)
            {
                if (nums[i] + nums[k] == target)
                {
                    return {i, k};
                }
            }
        }
        return {0, 0};
    }
};

int main()
{
    vector<int> a = {2, 7, 11, 15};
    Solution b;
    b.twoSum(a, 5);

    std::system("pause");
    return 0;
}