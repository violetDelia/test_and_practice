#include <iostream>
#include <stdio.h>
using namespace std;
typedef unsigned int uint32_t;

uint32_t reverseBits(uint32_t n)
{
    uint32_t res = 0;
    for (int i = 0; i < 32 && n > 0; i++)
    {
        res |= (n & 1) << (31 - i);
        n >>= 1;
    }
    return res;
}

int main()
{
    
    
    std::cout << "8";
    std::system("pause");
    return 0;
}