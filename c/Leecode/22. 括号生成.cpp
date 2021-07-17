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
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        vector<pair<int, int>> count;
        res.push_back("(");
        count.push_back({n - 1, n});
        while (!count.empty())
        {
            string s = res[0];
            auto state = count[0];
            res.erase(res.begin());
            count.erase(count.begin());
            if (state.first != 0 && state.first <= state.second)
            {
                res.push_back(s + '(');
                count.push_back({state.first - 1, state.second});
            }
            if (state.second != 0 && state.first < state.second)
            {
                res.push_back(s + ')');
                if (state.first == 0 && state.second == 1)
                    continue;
                count.push_back({state.first, state.second - 1});
            }
        }
        return res;
    }
};
int main()
{
    Solution a;
    a.generateParenthesis(3);
    std::system("pause");
    return 0;
}