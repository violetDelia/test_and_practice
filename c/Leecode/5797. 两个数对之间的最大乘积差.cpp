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
    int maxProductDifference(vector<int> &nums)
    {
        int max1 = 0;
        int max2 = 0;
        int min1 = 10001;
        int min2 = 10001;
        for (int n : nums)
        {
            if (n > max2)
            {
                if (n > max1)
                {
                    max2 = max1;
                    max1 = n;
                }
                else
                {
                    max2 = n;
                }
            }
            if (n < min2)
            {
                if (n < min1)
                {
                    min2 = min1;
                    min1 = n;
                }
                else
                {
                    min2 = n;
                }
            }
        }
        return max1 * max2 - min1 * min2;
    }
};
int main()
{
    vector<int> c = {4, 2, 5, 9, 7, 4, 8};
    Solution a;
    a.maxProductDifference(c);
    std::system("pause");
    return 0;
}