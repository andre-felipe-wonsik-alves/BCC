#include <stdio.h>

int comp(const char str1[], const char str2[])
{
    int tamanho1 = 0, tamanho2 = 0;
    for (int i = 0; str1[i] != '\0'; i++)
    {
        tamanho1++;
    }
    for (int i = 0; str2[i] != '\0'; i++)
    {
        tamanho2++;
    }

    if(tamanho1 < tamanho2) return -1;
    if(tamanho1 == tamanho2) return 0;
    if(tamanho1 < tamanho2) return 1;

    for (int i = 0; str1[i] != '\0'; i++)
    {
        /* code */
    }

    return 0;
}

int main()
{
    return 0;
}