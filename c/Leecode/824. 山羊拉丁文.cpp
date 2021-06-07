#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    string toGoatLatin(string S)
    {
        string res = "";
        int wordnum = 0;
        int wordmoder = 0;
        char tail;
        int i = 0;
        for (; i < S.length(); i++)
        {
            if (S[i] != ' ')
                break;
        }
        char last = ' ';
        for (; i < S.length(); i++)
        {
            if (S[i] == ' ')
            {
                if (wordmoder)
                    res += tail;
                res += "ma";
                for (int i = 0; i < wordnum; ++i)
                    res += 'a';
                res += S[i];
            }
            else if (last == ' ')
            {
                wordnum++;
                if (S[i] == 'a' || S[i] == 'e' ||
                    S[i] == 'i' || S[i] == 'o' ||
                    S[i] == 'u' || S[i] == 'A' ||
                    S[i] == 'E' || S[i] == 'I' ||
                    S[i] == 'O' || S[i] == 'U')
                {
                    res += S[i];
                    wordmoder = 0;
                }
                else
                {
                    tail = S[i];
                    wordmoder = 1;
                }
            }
            else
                res += S[i];
            last = S[i];
        }
        if (wordmoder)
            res += tail;
        res += "ma";
        for (int i = 0; i < wordnum; ++i)
            res += 'a';
        return res;
    }
};

int main()
{
    string a = "I speak Goat Latin";
    Solution b;
    b.toGoatLatin(a);

    std::system("pause");
    return 0;
}