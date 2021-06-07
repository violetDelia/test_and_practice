#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxCount(int m, int n, vector<vector<int>> &ops)
    {
        int minc = INT_MAX;
        int minl = INT_MAX;
        if (ops.size() == 0)
            return m*n;
        for (auto a : ops)
        {
            if (a[0] < minc)
                minc = a[0];
            if (a[1] < minl)
                minl = a[1];
        }
        return minc * minl;
    }
};

int main()
{

    std::system("pause");
    return 0;
}