#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool isLongPressedName(string name, string typed)
    {
        int p = 0;
        char last = 'a' - 1;
        for (int i = 0; i < typed.size(); ++i)
        {
            if (typed[i] == name[p])
            {
                ++p;
            }
            else if (typed[i] != last)
                return false;
            last = typed[i];
        }
        if (p == name.size() - 1)
            return true;
        return false;
    }
};

int main()
{

    std::system("pause");
    return 0;
}