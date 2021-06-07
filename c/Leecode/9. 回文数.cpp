#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        if (x == 0)
            return true;
        if (!(x % 10))
            return false;
        int rev = 0;
        while (rev < x)
        {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return rev == x || rev / 10 == x;
    }
};

int main()
{

    std::system("pause");
    return 0;
}