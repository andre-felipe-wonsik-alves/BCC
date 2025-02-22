#include <stdio.h>

void vector_union(int tamanhoA, int v1[], int tamanhoB, int v2[], int v3[])
{
    int k = 0;

    for (int i = 0; i < tamanhoA; i++)
    {
        v3[k++] = v1[i];
    }

    for (int i = 0; i < tamanhoB; i++)
    {
        int exists = 0;

        for (int j = 0; j < k; j++)
        {
            if (v3[j] == v2[i])
            {
                exists = 1;
                break;
            }
        }

        if (!exists)
        {
            v3[k++] = v2[i];
        }
    }

    while (k < tamanhoA + tamanhoB)
    {
        v3[k++] = 0;
    }
}

int main()
{
    int v1[5] = {1, 2, 3, 4, 5};
    int v2[3] = {2, 3, 8};
    int v3[8] = {0};

    vector_union(5, v1, 3, v2, v3);

    printf("v3: {");
    for (int i = 0; i < 8; i++)
    {
        printf("%d", v3[i]);
        if (i < 7)
        {
            printf(", ");
        }
    }
    printf("}\n");

    return 0;
}
