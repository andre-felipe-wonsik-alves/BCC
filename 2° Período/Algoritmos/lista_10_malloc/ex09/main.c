#include <stdio.h>
#include <stdlib.h>

int **create_vector2D(int m, int n)
{
    int **matrix = (int **)malloc(m * sizeof(int *));
    if (matrix == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < m; i++)
    {
        matrix[i] = (int *)malloc(n * sizeof(int));
        if (matrix[i] == NULL)
        {
            for (int j = 0; j < i; j++)
            {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
    }

    int value = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = value++;
        }
    }

    return matrix;
}

int main()
{
    int m = 3, n = 4;
    int **matrix = create_vector2D(m, n);

    if (matrix != NULL)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }

        for (int i = 0; i < m; i++)
        {
            free(matrix[i]);
        }
        free(matrix);
    }
    else
    {
        printf("Falha na alocação de memória\n");
    }

    return 0;
}