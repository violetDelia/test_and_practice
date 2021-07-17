#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        map<int, int> presum;
        int sum = 0;
        int res = 0;
        for (int n : nums)
        {
            presum[sum]++;
            sum += n;
            res += presum[sum - goal];
        }
        return res;
    }
};
int main()
{

    vector<int> a = {1, 0, 1, 0, 1};
    Solution b;
    b.numSubarraysWithSum(a, 2);

    std::system("pause");
    return 0;
}