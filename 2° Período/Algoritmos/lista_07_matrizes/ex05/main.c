#include <stdio.h>

void init_values(int rows, int cols, int m[rows][cols], int start, int step)
{
    printf("\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            m[i][j] = start;
            printf("%d  ", m[i][j]);
            start += step;
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int v[4][6];
    init_values(4, 6, v, 10, 2);

    return 0;
}