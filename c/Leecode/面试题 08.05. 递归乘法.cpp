#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int multiply(int A, int B)
    {
        if (A && B)
        {
            if (A >= B)
                return A + multiply(A, B - 1);
            else
                return B + multiply(A - 1, B);
        }
        return 0;
    }
};
int main()
{

    std::system("pause");
    return 0;
}