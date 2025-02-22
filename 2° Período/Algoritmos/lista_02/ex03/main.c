#include <stdio.h>

int main(){
    int numero;

    printf("Digite um número:\n> ");
    scanf(" %d", &numero);

    if(!(numero%2)) {
        return printf("O número é par!\n");
    }

    return printf("O número é ímpar!\n");
}