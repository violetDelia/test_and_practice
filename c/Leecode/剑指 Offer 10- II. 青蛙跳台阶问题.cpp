#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    int numWays(int n)
    {
        vector<int> res(n + 1, 0);
        if (n == 0)
            return 1;
        res[0] = 1;
        if (n == 1)
            return 1;
        res[1] = 1;
        for(int i = 2;i <= n; ++i){
            res[i] = (res[i-1] + res[i-2])%1000000007;
        }
        return res[n];
    }
};
int main()
{
    std::system("pause");
    return 0;
}