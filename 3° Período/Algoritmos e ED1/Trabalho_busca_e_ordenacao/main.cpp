#include <iostream>
#include <vector>

#include "codigo/ordenacao.cpp"
#include "codigo/gerador_dados.cpp"
#include "codigo/busca.cpp"

using namespace std;

void buscar(std::vector<int> &dados, int chave)
{
    Busca busca(dados);

    int idx_linear = busca.linear_search(chave);
    if (idx_linear != -1)
    {
        std::cout << "Busca Linear: valor " << chave << " encontrado no índice " << idx_linear << std::endl;
    }
    else
    {
        std::cout << "Busca Linear: valor " << chave << " não encontrado." << std::endl;
    }

    cout << "\n";

    int idx_binaria = busca.binary_search(chave);
    if (idx_binaria != -1)
    {
        std::cout << "Busca Binária: valor " << chave << " encontrado no índice " << idx_binaria << std::endl;
    }
    else
    {
        std::cout << "Busca Binária: valor " << chave << " não encontrado." << std::endl;
    }
}

void ordenar(std::vector<int> &dados)
{
    Ordenacao ordenacao(dados);

    cout << "Selection Sort:\n";
    ordenacao.selection_sort();

    cout << "\n";

    cout << "Selection Sort Otimizado:\n";
    ordenacao.optimized_selection_sort();

    cout << "\n";

    cout << "Bubble Sort:\n";
    ordenacao.bubble_sort();

    cout << "\n";

    cout << "Bubble Sort Otimizado:\n";
    ordenacao.optimized_bubble_sort();

    cout << "\n";

    cout << "Insertion Sort:\n";
    ordenacao.insertion_sort();
}

int main()
{
    Gerador gerador("./dados/");
    Utilities util;

    gerador.gerar_dados();

    cout << "\nARQUIVO PEQUENO DESORDENADO\n";
    vector<int> dados = util.read_binary_file("dados/pequeno_13000_desordenado.bin", 13000);
    ordenar(dados);

    cout << "\nARQUIVO MEDIO DESORDENADO\n";
    vector<int> dados2 = util.read_binary_file("dados/medio_70000_desordenado.bin", 70000);
    ordenar(dados2);

    cout << "\nARQUIVO GRANDE DESORDENADO\n";
    vector<int> dados3 = util.read_binary_file("dados/grande_165000_desordenado.bin", 165000);
    ordenar(dados3);

    cout << "\nARQUIVO PEQUENO ORDENADO\n";
    vector<int> dados4 = util.read_binary_file("dados/pequeno_13000_ordenado.bin", 13000);
    ordenar(dados4);

    cout << "\nARQUIVO MEDIO ORDENADO\n";
    vector<int> dados5 = util.read_binary_file("dados/medio_70000_ordenado.bin", 70000);
    ordenar(dados5);

    cout << "\nARQUIVO GRANDE ORDENADO\n";
    vector<int> dados6 = util.read_binary_file("dados/grande_165000_ordenado.bin", 165000);
    ordenar(dados6);

    // cout << "\nBUSCAS NO ARQUIVO PEQUENO ORDENADO\n";
    // int chave = 1234; // valor para buscar
    // buscar(dados4, chave);

    // cout << "\nBUSCAS NO ARQUIVO MEDIO ORDENADO\n";
    // buscar(dados5, chave);

    // cout << "\nBUSCAS NO ARQUIVO GRANDE ORDENADO\n";
    // buscar(dados6, chave);

    return 0;
}