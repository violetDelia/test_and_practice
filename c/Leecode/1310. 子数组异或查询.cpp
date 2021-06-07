#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        vector<int> res;
        int count = 0;
        for (int i = 0; i < arr.size(); ++i)
        {
            count ^= arr[i];
            arr[i] = count ^ arr[i];
        }
        for (auto a : queries)
        {
            if (a[0] != 0)
                res.push_back(arr[a[1]] ^ arr[a[0] - 1]);
            else
                res.push_back(arr[a[1]]);
        }
        return res;
    }
};
int main()
{
    std::system("pause");
    return 0;
}