#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue)
    {
        int keynum = -1;
        if (ruleKey == "type")
            keynum = 0;
        else if (ruleKey == "color")
            keynum = 1;
        else
            keynum = 2;
        int count = 0;
        for(int i = 0; i < items.size(); ++i){
            if(items[i][keynum] == ruleValue)
                ++count;
        }
        return count;
    }
};
int main()
{
    std::system("pause");
    return 0;
}