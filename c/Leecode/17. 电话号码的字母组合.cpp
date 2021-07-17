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
    vector<string> letterCombinations(string digits)
    {
        vector<vector<char>> l = {{}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'o', 'n'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
        queue<string> res;
        res.push("");
        for (int i = 0; i < digits.size(); i++)
        {
            int p = digits[i] - '0';
            int n = res.size();
            for (; n > 0; --n)
            {
                for (int k = 0; k < l[p].size(); ++k)
                {
                    string newcase = res.front();
                    newcase += l[p][k];
                    res.push(newcase);
                }
                res.pop();
            }
        }
        vector<string> out;
        while (!res.empty())
        {
            out.push_back(res.front());
            res.pop();
        }
        return out;
    }
};
int main()
{
    std::system("pause");
    return 0;
}