#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool isUgly(int n)
    {
        if (n <= 0)
            return false;
        while (!(n % 2))
            n /= 2;
        while (!(n % 3))
            n /= 3;
        while (!(n % 5))
            n /= 5;
        if (n == 1)
            return true;
        return false;
    }
};

int main()
{
    int n = -2147483648;
    Solution a;
    a.isUgly(n);

    std::system("pause");
    return 0;
}