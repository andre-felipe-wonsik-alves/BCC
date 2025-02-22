#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void print_vector(int size, int *vector)
{
    printf("\n{");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", vector[i]);
    }
    printf("}\n");
}

int *getLargest(int size, int *vector, int max)
{
    int test = INT_MIN;
    int *biggestNumbers = malloc(max * sizeof(int));

    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (vector[j] > test)
            {
                test = vector[j];
            };
        }

        biggestNumbers[i] = test;

        for (int j = 0; j < size; j++)
        {
            if (vector[j] == test)
            {
                vector[j] = INT_MIN;
            };
        }
        test = INT_MIN;
    }

    return biggestNumbers;
}

int main()
{
    int v[] = {1, 12, 5, 4, 1};
    int *pointer = v;
    int size = 4;

    int *v1 = getLargest(5, pointer, size);
    print_vector(size, v1);

    free(v1);
    return 0;
}