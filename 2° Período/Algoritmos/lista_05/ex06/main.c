#include <stdio.h>

int isSorted(int tamanho, int vetor[])
{
    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i] > vetor[i + 1] && i != tamanho - 1)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int tamanho, entrada;

    printf("Digite o tamanho do vetor:\n>> ");
    scanf("%d", &tamanho);

    int vetor[tamanho];
    for (int i = 0; i < tamanho; i++)
    {
        printf("Digite o %dº valor a ser inserido: \n>> ", i + 1);
        scanf("%d", &entrada);
        vetor[i] = entrada;
    }

    int res = isSorted(tamanho, vetor);
    if (res)
    {
        printf("Está em ordem crescente!\n");
        return 0;
    }
    printf("Não está em ordem crescente!\n");
    return 0;
}