#include <iostream>
#include <vector>
using namespace std;
void memory_dump(void *ptr, int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        if (i % 8 == 0 && i != 0)
            printf(" ");
        if (i % 16 == 0 && i != 0)
            printf("\n");
        printf("%02x ", *((uint8_t *)ptr + i));
    }
    printf("\n");
}

int main()
{

    std::system("pause");
    return 0;
}