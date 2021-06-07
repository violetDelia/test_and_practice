#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    string addBinary(string a, string b)
    {
        int l1, l2;
        string s1, s2;
        if (a.length() >= b.length())
        {
            l1 = a.length();
            s1 = a;
            l2 = b.length();
            s2 = b;
        }
        else
        {
            l1 = b.length();
            s1 = b;
            l2 = a.length();
            s2 = a;
        }
        int count = 0;
        int i = 1;
        string res = "";
        for (; i <= l2; ++i)
        {
            if (count == 0)
            {
                if (s1[l1 - i] == '0')
                {
                    if (s2[l2 - i] == '0')
                        res.insert(res.begin(), '0');
                    else
                        res.insert(res.begin(), '1');
                }
                else
                {
                    if (s2[l2 - i] == '0')
                        res.insert(res.begin(), '1');
                    else
                    {
                        res.insert(res.begin(), '0');
                        count = 1;
                    }
                }
            }
            else
            {
                if (s1[l1 - i] == '0')
                {
                    if (s2[l2 - i] == '0')
                    {
                        res.insert(res.begin(), '1');
                        count = 0;
                    }
                    else
                        res.insert(res.begin(), '0');
                }
                else
                {
                    if (s2[l2 - i] == '0')
                        res.insert(res.begin(), '0');
                    else
                        res.insert(res.begin(), '1');
                }
            }
        }
        for (; i <= l1; ++i)
        {
            if (count == 1)
            {
                if (s1[l1 - i] == '0')
                {
                    res.insert(res.begin(), '1');
                    count = 0;
                }
                else
                    res.insert(res.begin(), '0');
            }
            else
            {
                res.insert(res.begin(), s1[l1 - i]);
            }
        }
        if (count == 1)
            res.insert(res.begin(), '1');
        return res;
    }
};

int main()
{
    string a = "11";
    string b = "1";
    Solution aa;
    aa.addBinary(a, b);
    std::system("pause");
    return 0;
}