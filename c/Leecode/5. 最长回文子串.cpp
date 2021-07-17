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
class Solution {
public:
    int single(string s, int p){
        int res = 1;
        int left = p-1;
        int right = p+1;
        while(left>=0 && right<s.size()&& s[left]==s[right]){
            res+=2;
            left--;
            right++;
        }
        return res;
    }
    int doublecase(string s, int p){
        int res = 2;
        int left = p-2;
        int right = p+1;
        while(left>=0 && right<s.size()&& s[left]==s[right]){
            res+=2;
            left--;
            right++;
        }
        return res;
    }
    string longestPalindrome(string s) {
        char last = s[0]-1;
        int len = 0;
        int resp = 0;
        for(int i = 0; i < s.size(); ++i){
            int n = single(s,i);
            if(n > len){
                len = n;
                resp = i-(n-1)/2;
            }
            if(last == s[i]){
                int n = doublecase(s,i);
                if(n > len){
                len = n;
                resp = i-(n)/2;
                }
            }
            last = s[i];
        }
        return s.substr(resp,len);
    }
};
int main()
{
    string s = 
"c";
    Solution a;
    a.longestPalindrome(s);
    std::system("pause");
    return 0;
}