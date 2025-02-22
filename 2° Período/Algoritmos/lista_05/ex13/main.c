#include <stdio.h>

void concat(int tamanhoA, int v1[], int tamanhoB, int v2[], int v3[])
{
    int posParada, j = 0;
    for (int i = 0; i < tamanhoA + tamanhoB; i++)
    {
        if (i < tamanhoA)
        {
            v3[i] = v1[i];
        }
        else
        {
            v3[i] = v2[j];
            j++;
        }
    }
}

int main()
{
    int v1[5] = {1, 2, 3, 4, 5};
    int v2[3] = {2, 3, 8};
    int v3[8];

    concat(5, v1, 3, v2, v3);
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", v3[i]);
    }
    printf("\n");
    return 0;
}