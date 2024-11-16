#include <stdio.h>

void readVector(int tamanho, int vetor[])
{
    printf("[");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("]\n");
}

int main()
{
    int tamanho, numero, elemento;

    printf("Tamanho: \n>> ");
    scanf("%d", &tamanho);

    int vetor[tamanho];

    for (int i = 0; i < tamanho; i++)
    {
        printf("Valor a ser adicionado: \n>> ");
        scanf("%d", &numero);
        vetor[i] = numero;
    }

    readVector(tamanho, vetor);

    return 0;
}