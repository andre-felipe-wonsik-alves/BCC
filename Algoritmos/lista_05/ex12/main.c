#include <stdio.h>

void defrag(int tamanho, int vetor[])
{
    int j = 0;

    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i] != -1)
        {
            vetor[j] = vetor[i];
            j++;
        }
    }

    for (int i = j; i < tamanho; i++)
    {
        vetor[i] = -1;
    }
}

int main()
{
    int v[9] = {1, 6, -1, 9, 4, -1, -1, 2, -1};

    defrag(9, v);

    printf("Vetor desfragmentado: ");
    for (int i = 0; i < 9; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}