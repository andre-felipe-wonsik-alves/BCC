#include <stdio.h>

int strCompare(char strA[], char strB[])
{
    int sizeA = 0, sizeB = 0;

    for (int i = 0; strA[i] != '\0'; i++)
    {
        sizeA++;
    }
    for (int i = 0; strB[i] != '\0'; i++)
    {
        sizeB++;
    }

    if (sizeA == sizeB)
        return 0;
    int res = sizeA > sizeB ? -1 : 1;
    return res;
}

int main()
{
    char string1[] = "abelha";
    char string2[] = "abElha";

    int res = strCompare(string1, string2);
    printf("%d\n", res);

    return 0;
}