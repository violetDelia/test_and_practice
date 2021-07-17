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
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> count;
        for (int n : nums)
        {
            count[n]++;
        }
        for (auto s : count)
        {
            if (s.second < 0)
                return false;
            if (s.second > 0)
            {
                for (int i = 0; i < k; ++i)
                {
                    count[s.first + i] -= s.second;
                }
            }
        }
        return true;
    }
};
int main()
{
    
    std::system("pause");
    return 0;
}