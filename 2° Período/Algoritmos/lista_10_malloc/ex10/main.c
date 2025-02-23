#include <stdio.h>
#include <stdlib.h>

int **transpose(int m, int n, int v[m][n])
{
    int **transposed = (int **)malloc(n * sizeof(int *));
    if (transposed == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < n; i++)
    {
        transposed[i] = (int *)malloc(m * sizeof(int));
        if (transposed[i] == NULL)
        {
            for (int j = 0; j < i; j++)
            {
                free(transposed[j]);
            }
            free(transposed);
            return NULL;
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            transposed[j][i] = v[i][j];
        }
    }

    return transposed;
}

int main()
{
    int m = 3, n = 2;
    int v[3][2] = {{1, 2}, {3, 4}, {5, 6}};

    int **transposed = transpose(m, n, v);
    if (transposed == NULL)
    {
        return 1;
    }

    printf("Original matrix:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }

    printf("Transposed matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", transposed[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++)
    {
        free(transposed[i]);
    }
    free(transposed);

    return 0;
}