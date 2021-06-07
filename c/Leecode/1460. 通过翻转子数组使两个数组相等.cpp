#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr)
    {
        (sort(target.begin(), target.end()));
        (sort(arr.begin(), arr.end()));
        return arr == target;
    }
};

int main()
{

    std::system("pause");
    return 0;
}