#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int My_factorial(int n)
    {
        if (n > 1)
            n = n + My_factorial(n - 1);
        return n % 1000000007;
    }
    int countHomogenous(string s)
    {
        int i = 1;
        int biginposition = 0;
        int res = 0;
        while (s[i] != '\0')
        {
            if (s[i] == s[biginposition])
            {
                i++;
            }
            else
            {
                res += My_factorial(i - biginposition);
                biginposition = i;
                i++;
            }
        }
        return res;
    }
};

int main()
{
    string a = "aaabb";
    Solution b;
    b.countHomogenous(a);

    std::system("pause");
    return 0;
}