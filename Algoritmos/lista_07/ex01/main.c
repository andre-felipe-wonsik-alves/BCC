#include <stdio.h>

void printMatriz(int linhas, int colunas, int m[linhas][colunas])
{
    printf("\n");
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("%d, ", m[i][j]);
        }
    }
    printf("\n");
}

int main()
{
    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    printMatriz(3, 3, mat);
    return 0;
}