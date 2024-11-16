#include <stdio.h>

int findMax(int tamanho, int vetor[])
{
    int maior;

    for (int i = 0; i < tamanho; i++)
    {
        if (!i)
        {
            maior = vetor[i] < vetor[i + 1] ? vetor[i + 1] : vetor[i];
        }
        else if (i != tamanho - 1 && !tamanho)
        {
            maior = vetor[i] < maior ? maior : vetor[i];
        }
        else
        {
            maior = maior < vetor[tamanho - 1] ? vetor[tamanho - 1] : maior;
        }
        printf("%d\n", maior);
    }
    return maior;
}

int main()
{
    int tamanho, entrada;

    printf("Tamanho do vetor:\n>> ");
    scanf("%d", &tamanho);

    int vetor[tamanho];

    for (int i = 0; i < tamanho; i++)
    {
        printf("Valor a ser inserido:\n>> ");
        scanf("%d", &entrada);
        vetor[i] = entrada;
    }

    int maior = findMax(tamanho, vetor);

    printf("O maior é valor no array é: %d\n\n", maior);
    return 0;
}