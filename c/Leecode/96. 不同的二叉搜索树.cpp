#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int numTrees(int n) {
        int res[n+1];
        memset(res,0,n+1);
        res[0] = 1;
        res[1] = 1;
        for(int i = 2; i < n+1; ++i)
        {
            int sum = 0;
            for(int l = i-1; l >= 0; --l)
            {
                sum += res[l]*res[i-l-1];
            }
            res[i] = sum;
        }
        return res[n];
    }
};
int main()
{
    std::system("pause");
    return 0;
}