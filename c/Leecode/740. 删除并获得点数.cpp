#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
    int max(int a, int b)
    {
        return a >= b ? a : b;
    }
    void print(vector<int> a)
    {
        for (int i = 0; i < a.size(); ++i)
        {
            cout.width(5);
            std::cout << a[i] << ' ';
            if ((i + 1) % 10 == 0)
                std::cout << '\n';
        }
        return;
    }

public:
    int deleteAndEarn(vector<int> &nums)
    {
        vector<pair<int, int>> count;
        sort(nums.begin(), nums.end());
        count.push_back({nums[0], 0});
        int last = nums[0];
        for (int n : nums)
        {
            if (n == count[count.size() - 1].first)
                count[count.size() - 1].second++;
            else
                count.push_back({n, 1});
        }
        print(nums);
        vector<int> res;
        res.push_back(0);
        res.push_back(count[0].first * count[0].second);
        for (int i = 1; i < count.size(); ++i)
        {
            if (count[i].first == count[i - 1].first + 1)
            {
                res[res.size() - 1] = max(res[res.size() - 1], res[res.size() - 2]);
                res.push_back(res[res.size() - 2] +
                              count[i].first * count[i].second);
            }

            else
            {
                res[res.size() - 1] = max(res[res.size() - 1], res[res.size() - 2]);
                res.push_back(res[res.size() - 1] +
                              count[i].first * count[i].second);
            }
        }
        return max(res[res.size() - 1], res[res.size() - 2]);
    }
};
int main()
{
    vector<int> b = {10, 8, 4, 2, 1, 3, 4, 8, 2, 9, 10, 4, 8, 5, 9, 1, 5, 1, 6, 8, 1, 1, 6, 7, 8, 9, 1, 7, 6, 8, 4, 5, 4, 1, 5, 9, 8, 6, 10, 6, 4, 3, 8, 4, 10, 8, 8, 10, 6, 4, 4, 4, 9, 6, 9, 10, 7, 1, 5, 3, 4, 4, 8, 1, 1, 2, 1, 4, 1, 1, 4, 9, 4, 7, 1, 5, 1, 10, 3, 5, 10, 3, 10, 2, 1, 10, 4, 1, 1, 4, 1, 2, 10, 9, 7, 10, 1, 2, 7, 5};
    Solution a;
    a.deleteAndEarn(b);
    std::system("pause");
    return 0;
}