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
    long long maxAlternatingSum(vector<int> &nums)
    {
        long long res = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            res += (nums[i - 1] - nums[i] > 0 ? nums[i - 1] - nums[i] : 0);
        }
        res += nums.back();
        return res;
    }
};
int main()
{

    std::system("pause");
    return 0;
}