#include <stdio.h>
#include <string.h>

int tem_espaco(char c)
{
    return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v';
}

int tem_letra(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

void corrigir_nome(char nome[])
{
    int i, j = 0;
    int len = strlen(nome);
    char temp[len + 1];

    while (tem_letra(nome[j]))
    {
        j++;
    }

    int inicio_palavra = 1;
    for (i = 0; j < len; j++)
    {
        if (tem_letra(nome[j]))
        {
            if (inicio_palavra)
            {
                temp[i++] = nome[j] >= 'a' && nome[j] <= 'z' ? nome[j] - 32 : nome[j];
                inicio_palavra = 0;
            }
            else
            {
                temp[i++] = nome[j] >= 'A' && nome[j] <= 'Z' ? nome[j] + 32 : nome[j];
            }
        }
        else if (tem_espaco(nome[j]))
        {
            if (i > 0 && !tem_espaco(temp[i - 1]))
            {
                temp[i++] = ' ';
                inicio_palavra = 1;
            }
        }
    }

    if (i > 0 && tem_espaco(temp[i - 1]))
    {
        i--;
    }

    temp[i] = '\0';
    strcpy(nome, temp);
}

int main()
{
    char nome[] = "  jOhN   doE  ";
    corrigir_nome(nome);
    printf("Nome corrigido: '%s'\n", nome);
    return 0;
}