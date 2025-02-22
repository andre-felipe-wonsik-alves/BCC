#include <stdio.h>

int main(){
    float n1,n2,n3,n4;

    printf("Digite 4 números: \n> ");
    scanf(" %f %f %f %f", &n1,&n2,&n3,&n4);

    if(n1 > n2 && n1 > n3 && n1 > n4){
        printf("O maior número é: %f\n", n1);
    } else if (n2 > n1 && n2 > n3 && n2 > n4){
        printf("O maior número é: %f\n", n2);
    } else if (n3 > n1 && n3 > n2 && n3 > n4){
        printf("O maior número é: %f\n", n3);
    } else {
        printf("O maior número é: %f\n", n4);
    }

    return 0;
}