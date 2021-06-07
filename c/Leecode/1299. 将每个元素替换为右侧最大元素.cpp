#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> replaceElements(vector<int> &arr)
    {
        int max = INT_MIN;
        int l = arr.size() - 1;
        for (int i = l; i >= 0; --i)
        {
            int temp = arr[i];
            arr[i] = max;
            max = temp > max ? temp : max;
        }
        arr[l] = -1;
        return arr;
    }
};

int main()
{

    std::system("pause");
    return 0;
}