#include <stdio.h>

int isSymmetric(int matrix[][100], int d)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (matrix[i][j] != matrix[j][i])
            {
                return 0; // false
            }
        }
    }
    return 1; // true
}

int main()
{
    int d;
    printf("Tamanho da matriz: ");
    scanf("%d", &d);

    int matrix[100][100];
    printf("Elementos:\n");
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("%d\n", isSymmetric(matrix, d));

    return 0;
}