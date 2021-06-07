#include < vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int bigin = 0;
        int end = nums.size() - 1;
        if (end == 0)
        {
            if (nums[0] >= target)
                return 0;
            return 1;
        }
        int mid;
        while (bigin <= end)
        {
            mid = (bigin + end) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                bigin = mid + 1;
            }
        }
        if (nums[mid] > target)
        {
            return mid;
        }
        else
        {
            return mid + 1;
        }
    }
};
int main()
{
    int a[1] = {1};
    Solution f;
    std::system("pause");
    return 0;
}