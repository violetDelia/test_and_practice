#include <array>
#include <cstddef>
#include <exception>
#include <iostream>
#include <my_head.hpp>
#include <new>
#include <type_traits>
#include <vector>

void test_nullptr_t(){};
void f(int *)
{
    std::cout << "Pointer to integer overload\n";
}

void f(double *)
{
    std::cout << "Pointer to double overload\n";
}

void f(my_std::nullptr_t)
{
    std::cout << "null pointer overload\n";
}

int main()
{
    int *pi{};
    double *pd{};

    f(pi);
    f(pd);
    f(nullptr);
    std::system("pause");
}