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
    string replaceSpace(string s) {
        string res = "";
        for(char c : s)
        {
            if(c == ' '){
                res.append("%20");
            }
            else
            {
                res+=c;
            }
        }
        return res;
    }
};
int main()
{
    std::system("pause");
    return 0;
}