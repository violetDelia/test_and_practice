#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool halvesAreAlike(string s)
    {
        int len = s.length();
        int cnt1 = 0;
        int cnt2 = 0;
        int i;
        for (i = 0; i < len / 2; i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
                s[i] == 'o' || s[i] == 'u' || s[i] == 'A' ||
                s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                cnt1++;
            }
        }

        for (int j = i; j < len; j++)
        {
            if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' ||
                s[j] == 'o' || s[j] == 'u' || s[j] == 'A' ||
                s[j] == 'E' || s[j] == 'I' || s[j] == 'O' || s[j] == 'U')
            {
                cnt2++;
            }
        }

        if (cnt1 == cnt2)
            return true;

        else
            return false;
    }
};

int main()
{

    std::system("pause");
    return 0;
}