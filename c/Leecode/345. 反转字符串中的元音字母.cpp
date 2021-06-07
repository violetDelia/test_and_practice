#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    string reverseVowels(string s)
    {
        vector<int> position;
        vector<char> elem;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
                s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                elem.emplace_back(s[i]);
                position.emplace_back(i);
            }
        }
        for (int i = 0; i < position.size(); ++i)
        {
            s[position[i]] = elem[elem.size() - 1 - i];
        }
        return s;
    }
};
int main()
{
    Solution a;
    a.reverseVowels("hello");
    std::system("pause");
    return 0;
}