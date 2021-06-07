#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        int n = mat.size() - 1;
        int i = 0;
        int sum = 0;
        while (i <= n)
        {
            if (i == n - i)
                sum += mat[i][i];
            else
                sum += mat[i][i] + mat[i][n - i];
            ++i;
        }
        return sum;
    }
};

int main()
{
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution a;
    a.diagonalSum(mat);
    std::system("pause");
    return 0;
}