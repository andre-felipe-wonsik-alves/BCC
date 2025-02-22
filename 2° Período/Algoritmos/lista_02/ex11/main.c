#include <stdio.h>

void verVogal(char entrada){
    if((entrada == 65 || entrada == 69 || entrada == 73 || entrada == 79 || entrada == 85) ||
        (entrada == 97 || entrada == 101 || entrada == 105 || entrada == 111 || entrada == 117)
    ) {
        printf("É vogal!\n");
    } else {
        printf("Não é vogal!\n");
    }
}

int main(){
    char entrada;

    printf("Digite um caractere: \n> ");
    scanf("%c", &entrada);

    if((entrada>64 && entrada < 90) || (entrada > 96 && entrada < 123)){
        printf("É uma letra!\n");
        verVogal(entrada);
    } else if(entrada >= 48 && entrada <= 57){
        printf("É um número!\n");
    } else if (entrada >= 33 && entrada <= 126){
        printf("É um símbolo!\n")
    }

    return 0;
}
