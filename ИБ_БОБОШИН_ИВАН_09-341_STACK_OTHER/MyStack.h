#include <iostream>

#ifndef MYSTACK_H
#define MYSTACK_H
  
template<typename T>
class MyStack {
private:
    class Node {
        T info;
        Node* next;

        Node(T info) {
            this->info = info;
            this->next = next;
        }
    };

   
public:
    Node* head;
    MyStack();
    ~MyStack();
    void print();
    bool isEmpty();
    void push(T info);
    T top();
    T pop();
};

#endif
