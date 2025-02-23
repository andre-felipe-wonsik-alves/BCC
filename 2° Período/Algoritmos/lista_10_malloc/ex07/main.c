#include <stdio.h>
#include <stdlib.h>

int *array_intersection(int n1, const int *v1, int n2, const int *v2, int *result_size)
{
    int *intersection = (int *)malloc((n1 < n2 ? n1 : n2) * sizeof(int));
    if (intersection == NULL)
    {
        *result_size = 0;
        return NULL;
    }

    int k = 0;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (v1[i] == v2[j])
            {
                intersection[k++] = v1[i];
                break;
            }
        }
    }

    *result_size = k;
    return intersection;
}

int main()
{
    int v1[] = {1, 2, 3, 4, 5};
    int v2[] = {3, 4, 5, 6, 7};
    int n1 = sizeof(v1) / sizeof(v1[0]);
    int n2 = sizeof(v2) / sizeof(v2[0]);
    int result_size;

    int *result = array_intersection(n1, v1, n2, v2, &result_size);

    printf("Intersection: ");
    for (int i = 0; i < result_size; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}