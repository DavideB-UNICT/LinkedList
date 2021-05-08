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
    void setNode(int index, Node<T>* node) {
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
public:
    LinkedList() {
        this->setHead(nullptr);
    }
    T at(int index) {
        Node<T>* node = this->getNode(index);
        return node->getValue();
    }
    void at(int index, T value) {
        Node<T>* node = this->getNode(index);
        auto* next = new Node<T>(value);
        node->setNext(next);
        next->setPrev(node);
        next->setNext(node->getNext());
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
    T operator[](int index) {
        return this->at(index);
    }
};


#endif //LINKEDLIST_LINKEDLIST_H
