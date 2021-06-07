#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> count;
        int max = 0;
        int r = 0;
        int l = s.length();
        for (int i = 0; i < l; ++i)
        {
            if (i)
            {
                count.erase(s[i - 1]);
            }
            while (r < l && !count.count(s[r]))
            {
                count.insert(s[r]);
                ++r;
            }
            max = max > r - i ? max : r - i;
        }
        return max;
    }
    int lengthOfLongestSubstrings(string s)
    {
        int start = 0;
        int l = s.length();
        int count = 0;
        int max = 0;
        for (int i = 0; i < l; ++i)
        {
            for (int k = start; k < i; ++k)
            {
                if (s[k] == s[i])
                {
                    ++count;
                    start += count;
                    count = 0;
                    break;
                }
                ++count;
            }
            count = 0;
            max = max > i - start + 1 ? max : i - start + 1;
        }
        return max;
    }
};

int main()
{
    string a = "bbbb";
    Solution b;
    b.lengthOfLongestSubstrings(a);

    std::system("pause");
    return 0;
}