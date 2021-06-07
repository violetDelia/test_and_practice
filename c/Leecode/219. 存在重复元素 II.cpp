#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        vector<pair<int, int>> count;
        for (int i = 0; i < nums.size(); ++i)
        {
            count.emplace_back(nums[i], i);
        }
        stable_sort(count.begin(), count.end());
        pair<int, int> last = count[0];
        int issame = 0;
        for (int i = 1; i < count.size(); ++i)
        {
            if (count[i].first == last.first)
            {
                int min = INT_MAX;
                for (; i < count.size() && count[i].first == last.first; ++i)
                {
                    min = min < count[i].second - last.second
                              ? min
                              : count[i].second - last.second;
                    last = count[i];
                }
                if (min <= k)
                    issame++;
                --i;
            }
            else
            {
                last = count[i];
            }
        }
        if (issame)
            return true;
        return false;
    }
};

int main()
{
    vector<int> a = {1, 2};
    Solution b;
    b.containsNearbyDuplicate(a, 2);

    std::system("pause");
    return 0;
}