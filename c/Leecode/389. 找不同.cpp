#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        char res = '\0';
        for (char op : s)
            res ^= op;
        for (char op : t)
            res ^= op;
        return res;
    }
};
int main()
{
    std::system("pause");
    return 0;
}