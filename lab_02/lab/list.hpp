#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <memory>
#include <fstream>
#include <vector>

#include "exceptions.h"

template <class T>
using Shared = std::shared_ptr<T>;

template <class T>
using Weak = std::weak_ptr<T>;

#include "base_list.hpp"

#include "list_iterator.hpp"
#include "__list_iterator.hpp"

#include "list_node.hpp"
#include "__list_node.hpp"

namespace flexlist {
template <typename T>
class List : public BaseList {
 public:
    List();
    explicit List(const List<T>& l);
    List(List<T>&& l) noexcept;
    List(T data, size_t n = 1);
    
    List(T* array, const size_t size);
    explicit List(std::istream& is); 
    List(const std::initializer_list<T>& il);
    ~List() override;

    List<T>& operator=(const List<T>& l) = default;
    List<T>& operator=(List<T>&& l);
    List<T>& operator=(const std::initializer_list<T>& il);

    constexpr size_t size() const noexcept;
    void clear();
    bool isEmpty() const noexcept;
    void reverse();

    List<T>& operator+=(const List<T>& l);
    List<T>& operator+=(const T data);
    List<T>& pushBack(const List<T>& l);
    List<T>& pushBack(const T data);

    List<T>& pushFront(const List<T>& l);
    List<T>& pushFront(const T data);

    T popBack();
    T popFront();
    
    void remove(Iterator<T>& prev);
    void insert(Iterator<T>& prev, const T& data);

    bool operator==(const List<T>& l) const;
    bool operator!=(const List<T>& l) const;
    
    Iterator<T> begin() noexcept;
    Iterator<const T> begin() const noexcept;
    Iterator<T> end() noexcept;
    Iterator<const T> end() const noexcept;
   
    friend class Iterator<T>;

 protected:
    List<T>& pushBack(Shared<ListNode<T>> node);
    List<T>& pushFront(Shared<ListNode<T>> node);
    List<T>& operator+=(const Shared<ListNode<T>> data);

 private:
    Shared<ListNode<T>> head;
    Shared<ListNode<T>> tail;
};
}  // namespace flexlist

#include "__list.hpp"

#endif  // LIST_H
