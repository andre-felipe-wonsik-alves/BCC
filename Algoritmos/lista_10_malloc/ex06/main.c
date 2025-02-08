#include <stdio.h>
#include <stdlib.h>

int *array_union(int n1, const int *v1, int n2, const int *v2)
{
    int *pointer = malloc((n1 + n2) * sizeof(int));

    for (int i = 0; i < n1; i++)
    {
        pointer[i] = v1[i];
    }

    int test = n1;

    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            if (pointer[j] != v2[i])
            {
                pointer[test] = v2[i];
                test++;
            }
        }
    }

    return pointer;
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
    int str1[] = {1, 2, 3, 4};
    int str2[] = {3, 6, 7};

    int *p = array_union(4, str1, 3, str2);

    print_vector(7, p);

    free(p);
    return 0;
}