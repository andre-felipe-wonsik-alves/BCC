#include <stdio.h>

void showEven(int tamanho, int vetor[])
{
    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i] % 2 == 0)
        {
            printf("O número %d é par!\n", vetor[i]);
        }
    }
}

int main()
{
    int tamanho, valor;

    printf("Digite o tamanho do vetor:\n>> ");
    scanf("%d", &tamanho);

    int vetor[tamanho];

    for (int i = 0; i < tamanho; i++)
    {
        printf("Digite um valor a ser inserido:\n>> ");
        scanf("%d", &valor);

        vetor[i] = valor; // insert
    }

    showEven(tamanho, vetor);

    return 0;
}