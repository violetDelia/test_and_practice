#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int l = nums.size();
        for (int i = 0; i < l - 1; ++i)
        {
            if (nums[i] >= nums[i + 1])
            {
                return nums[i + 1];
            }
        }
        return nums[0];
    }
    int findMin(vector<int> &nums)
    {
        int high = nums.size() - 1;
        int low = 0;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return nums[low];
    }
    int findMin(vector<int> &nums)
    {
        return *min_element(nums.begin(), nums.end());
    }
};
int main()
{

    std::system("pause");
    return 0;
}