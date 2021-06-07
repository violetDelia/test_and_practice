#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    int max(vector<int> flower, int k, int day)
    {
        int res = 0;
        int count = 0;
        for (int i = 0; i < flower.size(); ++i)
        {
            if (flower[i] <= day)
            {
                ++count;
                if (count == k)
                {
                    count = 0;
                    ++res;
                }
            }
            else
            {
                count = 0;
            }
        }
        return res;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        if (m * k > bloomDay.size())
            return -1;
        int res;
        int low = 0;
        int high = INT_MIN;
        for (int n : bloomDay)
        {
            high = high > n ? high : n;
        }
        int mid;
        while (low < high)
        {
            mid = low + (high - low) / 2;
            if (max(bloomDay, k, mid) >= m)
            {
                high = mid;
                res = high;
            }
            else
            {
                low = mid + 1;
                res = low;
            }
        }
        return res;
    }
};
int main()
{
    Solution a;
    vector<int> f = {1, 10, 3, 10, 2};
    a.minDays(f, 3, 1);
    std::system("pause");
    return 0;
}