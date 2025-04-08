#include <iostream>

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
    void push_back(int elem);
    bool pop_back();
    bool pop_front();

    Node *find(int key);

    void insert_after(int key, Node *pos);
    bool remove_after(Node *pos);

    bool insert(int key, int pos);
    bool remove(int pos);
    bool remove(int key);
    bool equals(LinkedList* outra);

    bool insert_sorted(int key);

    bool equals(LinkedList *other);
};