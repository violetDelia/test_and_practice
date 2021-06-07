#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int isup = 1;
        for (char c : word)
        {
            if (isupper(c))
            {
                if (isup == 0)
                    return false;
            }else
            {
                isup = 0;
            }
            
        }
        if(isup==0&&isupper(word[1]))
            return false;
        return true;
    }
};

int main()
{

    std::system("pause");
    return 0;
}