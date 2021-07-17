#include <algorithm>
#include <bitset>
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
    bool canPermutePalindrome(string s)
    {
        bitset<128> b;
        for (char &c : s)
        {
            b.flip(c);
        }
        return b.count() <= 1;
    }
};
int main()
{
    Solution a;
    a.canPermutePalindrome("tactcoa");
    std::system("pause");
    return 0;
}