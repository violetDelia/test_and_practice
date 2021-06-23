#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    int h[10] = {1, 2, 4, 8, 0, 0, 0, 0, 0, 0};
    int m[10] = {0, 0, 0, 0, 1, 2, 4, 8, 16, 32};
    void dfs(vector<string> &res, int turnedOn, int index, int hour, int minite)
    {
        if (hour > 11 || minite > 59)
            return;
        else if (turnedOn == 0)
        {
            res.push_back(to_string(hour) + ":" + (minite > 9 ? "" : "0") + to_string(minite));
            return;
        }
        for (int i = index; i < 10; i++)
        {
            dfs(res, turnedOn - 1, i + 1, hour + h[i], minite + m[i]);
        }
    }
    vector<string> readBinaryWatch(int turnedOn)
    {
        vector<string> res;
        int hour = 0;
        int minite = 0;
        int index = 0;
        dfs(res, turnedOn, index, hour, minite);
        return res;
    }
};
int main()
{
    Solution a;
    a.readBinaryWatch(1);
}