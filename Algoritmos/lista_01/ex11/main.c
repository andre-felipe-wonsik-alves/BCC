#include <stdio.h>

int main(){
    float numero;

    printf("Digite um numero: \n> ");
    scanf(" %f", &numero);

    printf("2 casas: %.2f\n", numero);
    printf("Parte inteira: %.0f\n", numero);
    printf("Parte decimal: %f\n", (int)numero - numero);
    printf("Notação científica: %e\n");

    return 0;
}