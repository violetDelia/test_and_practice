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
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        map<int, int> count;
        for (int n : hand)
        {
            count[n]++;
        }
        /*for (int i = 0; i < count.size(); ++i)
        {
            if (count[i])
            {
                --count[i];
                for (int j = 1; j < groupSize; ++j)
                {
                    if (count[i + j] == 0)
                        return false;
                    else
                        count[i + j]--;
                }
            }
        }*/
        for (auto s : count)
        {
            if (s.second < 0)
                return false;
            if (s.second > 0)
            {
                for (int i = 0; i < groupSize; ++i)
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
    vector<int> a = {1, 2, 3, 4, 5};
    Solution b;
    b.isNStraightHand(a, 3);
    std::system("pause");
    return 0;
}