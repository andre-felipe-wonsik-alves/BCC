#include <stdio.h>

int calcularMMC(int numeroA, int numeroB)
{
    int multiploMaior, multiploMenor;
    int maior = numeroA > numeroB ? numeroA : numeroB;
    int menor = numeroA < numeroB ? numeroA : numeroB;

    for (int i = 0; i < maior; i++)
    {
        multiploMaior = maior * (i + 1);
        for (int j = 0; j < (multiploMaior / 2); j++)
        {
            multiploMenor = menor * (j + 1);
            if (multiploMaior == multiploMenor)
            {
                return multiploMaior;
            }
        }
    }
}

int main()
{
    int numA, numB, mmc;

    printf("Digite dois números para saber o seu MMC:\n>> ");
    scanf("%d %d", &numA, &numB);

    mmc = calcularMMC(numA, numB);
    printf("O MMC de %d e %d é: %d\n", numA, numB, mmc);

    return 0;
}