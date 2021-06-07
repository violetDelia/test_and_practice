#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        string a = countAndSay(n - 1);
        int l = a.length();
        int count = 1;
        char num = a[0];
        string res = "";
        for (int i = 1; i < l; i++)
        {
            if (a[i] == a[i - 1])
            {
                count++;
            }
            else
            {
                res += to_string(count) + num;
                num = a[i];
                count = 1;
            }
        }
        res += to_string(count) + num;
        return res;
    }
};

int main()
{
    Solution a;
    a.countAndSay(2);
    std::system("pause");
    return 0;
}