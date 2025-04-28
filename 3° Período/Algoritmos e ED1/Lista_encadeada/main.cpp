#include <stdio.h>
#include "lista_encadeada.hpp"
#include <iostream>

int main()
{
    LinkedList *list = new LinkedList();
    int v1[5] = {1, 2, 3, 4, 6};

    list->push_front(3);
    list->push_front(2);
    list->push_front(1);
    list->print();

    int res = list->empty();

    int pos = list->get(1);

    list->print_last();

    list->push_back(5, v1);
    list->insert_sorted(5);
    list->print();

    LinkedList *novaLista = list->deep_copy();
    novaLista->print();

    delete list;
}