#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int reverse(int x)
    {
        int res = 0;
        int rear;
        while (x)
        {
            rear = x % 10;
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && rear > 7))
                return 0;
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && rear < -8))
                return 0;

            res = res * 10 + rear;
            x /= 10;
        }
        return res;
    }
};

int main()
{

    std::system("pause");
    return 0;
}