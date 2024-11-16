#include <stdio.h>

int main(){
    int numA, numB, resposta;

    printf("Digite dois números: \n> ");
    scanf("%d %d", &numA, &numB);

    for(int i = 0; i < numB; i++){
        resposta += numA;
    }

    printf("%d X %d = %d\n", numA, numB, resposta);
}