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
    int kthGrammar(int n, int k)
    {
        if (n == 1)
            return 0;
        if (k == 1)
            return 0;
        int num = kthGrammar(n - 1, (k + 1) / 2);
        if (num)
        {
            if (k & 1)
                return 1;
            return 0;
        }
        if (k & 1)
            return 0;
        return 1;
    }
};
int main()
{
    std::system("pause");
    return 0;
}