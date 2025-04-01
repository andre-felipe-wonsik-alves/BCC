#include <stdio.h>
#include <iostream>
#include "lista_sequencial.hpp"
#include <algorithm>

int main(){
    ListSeq ls(5);
    ls.add(1);
    ls.add(3);
    ls.add(4);
    ls.add(5);
    ls.add(6);
    ls.print();

    if(ls.isFull()){
        ls.resize();
    }

    ls.add(20);
    ls.print();
    ls.remove();
    ls.removeAt(5);
    ls.print();

    return 0;
}