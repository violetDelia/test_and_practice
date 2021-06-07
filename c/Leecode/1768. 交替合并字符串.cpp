#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string res = "";
        int l1 = word1.length();
        int l2 = word2.length();
        int min = l1 < l2 ? l1 : l2;
        for (int i = 0; i < min; ++i)
        {
            res += word1[i] ;
            res += word2[i] ;
        }
        if (l1 > l2)
            res += word1.substr(min);
        else
            res += word2.substr(min);
        return res;
    }
};

int main()
{
    Solution a;
    a.mergeAlternately("abc", "pqr");

        std::system("pause");
    return 0;
}