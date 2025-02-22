#include <stdio.h>

void copyInto(int tamanho, int v1[], int v2[]){
    for(int i = 0; i<tamanho;i++){
        v2[i] = v1[i];
    }

}

int main(){
    int tamanho, elemento;

    printf("Digite o tamanho do array: \n>> ");
    scanf("%d", &tamanho);

    int vetor[tamanho], vetorCopia[tamanho];

    for(int i = 0; i<tamanho; i++){
        printf("Digite o valor do elemento que será copiado: \n>> ");
        scanf("%d", &elemento);
        vetor[i] = elemento;
    }

    copyInto(tamanho, vetor, vetorCopia);

    return 0;
}