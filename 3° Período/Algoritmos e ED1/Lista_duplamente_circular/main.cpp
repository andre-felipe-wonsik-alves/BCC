#include <stdio.h>
#include "lista_dp_circular.hpp"

int main()
{
    CircleDoubleList *list = new CircleDoubleList();

    list->push_front(1);
    list->push_front(2);
    list->push_front(3);
    list->push_front(4);

    list->print();

    int res = list->insert(2, 300);

    list->print();

    res = list->remove_at(1);

    list->print();

    res = list->remove(3);
    list->print();

    delete list;
}