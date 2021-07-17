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
    char shift(char last, char c)
    {
        return last + (c - '0');
    }
    string replaceDigits(string s) {
        char last;
        for(char&c : s)
        {
            if(c >= '0' && c <= '9')
                c = shift(last,c);
            last = c;
        }
        return s;
    }
};
int main()
{
    std::system("pause");
    return 0;
}