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
        int i = 0;
        for (Node<T>* node = this->begin(); node != this->end(); node = node->getNext()) {
            if (i == index) return node;
            i++;
        }
        return nullptr;
    }
public:
    class Iterator {
    private:
        int i_index;
        const LinkedList<T> *list;
    public:
        Iterator(const LinkedList<T> *vector, int nIndex) {
            this->list = vector;
            this->i_index = nIndex;
        }
        const T &operator*() const {
            return this->list[this->i_index];
        }
        Iterator &operator++() {
            this->i_index++;
            return *this;
        }
        bool operator!=(const Iterator &other) const {
            return this->i_index != other.i_index;
        }
    };
    LinkedList() {
        auto newHead = new Node<T>();
        newHead->setNext(newHead);
        newHead->setPrev(newHead);
        this->setHead(newHead);
    }
    T* at(int index) const {
        auto node = this->getNode(index);
        if (node == nullptr) return nullptr;
        return new T(node->getValue());
    }
    void at(int index, T value) {
        auto node = this->getNode(index);
        if (node != nullptr) {
            node->setValue(value);
        } else {
            cerr << "Value not modified. Index not in range" << endl;
        }
    }
    Node<T>* begin() const {
        return this->getHead();
    }
    void clear() {
        auto node = this->begin();
        auto end = this->end();
        while (node != end) {
            auto temp = node;
            node = node->getNext();
            delete temp;
        }
    }
    bool empty() const {
        return this->size() == 0;
    }
    Node<T>* end() const {
        return this->getHead()->getPrev();
    }
    void insert(int index, T value) {
        if (index < this->size()) {
            auto node = this->getNode(index);
            auto next = node->getNext();
            auto newNode = new Node<T>(value, node, next);
            node->setNext(newNode);
            next->setPrev(newNode);
        } else if (index == this->size()) {
            this->push_back(value);
        } else {
            cerr << "Element not inserted. Index not in range" << endl;
        }
    }
    void pop_back() {
        if (!this->empty()) {
            auto lastNode = this->end();
            auto prev = lastNode->getPrev();
            auto next = lastNode->getNext();
            prev->setNext(next);
            next->setPrev(prev);
            delete lastNode;
        } else {
            cerr << "Nothing to remove. Empty list" << endl;
        }
    }
    void push_back(T value) {
        auto lastNode = this->end();
        auto next = lastNode->getNext();
        auto newNode = new Node<T>(value, lastNode, next);
        lastNode->setNext(newNode);
        next->setPrev(newNode);
    }
    void remove(int index) {
        auto node = this->getNode(index);
        if (node != nullptr) {
            auto prev = node->getPrev();
            auto next = node->getNext();
            prev->setNext(next);
            next->setPrev(prev);
            delete node;
        } else {
            cerr << "Element not deleted. Index not in range" << endl;
        }
    }
    int size() const {
        int size = 0;
        for (Node<T>* node = this->begin(); node != this->end(); node = node->getNext()) size++;
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
