#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        if(target == "0000")
            return 0;
        int res = -1;
        queue<pair<string, int>> count;
        unordered_set<string> been;
        for (string s : deadends)
        {
            if(s == "0000")
                return -1;
            been.emplace(s);
        }
        count.push({"0000", 0});
        while (!count.empty())
        {
            string s = count.front().first;
            int n = count.front().second;
            count.pop();
            for (int i = 0; i < s.size(); ++i)
            {
                string newsup = s;
                if (newsup[i] == '9')
                    newsup[i] = '0';
                else
                    newsup[i] += 1;
                if (!been.count(newsup))
                {
                    if (newsup == target)
                        return n + 1;
                    been.emplace(newsup);
                    count.push({newsup, n + 1});
                }
                string newslow = s;
                if (newslow[i] == '0')
                    newslow[i] = '9';
                else
                    newslow[i] -= 1;
                if (!been.count(newslow))
                {
                    if (newslow == target)
                        return n + 1;
                    been.emplace(newslow);
                    count.push({newslow, n + 1});
                }
            }
        }
        return -1;
    }
};
int main()
{
    vector<string> c ={"0201", "0101", "0102", "1212", "2002"};
    Solution a;
    a.openLock(c, "0202");
    std::system("pause");
    return 0;
}