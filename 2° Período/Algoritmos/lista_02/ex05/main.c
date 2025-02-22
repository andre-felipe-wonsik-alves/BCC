#include <stdio.h>

int main(){
    float n1, n2, n3, media;

    printf("Digite as notas escoalares:\n> ");
    scanf(" %f %f %f", &n1, &n2, &n3);

    if(!(n1 >= 0 && n1 <= 10)) return printf("NOTA INVALIDA\n");
    if(!(n2 >= 0 && n2 <= 10)) return printf("NOTA INVALIDA\n");
    if(!(n3 >= 0 && n3 <= 10)) return printf("NOTA INVALIDA\n");

    media = (n1+n2+n3)/3;

    if(media >= 8.5 && media <= 10) return printf("Conceito A\n");
    if(media >= 7.0 && media < 8.5) return printf("Conceito B\n");
    if(media >= 5.5 && media < 7) return printf("Conceito C\n");
    if(media >= 0 && media < 5.5) return printf("Conceito F\n");


    return printf("erro paezao");
}
