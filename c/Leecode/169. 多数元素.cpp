#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0;
        int candidate;
        for (int c : nums)
        {
            if (count == 0)
                candidate = c;
            if (c == candidate)
                ++count;
            else
                --count;
        }
        return candidate;
    }
};

int main()
{

    std::system("pause");
    return 0;
}