#include <ctype.h>
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool isPalindrome(string s)
    {
        string count = "";
        for (char op : s)
        {
            if (isalnum(op))
                count += tolower(op);
        }
        string count_rev(count.rbegin(), count.rend());
        return count == count_rev;
    }
};

int main()
{

    std::system("pause");
    return 0;
}