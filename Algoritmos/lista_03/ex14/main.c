#include <stdio.h>

int calcularMDC(int numero1, int numero2)
{
    int menor = (numero1 < numero2) ? numero1 : numero2;

    for (int divisor = menor; divisor >= 2; divisor--)
    {
        if (numero1 % divisor == 0 && numero2 % divisor == 0)
        {
            return divisor;
        }
    }

    return 1;
}

int main()
{
    int numero1, numero2;

    printf("Digite dois números inteiros positivos:\n>> ");
    scanf("%d %d", &numero1, &numero2);

    int mdc = calcularMDC(numero1, numero2);

    printf("O MDC de %d e %d é: %d\n", numero1, numero2, mdc);

    return 0;
}
