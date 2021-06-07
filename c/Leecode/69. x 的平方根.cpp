#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int mySqrt(int x)
    {
        int high = x;
        int low = 0;
        int res;
        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            if (mid * mid == x)
            {
                res = (int)mid;
                return res;
            }
            else if (mid * mid > x)
                high = mid - 1;
            else
            {
                res = (int)mid;
                low = mid + 1;
            }
        }
        return res;
    }
};

int main()
{
    Solution a;
    a.mySqrt(4);

    std::system("pause");
    return 0;
}