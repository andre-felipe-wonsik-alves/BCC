#include <stdio.h>

void merge(int n1, int v1[], int n2, int v2[], int v3[])
{
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2)
    {
        if (v1[i] < v2[j])
        {
            v3[k++] = v1[i++];
        }
        else
        {
            v3[k++] = v2[j++];
        }
    }

    while (i < n1)
    {
        v3[k++] = v1[i++];
    }

    while (j < n2)
    {
        v3[k++] = v2[j++];
    }
}

int main()
{
    int v1[] = {1, 3, 5, 7};
    int v2[] = {2, 4, 6, 8, 10};
    int n1 = 4;
    int n2 = 5;
    int v3[n1 + n2];

    merge(n1, v1, n2, v2, v3);

    printf("Vetor mesclado ordenado: ");
    for (int i = 0; i < n1 + n2; i++)
    {
        printf("%d ", v3[i]);
    }
    printf("\n");

    return 0;
}