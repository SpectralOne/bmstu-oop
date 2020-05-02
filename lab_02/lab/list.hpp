#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <memory>
#include <fstream>
#include <vector>

#include "exceptions.h"

template <class T>
using Shared = std::shared_ptr<T>;

#include "list_iterator.hpp"
#include "__list_iterator.hpp"

#include "list_node.hpp"
#include "__list_node.hpp"

template <typename T>
class List {
 public:
    List();
    explicit List(const List<T>& l);
    List(List<T>&& l);
    List(T data, size_t n = 1);
    explicit List(ListIterator<T>& first, ListIterator<T>& last);
    
    List(std::vector<T> vec);
    explicit List(std::istream& is);
    List(std::initializer_list<T> il);

    virtual ~List();

    List<T>& operator=(const List<T>& l) = default;
    List<T>& operator=(List<T>&& l);

    List<T>& operator+=(const List<T>& l);
    List<T>& operator+=(const T data);

    List<T>& operator+(const List<T>& l);
    List<T>& operator+(const T data);

    bool operator==(const List<T>& l) const;
    bool operator!=(const List<T>& l) const;

    size_t size() const;
    void clear();
    void flush();
    bool isEmpty() const;
    size_t length() const;
    void unique();

    ListIterator<T>& begin();
    ListIterator<T>& end();
    ListIteratorConst<T>& begin() const;
    ListIteratorConst<T>& end() const;

    List<T>& append(const List<T>& l);
    List<T>& append(const T data);

    T popBackArg();
    void popBack();

    T popFrontArg();
    void popFront();

    List<T>& insertFront(const List<T>& l);
    List<T>& insertFront(const T data);

    List<T>& insertAfter(ListIterator<T>& it, const T data);
    List<T>& insertAfter(ListIterator<T>& it, const List<T>& after);

    List<T>& insertBefore(ListIterator<T>& it, const T data);
    List<T>& insertBefore(ListIterator<T>& it, const List<T>& before);

    List<T>& insertBefore(ListIteratorConst<T>& it, const T data);
    List<T>& insertBefore(ListIteratorConst<T>& it, const List<T>& before);

    void sort(bool ascending = true);
    void reverse();
    std::vector<T> to_vect() const;
    
    Shared<ListNode<T>> find(const T data) const;
    Shared<ListNode<T>> del(ListIterator<T>& it);
    List<T>& reset(ListIterator<T>& it, const T data);
    
    friend class ListIterator<T>;
    friend class ListIteratorConst<T>;

 protected:
    List<T>& operator+=(const Shared<ListNode<T>> data);
    List<T>& operator+(const Shared<ListNode<T>> data);

    Shared<ListNode<T>> find(const Shared<ListNode<T>> node) const;
    Shared<ListNode<T>> del(const Shared<ListNode<T>> node);
    List<T>& reset(Shared<ListNode<T>> node, Shared<ListNode<T>> temp);
    List<T>& reset(Shared<ListNode<T>> node, T data);

    List<T>& append(Shared<ListNode<T>> node);
    List<T>& insertFront(Shared<ListNode<T>> node);

    List<T>& insertAfter(Shared<ListNode<T>> node, Shared<ListNode<T>> after);
    List<T>& insertAfter(Shared<ListNode<T>> node, const T data);
    List<T>& insertAfter(Shared<ListNode<T>> node, List<T>& after);

    List<T>& insertBefore(Shared<ListNode<T>> node, Shared<ListNode<T>> before);
    List<T>& insertBefore(Shared<ListNode<T>> node, const T data);
    List<T>& insertBefore(Shared<ListNode<T>> node, List<T>& before);

 private:
    Shared<ListNode<T>> head;
    Shared<ListNode<T>> tail;
};

#include "__list.hpp"

#endif  // LIST_H
