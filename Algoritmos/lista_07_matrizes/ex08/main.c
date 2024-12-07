#include <stdio.h>

void sumPerRow(int rows, int cols, int m[rows][cols])
{
    int soma = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            soma += m[i][j];
        }
        m[i][cols - 1] = soma;
        soma = 0;
    }
}

int main()
{
    int mat[4][5] = {
        {1, 2, 3, 4, 0},
        {2, 4, 6, 8, 0},
        {3, 6, 9, 12, 0},
        {4, 8, 12, 16, 0},
    };

    sumPerRow(4, 5, mat);

    return 0;
}