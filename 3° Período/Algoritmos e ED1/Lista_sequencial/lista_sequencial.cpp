#include <iostream>
#include <algorithm>
#include "lista_sequencial.hpp"

using namespace std;

ListSeq::ListSeq(int _capacity){
    data = new int[_capacity];
    capacity = _capacity;
};

bool ListSeq::add(int elem){
    if(size < capacity){
        data[size++] = elem;
        return true;
    } else {
        return false;
    }
}

bool ListSeq::isEmpty(){
    return size == 0;
}

bool ListSeq::isFull(){
    return size == capacity;
}

bool ListSeq::print(){
    for (int i = 0; i < size; i++)
    {
        cout<<data[i]<<" ";
    }
    cout << endl;
    
}

int main(){
    ListSeq ls(5);
    ls.add(1);
    ls.add(3);
    ls.add(4);
    ls.add(5);
    ls.add(6);
}