#include <stdio.h>

int max_sum_slice2(int tamanho, int v[])
{
    int somaFinal = v[0];
    int somaSegmento = v[0];

    for (int i = 1; i < tamanho; i++)
    {
        if (v[i] > somaSegmento + v[i])
        {
            somaSegmento = v[i];
        }
        else
        {
            somaSegmento += v[i];
        }
        if (somaSegmento > somaFinal)
        {
            somaFinal = somaSegmento;
        }
    }

    return somaFinal;
}

int main()
{
    int v[] = {5, 2, -2, -7, 3, 14, 10, -3, 9, -6, 4, 1};
    int result = max_sum_slice2(12, v);

    printf("A soma máxima do segmento é: %d\n", result);

    return 0;
}
