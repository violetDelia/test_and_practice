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
class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        sort(costs.begin(), costs.end());
        int res = 0;
        for (int i = 0; i < costs.size(); ++i)
        {
            if ((coins -= costs[i]) >= 0)
            {
                res++;
                continue;
            }
            break;
        }
        return res;
    }
};
int main()
{
    std::system("pause");
    return 0;
}