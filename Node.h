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
    Node() {
        this->setNext(nullptr);
        this->setPrev(nullptr);
    }
    explicit Node(T value) {
        this->setValue(value);
        this->setNext(nullptr);
        this->setPrev(nullptr);
    }
    Node(T value, Node<T>* prev, Node<T>* next) {
        this->setValue(value);
        this->setNext(next);
        this->setPrev(prev);
    }
    T getValue() const {
        return this->value;
    }
    void setValue(T value) {
        this->value = value;
    }
    Node<T>* getNext() {
        return this->next;
    }
    void setNext(Node<T>* node) {
        this->next = node;
    }
    Node<T>* getPrev() {
        return this->prev;
    }
    void setPrev(Node<T>* node) {
        this->prev = node;
    }
    string toString() const {
        return to_string(this->getValue());
    }
    friend ostream& operator<<(ostream& stream, const Node<T> node) {
        stream << node.toString() << endl;
        return stream;
    }
};


#endif //LINKEDLIST_NODE_H
