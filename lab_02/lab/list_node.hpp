#ifndef LIST_NODE_H
#define LIST_NODE_H
#include <iostream>

#include "exceptions.h"
#include "list.hpp"
#include "list_iterator.hpp"

template <typename T>
class List;
template <typename T>
class ListIterator;

template <typename T>
class ListNode {
 public:
    ListNode();
    ListNode(T data);
    explicit ListNode(Shared<ListNode<T>> node);
    ~ListNode();

    void setNext(Shared<ListNode<T>> node);
    Shared<ListNode<T>> getNext();
    void destroyNext();
    T getData() const;
    void set(T data);

    List<T>& operator+(List<T>& l);

    friend class List<T>;
    friend class ListIterator<T>;

 private:
    Shared<ListNode<T>> next;
    T data;
};

#endif  // LIST_NODE_H
