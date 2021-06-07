#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points)
    {
        int res = 0;
        int lastx = points[0][0];
        int lasty = points[0][1];
        for (int i = 1; i < points.size(); ++i)
        {
            int x = abs(lastx - points[i][0]);
            int y = abs(lasty - points[i][1]);
            int l = x > y ? x : y;
            res += l;
            lastx = points[i][0];
            lasty = points[i][1];
        }
        return res;
    }
};

int main()
{

    std::system("pause");
    return 0;
}