//
// Created by barba on 06/05/2021.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include "Node.h"

template<typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* getHead();
    void setHead(Node<T>* head);
    Node<T>* getNode(int index);
    void setNode(int index, Node<T>* node);
public:
    LinkedList();
    T at(int index);
    void at(int index, T value);
    bool empty();
    void pop_back();
    void push_back(T value);
    void remove(int index);
    int size();
    T operator[](int index);
};


#endif //LINKEDLIST_LINKEDLIST_H
