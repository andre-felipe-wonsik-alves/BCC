#include <stdio.h>
int matrix_equals(int r1, int c1, int m1[r1][c1], int r2, int c2, int m2[r2][c2])
{
    if (r1 != r2 || c1 != c2)
    {
        return 0;
    }

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            if (m1[i][j] != m2[i][j])
            {
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
    int m1[3][3] = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1},
    };
    int m2[3][3] = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1},
    };
    int m3[3][3] = {
        {1, 1, 1},
        {1, 2, 1},
        {1, 1, 1},
    };
    int m4[3][2] = {
        {1, 1},
        {1, 1},
        {1, 1},
    };

    int res1 = matrix_equals(3, 3, m1, 3, 3, m2);
    int res2 = matrix_equals(3, 3, m3, 3, 2, m4);

    printf("res1: %d\nres2: %d\n", res1, res2);

    return 0;
}