#include <stdio.h>

int calcularQuociente(int numA, int numB)
{
    int quociente = 0;
    while (1)
    {
        if ((numA - numB) <= 0)
        {
            break;
        }
        numA -= numB;
        quociente++;
    }
    return quociente;
}

int calcularResto(int numA, int numB, int quociente){
    return numA - (quociente*numB);
}

int main()
{
    int numA, numB, quociente = 0, resto = 0;

    printf("Digite dois números: \n> ");
    scanf(" %d %d", &numA, &numB);

    quociente = calcularQuociente(numA, numB);
    resto = calcularResto(numA, numB, quociente);

    printf("%d / %d = %d\n", numA, numB, quociente);
    printf("%d %% %d = %d\n", numA, numB, resto);

    return 0;
}