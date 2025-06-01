#include <iostream>
#include <vector>

#include "codigo/ordenacao.cpp"
#include "codigo/gerador_dados.cpp"
#include "codigo/busca.cpp"

int main()
{
    Gerador pequeno("/dados/pequeno", 1000);
    Gerador medio("/dados/medio", 1000);
    Gerador grande("/dados/grande", 1000);

    Utilities util;

    Ordenacao ordenacao();

    return 0;
}