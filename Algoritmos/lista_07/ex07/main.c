#include <stdio.h>

int max_line(int row, int col, int m[row][col])
{
    int soma = 0, maior;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            soma += m[i][j];
        }
        if ((i == 0) || (soma > maior))
        {
            maior = soma;
        }
        soma = 0;
    }
    return maior;
}

int main()
{
    int mat[5][5] = {
        {1, 2, 3, 4, 5},
        {2, 4, 6, 8, 10},
        {1, 2, 3, 4, 7},
        {2, 0, 60, 1, 10},
        {7, 3, 4, 0, 0},
    };
    int res = max_line(5, 5, mat);
    printf("Maior soma: %d\n", res);

    return 0;
}