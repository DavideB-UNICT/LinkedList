//
// Created by barba on 06/05/2021.
//

#ifndef LINKEDLIST_NODE_H
#define LINKEDLIST_NODE_H

#include <iostream>
#include <string>
using namespace std;

class Node {
private:
    double value;
    Node* next;
    Node* prev;
public:
    Node();
    Node(double value);
    Node(double value, Node* prev, Node* next);
    double getValue();
    void setValue(double value);
    Node* getNext();
    void setNext(Node* node);
    Node* getPrev();
    void setPrev(Node* node);
    string toString();
    ostream& operator<<(ostream& stream);
};


#endif //LINKEDLIST_NODE_H
