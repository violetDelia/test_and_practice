#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int dominantIndex(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
            return 0;
        int i = 0;
        int max = 0;
        int res;
        while (i < n)
        {
            if (nums[i] > nums[max])
            {
                if (nums[i] >= nums[max] << 1)
                {
                    max = i;
                    res = max;
                }
                else
                {
                    max = i;
                    res = -1;
                }
            }
            else
            {
                if (nums[i] << 1 > nums[max])
                {
                    if (i == max && nums[i] == nums[max])
                        res = max;
                    else

                        res = -1;
                }
            }
            i++;
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {1, 0};
    Solution a;
    a.dominantIndex(nums);
    std::system("pause");
    return 0;
}