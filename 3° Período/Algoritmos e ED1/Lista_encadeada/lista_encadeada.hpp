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

    Node *find(int key);

    bool insert_after(int key, Node *pos);
    bool remove_after(Node *pos);

    bool insert(int pos);
    bool remove(int pos);
    bool remove(int key);

    bool insert_sorted(int key);

    bool equals(LinkedList *other);
};