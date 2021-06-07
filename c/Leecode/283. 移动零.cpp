#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int p = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[p] == 0)
            {
                nums.erase(nums.begin() + p);
                nums.push_back(0);
            }
            else
                ++p;
        }
    }
};
int main()
{
    std::system("pause");
    return 0;
}