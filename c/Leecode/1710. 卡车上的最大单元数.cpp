#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        vector<pair<int, int>> count;
        for (int i = 0; i < boxTypes.size(); ++i)
            count.emplace_back(boxTypes[i][1], boxTypes[i][0]);
        stable_sort(count.begin(), count.end(),
                    [=](pair<int, int> a, pair<int, int> b) { return a.first > b.first; });
        int res = 0;
        int p = 0;
        while (truckSize > 0 && p < count.size())
        {
            if (truckSize - count[p].second > 0)
            {
                res += count[p].first * count[p].second;
                truckSize -= count[p].second;
                ++p;
            }
            else
            {
                res += count[p].first * truckSize;
                truckSize = 0;
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> a = {{1, 3}, {5, 5}, {2, 5}, {4, 2}, {4, 1}, {3, 1}, {2, 2}, {1, 3}, {1, 5}, {3, 2}};
    Solution b;
    b.maximumUnits(a, 35);

    std::system("pause");
    return 0;
}