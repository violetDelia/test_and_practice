#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        if (nums.size() < 3)
            return 0;
        int res = 0;
        int count = 1;
        int space = nums[1] - nums[0];
        for (int i = 2; i < nums.size(); ++i)
        {
            if (nums[i] - nums[i - 1] == space)
            {
                count++;
            }
            else
            {
                space = nums[i] - nums[i - 1];
                if (count > 1)
                    res += (count) * (count - 1) / 2;
                count = 1;
            }
        }
        if (count > 1)
            res += (count) * (count - 1) / 2;
        return res;
    }
};
int main()
{
    vector<int> n = {1, 2, 3, 8, 9, 10};
    Solution a;
    a.numberOfArithmeticSlices(n);
    std::system("pause");
    return 0;
}