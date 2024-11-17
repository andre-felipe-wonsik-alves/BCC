#include <stdio.h>

void vector_intersection(int tamanhoA, int v1[], int tamanhoB, int v2[], int v3[])
{
    int k = 0;

    for (int i = 0; i < tamanhoA; i++)
    {
        for (int j = 0; j < tamanhoB; j++)
        {
            if (v1[i] == v2[j])
            {

                int exists = 0;
                for (int l = 0; l < k; l++)
                {
                    if (v3[l] == v1[i])
                    {
                        exists = 1;
                        break;
                    }
                }

                if (!exists)
                {
                    v3[k++] = v1[i];
                }
                break;
            }
        }
    }

    while (k < (tamanhoA < tamanhoB ? tamanhoA : tamanhoB))
    {
        v3[k++] = 0;
    }
}

int main()
{
    int v1[5] = {1, 2, 3, 4, 5};
    int v2[3] = {2, 3, 8};
    int v3[3] = {0};

    vector_intersection(5, v1, 3, v2, v3);

    printf("v3: {");
    for (int i = 0; i < 3; i++)
    {
        printf("%d", v3[i]);
        if (i < 2)
        {
            printf(", ");
        }
    }
    printf("}\n");

    return 0;
}
