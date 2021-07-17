#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int serchfront(vector<int> & nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r)
        {
            int mid = l + ( r - l) /2;
            if(nums[mid] >= target)
            {
                r = mid -1;
            }
            else
            {
                l = mid +1;
            }
        }
        return l;
    }
    int search(vector<int>& nums, int target) {
        return serchfront(nums,target+1) - serchfront(nums,target);
    }
};
int main()
{
    std::system("pause");
    return 0;
}