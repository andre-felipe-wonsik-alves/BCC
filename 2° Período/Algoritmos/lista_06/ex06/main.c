#include <stdio.h>

int countWords(char str[])
{
    int hadSpace = 1, quantidadePalavras = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] == ' '))
        {
            hadSpace = 1;
        }
        if ((str[i] < 'z' && str[i] > 'a') && hadSpace)
        {
            quantidadePalavras++;
            hadSpace = 0;
        }
    }

    return quantidadePalavras;
}

int main()
{
    char s[] = "    first things first, second things latter ";
    int res = countWords(s);
    printf("res: %d\n", res);
    return 0;
}