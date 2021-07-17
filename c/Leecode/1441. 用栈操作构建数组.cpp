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
    vector<string> buildArray(vector<int> &target, int n)
    {
        vector<string> res;
        int p = 1;
        for (int n : target)
        {
            while (p < n)
            {
                res.push_back("Push");
                res.push_back("Pop");
                ++p;
            }
            res.push_back("Push");
            ++p;
        }
        return res;
    }
};
int main()
{
    std::system("pause");
    return 0;
}