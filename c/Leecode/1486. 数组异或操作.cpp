#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    int xorOperation(int n, int start)
    {
        int res = 0;
        while (n)
        {
            res ^= start;
            start += 2;
            n--;
        }
        return res;
    }
};
int main()
{
    std::system("pause");
    return 0;
}