#include <stdio.h>

int main(){
    char entrada;

    printf("Digite um caractere: \n> ");
    scanf("%c", &entrada);

    if(!((entrada>64 && entrada < 90) || (entrada > 96 && entrada < 123))) return printf("Não é um char!\n");
    if(entrada > 96 && entrada < 123) entrada -= 32;
    printf("O caracterece em maiúculo é: %c\n", entrada);

    return 0;
}