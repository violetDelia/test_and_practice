#include <iostream>
#include <stdio.h>
using namespace std;
class Solution
{
public:
    int clumsy(int N)
    {
        int res = 0;
        if (N >= 4)
        {
            res += (N--) * (N--) / (N--) + (N--);
            while (N >= 4)
            {
                res -= (N--) * (N--) / (N--) - (N--);
            }
            if (N == 3)
            {
                res -= 6;
            }
            else if (N == 2)
            {
                res -= 2;
            }
            else if (N == 1)
            {
                res -= 1;
            }
        }
        else if (N == 3)
        {
            return 6;
        }
        else if (N == 2)
        {
            return 2;
        }
        else
        {
            return 0;
        }
        return res;
    }
};
int main()
{
    Solution r;
    r.clumsy(4);
    std::system("pause");
    return 0;
}