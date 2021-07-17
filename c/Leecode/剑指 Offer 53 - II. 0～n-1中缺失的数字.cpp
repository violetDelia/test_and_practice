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
    int missingNumber(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] != i)
                return i;
        }
        return nums[nums.size()-1]+1;
    }
};
int main()
{
    std::system("pause");
    return 0;
}