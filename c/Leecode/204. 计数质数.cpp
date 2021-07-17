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
    int countPrimes(int n)
    {
        if (!n || n == 1)
            return 0;
        vector<int> nums(n, 1);
        int res = 0;
        for (int i = 2; i < n; ++i)
        {
            if (nums[i])
            {
                res++;
                for (int p = 2; p * i < n; ++p)
                {
                    nums[p * i] = 0;
                }
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