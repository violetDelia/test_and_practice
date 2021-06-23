#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int n = arr.size();
        int left = 0, right = n - 1, ans = 0;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (arr[mid] > arr[mid + 1])
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }
};
int main()
{
    std::system("pause");
    return 0;
}