#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int count = 0;
        char last = ' ';
        for (char a : s)
        {
            if (a != ' ')
            {
                if (last == ' ')
                    count = 1;
                else
                    ++count;
            }
            last = a;
        }
        return count;
    }
};

int main()
{

    std::system("pause");
    return 0;
}