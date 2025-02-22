#include <stdio.h>

void pascal_triangle(int n)
{
    int m[n][n + 1];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            m[i][j] = 0;
        }
    }

    m[0][1] = 1;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 1; j <= i + 1; j++)
        {
            m[i + 1][j] += m[i][j];
            m[i + 1][j + 1] += m[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= i + 1; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n = 3;
    pascal_triangle(n);
    return 0;
}