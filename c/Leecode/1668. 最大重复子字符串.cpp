#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxRepeating(string sequence, string word)
    {
        int res = 0;
        int l = word.length();
        for (int i = 0; i < sequence.length();)
        {
            if (sequence[i] == word[0])
            {
                int p = i + 1;
                int count = 1;
                while (p < sequence.length() &&
                       sequence[p] == word[count % l])
                {
                    ++p;
                    ++count;
                }
                res = res > count / l ? res : count / l;
            }
        }
        return res;
    }
};

int main()
{

    std::system("pause");
    return 0;
}