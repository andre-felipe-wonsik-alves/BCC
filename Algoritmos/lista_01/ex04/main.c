#include <stdio.h>

int main(){
    int numeroA;
    int numeroB;

    printf("Digite o primeiro e o segundo número.\n>");
    scanf(" %d %d", &numeroA, &numeroB);

    printf("Multiplicação: %d\n", numeroA*numeroB);
    printf("Divisao inteira: %d\n", numeroA/numeroB);
    printf("Divisao float: %f\n", (numeroA * 1.0) /(numeroB * 1.0));

    return 0;
}