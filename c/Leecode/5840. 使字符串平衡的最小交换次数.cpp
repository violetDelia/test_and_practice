#include <algorithm>
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
    int minSwaps(string s)
    {
        stack<char> count;
        for (char c : s)
        {
            if (c == ']' && !count.empty() && count.top() == '[')
                count.pop();
            else
                count.push(c);
        }
        return (count.size() / 2+1)/2;
    }
};
