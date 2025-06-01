#include <iostream>
#include <vector>

#include "codigo/ordenacao.cpp"

int main()
{
    vector<int> teste = {5, 6, 2, 1};

    Ordenacao *ordenacao = new Ordenacao(teste);
    // ordenacao->bubble_sort();
    // ordenacao->selection_sort();
    ordenacao->insertion_sort();

    return 0;
}