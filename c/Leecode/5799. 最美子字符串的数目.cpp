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
    long long wonderfulSubstrings(string word)
    {
        long long res = 0;
        vector<int> statecount(1 << 10, 0);
        statecount[0] = 1;
        int state = 0;
        for (char s : word)
        {
            state ^= 1 << (s - 'a');
            res += statecount[state];
            for (int i = 0; i < 10; i++)
            {
                res += statecount[state ^ (1 << i)];
            }
            statecount[state]++;
        }
        return res;
    }
};
int main()
{
    Solution a;
    a.wonderfulSubstrings("aabb");
    std::system("pause");
    return 0;
}