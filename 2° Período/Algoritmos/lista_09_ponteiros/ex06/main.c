#include <stdio.h>

void print_matrix(int rows, int cols, const int *v)
{
    for (int i = 0; i < rows * cols; i++)
    {
        printf("%d ", *v);
        v++;
    }
}

int main()
{
    int v[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
    };

    int *p = (int *)v;

    print_matrix(3, 4, p);
    return 0;
}