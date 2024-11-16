#include <stdio.h>

void count(int tamanho, int vetor[])
{
    int count[tamanho];

    for (int i = 0; i < tamanho; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i] == count[i])
        {
            count[i] += 1;
        }
        printf("%d ", count[i]);
    }
}

int main()
{
    int vet[] = {1, 2, 3, 2, 4};
    count(4, vet);

    return 0;
}