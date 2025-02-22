#include <stdio.h>

int sum(float numA, float numB){
    printf("%.2f + %.2f = %.2f\n", numA, numB, numA+numB);
    return 0;
}

int sub(float numA, float numB){
    printf("%.2f - %.2f = %.2f\n", numA, numB, numA-numB);
    return 0;
}

int mult(float numA, float numB){
    printf("%.2f * %.2f = %.2f\n", numA, numB, numA*numB);
    return 0;
}

int div(float numA, float numB){
    printf("%.2f / %.2f = %.2f\n", numA, numB, numA/numB);
    return 0;
}

int mod(float numA, float numB){
    printf("%.2f %% %.2f = %.2f\n", numA, numB, ((int) numA)%((int) numB));
    return 0;
}

int main(){
    char operador;
    float numA, numB;

    printf("Digite um operador: \n> ");
    scanf("%c", &operador);

    printf("Digite os operados:\n> ");
    scanf("%f %f", &numA, &numB);

    if(operador == 43 ){ return sum(numA, numB);} // operador == +
    if(operador == 45 ){ return sub(numA, numB);} // operador == -
    if(operador == 42 ){ return mult(numA, numB);} // operador == *
    if(operador == 47 ){ return div(numA, numB);} // operador == /
    if(operador == 37 ){ return mod(numA, numB);} // operador == %

    printf("ERRO: Operador inválido!\n");
    return 0;
}
