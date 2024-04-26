#include "MyStack.h"
#include <iostream>

template<typename T>
MyStack<T>::MyStack()
{
    head = NULL;
}

template<typename T>
MyStack<T>::~MyStack() 
{
    while (!isEmpty())
        pop();
}

template<typename T>
void MyStack<T>::print() 
{
    std::cout << "(";
    for (Node* cur = head; cur != NULL; cur = cur->next)
        std::cout << cur->info << " ";
    std::cout << ")" << "\n";
}

template<typename T>
bool MyStack<T>::isEmpty() 
{
    return head == NULL;
}

template<typename T>
void MyStack<T>::push(T info) 
{
    head = new Node(info, head);
}

template<typename T>
T MyStack<T>::top() 
{
    if (isEmpty()) 
        throw -1;
    return head->info;
}

template<typename T>
T MyStack<T>::pop() 
{
    if (isEmpty()) 
        throw -1;
    T res = head->info;
    Node* help = head;
    head = head->next;

    delete help;

    return res;
}