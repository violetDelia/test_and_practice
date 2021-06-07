#include <iostream>
#include <stdio.h>
using namespace std;
int hammingDistance(int x, int y)
{
    int distance = 0;
    while (x || y)
    {
        int a = x&1;
        int b = y&1;
        if (a!=b)
            distance++;
        x = x/2;
        y = y/2;
    }
    return distance;
}
int main()
{
    hammingDistance(1, 4);

    std::system("pause");
    return 0;
}