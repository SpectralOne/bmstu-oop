#ifndef LIST_ITERATOR_H
#define LIST_ITERATOR_H

#include <cstddef>
#include <algorithm>
#include <iterator>
#include <ctime>

#include "exceptions.h"
#include "list.hpp"
#include "list_node.hpp"

template <typename T>
using base = std::iterator<std::forward_iterator_tag, T>;

template <typename T>
using pointer = typename base<T>::pointer;

template <typename T>
using reference = typename base<T>::reference;

template <typename T>
using difference_type = typename base<T>::difference_type;

template <typename T>
using const_pointer = const T*;

template <typename T>
using const_reference = const T&;


namespace flexlist {
template <typename T>
class Iterator : public std::iterator<std::forward_iterator_tag, T> {
 public:
    Iterator() = default;
    explicit Iterator(List<T>& l) : node(l.head) { }
    explicit Iterator(Shared<ListNode<T>> n) : node(n) { }
    Iterator(const Iterator<T>&) = default;
    Iterator<T>& operator=(const Iterator<T>&) = default;
    ~Iterator() = default;

    void next();
    bool check() noexcept;
    T get();
    T getNext();
    Weak<ListNode<T>> getNode();

    operator bool() noexcept;

    reference<T> operator*();
    const_reference<T> operator*() const;

    pointer<T> operator->();
    const_pointer<T> operator->() const;
    
    Iterator<T>& operator++();
    const Iterator<T> operator++(int);
    Iterator<T>& operator+=(difference_type<T> n);

    friend class ListNode<T>;

    template <typename U> friend bool operator==(const Iterator<U>& a, const Iterator<U>& b);
    template <typename U> friend void swap(Iterator<U>& a, Iterator<U>& b);
    template <typename U> friend bool operator<(const Iterator<U>& a, const Iterator<U>& b);
 private:
    Weak<ListNode<T>> node;
};
}  // namespace flexlist

#endif  // LIST_ITERATOR_H
