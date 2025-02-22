#include <stdio.h>
#include <math.h>

void printDistance(int tamanho, int vetorPontos[])
{
    double distFinal = 0, distIntermed = 1;
    for (int i = 0; i < tamanho; i += 4)
    {
        printf("[%d, %d][%d, %d] é: %d\n", vetorPontos[i], vetorPontos[i + 1], vetorPontos[i + 2], vetorPontos[i + 3], distIntermed);
        distIntermed = (vetorPontos[i + 2] - vetorPontos[i]) * (vetorPontos[i + 2] - vetorPontos[i]) + (vetorPontos[i + 3] - vetorPontos[i + 1]) * (vetorPontos[i + 3] - vetorPontos[i + 1]);
        distIntermed = sqrt(distIntermed);
        printf("Distância entre os pontos [%d, %d][%d, %d] é: %d\n", vetorPontos[i], vetorPontos[i + 1], vetorPontos[i + 2], vetorPontos[i + 3], distIntermed);
    }
}

int main()
{
    int tamanho, entrada;

    printf("Digite o tamanho do array: \n>>");
    scanf("%d", &tamanho);

    int vetor[tamanho];

    for (int i = 0; i < tamanho / 2; i++)
    {
        printf("Digite o %dX valor a ser inserido:\n>> ");
        scanf("%d", &entrada);
        vetor[i] = entrada;
        printf("Digite o %dY valor a ser inserido:\n>> ");
        scanf("%d", &entrada);
        vetor[i] = entrada;
    }

    printDistance(tamanho, vetor);

    return 0;
}