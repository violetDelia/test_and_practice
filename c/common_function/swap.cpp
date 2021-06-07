void swap(int &a, int &b)
{
    int tep = a;
    a = b;
    b = tep;
}

void swap(int *a, int *b)
{
    int tep = *a;
    *a = *b;
    *b = tep;
}