#include <stdio.h>

// ? Resumidamente, referencia a um enderço de memória ao invés do valor

void min_max(int tamanho, int* v, int* max, int* min){
    int mx = v[0], mn = v[0];

    /* 
    ! [] indica um endereço de memória, apesar de não ser um ponteiro, ou seja, qualquer
    ! variável pode ter seu endereço acessado 
    */

    for (int i = 1; i < tamanho; i++)
    {
        *max = v[i] > mx ? v[i] : mx;
        *min = v[i] < mn ? v[i] : mn; // * UMA FUNÇÃO PODE RETORNAR MAIS DE UM VALOR ASSIM
    }
    
}

void print_odd(int n, int* v){
    v++;
    for (int i = 0; i < n/2; i++)
    {
        printf("%d ", *v);
        v+=2;
    }
    
}

int main(){
    int v[4] = {1,2,3,4}, min, max;

    min_max(4, v, &min, &max);

    printf("\nmin: %d\nmax: %d\n", min, max);

    /*
        ? Caso seja necessário passar um vetor para um ponteiro, NÃO se deve colocar um &
    */
    int v1[] = {12,3,4,56};
    int *p = v1;
    for (int i = 0; i < 4; i++)
    {
        printf("%d", *p);
        p++; // ! O p pulará 1 endereço no array
    }
    

    return 0;
}