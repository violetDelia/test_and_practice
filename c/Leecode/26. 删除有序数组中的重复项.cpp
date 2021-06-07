#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int l = nums.size();
        if (l == 0)
            return 0;
        int count = 0;
        for (int i = 1; i < l; i++)
        {
            if (nums[i] != nums[count])
            {
                count++;
                nums[count] = nums[i];
            }
        }
        return count + 1;
    }
};

int main()
{

    std::system("pause");
    return 0;
}