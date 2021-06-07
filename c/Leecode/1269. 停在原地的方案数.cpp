#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    int numWays(int steps, int arrLen)
    {
        int mod = 1000000007;
        if (steps == 1)
            return 1;
        int l;
        if (steps > arrLen)
            l = arrLen;
        else
            l = steps;
        vector<vector<int>> count(steps, vector<int>(l));
        count[0][0] = 1;
        if (arrLen > 1)
            count[0][1] = 1;
        for (int i = 1; i < steps; ++i)
        {
            for (int j = 0; j < l; ++j)
            {
                count[i][j] = count[i - 1][j];
                if (j > 0)
                    count[i][j] = (count[i][j] + count[i - 1][j - 1]) % mod;
                if (j < l - 1)
                    count[i][j] = (count[i][j] + count[i - 1][j + 1]) % mod;
            }
        }
        return count[steps - 1][0];
    }
};
int main()
{
    Solution a;
    a.numWays(3, 2);
    std::system("pause");
    return 0;
}