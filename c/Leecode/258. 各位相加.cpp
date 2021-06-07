#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int addDigits(int num) {
        return (num-1)%9+1;
    }
};



int main()
{
    
    std::system("pause");
    return 0;
}