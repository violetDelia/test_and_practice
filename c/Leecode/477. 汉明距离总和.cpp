#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    int totalHammingDistance(vector<int> &nums)
    {
        int res = 0;
        int max = INT_MIN;
        for (int n : nums)
        {
            max = max > n ? max : n;
        }
        while (max != 0)
        {
            int count = 0;
            for (int i = 0; i < nums.size(); ++i)
            {
                int a = nums[i] & 1;
                if (a == 1)
                    count++;
            }
            res += count * (nums.size() - count);
            for (int i = 0; i < nums.size(); ++i)
            {
                nums[i] /= 2;
            }
            max /= 2;
        }
        return res;
    }
};
int main()
{
    std::system("pause");
    return 0;
}