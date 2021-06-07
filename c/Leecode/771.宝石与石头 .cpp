int numJewelsInStones(char *jewels, char *stones)
{
    int n = 0;
    for (int i = 0; jewels[i] != '\0'; i++)
    {
        for (int k = 0; stones[k] != '\0'; k++)
        {
            if (jewels[i] == stones[k])
                n++;
        }
    }
    return n;
}