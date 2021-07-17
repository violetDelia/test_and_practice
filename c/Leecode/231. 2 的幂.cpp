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
    bool isPowerOfTwo(int n) {
        if ( n <= 0)
            return false;
        int x = n-1;
        x = x | x >> 1;
        x = x | x >> 2;
        x = x | x >> 4;
        x = x | x >> 8;
        x = x | x >> 16;
        return x == n-1;
    }
};
int main()
{
    std::system("pause");
    return 0;
}