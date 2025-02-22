#include <stdio.h>
#include <string.h>

void uncompress(int tamanho, int vec[])
{
    for (int i = 0; i < tamanho; i++)
    {
        if (vec[i] < 0)
        {
            for (int j = 0; j < vec[i + 2]; j++)
            {
                printf(" %d ", vec[i + 1]);
            }
            i += 2;
        }
        else
        {
            printf(" %d ", vec[i]);
        }
    }
}

int main()
{
    int v[] = {1, -1, 2, 3, -1, 3, 2, 4, -1, 6, 3, -1, 5, 12};

    uncompress(14, v);

    return 0;
}