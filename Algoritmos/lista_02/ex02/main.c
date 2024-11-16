#include <stdio.h>

int main(){
    int numero;

    printf("Digite um número:\n> ");
    scanf(" %d", &numero);

    if(numero == 1){
        printf("Um\n");
    } else if (numero == 2){
        printf("Dois\n");
    } else if (numero == 3){
        printf("Três\n");
    } else if (numero == 4){
        printf("Quatro\n");
    } else if (numero == 5){
        printf("Cinco\n");
    } else if (numero == 6){
        printf("Seis\n");
    } else if (numero == 7){
        printf("Sete\n");
    } else if (numero == 8){
        printf("Oito\n");
    } else if (numero == 9){
        printf("Nove\n");
    } else {
        printf("Algum erro aconteceu!\n");
    }
    return 0;
}