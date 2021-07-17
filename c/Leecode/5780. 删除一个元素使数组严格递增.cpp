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
    string removeOccurrences(string s, string part)
    {
        if (s.size() < part.size())
            return s;
        int p = 0;
        string ss = "";
        for (; p < s.size(); ++p)
        {
            if (ss.size() == part.size())
            {
                if (ss == part)
                {
                    ss.clear();
                    s.erase(s.begin() + p - part.size(), s.begin() + p);
                    p -= 2 * part.size();
                    if (p <= 0)
                        p = -1;
                }
                else
                {
                    ss.erase(ss.begin());
                    ss += s[p];
                }
            }
            else
            {
                ss += s[p];
            }
        }
        if (ss == part)
            s.erase(s.begin() + p - part.size(), s.begin() + p);
        return s;
    }
};
int main()
{
    string a = "xxxxxyyyyy";
    Solution b;
    b.removeOccurrences(a, "xy");

    std::system("pause");
    return 0;
}