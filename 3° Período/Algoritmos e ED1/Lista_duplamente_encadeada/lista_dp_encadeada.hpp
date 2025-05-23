#include <iostream>

class Node
{
public:
    int key;
    Node *next;
    Node* prev;
};

class LinkedList2
{
private:
    Node *head;
    Node *tail;

public:
    LinkedList2();
    ~LinkedList2();

    void push_front(int elem);
    void push_back(int elem);
    bool pop();
    bool pop_back();
    bool pop_front();
    int get(int pos);


    void insert_after(int key, Node *pos);
    bool insert(int key, int pos);
    bool insert_sorted(int key);

    bool remove_after(Node *pos);
    bool remove_pos(int pos);
    bool remove_key(int key);

    bool equals(LinkedList2* outra);
    void print();
    int size();
    bool empty();
    Node *find(int key);

};