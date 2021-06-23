#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
#include <set>
using namespace std;
class Solution
{
public:
    vector<string> restrue;
    vector<char> conuts;
    set<string> res;
    void dfs(string now, int lenth, int featuer)
    {
        if (lenth == 0)
        {
            res.emplace(now);
            return;
        }
        for (int i = 0; i < conuts.size(); ++i)
        {
            if (((featuer >> i) & 1) == 0)
                dfs(now + conuts[i], lenth - 1, featuer | (1 << i));
        }
    }
    vector<string> permutation(string s)
    {
        for (char c : s)
        {
            conuts.push_back(c);
        }
        dfs("", s.size(), 0);
        for (string a : res){
            restrue.push_back(a);
        }
        return restrue;
    }
};
int main()
{
    Solution a;
    a.permutation("baa");
    std::system("pause");
    return 0;
}