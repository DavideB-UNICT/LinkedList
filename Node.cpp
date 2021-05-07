//
// Created by barba on 06/05/2021.
//

#include "Node.h"

template<typename T>
Node<T>::Node() {
    this->setNext(nullptr);
    this->setPrev(nullptr);
}
template<typename T>
Node<T>::Node(T value) {
    this->setValue(value);
    this->setNext(nullptr);
    this->setPrev(nullptr);
}
template<typename T>
Node<T>::Node(T value, Node<T>* prev, Node<T>* next) {
    this->setValue(value);
    this->setNext(next);
    this->setPrev(prev);
}
template<typename T>
T Node<T>::getValue() {
    return this->value;
}
template<typename T>
void Node<T>::setValue(T value) {
    this->value = value;
}
template<typename T>
Node<T>* Node<T>::getNext() {
    return this->next;
}
template<typename T>
void Node<T>::setNext(Node<T>* node) {
    this->next = node;
}
template<typename T>
Node<T>* Node<T>::getPrev() {
    return this->prev;
}
template<typename T>
void Node<T>::setPrev(Node<T>* node) {
    this->prev = node;
}
template<typename T>
string Node<T>::toString() {
    cout << this->getValue() << endl;
}
template<typename T>
ostream& Node<T>::operator<<(ostream& stream) {
    stream << this->toString();
    return stream;
}
