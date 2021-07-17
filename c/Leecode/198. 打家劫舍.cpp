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
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+2,0);
        for(int i = 2; i < nums.size()+2; ++i){
            dp[i] = max(nums[i-2] + dp[i-2],dp[i-1]);
        }
        return dp.back();
    }
};
int main()
{
    vector<int> s  = {2,7,4,3,1};
    Solution a;
    a.rob(s);
    std::system("pause");
    return 0;
}