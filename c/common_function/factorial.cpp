#include <iostream>
#include <vector>
using namespace std;
int My_factorial(int n);

int main()
{My_factorial(3);

    std::system("pause");
    return 0;
}

int My_factorial(int n)
{
    if (n > 1)
        n *= My_factorial(n - 1);
    return n;
}