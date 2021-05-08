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
    Node<T>* getHead() {
        return this->head;
    }
    void setHead(Node<T>* head) {
        this->head = head;
    }
    Node<T>* getNode(int index) {
        int current = 0;
        int headNum = 0;
        Node<T>* currentHead = this->getHead();
        Node<T>* pointer = currentHead;
        while (current != index) {
            pointer = pointer->getNext();
            current++;
            if (pointer == currentHead) headNum++;
        }
        if (headNum > 0) return nullptr;
        return pointer;
    }
public:
    LinkedList() {
        this->setHead(nullptr);
    }
    T* at(int index) {
        Node<T>* node = this->getNode(index);
        if (node == nullptr) return nullptr;
        return new T(node->getValue());
    }
    void at(int index, T value) {
        Node<T>* node = this->getNode(index);
        if (node != nullptr) {
            node->setValue(value);
        } else {
            cerr << "Value not modified. Index not in range" << endl;
        }
    }
    bool empty() {
        return this->getHead() == nullptr;
    }
    void pop_back() {
        Node<T>* pointer = this->getHead();
        if (pointer != nullptr) {
            auto last = pointer->getPrev();
            if (last == pointer) {
                delete this->getHead();
            } else {
                auto prePrev = last->getPrev();
                prePrev->setNext(pointer);
                pointer->setPrev(prePrev);
                delete last;
            }
        }
    }
    void push_back(T value) {
        Node<T>* pointer = this->getHead();
        auto node = new Node<T>(value);
        if (pointer != nullptr) {
            auto last = pointer->getPrev();
            node->setNext(pointer);
            node->setPrev(last);
            last->setNext(node);
        } else {
            node->setNext(node);
            node->setPrev(node);
            this->setHead(node);
        }
    }
    void remove(int index) {
        Node<T>* node = this->getNode(index);
        if (node != nullptr) {
            Node<T>* prev = node->getPrev();
            Node<T>* next = node->getNext();
            prev->setNext(next);
            next->setPrev(prev);
            delete node;
        } else {
            cerr << "Element not deleted. Index not in range" << endl;
        }
    }
    int size() {
        int size = 0;
        Node<T>* pointer = this->getHead();
        Node<T>* next = nullptr;
        if (pointer != nullptr) {
            next = pointer->getNext();
            size++;
        }
        while (next != nullptr && next != pointer) {
            next = next->getNext();
            size++;
        }
        return size;
    }
    T* operator[](int index) {
        return this->at(index);
    }
};


#endif //LINKEDLIST_LINKEDLIST_H
