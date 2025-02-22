#include <stdio.h>

int main(){
    int ano;

    printf("Digite o ano: \n> ");
    scanf(" %d", &ano);
    if ((!(ano%4) && ano%100) || !(ano%400)){
        return printf("Ano bissexto!\n");
    }
    return printf("Ano não bissexto!\n");
}