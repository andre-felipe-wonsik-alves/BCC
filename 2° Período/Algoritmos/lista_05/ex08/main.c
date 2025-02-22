#include <stdio.h>

void reverse(int tamanho, int v[]){
    int vReversed[tamanho];
    for(int i = tamanho; i>0;i--){
        vReversed[(i-tamanho)*-1] = v[i-1];
    }
    for(int i = 0; i<tamanho;i++){
        v[i] = vReversed[i];
        printf("%d ", v[i]);
    }
    printf("\n");
}


int main(){
    int tamanho, elemento;

    printf("Digite o tamanho do array: \n>> ");
    scanf("%d", &tamanho);

    int vetor[tamanho];

    for(int i = 0; i<tamanho; i++){
        printf("Digite o valor do elemento: \n>> ");
        scanf("%d", &elemento);
        vetor[i] = elemento;
    }

    reverse(tamanho, vetor);

    return 0;
}