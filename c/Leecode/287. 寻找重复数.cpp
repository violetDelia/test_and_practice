#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int high = nums.size() - 1;
        int low = 1;
        int res = -1;
        int mid;
        if (high == 1)
            if (nums[1] == nums[0])
                return nums[0];
            else
                return res;
        while (low < high)
        {
            mid = low + (high - low) / 2;
            int count = 0;
            for (int n : nums)
            {
                if (n <= mid)
                    count++;
            }
            if (count <= mid)
            {
                low = mid + 1;
                res = low;
            }
            else
            {
                high = mid;
                res = high;
            }
        }
        return res;
    }
};
int main()
{
    std::system("pause");
    return 0;
}