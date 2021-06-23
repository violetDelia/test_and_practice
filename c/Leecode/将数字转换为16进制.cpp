#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    string toHex(int num)
    {
        string res = "";
        char op[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        if (num == 0)
            return "0";
        for (int i = 0; i < 8; i++)
        {
            res = op[num & 0xF] + res;
            num >>= 4;
        }
        int j;
        for (j = 0; j < 8; j++)
        {
            if (res[j] != '0')
                break;
        }
        if(j != 9)
            res.erase(res.begin(),res.begin()+j);
        return res;
    }
};
int main()
{
    Solution a;
    a.toHex(INT_MIN);
    std::system("pause");
    return 0;
}