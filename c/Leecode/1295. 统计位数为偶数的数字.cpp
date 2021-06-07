#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int res = 0;
        for (int n : nums)
        {
            int bit = 1;
            while (n / 10)
            {
                n /= 10;
                ++bit;
            }
            if (bit % 2 == 0)
                ++res;
        }
        return res;
    }
};

int main()
{

    std::system("pause");
    return 0;
}