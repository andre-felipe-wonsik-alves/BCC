#include <iostream>
#include <algorithm>
#include "lista_encadeada.hpp"

using namespace std;

LinkedList::LinkedList()
{
    this->head = nullptr;
}

LinkedList::~LinkedList()
{
}

void LinkedList::push_front(int elem)
{
    Node *node = new Node{elem, this->head};
    if (!node)
    {
        return;
    }
    this->head = node;
}

bool LinkedList::pop()
{
    return true;
}
bool LinkedList::pop_front()
{
    if (!this->head)
        return false;
    Node *aux = this->head;
    this->head = aux->next;
    delete aux;
    return true;
}

int LinkedList::get(int pos)
{
    Node *aux = this->head;

    for (int i = 0; i < pos - 1; i++)
    {
        aux = aux->next;
        cout << aux->key << endl;
    }

    if (!aux)
    {
        return -1;
    }
    return aux->key;
}

void LinkedList::print()
{
    Node *node = this->head;
    cout << "PRINT: \n"
         << node->key;
    while (node)
    {
        cout << " " << node->key;
        node = node->next;
    }
    cout << endl;
}

void LinkedList::print_last()
{
    Node *node = this->head;

    while (node->next)
    {
        node = node->next;
    }
    cout << "LAST NODE KEY: " << node->key << endl;
}

bool LinkedList::is_sorted()
{
    Node *node = this->head;
    while (node)
    {
        if (node->key > node->next->key)
            return false;
        node = node->next;
    }
    return true;
}

int LinkedList::size()
{
    int n = 0;
    Node *aux = this->head;

    while (aux)
    {
        aux = aux->next;
        n++;
    }
    return n;
}

bool LinkedList::empty()
{
    return this->head == nullptr;
}

bool LinkedList::equals(LinkedList *outra)
{
    Node *a1 = this->head;
    Node *a2 = outra->head;

    while (a1 && a2)
    {
        if (a1->key == a2->key)
        {
            a1 = a1->next;
            a2 = a2->next;
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool LinkedList::push_back(int n, int *vec)
{
    try
    {
        Node *aux = this->head;

        while (aux->next)
        {
            aux = aux->next;
        }

        for (int i = 0; i < n; i++)
        {
            aux->next = new Node{vec[i], nullptr};
            aux = aux->next;
        }
        return true;
    }
    catch (const std::exception &e)
    {
        return false;
    }
}

bool LinkedList::insert_sorted(int key)
{
    Node *aux = this->head;
    Node *novo = new Node{key, nullptr};

    while (aux->next->key <= key)
    {
        aux = aux->next;
    }

    novo->next = aux->next;
    aux->next = novo;

    return true;
}

LinkedList *LinkedList::deep_copy()
{
    LinkedList *novaLista = new LinkedList();

    if (!this->head)
    {
        return novaLista;
    }

    Node *aux = this->head;

    while (aux)
    {
        novaLista->insert_back(aux->key);
        aux = aux->next;
    }

    return novaLista;
}

void LinkedList::insert_back(int key)
{
    Node *novo = new Node{key, nullptr};

    if (!this->head)
    {
        this->head = novo;
        return;
    }

    Node *aux = this->head;
    while (aux->next)
    {
        aux = aux->next;
    }

    aux->next = novo;
}

bool LinkedList::pop_back()
{
    return true;
}

Node *LinkedList::find(int key)
{
    Node *aux = this->head;

    for (int i = 0; i < this->size(); i++)
    {
        if (aux->key == key)
        {
            break;
        }
        else
        {
            aux = aux->next;
        }
    }
    cout << " -> " << aux->key;
    return aux;
}

void LinkedList::insert_after(int key, Node *pos)
{

    Node *novo = new Node{key, pos->next};
    pos->next = novo;
}

bool LinkedList::remove_after(Node *pos)
{
    return true;
}

bool LinkedList::insert(int key, int pos)
{
    if (pos <= this->size())
    {
        Node *aux = this->head;
        for (int i = 0; i <= pos; i++)
        {
            aux = aux->next;
        }
        Node *novo = new Node{key, aux->next};
        aux->next = novo;
        return true;
    }
    return false;
}

bool LinkedList::remove_pos(int pos)
{
    return true;
}

bool LinkedList::remove_key(int key)
{
    return true;
}