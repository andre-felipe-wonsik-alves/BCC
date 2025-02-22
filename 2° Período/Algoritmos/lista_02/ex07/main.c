#include <stdio.h>

int retornaMenor(int numA, int numB, int numC){
    if (numA < numB && numA < numC) return numA;
    if (numB < numA && numB < numC) return numB;
    if (numC < numA && numC < numB) return numC;
    return 0;
}

int retornaMaior(int numA, int numB, int numC){
    if (numA > numB && numA > numC) return numA;
    if (numB > numA && numB > numC) return numB;
    if (numC > numA && numC > numB) return numC;
    return 0;
}

int main(){
    int num1,num2,num3, maior, meio, menor;
    printf("Digite 3 números: \n> ");
    scanf(" %d %d %d", &num1, &num2, &num3);

    menor = retornaMenor(num1,num2,num3);
    maior = retornaMaior(num1,num2,num3);

    if(num1 != menor && num1 != maior) meio = num1;
    if(num2 != menor && num2 != maior) meio = num2;
    if(num3 != menor && num3 != maior) meio = num3;

    printf("Em ordem crescente: %d %d %d\n", menor, meio, maior);
    return 0;
}
