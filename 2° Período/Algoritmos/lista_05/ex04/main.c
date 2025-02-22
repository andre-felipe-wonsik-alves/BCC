#include <stdio.h>

void replaceAll(int tamanho, int vetor[], int elemento)
{
    printf("Vetor com o número alterado: [ ");
    for (int i = 0; i < tamanho; i++)
    {
        vetor[i] = vetor[i] == elemento ? -1 : vetor[i];
        printf("%d ", vetor[i]);
    }
    printf("]\n");
}

int main()
{
    int tamanho, numero, elemento;

    printf("Tamanho: \n>> ");
    scanf("%d", &tamanho);

    int vetor[tamanho];

    for (int i = 0; i < tamanho; i++)
    {
        printf("Valor a ser adicionado: \n>> ");
        scanf("%d", &numero);
        vetor[i] = numero;
    }

    printf("Valor a ser alterado: \n>> ");
    scanf("%d", &elemento);

    replaceAll(tamanho, vetor, elemento);

    return 0;
}