#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    Node *next;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList();
    ~LinkedList();

    void push_front(int elem);
    bool pop();
    int get(int pos);
    void print();
    int size();
    bool empty();
    bool push_back(int n, int *vec);
    bool pop_back();
    bool pop_front();

    Node *find(int key);

    void insert_after(int key, Node *pos);
    bool remove_after(Node *pos);
    void insert_back(int key);

    bool insert(int key, int pos);
    bool remove_pos(int pos);
    bool remove_key(int key);
    bool equals(LinkedList *outra);

    bool insert_sorted(int key);
    void print_last();
    bool is_sorted();
    LinkedList *concat(LinkedList *list2);
    LinkedList *deep_copy();
    LinkedList *merge(LinkedList *list2);
};