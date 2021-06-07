#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 1;
        int l = nums.size();
        int p = 0;
        int count = 0;
        int last = nums[0];
        while (i < l)
        {
            if (nums[i] > last)
            {

                count = 0;
                p++;
                nums[p] = nums[i];
            }
            else
            {
                if (!count)
                {
                    count++;
                    p++;
                    nums[p] = nums[i];
                }
            }
            last = nums[i];
            i++;
        }
        return p + 1;
    }
};

int main()
{
    vector<int> a = {1, 1, 1, 2, 2, 3};
    Solution b;
    b.removeDuplicates(a);
    std::system("pause");
    return 0;
}