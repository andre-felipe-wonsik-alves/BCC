#include <iostream>
#include <vector>

#include "codigo/ordenacao.cpp"
#include "codigo/gerador_dados.cpp"
#include "codigo/busca.cpp"

int main()
{
    Gerador pequeno("./dados/pequeno", 13000);
    Utilities util;

    pequeno.create_unordered_file();

    vector<int> res = util.read_binary_file("./dados/pequeno_13000_ordenado.bin", 13000);

    Ordenacao ordenacao(res);
    // ordenacao.selection_sort();
    // ordenacao.bubble_sort();
    ordenacao.insertion_sort();
    // ordenacao.optimized_bubble_sort();

    return 0;
}