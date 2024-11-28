#include <stdio.h>

void minMax(int rows, int columns, int m[rows][columns])
{
    int biggest = m[0][0], lowest = m[0][0];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (m[i][j] > biggest)
            {
                biggest = m[i][j];
            }
            else if (m[i][j] < lowest)
            {
                lowest = m[i][j];
            }
        }
    }

    printf("\nMAIOR: %d\nMENOR: %d\n", biggest, lowest);
}

int main()
{
    int mat[3][3] = {
        {1, 2, 3},
        {4, 29, 6},
        {-7, 8, 9}};

    minMax(3, 3, mat);

    return 0;
}