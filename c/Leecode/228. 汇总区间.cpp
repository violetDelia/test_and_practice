#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> res;
        if (nums.size() == 0)
            return res;
        int count = 1;
        int begin = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == nums[i - 1] + 1)
            {
                count++;
            }
            else
            {
                string s = to_string(nums[begin]);
                if (count > 1)
                {
                    s.append("->");
                    s.append(to_string((nums[begin+count-1])));
                }
                res.emplace_back(s);
                begin = i;
                count = 1;
            }
        }
        string s = to_string(nums[begin]);
        if (count > 1)
        {
            s.append("->");
            s.append(to_string((nums[begin+count-1])));
        }
        res.emplace_back(s);
        return res;
    }
};

int main()
{
    vector<int> a = {-2,-1,1,2,2147483646,2147483647};
    Solution b;
    b.summaryRanges(a);

    std::system("pause");
    return 0;
}