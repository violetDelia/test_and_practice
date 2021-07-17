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
    vector<vector<int>> res;
    multiset<int> height;
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        vector<vector<int>> build;
        for (auto &b : buildings)
        {
            build.push_back({b[0], b[2]});
            build.push_back({b[1], -b[2]});
        }
        sort(build.begin(), build.end(), [&](auto &a, auto &b)
             {
                 if (a[0] == b[0])
                     return a[1] > b[1];
                 return a[0] < b[0];
             });
        int currentheight = 0;
        height.insert(0);
        for (auto &s : build)
        {
            if (s[1] > 0)
            {
                height.emplace(s[1]);
            }
            else
            {
                height.erase(height.find({-s[1]}));
            }
            if (currentheight == *height.rbegin())
                continue;
            res.push_back({s[0], *height.rbegin()});
            currentheight = *height.rbegin();
        }
        height.clear();
        return res;
    }
};
int main()
{
    vector<vector<int>> b = {{2, 9, 10}, {2, 9, 10}, {2, 9, 10}};
    Solution a;
    a.getSkyline(b);
    std::system("pause");
    return 0;
}