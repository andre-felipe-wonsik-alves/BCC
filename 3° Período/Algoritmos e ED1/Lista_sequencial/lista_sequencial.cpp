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

int ListSeq::list_is_sorted()
{
    for (int i = 0; i < size - 1; i++)
    {
        if (data[i] > data[i + 1])
            return 0;
    }
    return 1;
}

void ListSeq::list_reverse()
{
    int aux[size];
    for (int i = 0; i < size; i++)
    {
        aux[i] = data[(size - 1) - i];
    }

    // ? os elementos estao reversos em aux agora
    for (int i = 0; i < size; i++)
    {
        data[i] = aux[i];
    }
}

int ListSeq::list_equal(ListSeq *outra)
{
    if (size != outra->size)
        return 0;

    for (int i = 0; i < size; i++)
    {
        if (data[i] != outra->data[i])
            return 0;
    }

    return 1;
}

ListSeq *list_from_vector(int n, int *vet)
{
    ListSeq *novaLista = new ListSeq(2 * n);

    for (int i = 0; i < n; i++)
    {
        novaLista->add(vet[i]);
    }
    return novaLista;
}

ListSeq *ListSeq::list_copy()
{
    ListSeq *copia = new ListSeq(capacity);
    for (int i = 0; i < size; i++)
    {
        copia->add(data[i]);
    }
    return copia;
}

int ListSeq::list_concat(ListSeq *list2)
{
    int count = 0;
    int items = this->size;
    for (int i = 0; i < capacity; i++)
    {
        this->add(list2->data[i]);
        if (i >= items)
        {
            count++;
        }
    }

    return count;
}