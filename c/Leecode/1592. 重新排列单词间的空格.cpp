#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    string reorderSpaces(string text)
    {
        int word = 0;
        int count = 0;
        char last = 'a';
        for (char c : text)
        {
            if (c == ' ')
                count++;
            else if (last == ' ')
                word++;
            last = c;
        }
        string res = "";
        if (text[0] != ' ')
            word++;
        int more, space;
        if (word <= 1)
        {
            space = 0;
            more = count;
        }
        else
        {
            more = count % (word - 1);
            space = count / (word - 1);
        }
        int i = 0;
        for (; i < text.length(); ++i)
        {
            if (text[i] != ' ')
            {
                last = text[i];
                break;
            }
        }
        res += text[i++];
        for (; i < text.length(); ++i)
        {
            if (text[i] != ' ')
            {
                if (last == ' ')
                {
                    for (int i = 0; i < space; ++i)
                    {
                        res += ' ';
                    }
                }
                res += text[i];
            }
            last = text[i];
        }
        for (int i = 0; i < more; ++i)
            res += ' ';
        return res;
    }
};

int main()
{
    string a =

        "  this   is  a sentence ";
    Solution b;
    b.reorderSpaces(a);
    std::system("pause");
    return 0;
}