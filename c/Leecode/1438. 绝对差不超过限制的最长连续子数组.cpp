#include <iostream>
#include <set>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        multiset<int> count;
        if (nums.size() == 1)
            return 1;
        count.insert(nums[0]);
        int i = 1;
        int front = 0;
        int res = 0;
        while (i < nums.size())
        {
            if (*count.rbegin() - *count.begin() <= limit)
            {
                res = res > count.size() ? res : count.size();
                count.insert(nums[i]);
                ++i;
            }
            else
            {
                count.erase(count.find(nums[front++]));
            }
        }
        res = res > count.size() ? res : count.size();
        return res;
    }
};
int main()
{
    vector<int> a = {2,2,2,4,4,2,5,5,5,5,5,2};
    Solution b;
    b.longestSubarray(a, 2);
    std::system("pause");
    return 0;
}