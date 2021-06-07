#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int l = nums.size();
        if (l == 0)
            return 0;
        int sum = 0;
        int max = INT_MIN;
        for (int i = 0; i < l; i++)
        {
            sum += nums[i];
            if (sum > max)
                max = sum;
            if (sum <= 0)
                sum = 0;
        }
    
    return max;
}
}
;

int main()
{
    vector<int> a = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution s;
    s.maxSubArray(a);
    std::system("pause");
    return 0;
}