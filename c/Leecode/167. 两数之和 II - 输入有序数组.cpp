#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int high = numbers.size() - 1;
        int low = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (numbers[mid] <= target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        if (low > numbers.size() - 1)
            low = numbers.size() - 1;
        high = 0;
        while (high < low)
        {
            int sum = numbers[low] + numbers[high];
            if (sum == target)
                return {high + 1, low + 1};
            if (sum > target)
                --low;
            else
                ++high;
        }
        return {0, 0};
    }
};

int main()
{
    vector<int> a = {-3, 3, 4, 90};
    Solution b;
    b.twoSum(a, 0);

    std::system("pause");
    return 0;
}