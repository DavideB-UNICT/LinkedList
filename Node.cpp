//
// Created by barba on 06/05/2021.
//

#include "Node.h"

Node::Node() {
    this->setValue(0);
    this->setNext(nullptr);
    this->setPrev(nullptr);
}
Node::Node(double value) {
    this->setValue(value);
    this->setNext(nullptr);
    this->setPrev(nullptr);
}
Node::Node(double value, Node* prev, Node* next) {
    this->setValue(value);
    this->setNext(next);
    this->setPrev(prev);
}
double Node::getValue() {
    return this->value;
}
void Node::setValue(double value) {
    this->value = value;
}
Node* Node::getNext() {
    return this->next;
}
void Node::setNext(Node* node) {
    this->next = node;
}
Node* Node::getPrev() {
    return this->prev;
}
void Node::setPrev(Node* node) {
    this->prev = node;
}
string Node::toString() {

}
ostream& Node::operator<<(ostream& stream) {

}
