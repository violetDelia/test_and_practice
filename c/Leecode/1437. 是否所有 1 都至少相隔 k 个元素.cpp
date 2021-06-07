#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool kLengthApart(vector<int> &nums, int k)
    {
        int i = 0;
        int last;
        for (; i < nums.size(); ++i)
        {
            if (nums[i] == 1)
            {
                last = i;
                break;
            }
        }
        ++i;
        for (; i < nums.size(); ++i)
        {
            if (nums[i] == 1)
            {
                if (i - last < k + 1)
                    return false;
                else
                    last = i;
            }
        }
        return true;
    }
};

int main()
{
    Solution a;
    vector<int> b = {1, 0, 0, 1, 0, 1};
    a.kLengthApart(b, 2);
    std::system("pause");
    return 0;
}