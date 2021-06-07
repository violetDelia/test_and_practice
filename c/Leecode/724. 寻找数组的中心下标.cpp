#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        vector<int> left;
        left.push_back(0);
        int count = 0;
        int l = nums.size();
        for (int n : nums)
        {
            count += n;
            left.push_back(count);
        }
        count = 0;
        vector<int> right;
        right.push_back(0);
        for (int i = l - 1; i >= 0; --i)
        {
            count += nums[i];
            right.push_back(count);
        }
        for (int i = 0; i < l; ++i)
        {
            if (left[i] == right[l - i - 1])
                return i;
        }
        return -1;
    }
};
int main()
{
    std::system("pause");
    return 0;
}