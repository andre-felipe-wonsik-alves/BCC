#include <stdio.h>
#include <stdlib.h>

int *create_vector(int size)
{
    int *v = malloc(size * sizeof(int));
    if (v == NULL)
        return 0;
    for (int i = 0; i < size; i++)
    {
        v[i] = 0;
    }

    return v;
}

void print_vector(int size, int *vector)
{
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

int main()
{
    int *v1 = create_vector(7);
    print_vector(7, v1);
    free(v1);
    v1 = NULL;
    return 0;
}