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
    int hIndex(vector<int> &citations)
    {
        sort(citations.begin(), citations.end(), [=](int a, int b)
             { return a > b; });
        int count;
        for (int i = 0; i < citations.size(); ++i)
        {
            if (i + 1 == citations[i])
                return citations[i];
            if (i + 1 > citations[i])
                return i;
        }
        return citations.size();
    }
};
int main()
{
    std::system("pause");
    return 0;
}