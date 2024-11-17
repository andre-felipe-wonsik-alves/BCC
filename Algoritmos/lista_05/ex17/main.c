#include <stdio.h>

void min_bills(int valor, int tamanho, int cedulas[])
{
    int count[tamanho];

    for (int i = 0; i < tamanho; i++)
    {
        count[i] = 0;
    }

    for (int i = tamanho - 1; i >= 0; i--)
    {
        if (valor >= cedulas[i])
        {
            count[i] = valor / cedulas[i];
            valor %= cedulas[i];
        }
    }

    for (int i = tamanho - 1; i >= 0; i--)
    {
        if (count[i] > 0)
        {
            printf("%d x R$%d,00\n", count[i], cedulas[i]);
        }
    }
}

int main()
{
    int value = 209;
    int bills[] = {1, 5, 10, 50, 100};

    min_bills(value, 5, bills);

    return 0;
}
