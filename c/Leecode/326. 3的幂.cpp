#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (n <= 0)
            return 0;
        while (n)
        {
            if (n % 3 != 0 && n != 1)
                return false;
            n /= 3;
        }
        return true;
    }
};
int main()
{
    std::system("pause");
    return 0;
}