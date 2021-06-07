#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        int l = mat.size();
        vector<pair<int, int>> count;
        for (int i = 0; i < l; ++i)
        {
            int left = 0, right = mat[0].size() - 1;
            while (left <= right)
            {
                int mid = left + ((right - left) >> 1);
                if (mat[i][mid] != 1)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            int sum = left + 1;
            count.emplace_back(sum, i);
        }
        stable_sort(count.begin(), count.end(),
                    [=](pair<int, int> a, pair<int, int> b) { return a.first <= b.first; });
        vector<int> res;
        for (int i = 0; i < k; ++i)
        {
            res.push_back(count[i].second);
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> a = {{1, 0}, {1, 0}, {1, 0}, {1, 1}};
    Solution b;
    b.kWeakestRows(a, 4);

    std::system("pause");
    return 0;
}