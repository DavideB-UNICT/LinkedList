//
// Created by barba on 06/05/2021.
//

#ifndef LINKEDLIST_NODE_H
#define LINKEDLIST_NODE_H

#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Node {
private:
    T value;
    Node<T>* next;
    Node<T>* prev;
public:
    Node();
    Node(T value);
    Node(T value, Node<T>* prev, Node<T>* next);
    T getValue();
    void setValue(T value);
    Node<T>* getNext();
    void setNext(Node<T>* node);
    Node<T>* getPrev();
    void setPrev(Node<T>* node);
    string toString();
    ostream& operator<<(ostream& stream);
};


#endif //LINKEDLIST_NODE_H
