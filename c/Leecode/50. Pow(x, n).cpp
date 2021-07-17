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
    double pow(double x, int n, double more)
    {
        if (n == 1)
            return x * more;
        if (n & 1)
            return pow(x * x, n >> 1, more * x);
        return pow(x * x, n >> 1, more);
    }
    double myPow(double x, int n)
    {
        if (n < 0)
        {
            if (n == INT_MIN)
            {
                x = x * x;
                n >>= 1;
            }
            x = 1 / x;
            n = -n;
        }
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        if (n & 1)
            return pow(x, n - 1, x);
        return pow(x, n, 1);
    }
};
int main()
{
    std::system("pause");
    return 0;
}