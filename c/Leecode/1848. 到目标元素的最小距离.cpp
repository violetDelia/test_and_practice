#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution
{
public:
    int getMinDistance(vector<int> &nums, int target, int start)
    {
        vector<int> pos;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == target)
                pos.push_back(i);
        }
        int res = INT_MAX;
        for (int n : pos)
        {
            int x = abs(n - start);
            res = res < x ? res : x;
        }
        return res;
    }
};
int main()
{
    std::system("pause");
    return 0;
}