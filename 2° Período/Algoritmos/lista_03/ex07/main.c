#include <stdio.h>

int max(int numA, int numB){
    if(numA>numB) return numA;
    return numB;
}

int min(int numA, int numB){
    if(numA<numB) return numA;
    return numB;
}


int main()
{
    int entrada, maior = 0, menor = 99999;

    printf("Digite um valor de entrada ( 0 quebra o laço! ):\n> ");
    scanf("%d", &entrada);

    while (entrada != 0)
    {
        maior = max(maior, entrada);
        menor = min(menor, entrada);

        printf("Digite outro valor de entrada ( 0 quebra o laço! ):\n> ");
        scanf("%d", &entrada);
    }

    printf("MAIOR: %d\nMENOR: %d\n", maior, menor);

    return 0;
}