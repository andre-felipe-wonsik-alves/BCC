#include <stdio.h>
#include <iostream>
#include "lista_sequencial.hpp"
#include <algorithm>

int main()
{
    int lista[3] = {3, 4, 5};
    ListSeq ls(5);
    ls.add(1);
    ls.add(3);
    ls.add(4);
    ls.add(5);
    ls.add(6);

    ls.print();
    ls.list_add(3, lista);
    ls.print();

    return 0;
}