#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    string toLowerCase(string str)
    {
        for (int i = 0; i < str.size(); ++i)
        {
            if (isupper(str[i]))
                str[i] = tolower(str[i]);
        }
        return str;
    }
};
int main()
{
    std::system("pause");
    return 0;
}