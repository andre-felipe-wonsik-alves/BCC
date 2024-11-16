#include <stdio.h>

int main()
{
    int numero, soma = 0, contador = 0;

    printf("Digite um número para saber seu quadrado perfeito: \n> ");
    scanf(" %d", &numero);

    while (contador <= numero)
    {
        if (contador % 2 != 0)
        {
            soma += contador;
        };
        contador++;
    }

    printf("O quadrado perfeito é: %d\n", soma);
    return 0;
}