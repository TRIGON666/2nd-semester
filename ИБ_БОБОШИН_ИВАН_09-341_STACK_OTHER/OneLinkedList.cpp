#include "OneLinkedList.h"
#include <iostream>
#include <ctime>

OneLinkedList::OneLinkedList() {
    this->head = this->tail = NULL;
}

OneLinkedList::OneLinkedList(const OneLinkedList& other) {
    head = tail = NULL;
    Node* node = other.head;
    while (node) {
        push_back(node->data);
        node = node->next;
    }
}

OneLinkedList::~OneLinkedList() {
    while (head != NULL) pop_front();
}

void OneLinkedList::pop_front() {
    if (head == NULL) return;
    if (head == tail) {
        delete tail;
        head = tail = NULL;
        return;
    }

    Node* node = head;
    head = node->next;
    delete node;
}

void OneLinkedList::push_back(double data) {
    Node* node = new Node(data);
    if (head == NULL) {
        head = node;
        tail = node;
    }
    else {
        tail->next = node;
        tail = node;
    }
}

void OneLinkedList::push_front(double data) {
    Node* node = new Node(data);
    node->next = head;
    head = node;
    if (tail == NULL) tail = node;
}

void OneLinkedList::pop_back() {
    if (tail == NULL) return;
    if (head == tail) {
        delete tail;
        head = tail = NULL;
        return;
    }

    Node* node = head;
    for (; node->next != tail; node = node->next);
    node->next = NULL;
    delete tail;
    tail = node;
}

Node* OneLinkedList::getAt(int k) {
    if (k < 0) return NULL;

    Node* node = head;
    int n = 0;
    while (node && n != k) {
        node = node->next;
        n++;
    }
    return (n == k) ? node : NULL;
}

void OneLinkedList::insert(int k, double data) {
    Node* left = getAt(k);
    if (left == NULL) return;

    Node* right = left->next;
    Node* node = new Node(data);

    left->next = node;
    node->next = right;
    if (right == NULL) tail = node;
}

void OneLinkedList::earse(int k) {
    if (k < 0) return;

    if (k == 0) {
        pop_front();
        return;
    }

    Node* left = getAt(k - 1);

    if (left == NULL) return;

    Node* node = left->next;

    if (node == NULL) return;

    Node* right = node->next;

    left->next = right;
    if (node == tail) tail = left;
    delete node;
}

int OneLinkedList::FindElem(double data) {
    int k = 0;
    Node* node = head;
    while (node) {
        if (node->data == data) return k;
        node = node->next;
        k++;
    }
    return -1;
}

int OneLinkedList::GetElemData(int k, bool& ok) {
    Node* node = getAt(k);
    if (node) {
        ok = true;
        return node->data;
    }
    ok = false;
    return INT_MIN;
}

int OneLinkedList::GetListSize() {
    Node* node = head;
    int n = 0;
    while (node) {
        node = node->next;
        n++;
    }
    return n;
}

bool OneLinkedList::remElm(double data) {
    bool del = false;
    Node* node = head;
    Node* prev = NULL;

    while (node != NULL) {
        if (node->data == data) {
            Node* tmp = node;
            if (prev != NULL)
                prev->next = node->next;
            else
                head = node->next;
            node = node->next;
            delete tmp;
            del = true;
        }
        else {
            prev = node;
            node = node->next;
        }
    }

    return del;
}

void OneLinkedList::sort() {
    if (!head || !head->next) return;

    Node* sorted = NULL;
    Node* unsorted = head;

    while (unsorted) {
        Node* node = unsorted;
        unsorted = unsorted->next;

        if (!sorted || sorted->data >= node->data) {
            node->next = sorted;
            sorted = node;
        }
        else {
            Node* prev = NULL;
            Node* tmp = sorted;
            while (tmp && tmp->data < node->data) {
                prev = tmp;
                tmp = tmp->next;
            }

            if (!prev) {
                node->next = sorted;
                sorted = node;
            }
            else {
                node->next = prev->next;
                prev->next = node;
            }
        }
    }

    head = sorted;

    Node* lastNode = sorted;
    while (lastNode->next) {
        lastNode = lastNode->next;
    }
    tail = lastNode;
}

void OneLinkedList::transpose() {
    if (!head || !head->next) return;

    Node* node = head;
    Node* prev = NULL;
    Node* ptr;

    while (node) {
        ptr = node->next;
        node->next = prev;
        prev = node;
        node = ptr;
    }

    head = prev;
    tail = head;
}

void OneLinkedList::fill_size(int size) {
    double data;
    for (int i = 0; i < size; ++i) {
        std::cin >> data;
        push_back(data);
    }
}

void OneLinkedList::fillRandom(int size) {
    srand(time(0));
    double data;
    for (int i = 0; i < size; ++i) {
        data = (double)rand() / RAND_MAX;
        push_back(data);
    }
}

OneLinkedList OneLinkedList::sortedLists(const OneLinkedList& other) {
    OneLinkedList result;
    Node* node = other.head;
    while (node) {
        result.push_back(node->data);
        node = node->next;
    }
    result.sort();
    return result;
}