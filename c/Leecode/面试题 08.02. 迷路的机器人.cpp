#include <iostream>
#include <stack>
#include <vector>
using namespace std;
/*class Solution
{
public:
    vector<vector<int>> pathWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        vector<vector<int>> res(0);
        stack<pair<int, int>> count;
        if (obstacleGrid[0][0] == 1)
            return res;
        int p1 = 0;
        int p2 = 0;
        do
        {
            if (p1 < obstacleGrid.size() &&
                p2 < obstacleGrid[0].size() &&
                obstacleGrid[p1][p2] == 0)
            {
                count.push({p1, p2});
                if (p1 == obstacleGrid.size() - 1 &&
                    p2 == obstacleGrid[0].size() - 1)
                {
                    while (!count.empty())
                    {
                        res.push_back({count.top().first, count.top().second});
                        count.pop();
                    }
                    vector<vector<int>> newres;
                    while (!res.empty())
                    {
                        newres.push_back(*res.rbegin());
                        res.pop_back();
                    }
                    return newres;
                }
                obstacleGrid[p1][p2] = 1;
                p2++;
            }
            else
            {
                p1 = count.top().first;
                p2 = count.top().second;
                if (p1 + 1 < obstacleGrid.size() &&
                    obstacleGrid[p1 + 1][p2] == 0)
                {
                    count.push({++p1, p2});
                    if (p1 == obstacleGrid.size() - 1 &&
                        p2 == obstacleGrid[0].size() - 1)
                    {
                        while (!count.empty())
                        {
                            res.push_back({count.top().first, count.top().second});
                            count.pop();
                        }
                        vector<vector<int>> newres;
                        while (!res.empty())
                        {
                            newres.push_back(*res.rbegin());
                            res.pop_back();
                        }
                        return newres;
                    }
                    obstacleGrid[p1][p2] = 1;
                    ++p2;
                }
                else
                {
                    count.pop();
                    if (count.empty())
                        return res;
                    p1 = count.top().first;
                    p2 = count.top().second;
                }
            }
        } while (count.empty() == false);
    }
};*/
class Solution
{
private:
    vector<vector<int>> path;

public:
    vector<vector<int>> pathWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        const int r = obstacleGrid.size();
        if (r < 1)
            return path;
        vector<vector<bool>> failedPoints(r);
        const int c = obstacleGrid[r - 1].size();
        for (int i = 0; i < r; ++i)
            failedPoints[i].resize(c);
        getPath(r - 1, c - 1, obstacleGrid, failedPoints);
        return path;
    }

    bool getPath(const int r, const int c, vector<vector<int>> &obstacleGrid, vector<vector<bool>> &failedPoints)
    {
        if (r < 0 || c < 0 || obstacleGrid[r][c] == 1 || failedPoints[r][c])
            return false;
        if (r == 0 && c == 0)
        {
            vector<int> v(2, 0);
            path.push_back(v);
            return true;
        }
        if (getPath(r - 1, c, obstacleGrid, failedPoints) || getPath(r, c - 1, obstacleGrid, failedPoints))
        {
            vector<int> v;
            v.push_back(r);
            v.push_back(c);
            path.push_back(v);
            return true;
        }
        failedPoints[r][c] = true;
        return false;
    }
};
int main()
{
    vector<vector<int>> a = {{0, 1,0},{0,0,0},{0,0,0}};
    Solution b;
    b.pathWithObstacles(a);
    std::system("pause");
    return 0;
}