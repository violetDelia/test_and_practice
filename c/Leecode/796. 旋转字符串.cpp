#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool rotateString(string A, string B)
    {
        if (A.length() != B.length())
            return false;
        int l = A.length();
        if (!l)
            return true;
        for (int i = 0; i < l; ++i)
        {
            if (B[i] == A[0])
            {
                int k = 1;
                for (; k < l; ++k)
                {
                    if (B[(i + k) % l] != A[k])
                        break;
                }
                if (k == l)
                    return true;
            }
        }
        return false;
    }
};

int main()
{

    std::system("pause");
    return 0;
}