#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int shipWithinDays(vector<int> &weights, int D)
    {
        int min = INT_MIN;
        int max = 0;
        for (int i : weights)
        {
            if (i > min)
                min = i;
            max += i;
        }
        int res;
        while (min < max)
        {
            int mid = min + (max - min) / 2;
            int count = 1;
            int sum = 0;
            for (int i : weights)
            {
                if (sum + i > mid)
                {
                    ++count;
                    sum = i;
                }
                else
                {
                    sum += i;
                }
            }
            if (count <= D)
            {
                max = mid;
                res = max;
            }
            else
            {
                min = mid + 1;
                res = min;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Solution b;
    b.shipWithinDays(a, 1);

    std::system("pause");
    return 0;
}