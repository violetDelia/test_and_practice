#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        char count = 'A';
        string res = "";
        while (columnNumber)
        {
            --columnNumber;
            char s = count + columnNumber % 26 ;
            res = s + res;
            columnNumber /= 26;
        }
        return res;
    }
};

int main()
{
    Solution a;
    a.convertToTitle(2147483647);

    std::system("pause");
    return 0;
}