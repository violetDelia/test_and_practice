#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<vector<int>> res(rowIndex + 1);
        for (int i = 0; i < rowIndex + 1; ++i)
        {
            res[i].resize(i + 1);
            res[i][0] = 1;
            if (i == 0)
                continue;
            res[i][i] = 1;
            if (i == 1)
                continue;
            for (int k = 1; k < i; ++k)
                res[i][k] = res[i - 1][k - 1] + res[i - 1][k];
        }
        return res[rowIndex];
    }
};

int main()
{

    std::system("pause");
    return 0;
}