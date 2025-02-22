#include <stdio.h>

int main(){
    float numero;

    printf("Digite um número:\n> ");
    scanf(" %f", &numero);

    if(numero<0){
        return printf("O número em valor absoluto é: %f\n", numero * -1);
    }
    return printf("O número em valor absoluto é: %f\n", numero);
}