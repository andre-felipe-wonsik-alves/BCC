#include <iostream>
using namespace std;

class ListSeq
{
public:
    int size = 0;
    int capacity;
    int *data;

    // * Construtor
    ListSeq(int _capacity);

    void destroy();
    bool resize();
    void print();
    int find(int elem);
    int get(int pos);
    bool isEmpty();
    bool isFull();

    bool add(int elem);
    bool remove();
    void insert(int elem, int pos);
    void removeAt(int pos);
    bool addSorted(int elem);

    // ? Lista
    int list_get_available();
    void list_clear();
    void list_remove_last(int n);
    void list_print_reverse();
    void list_add(int n, int *vet);
    int list_is_sorted();
    void list_reverse();
    int list_equal(ListSeq *outra);
    ListSeq *list_copy();
    int list_concat(ListSeq *list2);
};
ListSeq *list_from_vector(int n, int *vet);