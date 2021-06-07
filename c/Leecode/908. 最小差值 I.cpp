#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int smallestRangeI(vector<int> &A, int K)
    {
        int min = INT_MAX;
        int max = INT_MIN;
        int res;
        for (int i : A)
        {
            if (i < min)
                min = i;
            if (i > max)
                max = i;
        }
        res = max - min - 2 * K;
        return res > 0 ? res : 0;
    }
};

int main()
{

    std::system("pause");
    return 0;
}