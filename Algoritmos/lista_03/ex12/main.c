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

int main()
{
    int numero;

    printf("Digite um número para saber se é primo: \n> ");
    scanf("%d", &numero);

    numero = ePrimo(numero);
    if (numero)
    {
        printf("É primo!\n");
        return 0;
    }
    printf("Não é primo!\n");
    return 0;
}