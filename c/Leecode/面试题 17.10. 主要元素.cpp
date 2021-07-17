#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int more = 0;
        int morenum = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(more)
            {
                if(nums[i] == morenum)
                    more ++;
                else  
                    more --;
            }
            else
            {
                more ++;
                morenum = nums[i];
            }
        }
        if(!more)
            return -1;
        more = 0;
        for( int n : nums)
        {
            if(n == morenum)
                more++;
        }
        return more*2 > nums.size()? morenum:-1;
    }
};
int main()
{
    vector<int> n = {1,2,3};
    Solution a;
    a.majorityElement(n);
    std::system("pause");
    return 0;
}