#include <stdio.h>

int main(){
    int diasTotais;
    float anos, semanas, dias;

    printf("Informe a quantidade de dias: \n> ");
    scanf(" %d", &diasTotais);

    anos = (int) diasTotais/365;
    semanas = (int) (diasTotais-anos*365)/7;
    dias =(int) diasTotais-anos*365 - semanas*7;

    printf("%d dias equivalem à:\n%.0f ano(s);\n%.0f semana(s);\n%.0f dia(s).\n", diasTotais, anos, semanas, dias);

    return 0;
}