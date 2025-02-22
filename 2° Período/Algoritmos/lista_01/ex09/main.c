#include <stdio.h>

int main(){
    int numeroA;
    int numeroB;

    printf("Digite dois numeros: \n> ");
    scanf(" %d %d", &numeroA, &numeroB);

    printf("Resto (com operador): %d\n", numeroA%numeroB);
    printf("Resto (sem operador): %d\n", numeroA - (numeroB * (numeroA / numeroB)));

    return 0;
}