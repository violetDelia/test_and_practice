#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int max;
        int sum = 0;
        for (int i = 0; i < k; ++i)
        {
            sum += nums[i];
        }
        max = sum;
        for (int i = k; i < nums.size(); ++i)
        {
            sum = sum + nums[i] - nums[i - k];
            if (sum > max)
                max = sum;
        }
        double res = (double)max / k;
        return res;
    }
};
int main()
{
    std::system("pause");
    return 0;
}