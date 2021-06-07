#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    bool canMakeArithmeticProgression(vector<int> &arr)
    {
        if (arr.size() == 0)
            return false;
        if (arr.size() == 1 || arr.size() == 2)
            return true;
        sort(arr.begin(), arr.end());
        int space = arr[1] - arr[0];
        for (int i = 2; i < arr.size(); ++i)
        {
            if (arr[i] - arr[i - 1] != space)
                return false;
        }
        return true;
    }
};
int main()
{
    std::system("pause");
    return 0;
}