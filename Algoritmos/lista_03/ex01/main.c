#include <stdio.h>

int main(){
    int contador = 10;

    printf("Digite um número: \n> ");
    scanf(" %d", &contador);

    for(int i = contador; i>0; i--){
        printf("Linha %d \n", i);
        contador--;
    };

    return 0;
}