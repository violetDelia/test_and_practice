#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    int numSquares(int n)
    {
        int count[10001] = {
            0,
        };
        int i = 1;
        for (; i < 101; ++i)
        {
            if (i * i > n)
                break;
            count[i * i] = 1;
        }
        --i;
        for (; i > 0; --i)
        {
            for (int p = 1; p <= n; p++)
            {
                if (p + i * i > n)
                {
                    break;
                }
                else
                {
                    if (count[p] != 0)
                        if (count[p + i * i] == 0)
                            count[p + i * i] = count[p] + 1;
                        else
                        {
                            int tem = count[p] + 1;
                            count[p + i * i] = count[p + i * i] < tem ? count[p + i * i] : tem;
                        }
                }
            }
        }
        return count[n];
    }
};
int main()
{
    Solution a;
    a.numSquares(44);
    std::system("pause");
    return 0;
}