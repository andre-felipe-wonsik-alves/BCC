#include <stdio.h>

int main(){
    int numero;

    printf("Digite um número: \n> ");
    scanf("%d", &numero);

    printf("%d | %d | %d | %d | %d\n", (numero%100000)/10000, (numero%10000)/1000, (numero%1000)/100, (numero%100)/10, numero%10);

    return 0;
}