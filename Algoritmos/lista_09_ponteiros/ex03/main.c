#include <stdio.h>

void print_vector(int size, const int *v)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *v);
        v++;
    }
    printf("\n");
}

int main()
{
    int v[4] = {1, 2, 3, 4};
    int *p1 = v;

    print_vector(4, p1);
    return 0;
}