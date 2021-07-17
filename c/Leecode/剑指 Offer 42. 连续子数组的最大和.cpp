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
    int maxnum(int a, int b)
    {
        return a > b ? a : b;
    }
    int maxSubArray(vector<int> &nums)
    {
        int max = INT_MIN;
        int sum = 0;
        for (int &n : nums)
        {
            sum += n;
            max = maxnum(max, sum);
            if (sum < 0)
                sum = 0;
        }
        return max;
    }
};
int main()
{
    std::system("pause");
    return 0;
}