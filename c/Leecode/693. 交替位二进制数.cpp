#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        int last = n & 1;
        n >>= 1;
        while(n){
            int rear = n&1;
            if(rear == last)
                return false;
            last = rear;
            n >>= 1;
        }
        return true;
    }
};
int main()
{
    std::system("pause");
    return 0;
}