#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>

class DoublyLinkedList {
private:
    struct Node {
        int color;
        Node* prev;
        Node* next;

        explicit Node(int value)
            : color(value), prev(nullptr), next(nullptr) {}
    };

    Node* head_;
    Node* tail_;
    int size_;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void PushBack(int value);
    void Clear();

    int Size() const;

    Node* Head() const;
    Node* Tail() const;

    void Print() const;
};

#endif