#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        int letter[26] = {0,};
        for(char c : s)
        {
            letter[c-'a']++;
        }
        for(char c : t)
        {
            if(letter[c-'a'] == 0)
                return false;
            letter[c-'a']--;
        }
        for(int n : letter)
        {
            if(n)
                return false;
        }
        return true;
    }
};
int main()
{
    std::system("pause");
    return 0;
}