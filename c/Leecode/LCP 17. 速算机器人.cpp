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
    int x = 1;
    int y = 0;
    void caseA()
    {
        x = x * 2 + y;
    }
    void caseB()
    {
        y = 2 * y + x;
    }
    int calculate(string s) 
    {
        for(char c : s)
        {
            if(c == 'A')
                caseA();
            else
                caseB();
        }
        return x + y;
    }
};
int main()
{
    std::system("pause");
    return 0;
}