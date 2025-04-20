#include <stdio.h>
#include <iostream>
#include "lista_sequencial.hpp"
#include <algorithm>

int main()
{
    ListSeq ls(8);
    ls.add(1);
    ls.add(2);
    ls.add(3);
    ls.add(4);
    ls.add(5);

    ListSeq ls2(5);
    ls2.add(1);
    ls2.add(2);
    ls2.add(7);
    ls2.add(4);
    ls2.add(5);

    int vetor[] = {10, 20, 30, 40};
    int n = sizeof(vetor) / sizeof(int);

    ListSeq *lista = list_from_vector(n, vetor);
    ListSeq *copia = lista->list_copy();
    int count = ls.list_concat(&ls2);
    ls.print();
    cout << "COunt: " << count << endl;

    return 0;
}