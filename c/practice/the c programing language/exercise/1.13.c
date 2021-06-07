#include <stdio.h>
#define out 0
#define in 1
#define maxsize 15
#define maxheight 10
main()
{
    int c;
    int state = in;
    int wordsize[maxsize + 1] = {
        0,
    };
    int wordlen = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            if (state == in)
            {
                if (wordlen > maxsize)
                    ++wordsize[0];
                else
                    ++wordsize[wordlen];
                wordlen = 0;
                state = out;
            }
        }
        else
        {
            state = in;
            wordlen++;
        }
    }
    int maxvalue = 0;
    for (int i = 1; i <= maxsize; ++i)
    {
        if (wordsize[i] > maxvalue)
            maxvalue = wordsize[i];
    }
    for (int i = 0; i <= maxsize; ++i)
    {
        wordsize[i] = maxheight - wordsize[i] * maxheight / maxvalue;
    }
    for (int i = 0; i < maxheight; ++i)
    {
        for (int i = 1; i <= maxsize; ++i)
        {
            if (wordsize[i] > 0)
            {
                putchar(' ');
                putchar(' ');
                --wordsize[i];
            }
            else
            {
                putchar('*');
                putchar(' ');
            }
        }
        if (wordsize[0] > 0)
        {
            putchar(' ');
            --wordsize[0];
        }
        else
            putchar('*');
        putchar('\n');
    }
    for (int i = 1; i < 10; ++i)
    {
        printf("%d ", i);
    }
    for (int i = 10; i < 16; ++i)
    {
        printf("%d", i);
    }
    printf("other");
    getchar();
}