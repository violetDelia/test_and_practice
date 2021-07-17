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
#include <math.h>
using namespace std;
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i)
        {
            res.push_back(nums[nums[i]]);
        }
        return res;
    }
};
int main()
{
    std::system("pause");
    return 0;
}