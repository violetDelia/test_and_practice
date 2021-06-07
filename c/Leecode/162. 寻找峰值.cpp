#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        if(nums[1]< nums[0])
            return 0;
        for( int i = 1; i < nums.size()-1; ++i){
            if (nums[i] > nums[i+1] && nums[i] > nums[i-1])
                return i;
        }
        return nums.size()-1;
    }
};
int main()
{
    std::system("pause");
    return 0;
}