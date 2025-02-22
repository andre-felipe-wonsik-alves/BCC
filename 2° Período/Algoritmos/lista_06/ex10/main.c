#include <stdio.h>
#include <string.h>

void trim(char str[])
{
    int quantidadeEspaco = 0;
    while (str[quantidadeEspaco] == ' ')
    {
        quantidadeEspaco++;
    }

    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = str[i + quantidadeEspaco];
    }

    // for (int i = strlen(str) - 1; i > 0; i--)
    // {
    //     if (str[i] == ' ' && str[i - 1] != ' ')
    //     {
    //         printf("%c\n", str[i]);
    //         str[i + 1] = '\0';
    //     }
    // }
}

int main()
{
    char s[] = "                        fala fi         ";
    trim(s);

    printf("%s\n", s);

    return 0;
}