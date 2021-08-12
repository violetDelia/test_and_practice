#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int left = 0;
        long long space = 0;
        int res = 1;
        for (int right = 1; right < nums.size(); ++right)
        {
            space += (long long)(nums[right] - nums[right - 1]) * (right - left);
            while (space > k)
            {
                space -= nums[right] - nums[left];
                left++;
            }
            res = max(res, right - left + 1);
            cout << res << endl;
        }
        return res;
    }
};
int main()
{
    vector<int> a = {9930, 9923, 9983, 9997, 9934, 9952, 9945, 9914, 9985, 9982, 9970, 9932, 9985, 9902, 9975, 9990, 9922, 9990, 9994, 9937, 9996, 9964, 9943, 9963, 9911, 9925, 9935, 9945, 9933, 9916, 9930, 9938, 10000, 9916, 9911, 9959, 9957, 9907, 9913, 9916, 9993, 9930, 9975, 9924, 9988, 9923, 9910, 9925, 9977, 9981, 9927, 9930, 9927, 9925, 9923, 9904, 9928, 9928, 9986, 9903, 9985, 9954, 9938, 9911, 9952, 9974, 9926, 9920, 9972, 9983, 9973, 9917, 9995, 9973, 9977, 9947, 9936, 9975, 9954, 9932, 9964, 9972, 9935, 9946, 9966};
    Solution b;
    b.maxFrequency(a, 3056);
    std::system("pause");
    return 0;
}