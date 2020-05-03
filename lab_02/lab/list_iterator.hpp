#ifndef LIST_ITERATOR_H
#define LIST_ITERATOR_H

#include "base_iterator.hpp"
#include "exceptions.h"
#include "list.hpp"
#include "list_node.hpp"

template <typename T>
class ListIterator : public BaseIterator<ListNode<T>> {
 public:
    ListIterator(const List<T>& l);
    ListIterator(const ListIterator<T>& it);
    ~ListIterator();

    void first();
    void next();
    void last();
    bool range();
    const T current();

    Shared<List<T>> operator=(List<T> &l);
    ListIterator<T>& operator=(const ListIterator<T>& it);

    ListIterator<T>& operator++();
    ListIterator<T> operator++(int);
    Shared<ListNode<T>> operator*();
    Shared<ListNode<T>> operator->();
    ListIterator<T>& operator+=(size_t n);
    ListIterator<T> operator+(size_t n) const;

    bool operator!=(const ListIterator<T>& it) const;
    bool operator==(const ListIterator<T>& it) const;
    bool operator<(const ListIterator<T>& it) const;
    bool operator>(const ListIterator<T>& it) const;
    bool operator<=(const ListIterator<T>& it) const;
    bool operator>=(const ListIterator<T>& it) const;

 private:
    const List<T> *currentList;
    Shared<ListNode<T>> currentNode;
};

template <class T>
class ListIteratorConst : public BaseIterator<ListNode<T>> {
 public:
    ListIteratorConst(const List<T>& l);
    ListIteratorConst(const ListIteratorConst<T>& it);
    ~ListIteratorConst();

    void first();
    void next();
    void last();
    bool range();
    const T& current() const;

    const Shared<ListNode<T>> operator*();
    const Shared<ListNode<T>> operator->();

    bool operator!=(const ListIteratorConst<T>& it) const;
    bool operator==(const ListIteratorConst<T>& it) const;
    bool operator<(const ListIteratorConst<T>& it) const;
    bool operator>(const ListIteratorConst<T>& it) const;
    bool operator<=(const ListIteratorConst<T>& it) const;
    bool operator>=(const ListIteratorConst<T>& it) const;

    int difference(const ListIteratorConst<T>& it);

 private:
    const List<T>* currentList;
    Shared<ListNode<T>> currentNode;
};

#endif  // LIST_ITERATOR_H
