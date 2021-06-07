#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int res = 0;
        for (int c : nums)
        {
            res ^= c;
        }
        return res;
    }
};

int main()
{

    std::system("pause");
    return 0;
}