#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        if (s1.length() == 0 ||
            s2.length() == 0 ||
            s1.length != s2.length)
            return false;
        int count = 0;
        int first;
        int second;
        for (int i = 0; i < s1.length(); ++i)
        {
            if (s1[i] != s2[i])
            {
                count++;
                if (count == 1)
                    first = i;
                else if (count == 2)
                    second = i;
                else
                    return false;
            }
        }
        if (count == 0 ||
            count == 2 && s1[first] == s2[second] && s1[second] == s2[first])
            return true;
        return false;
    }
};

int main()
{

    std::system("pause");
    return 0;
}