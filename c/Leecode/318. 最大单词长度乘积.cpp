#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxProduct(vector<string> &words)
    {
        vector<vector<int>> count(words.size(), vector<int>(26, 0));
        int res = 0;
        for (int i = 0; i < words.size(); ++i)
        {
            for (int j = 0; j < words[i].size(); ++j)
            {
                count[i][words[i][j] - 'a']++;
            }
        }
        for (int i = 0; i < words.size() - 1; i++)
        {
            for (int j = i + 1; j < words.size(); ++j)
            {
                int len = words[i].size() * words[j].size();
                if (len < res)
                    continue;
                int issame = 1;
                for (int k = 0; k < 26; ++k)
                {
                    if (count[i][k] && count[j][k])
                    {
                        issame--;
                        break;
                    }
                }
                if (issame)
                {
                    if (len > res)
                        res = len;
                }
            }
        }
        return res;
    }
};
int main()
{
    vector<string> a = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    Solution b;
    b.maxProduct(a);
    std::system("pause");
    return 0;
}