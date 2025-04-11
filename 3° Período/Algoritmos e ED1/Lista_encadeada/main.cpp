#include <stdio.h>
#include "lista_encadeada.hpp"

int main(){
    LinkedList* list = new LinkedList();

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