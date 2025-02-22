#include <stdio.h>

int check_upper_triangle(int d, int m[d][d])
{
    for (int row = 0; row < d; row++)
    {
        for (int col = 0; col < row; col++)
        {
            if (m[row][col] != 0)
            {
                return 0; // false
            }
        }
    }
    return 1; // true
}

int main()
{
    int d = 3;
    int matrix[3][3] = {
        {1, 2, 3},
        {0, 5, 6},
        {0, 0, 9}};

    printf("%d\n", check_upper_triangle(d, matrix));

    return 0;
}