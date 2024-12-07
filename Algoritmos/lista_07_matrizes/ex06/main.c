#include <stdio.h>
#include <stdlib.h>

void initRandom(int row, int col, int m[row][col], int min, int max)
{
    int random;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            m[i][j] = rand() % (max - 2 * min);
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int v[4][6];
    int min = 5, max = 50;
    initRandom(4, 6, v, min, max);

    return 0;
}