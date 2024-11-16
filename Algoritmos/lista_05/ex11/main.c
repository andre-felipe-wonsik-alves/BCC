#include <stdio.h>

void slice(int tamanho, int vetor[], int posicao)
{
    if (posicao < 0)
    {
        printf("posicao invalida\n");
    }
    int saida = (posicao < tamanho) && (posicao > 0) ? vetor[posicao] = -1 : printf("Posicao invalida\n");
    // for (int i = 0; i < tamanho; i++)
    // {
    //     printf("%d\n", vetor[i]);
    // }
}

int main()
{
    int posicao;
    int lista[9] = {1, 6, 1, 9, 4, 1, 1, 2, 1};

    printf("Digite a posição a ser removida: \n>> ");
    scanf("%d", &posicao);

    slice(9, lista, posicao);

    return 0;
}