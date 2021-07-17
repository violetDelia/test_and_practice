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
    bool containsDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int last = nums[0] - 1;
        for (int n : nums)
        {
            if (n == last)
                return true;
            last = n;
        }
        return false;
    }
};
int main()
{
    std::system("pause");
    return 0;
}