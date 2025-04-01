#include <iostream>
#include <algorithm>
#include "lista_sequencial.hpp"

using namespace std;

ListSeq::ListSeq(int _capacity)
{
    data = new int[_capacity];
    capacity = _capacity;
};

bool ListSeq::add(int elem)
{
    if (size < capacity)
    {
        data[size++] = elem;
        return true;
    }
    else
    {
        return false;
    }
}

bool ListSeq::isEmpty()
{
    return size == 0;
}

bool ListSeq::isFull()
{
    return size == capacity;
}

void ListSeq::print()
{
    for (int i = 0; i < size; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

bool ListSeq::resize()
{
    int *_data = new int[++capacity];

    for (int i = 0; i < size; i++)
    {
        _data[i] = data[i];
    }

    destroy();

    data = _data;
    return true;
}

void ListSeq::destroy()
{
    delete[] data;
}

bool ListSeq::remove()
{
    if (isEmpty())
        return 0;
    size--;
    return 1;
}

void ListSeq::removeAt(int pos)
{
    if (isEmpty() || pos >= size) return;
    if(pos < (size-1)) remove();

    for (int i = pos; i < size; i++)
    {
        data[i] = data[i+1];
    }
    remove();
}