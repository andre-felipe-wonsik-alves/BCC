#include <stdio.h>

int main(){
    float largura;
    float comprimento;

    printf("Digite, respectivamente, a largura e comprimento:\n>");
    scanf(" %f %f", &largura, &comprimento);

    printf("Perímetro do retângulo: %f\n", largura*2 + comprimento *2);
    printf("Área do retângulo: %f\n", largura*comprimento);

    return 0;
}