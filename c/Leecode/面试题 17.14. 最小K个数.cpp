#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> smallestK(vector<int> &arr, int k)
    {
        vector<int> vec(k);
        sort(arr.begin(), arr.end());
        for (int i = 0; i < k; ++i)
        {
            vec[i] = arr[i];
        }
        return vec;
    }
};

int main()
{
    vector<int> a = {1, 3, 5, 7, 2, 4, 6, 8};
    Solution b;
    b.smallestK(a, 4);

    std::system("pause");
    return 0;
}