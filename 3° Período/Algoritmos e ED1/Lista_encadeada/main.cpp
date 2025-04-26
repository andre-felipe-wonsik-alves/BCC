#include <stdio.h>
#include "lista_encadeada.hpp"
#include <iostream>

int main()
{
    LinkedList *list = new LinkedList();

    list->push_front(3);
    list->push_front(2);
    list->push_front(1);
    list->print();

    int res = list->empty();

    int pos = list->get(1);

    list->print_last();
    bool isSorted = list->is_sorted();
    cout << isSorted << endl;
    delete list;
}