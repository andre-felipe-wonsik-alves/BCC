#include <stdio.h>

void dividirNumero(int controleLaco)
{
    int numero;
    printf("Inicial: %d\n", controleLaco);
    while (controleLaco > 0)
    {
        numero = controleLaco % 10;
        controleLaco = controleLaco / 10;
        printf("Origem: %d     |||     Desmontado: %d\n", controleLaco, numero);
    }
}

int main()
{
    int numero;

    printf("Digite um número para ser dividido: \n> ");
    scanf("%d", &numero);

    dividirNumero(numero);

    return 0;
}