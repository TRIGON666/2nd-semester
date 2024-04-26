#include <iostream>

#ifndef ONE_LINKED_LIST_H
#define ONE_LINKED_LIST_H

class Node 
{
public:
    double data;
    Node* prev, * next;

    Node(double data) 
    {
        this->data = data;
        this->prev = this->next = NULL;
    }
};

class OneLinkedList 
{
private:
    Node* getAt(int k);
public:
    Node* head, * tail;

    OneLinkedList();
    OneLinkedList(const OneLinkedList& other);

    ~OneLinkedList();

    void pop_front();
    void push_back(double data);
    void push_front(double data);
    void pop_back();
    void insert(int k, double data);
    void earse(int k);
    int FindElem(double data);
    int GetElemData(int k, bool& ok);
    int GetListSize();
    bool remElm(double data);
    void sort();
    void transpose();
    void fill_size(int size);
    void fillRandom(int size);
    OneLinkedList sortedLists(const OneLinkedList& other);
};

#endif