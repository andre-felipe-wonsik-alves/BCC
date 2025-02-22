#include <stdio.h>

int isIdentityMatrix(int matrix[][3], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == j && matrix[i][j] != 1)
            {
                return 0;
            }
            else if (i != j && matrix[i][j] != 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int matrix[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}};

    printf("%d\n", isIdentityMatrix(matrix, 3));

    return 0;
}