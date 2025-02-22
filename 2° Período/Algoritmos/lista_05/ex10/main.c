#include <stdio.h>

int insert(int tamanho, int vetor[], int valor)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i] == -1)
        {
            vetor[i] = valor;
            return 1;
        }
    }

    return 0;
}

int main()
{
    int entrada;
    int lista[9] = {1, 6, 1, 9, 4, 1, 1, 2, 1};

    printf("Digite o elemento a ser inserido: \n>> ");
    scanf("%d", &entrada);

    entrada = insert(9, lista, entrada);
    if (!entrada)
    {
        printf("Não foi inserido!\n");
        return 0;
    }
    printf("Foi inserido!\n");
    return 0;
}