//
// Created by barba on 06/05/2021.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include <iostream>
#include "Node.h"
using namespace std;

template<typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* getHead() const {
        return this->head;
    }
    void setHead(Node<T>* head) {
        this->head = head;
    }
    Node<T>* getNode(int index) const {
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
    T* at(int index) const {
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
    Node<T>* begin() {
        return this->getHead();
    }
    void clear() {
        Node<T>* pointer = this->getHead();
        int currentSize = this->size();
        for (int i = 0; i < currentSize; i++) {
            Node<T>* temp = pointer;
            pointer = pointer->getNext();
            delete temp;
        }
        this->setHead(nullptr);
    }
    bool empty() {
        return this->getHead() == nullptr;
    }
    Node<T>* end() {
        return this->getHead()->getPrev();
    }
    void insert(int index, T value) {
        Node<T>* currentHead = this->getHead();
        Node<T>* node = this->getNode(index);
        if (node != nullptr) {
            Node<T>* next = node->getNext();
            Node<T>* insert = new Node<T>(value, node, next);
            node->setNext(insert);
            next->setPrev(insert);
            if (index == 0) {
                this->setHead(insert);
            }
        } else if (currentHead == nullptr && index == 0) {
            Node<T>* newHead = new Node<T>(value);
            newHead->setNext(newHead);
            newHead->setPrev(newHead);
            this->setHead(newHead);
        } else {
            cerr << "Element not inserted. Index not in range" << endl;
        }
    }
    void pop_back() {
        Node<T>* pointer = this->getHead();
        if (pointer != nullptr) {
            auto last = pointer->getPrev();
            if (last == pointer) {
                delete this->getHead();
                this->setHead(nullptr);
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
            pointer->setPrev(node);
        } else {
            node->setNext(node);
            node->setPrev(node);
            this->setHead(node);
        }
    }
    void remove(int index) {
        Node<T>* currentHead = this->getHead();
        Node<T>* node = this->getNode(index);
        if (node != nullptr) {
            Node<T>* prev = node->getPrev();
            Node<T>* next = node->getNext();
            prev->setNext(next);
            next->setPrev(prev);
            if (node == currentHead) {
                this->setHead(next);
            }
            delete node;
        } else {
            cerr << "Element not deleted. Index not in range" << endl;
        }
    }
    int size() const {
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
    string toString() const {
        int currentSize = this->size();
        string s = "Linked list: \nSize: " + to_string(currentSize) + "\nData: \n";
        if (!currentSize) {
            s += "Empty list";
        }
        else {
            for (int i = 0; i < currentSize; i++) {
                s += to_string(i + 1) + ") " + to_string(*this->at(i)) + "\n";
            }
        }
        return s;
    }
    T* operator[](int index) {
        return this->at(index);
    }
    friend ostream& operator<<(ostream& stream, const LinkedList<T> list) {
        stream << list.toString();
        return stream;
    }
};


#endif //LINKEDLIST_LINKEDLIST_H
