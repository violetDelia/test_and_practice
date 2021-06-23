#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target)
    {
        int count[100010] = {
            0,
        };
        int flag[3] = {0, 0, 0};
        for (int j = 0; j < 3; ++j)
        {
            for (int i = 0; i < triplets.size(); ++i)
            {
                if (triplets[i][j] > target[j])
                    count[i]++;
            }
        }
        for (int j = 0; j < 3; ++j)
        {
            for (int i = 0; i < triplets.size(); ++i)
            {
                if (triplets[i][j] == target[j] && count[i] == 0)
                    flag[j]++;
            }
        }
        for (int i = 0; i < 3; i++)
        {
            if (flag[i] == 0)
                return false;
        }
        return true;
    }
};
int main()
{
    Solution a;
    vector<vector<int>> b = {{2, 5, 3}, {1, 8, 4}, {1, 7, 5}};
    vector<int> c = {1, 7, 5};
    a.mergeTriplets(b, c);
    std::system("pause");
    return 0;
}