#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution
{
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr)
    {
        unordered_map<int, int> m;
        for (int &i : arr)
        {
            m[i]++;
        }
        int res = 1;
        int count = arr.size();
        while (count)
        {
            if (m[res])
            {
                count -= m[res];
                if (count < 0)
                    return res + 1;
            }
            else
            {
                count--;
            }
            if (count)
                ++res;
        }
        return res;
    }
};
int main()
{
    std::system("pause");
    return 0;
}