//
// Created by barba on 06/05/2021.
//

#include "LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList() {
    this->setHead(nullptr);
}
template <typename T>
Node<T>* LinkedList<T>::getHead() {
    return this->head;
}
template <typename T>
void LinkedList<T>::setHead(Node<T>* head) {
    this->head = head;
}
template <typename T>
Node<T>* LinkedList<T>::getNode(int index) {
    Node<T>* pointer = this->getHead();
    try {
        for (int i = 0; i < index; i++) {
            Node<T>* next = pointer->getNext();
            if (next != nullptr) {
                pointer = next;
                if (i == index) return pointer;
            } else {
                throw out_of_range("Element out of range");
            }
        }
    } catch (out_of_range& e) {
        cerr << e.what() << endl;
    }
}
template <typename T>
void LinkedList<T>::setNode(int index, Node<T>* node) {
    Node<T>* pointer = this->getHead();
    try {
        for (int i = 0; i < index; i++) {
            auto next = pointer->getNext();
            if (next != nullptr) {
                pointer = next;
                if (i == index) pointer = node;
            } else {
                throw out_of_range("Element out of range");
            }
        }
    } catch (out_of_range& e) {
        cerr << e.what() << endl;
    }
}
template <typename T>
T LinkedList<T>::at(int index)  {
    Node<T>* node = this->getNode(index);
    return node->getValue();
}
template <typename T>
void LinkedList<T>::at(int index, T value) {
    Node<T>* node = this->getNode(index);
    auto* next = new Node<T>(value);
    node->setNext(next);
    next->setPrev(node);
    next->setNext(node->getNext());
}
template <typename T>
bool LinkedList<T>::empty()  {
    return this->getHead() == nullptr;
}
template <typename T>
void LinkedList<T>::pop_back() {
    Node<T>* pointer = this->getHead();
    Node<T>* next = pointer->getNext();
    while (next == pointer) {
        pointer = next;
        next = pointer->getNext();
    }
    delete pointer->getNext();
}
template <typename T>
void LinkedList<T>::push_back(T value) {
    Node<T>* pointer = this->getHead();
    Node<T>* next = pointer->getNext();
    while (next == pointer) {
        pointer = next;
        next = pointer->getNext();
    }
    auto* newNext = new Node<T>(value);
    pointer->setNext(newNext);
    newNext->setPrev(pointer);
    newNext->setNext(nullptr);
}
template <typename T>
void LinkedList<T>::remove(int index) {
    Node<T>* node = this->getNode(index);
}
template <typename T>
int LinkedList<T>::size() {
    int size = 0;
    Node<T>* pointer = this->getHead();
    while (pointer->getNext() != nullptr) {
        pointer = pointer->getNext();
        size++;
    }
    return size;
}
template <typename T>
T LinkedList<T>::operator[](int index) {
    return this->at(index);
}