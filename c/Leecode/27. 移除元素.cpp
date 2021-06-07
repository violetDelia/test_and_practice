#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int l = nums.size();
        if (l == 0)
            return 0;
        int count = 0;
        for (int i = 0; i < l; i++)
        {
            if (nums[i] != val)
            {
                nums[count] = nums[i];
                count++;
            }
        }
        return count;
    }

    int removeElements(vector<int>& nums, int val) {
        vector<int>::iterator itr=nums.begin();
        
    }

};

int main()
{

    std::system("pause");
    return 0;
}