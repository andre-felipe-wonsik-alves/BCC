#include <stdio.h>
#include <string.h>

int len(char string[])
{
    int contador = 0;
    for (int i = 0; string[i] != '\0'; i++)
    {
        contador++;
    }
    return contador;
}

void stringReversed(char string[])
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        printf("%c ", string[(strlen(string) - 1) - i]);
    }
    printf("\n");
}

int main()
{
    char string[] = "andrezao";

    stringReversed(string);

    return 0;
}