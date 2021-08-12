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
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        multimap<string,  int> count;
        for (int i = 0; i < strs.size(); ++i)
        {
            string head = strs[i];
            sort(head.begin(), head.end());
            count.emplace(head, i);
        }
        vector<vector<string>> res;
        int position = -1;
        string last = "*";
        for(auto & p : count)
        {
            if(p.first != last)
            {
                vector<string> newstringarray;
                res.push_back(newstringarray);
                position++;
                last = p.first;
            }
            res[position].push_back(strs[p.second]);
        }
        return res;
    }
};
int main()
{
    vector<string> s = {""};
    Solution a;
    a.groupAnagrams(s);
    std::system("pause");
    return 0;
}