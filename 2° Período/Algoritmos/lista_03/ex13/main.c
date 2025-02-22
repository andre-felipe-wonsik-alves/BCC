#include <stdio.h>

int ePrimo(int numero)
{
    int contador = 2, saida;
    while (contador < numero)
    {
        saida = numero % contador ? 1 : 0;
        if (!saida)
        {
            return saida;
        }
        contador++;
    }
    return saida;
}

void fatorarNumero(int numero)
{
    int proximoPrimo = 13;
    while (numero > 1)
    {
        if (numero % 2 == 0)
        {
            numero /= 2;
            printf("Fator 2\n");
        }
        else if (numero % 3 == 0)
        {
            numero /= 3;
            printf("Fator 3\n");
        }
        else if (numero % 5 == 0)
        {
            numero /= 5;
            printf("Fator 5\n");
        }
        else if (numero % 7 == 0)
        {
            numero /= 7;
            printf("Fator 7\n");
        }
        else if (numero % 11 == 0)
        {
            numero /= 11;
            printf("Fator 11\n");
        }
        else if ((numero % proximoPrimo == 0) && ePrimo(proximoPrimo))
        {
            printf("Fator %d", proximoPrimo);
            proximoPrimo++;
        }
        else
        {
            proximoPrimo++;
        }
    }
    return;
}

int main()
{
    int entrada;

    printf("Digite um número para ser fatorado:\n>>");
    scanf("%d", &entrada);

    fatorarNumero(entrada);
    return 0;
}