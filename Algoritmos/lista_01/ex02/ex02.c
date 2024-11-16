#include <stdio.h>

int main(){
    int numeroA;
    int numeroB;

    printf("Digite um numero inteiro:\n >");
    scanf(" %d", &numeroA);
    printf("Digite um numero inteiro:\n >");
    scanf(" %d", &numeroB);

    printf("O número %d + %d é igual a: %d\n", numeroA, numeroB, numeroA + numeroB);
    printf("O número %d - %d é igual a: %d\n", numeroA, numeroB, numeroA - numeroB);

    return 0;
}