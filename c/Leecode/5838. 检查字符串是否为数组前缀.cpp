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
class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int l  = s.size();
        string sum = "";
        int suml = 0;
        for(auto w : words)
        {
            sum += w;
            suml += w.size();
            if(suml == l)
                return s == sum;
            if(suml > l)
                return false;
        }
        return true;
    }
};
int main()
{
    Solution a;
    vector<string> test{"i","love","leetcode","apples"};
    string s = "iloveleetcode";
    a.isPrefixString(s,test);
}