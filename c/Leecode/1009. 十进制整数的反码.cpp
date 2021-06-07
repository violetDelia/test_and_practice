#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int bitwiseComplement(int N)
    {
        if (N == 0)
            return 1;
        int l = 0;
        int n = N;
        while (n)
        {
            ++l;
            n >>= 1;
        }
        int max = (1 << l) - 1;
        int res = N ^ max;
        return res;
    }
};

int main()
{
    Solution a;
    a.bitwiseComplement(1);
    std::system("pause");
    return 0;
}