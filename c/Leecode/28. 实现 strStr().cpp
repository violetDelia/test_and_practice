#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int l1 = haystack.length();
        int l2 = needle.length();
        if (l2 == 0)
            return 0;
        if (l2 > l1)
            return -1;
        for (int i = 0; i < l1 - l2 + 1; i++)
        {
            if (haystack[i] == needle[0])
            {
                int k = i;
                int count = 0;
                for (int j = 0; j < l2; j++)
                {
                    if (haystack[k] == needle[j])
                    {
                        k++;
                        count++;
                    }
                    else
                        break;
                }
                if (count >= l2)
                    return i;
            }
        }
        return -1;
    }
};

int main()
{
    string a = "hello";
    string b = "ll";
    Solution aa;
    aa.strStr(a, b);
    std::system("pause");
    return 0;
}