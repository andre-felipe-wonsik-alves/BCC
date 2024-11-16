#include <stdio.h>

float calcularMedia(float soma, float quantidadeEntrada)
{
    return soma / quantidadeEntrada;
}

int main()
{
    int entrada, soma = 0, quantidadeEntrada = 1;
    float media;
    printf("Digite um valor de entrada ( 0 quebra o laço! ):\n> ");
    scanf("%d", &entrada);

    while (entrada != 0)
    {
        soma += entrada;
        media = calcularMedia(soma, quantidadeEntrada);

        printf("Digite outro valor de entrada ( 0 quebra o laço! ):\n> ");
        scanf("%d", &entrada);

        quantidadeEntrada++;
    }

    printf("SOMA: %d\nMEDIA: %.2ff\n", soma, media);

    return 0;
}