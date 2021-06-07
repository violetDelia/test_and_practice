#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int count = 0;
        int l = strs.size();
        int c = strs[0].length();
        for (int i = 0; i < c; ++i)
        {
            char last = 'a' - 1;
            for (int k = 0; k < l; ++k)
            {
                if (last > strs[k][i])
                {
                    ++count;
                    break;
                }
                last = strs[k][i];
            }
        }
        return count;
    }
};

int main()
{
    vector<string> c = {"cba", "daf", "ghi"};
    Solution a;
    a.minDeletionSize(c);

    std::system("pause");
    return 0;
}