#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int i = 0;
        int off = 0;
        if (!(strs.size()) || !(strs[0].size()))
            return "";
        int l = strs[0].size();
        for (; i < l; ++i)
        {
            for (string a : strs)
            {
                if (a[i] == '\0' || a[i] != strs[0][i])
                {
                    off = -1;
                    break;
                }
            }
            if (off == -1)
                break;
        }
        return strs[0].substr(0, i);
    }
};

int main()
{
    vector<string> strs = {};
    Solution a;
    a.longestCommonPrefix(strs);

    std::system("pause");
    return 0;
}