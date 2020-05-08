#ifndef LIST_NODE_H
#define LIST_NODE_H
#include <iostream>

#include "exceptions.h"
#include "list.hpp"
#include "list_iterator.hpp"

namespace flexlist {
template <typename T>
class List;
template <typename T>
class Iterator;

template <typename T>
class ListNode {
 public:
    ListNode();
    explicit ListNode(T data);
    explicit ListNode(Shared<ListNode<T>> node);
    ~ListNode();

    void setNext(Shared<ListNode<T>> node);
    Shared<ListNode<T>> getNext();
    void destroyNext();
    T getData() const;
    void setData(T data);

    friend class List<T>;
    friend class Iterator<T>;

 private:
    Shared<ListNode<T>> next;
    T data;
};
}  // namespace flexlist

#endif  // LIST_NODE_H
