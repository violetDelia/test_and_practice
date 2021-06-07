#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> count;
        while (count.find(n) == count.end())
        {
            if (n == 1)
                return true;
            count.insert(n);
            int c = 0;
            while (n)
            {
                int bit = n % 10;
                c += bit * bit;
                n /= 10;
            }
            n = c;
        }
        return false;
    }
};

int main()
{
    Solution a;
    a.isHappy(19);

    std::system("pause");
    return 0;
}