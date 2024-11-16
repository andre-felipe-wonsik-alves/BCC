#include <stdio.h>

int main(){
    int numero;

    printf("Informe um numero: \n> ");
    scanf(" %d", &numero);

    printf("%d x 1 = %2d\n", numero, numero*1);
    printf("%d x 2 = %2d\n", numero, numero*2);
    printf("%d x 3 = %2d\n", numero, numero*3);
    printf("%d x 4 = %2d\n", numero, numero*4);
    printf("%d x 5 = %2d\n", numero, numero*5);
    printf("%d x 6 = %2d\n", numero, numero*6);
    printf("%d x 7 = %2d\n", numero, numero*7);
    printf("%d x 8 = %2d\n", numero, numero*8);
    printf("%d x 9 = %2d\n", numero, numero*9);
    printf("%d x 10= %d\n", numero, numero*10);
    return 0;
}