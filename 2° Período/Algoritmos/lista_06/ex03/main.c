#include <stdio.h>

void stringReport(char s[])
{
    int letras = 0, digitos = 0, simbolos = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if ((s[i] <= 90) && (s[i] >= 65) || (s[i] <= 122) && (s[i] >= 97))
        {
            letras++;
        }
        else if ((s[i] <= 57) && (s[i] >= 48))
        {
            digitos++;
        }
        else
        {
            simbolos++;
        }
    }

    printf("LETRAS: %d\nDÍGITOS: %d\nSÍMBOLOS: %d\n", letras, digitos, simbolos);
}

int main()
{
    char string[] = "abcd52--?";

    stringReport(string);

    return 0;
}