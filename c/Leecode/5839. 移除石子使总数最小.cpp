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
    int minStoneSum(vector<int> &piles, int k)
    {
        priority_queue<int> count;
        int res = 0;
        for (int n : piles)
        {
            count.push(n);
            res += n;
        }
        for (int i = 0; i < k; ++i)
        {
            int n = count.top();
            count.pop();
            int willdelete = n / 2;
            res -= willdelete;
            count.push(n - willdelete);
        }
        return res;
    }
};