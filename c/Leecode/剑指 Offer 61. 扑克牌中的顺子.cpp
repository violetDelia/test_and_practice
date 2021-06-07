#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    bool isStraight(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int last = nums[4];
        int count = 0;
        int count1 = 0;
        for (int i = 3; i >= 0; --i)
        {
            if (nums[i] == 0)
                count++;
            else if (nums[i] == last)
                return false;
            else
            {
                count1 += last - nums[i] - 1;
                last = nums[i];
            }
        }
        if (count1 > count)
            return false;
        return true;
    }
};
int main()
{
    std::system("pause");
    return 0;
}