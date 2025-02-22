#include <stdio.h>

void switch_diagonals(int size, int m1[size][size])
{
    for (int i = 0; i < size; i++)
    {
        int temp = m1[i][i];
        m1[i][i] = m1[i][size - i - 1];
        m1[i][size - i - 1] = temp;
    }
}

void print_matrix(int d, int m1[d][d])
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            printf("%d ", m1[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int d = 4;
    int matrix[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    print_matrix(d, matrix);

    switch_diagonals(d, matrix);

    print_matrix(d, matrix);

    return 0;
}