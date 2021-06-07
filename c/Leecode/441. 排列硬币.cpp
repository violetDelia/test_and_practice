#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int arrangeCoins(int n)
    {
        int res = 1;
        for (; res<=n; ++res)
            n -= res;
        return --res;
    }
};

int main()
{

    std::system("pause");
    return 0;
}