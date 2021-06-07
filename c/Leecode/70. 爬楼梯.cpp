#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        int res = 2;
        int last = 1;
        for (int i = 3; i <=n; ++i)
        {
            int temp = res;
            res += last;
            last = temp;
        }
        return res;
    }
};

int main()
{

    std::system("pause");
    return 0;
}