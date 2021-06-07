#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        vector<int> res;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (!(nums[i] & 1))
                sum += nums[i];
        }
        for (int i = 0; i < queries.size(); ++i)
        {
            if (!(nums[queries[i][1]] & 1))
                sum -= nums[queries[i][1]];
            nums[queries[i][1]] += queries[i][0];
            if (!(nums[queries[i][1]] & 1))
                sum += nums[queries[i][1]];
            res.push_back(sum);
        }
        return res;
    }
};
int main()
{
    vector<int> a = {1, 2, 3, 4};
    vector<vector<int>> b = {{1, 0}, {-3, 1}, {-4, 0}, {2, 3}};
    Solution c;
    c.sumEvenAfterQueries(a, b);
    std::system("pause");
    return 0;
}