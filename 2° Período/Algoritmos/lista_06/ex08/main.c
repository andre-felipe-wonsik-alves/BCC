#include <stdio.h>

int comp(const char str1[], const char str2[])
{
    for (int i = 0; str1[i] != '\0'; i++)
    {
        if (str1[i] > str2[i])
        {
            return 1;
        }
        else if (str1[i] < str2[i])
        {
            return -1;
        }
    }

    return 0;
}

int main()
{
    char s[] = "cebola";
    char s2[] = "cebola";

    int res = comp(s, s2);
    printf("%d\n", res);

    return 0;
}