#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads)
    {
        vector<vector<int>> count(n, vector<int>(n, 0));
        for (auto n : roads)
        {
            count[n[0]][n[1]] = 1;
            count[n[1]][n[0]] = 1;
        }
        int max = 0;
        vector<int> count1;
        for (int i = 0; i < n; ++i)
        {
            int time = 0;
            for (int k = 0; k < n; ++k)
            {
                if (count[i][k])
                    time++;
            }
            count1.push_back(time);
        }
        for (int i = 0; i < n - 1; ++i)
        {
            for (int k = i + 1; k < n; ++k)
            {
                max = max > (count1[i] + count1[k] - count[i][k]) ? max : (count1[i] + count1[k] - count[i][k]);
            }
        }
        return max;
    }
};
int main()
{
    vector<vector<int>> a = {{0, 1}, {0, 2}, {1, 2}, {1, 3}};
    Solution b;
    b.maximalNetworkRank(4, a);

    std::system("pause");
    return 0;
}