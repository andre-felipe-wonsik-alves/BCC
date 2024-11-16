#include <stdio.h>

int main(){
    int numeroA;
    int numeroB;
    int numeroC;
    float pesoA;
    float pesoB;
    float pesoC;

    printf("Digite os valores: \n> ");
    scanf(" %d %d %d", &numeroA, &numeroB, &numeroC);

    printf("Informe o peso de cada:\n> ");
    scanf(" %f %f %f", &pesoA, &pesoB, &pesoC);

    printf("Média Aritmética: %d\n", (numeroA+numeroB+numeroC)/3);
    printf("Média Ponderada: %f\n", (numeroA*pesoA + numeroB*pesoB + numeroC*pesoC)/ (pesoA + pesoB+ pesoC));

    return 0;
}