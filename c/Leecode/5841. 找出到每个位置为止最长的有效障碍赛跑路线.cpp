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
    vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles)
    {
        vector<int> dp;
        vector<int> res;
        dp.push_back(obstacles[0]);
        res.push_back(1);
        for (auto obs : obstacles)
        {
            if (obs >= dp.back())
            {
                dp.push_back(obs);
                res.push_back(dp.size());
            }
            else
            {
                int p = upper_bound(dp.begin(), dp.end(), obs) - dp.begin();
                dp[p] = obs;
                res.push_back(p + 1);
            }
        }
        return res;
    }
};
int main()
{
    Solution a;
    vector<int> test = {3, 1, 5, 6, 4, 2};
    a.longestObstacleCourseAtEachPosition(test);
}