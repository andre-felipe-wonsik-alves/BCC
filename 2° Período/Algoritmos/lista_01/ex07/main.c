#include <stdio.h>

int main(){
    int numeroA;
    int numeroB;
    int numeroC;

    printf("Digite os valores: \n> ");
    scanf(" %d %d %d", &numeroA, &numeroB, &numeroC);

    printf("Média Aritmética: %d\n", (numeroA+numeroB+numeroC)/3);
    printf("Média Ponderada: %f\n", (numeroA*0.1 + numeroB*0.5 + numeroC*0.4)/1);

    return 0;
}