#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    string removeDuplicates(string S)
    {
        string res = "";
        for (int i = 0; i < S.size(); ++i)
        {
            if (res.size() == 0 || S[i] != res[res.size() - 1])
                res.push_back(S[i]);
            else
               res.pop_back();
        }
        return res;
    }
};

int main()
{
    Solution a;
    a.removeDuplicates("abbaca");
    std::system("pause");
    return 0;
}