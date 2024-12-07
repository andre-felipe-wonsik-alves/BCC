#include <stdio.h>

float avg(int rows, int cols, int m[rows][cols])
{
    int avg, soma = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            soma += m[i][j];
        }
    }

    avg = soma / (rows * cols);

    return avg;
}

int main()
{
    int m[3][3] = {
        {10, 1, 1},
        {1, 1, 1},
        {1, 10, 1},
    };

    printf("\nMEDIA: %f\n", avg(3, 3, m));

    return 0;
}