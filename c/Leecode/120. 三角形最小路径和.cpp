#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        if(triangle.size() == 1)
            return triangle[0][0];
        vector<vector<int>> count(triangle.size(), vector<int>(triangle.size(), INT_MAX));
        count[0][0] = triangle[0][0];
        int res = INT_MAX;
        int i = 1;
        for (; i < triangle.size() - 1; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                int min;
                if (j == 0)
                    min = count[i - 1][j];
                else
                    min = count[i - 1][j-1] < count[i - 1][j] ? count[i - 1][j -1] : count[i - 1][j];
                count[i][j] = triangle[i][j] + min;
            }
        }
        for (int j = 0; j <= i; j++)
        {
            int min;
            if (j == 0)
                min = count[i - 1][j];
            else
                min = count[i - 1][j -1] < count[i - 1][j ] ? count[i - 1][j-1] : count[i - 1][j];
            count[i][j] = triangle[i][j] + min;
            res = res < count[i][j] ? res : count[i][j];
        }
        return res;
    }
};
int main()
{
    vector<vector<int>> a = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    Solution d;
    d.minimumTotal(a);
    std::system("pause");
    return 0;
}