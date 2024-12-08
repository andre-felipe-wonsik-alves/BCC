#include <stdio.h>

void get_min_max(int n, const int *v, int *min, int *max)
{
    *min = *v, *max = *v;

    for (int i = 0; i < n; i++)
    {
        *min = *min < *v ? *min : *v;
        *max = *max > *v ? *max : *v;
        v++;
    }
}

int main()
{
    int v[5] = {2, 4, 13, 6, 6}, menor, maior;
    int *p0 = v, *p1 = &menor, *p2 = &maior;

    get_min_max(5, p0, p1, p2);

    printf("Maior: %d\nMenor: %d\n", maior, menor);

    return 0;
}