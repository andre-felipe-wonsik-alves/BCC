#include <stdio.h>

int ePalindromo(int numero)
{
    int numOriginal = numero;
    int numInvertido = 0, ultimoDigito;

    while (numero > 0)
    {
        ultimoDigito = numero % 10;
        numInvertido = numInvertido * 10 + ultimoDigito;
        numero /= 10;
    }

    if (numOriginal == numInvertido)
    {
        return 1;
    }

    return 0;
}

int main()
{
    int entrada;

    printf("Digite um número para saber se é palíndromo: \n> ");
    scanf("%d", &entrada);

    if (ePalindromo(entrada))
    {
        return printf("Palíndromo!\n");
    }
    printf("Não é Palíndromo!\n");

    return 0;
}