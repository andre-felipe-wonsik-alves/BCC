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
    if (isEmpty() || pos >= size)
        return;
    if (pos < (size - 1))
        remove();

    for (int i = pos; i < size; i++)
    {
        data[i] = data[i + 1];
    }
    remove();
}

int ListSeq::find(int elem)
{
    for (int i = 0; i < size; i++)
    {
        if (elem == data[i])
        {
            return i;
        }
    }
    return -1;
}

int ListSeq::get(int pos)
{
    if (pos >= size)
    {
        return -1;
    }
    return data[pos];
}

// ? LISTA

int ListSeq::list_get_available()
{
    return capacity - size;
}

void ListSeq::list_clear()
{
    while (size)
    {
        size--;
    }
}

void ListSeq::list_remove_last(int n)
{
    int contador = 0;
    for (int i = size; i > 0; i--)
    {
        if (contador == n)
            return;
        contador++;
        size--;
    }
}

void ListSeq::list_print_reverse()
{

    cout << "Printando lista ao contrário:" << endl;
    for (int i = size - 1; i >= 0; i--)
    {
        cout << data[i] << " ";
    }
}

void ListSeq::list_add(int n, int *vet)
{
    int aux = 0;
    while (size < capacity && aux < n)
    {
        data[size++] = vet[aux];
        aux++;
    }
}