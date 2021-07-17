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
    int firstUniqChar(string s)
    {
        int letter[26] = {
            0,
        };
        for (char c : s)
        {
            letter[c - 'a']++;
        }
        for (int i = 0; i < s.size(); ++i)
        {
            if (letter[s[i] - 'a'] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};
int main()
{
    Solution a;
    a.firstUniqChar("leedcode");
    std::system("pause");
    return 0;
}