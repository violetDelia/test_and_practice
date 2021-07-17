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
    vector<int> countBits(int n)
    {
        vector<int> res;
        res.push_back(0);
        while (res.size() < n + 1)
        {
            int willadd = res.size();
            if (res.size() + willadd <= n + 1)
            {
                for (int i = 0; i < willadd; ++i)
                {
                    res.push_back(res[i] + 1);
                }
            }
            else
            {
                for (int i = 0; res.size() < n + 1; ++i)
                {
                    res.push_back(res[i] + 1);
                }
                break;
            }
            if (res.size() == n + 1)
                break;
        }
        return res;
    }
};
int main()
{
    Solution a;
    a.countBits(12);
    std::system("pause");
    return 0;
}