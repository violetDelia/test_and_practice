#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> decompressRLElist(vector<int> &nums)
    {
        vector<int> res;
        if (nums.size() == 0 || nums.size() %2 == 1)
            return res;
        for (int i = 0; i < nums.size(); i += 2)
        {
            for (int k = 0; k < nums[i];++k)
                res.push_back(nums[i + 1]);
        }
        return res;
    }
};

int main()
{

    std::system("pause");
    return 0;
}