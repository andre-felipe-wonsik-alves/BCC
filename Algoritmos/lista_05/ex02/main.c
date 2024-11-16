#include <stdio.h>

void mod(int tamanho, int vetor[])
{
    printf("Vetor após o módulo: { ");
    for (int i = 0; i < tamanho; i++)
    {
        vetor[i] = vetor[i] < 0 ? vetor[i] * -1 : vetor[i];
        printf("%d ", vetor[i]);
    }
    printf("}\n");
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

    mod(tamanho, vetor);

    return 0;
}