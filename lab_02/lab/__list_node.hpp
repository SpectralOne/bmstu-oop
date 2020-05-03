#ifndef __LIST_NODE_H
#define __LIST_NODE_H

namespace flexlist {
    template <typename T>
    ListNode<T>::ListNode() {
        this->next = nullptr;
    }

    template <typename T>
    ListNode<T>::ListNode(T data) {
        this->data = data;
        this->next = nullptr;
    }

    template <typename T>
    ListNode<T>::ListNode(Shared<ListNode<T>> node) {
        this->data = node->data;
        this->next = node->next;
    }

    template <typename T>
    ListNode<T>::~ListNode() {
        this->next = nullptr;
    }

    template <typename T>
    void ListNode<T>::setNext(Shared<ListNode<T>> node) {
        this->next = node;
    }

    template <typename T>
    Shared<ListNode<T>> ListNode<T>::getNext() {
        return this->next;
    }

    template <typename T>
    void ListNode<T>::destroyNext() {
        if (this->next) {
            this->next.reset();
        }

        this->next = nullptr;
    }

    template <typename T>
    T ListNode<T>::getData() const {
        return this->data;
    }

    template <typename T>
    void ListNode<T>::set(T data) {
        this->data = data;
    }

    template <typename T>
    bool operator>(Shared<ListNode<T>> n1, Shared<ListNode<T>> n2) {
        return n1->getData() > n2->getData();
    }

    template <typename T>
    bool operator<(Shared<ListNode<T>> n1, Shared<ListNode<T>> n2) {
        return n1->getData() < n2->getData();
    }
}  // namespace flexlist

#endif  // __LIST_NODE_H
