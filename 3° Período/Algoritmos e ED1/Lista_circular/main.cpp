#include <stdio.h>
#include "lista_circular.hpp"

int main(){
    CircularList* list = new CircularList();

    list->push_front(1);
    list->push_front(2);
    list->push_front(3);
    list->push_front(4);
    list->push_front(5);

    list->print();

    list->find(4);
    list->get(2);
    list->print();

    delete list;    
}