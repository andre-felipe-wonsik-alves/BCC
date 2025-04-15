#include <iostream>

class Node
{
public:
    int key;
    Node *next;
};

class CircularList
{
private:
    Node *head;
    Node *tail;

public:
    CircularList();
    ~CircularList();

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

    bool equals(CircularList* outra);
    void print();
    int size();
    bool empty();
    Node *find(int key);

};