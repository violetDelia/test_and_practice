#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        if (arr.size() == 0 || arr.size() == 1)
            return false;

        sort(arr.begin(), arr.end());
        int com = (arr.back() >> 1) + 1;
        for (int i = 0; i < arr.size(); ++i)
        {
            if (arr[i] > com)
                break;
            else
            {
                if (arr[i] < 0)
                {
                    int min = arr[i] / 2 + 1;
                    for (int k = i + 1; k < arr.size() && arr[k] <= min; ++k)
                    {
                        if (arr[k] * 2 == arr[i])
                            return true;
                    }
                }
                else
                {
                    int max = arr[i] * 2;
                    for (int k = i + 1; k < arr.size() && arr[k] <= max; ++k)
                    {
                        if (arr[k] == max)
                            return true;
                    }
                }
            }
        }
        return false;
    }
};

int main()
{
    vector<int> arr = {-10, 12, -20, -8, 15};
    Solution a;
    a.checkIfExist(arr);
    std::system("pause");
    return 0;
}