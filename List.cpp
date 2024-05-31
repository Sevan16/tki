#include "list.h"

Node::Node(int data) {
    this->data = data;
    this->next = nullptr;
}

LinkedList::LinkedList() {
    this->head = nullptr;
}

LinkedList::~LinkedList() {
    this->clear();
}

void LinkedList::pushFront(int data) {
    Node* newNode = new Node(data);
    newNode->next = this->head;
    this->head = newNode;
}

void LinkedList::pushBack(int data) {
    Node* newNode = new Node(data);
    if (this->head == nullptr) {
        this->head = newNode;
    } else {
        Node* current = this->head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void LinkedList::popFront() {
    if (this->head == nullptr) {
        return;
    }
    Node* temp = this->head;
    this->head = this->head->next;
    delete temp;
}

void LinkedList::popBack() {
    if (this->head == nullptr) {
        return;
    }
    if (this->head->next == nullptr) {
        delete this->head;
        this->head = nullptr;
    } else {
        Node* current = this->head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }
}

void LinkedList::clear() {
    while (this->head != nullptr) {
        this->popFront();
    }
}

void LinkedList::printList() const {
    Node* current = this->head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
