#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList()
    : head_(nullptr), tail_(nullptr), size_(0) {}

DoublyLinkedList::~DoublyLinkedList() {
    Clear();
}

void DoublyLinkedList::PushBack(int value) {
    Node* node = new Node(value);

    if (!head_) {
        head_ = tail_ = node;
    } else {
        tail_->next = node;
        node->prev = tail_;
        tail_ = node;
    }

    ++size_;
}

void DoublyLinkedList::Clear() {
    Node* current = head_;

    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
}

int DoublyLinkedList::Size() const {
    return size_;
}

DoublyLinkedList::Node* DoublyLinkedList::Head() const {
    return head_;
}

DoublyLinkedList::Node* DoublyLinkedList::Tail() const {
    return tail_;
}

void DoublyLinkedList::Print() const {
    Node* current = head_;

    while (current) {
        std::cout << current->color << " ";
        current = current->next;
    }

    std::cout << std::endl;
}