#ifndef __LIST_ITERATOR_H
#define __LIST_ITERATOR_H

template <typename T>
ListIterator<T>::ListIterator(const List<T>& l) {
    this->currentList = &l;
    this->currentNode = l.head;
}

template <typename T>
ListIterator<T>::ListIterator(const ListIterator<T>& it) {
    this->currentList = it.currentList;
    this->currentNode = it.currentNode;
}

template <typename T>
ListIterator<T>::~ListIterator() {
    this->currentList = nullptr;
    this->currentNode = nullptr;
}

template <typename T>
ListIterator<T>& ListIterator<T>::operator=(const ListIterator<T>& it) {
    this->currentList = it.currentList;
    this->currentNode = it.currentNode;
    return *this;
}

template <typename T>
void ListIterator<T>::first() {
    this->currentNode = this->currentList->head;
}

template <typename T>
void ListIterator<T>::last() {
    this->currentNode = this->currentList->tail;
}

template <typename T>
void ListIterator<T>::next() {
    if (!this->range())
        throw ListOutOfBounds();

    this->currentNode = this->currentNode->next;
}

template <typename T>
bool ListIterator<T>::range() {
    return !(this->currentNode == nullptr);
}

template <typename T>
ListIterator<T>& ListIterator<T>::operator++() {
    if (!this->range())
        throw ListOutOfBounds();
    this->next();

    return *this;
}

template <typename T>
ListIterator<T> ListIterator<T>::operator++(int) {
    if (!this->range())
        throw ListOutOfBounds();

    ListIterator<T> r(*this);
    this->next();

    return r;
}

template <typename T>
const T ListIterator<T>::current() {
    if (!this->range())
        throw EmptyList();

    return this->currentNode->getData();
}

template <typename T>
Shared<ListNode<T>> ListIterator<T>::operator*() {
    return this->currentNode;
}

template <typename T>
Shared<ListNode<T>> ListIterator<T>::operator->() {
    return this->currentNode;
}

template <typename T>
ListIterator<T>& ListIterator<T>::operator+=(size_t n) {
    while (n--) {
        if (!this->range()) {
            throw ListOutOfBounds();
        }
        this->currentNode = this->currentNode->next;
    }

    return *this;
}

template <typename T>
ListIterator<T> ListIterator<T>::operator+(size_t n) const {
    ListIterator<T> it(*this);

    it += n;

    return it;
}

template <typename T>
bool ListIterator<T>::operator!=(const ListIterator<T>& it) const {
    if (this->currentList != it.currentList) {
        throw IteratorCompareError();
    }

    return this->currentNode != it.currentNode;
}

template <typename T>
bool ListIterator<T>::operator==(const ListIterator<T>& it) const {
    if (this->currentList != it.currentList) {
        throw IteratorCompareError();
    }

    return this->currentNode == it.currentNode;
}

template <typename T>
bool ListIterator<T>::operator<(const ListIterator<T>& it) const {
    if (this->currentList != it.currentList) {
        throw IteratorCompareError();
    }

    return this->currentNode < it.currentNode;
}

template <typename T>
bool ListIterator<T>::operator>(const ListIterator<T>& it) const {
    if (this->currentList != it.currentList) {
        throw IteratorCompareError();
    }

    return this->currentNode > it.currentNode;
}

template <typename T>
bool ListIterator<T>::operator<=(const ListIterator<T>& it) const {
    if (this->currentList != it.currentList) {
        throw IteratorCompareError();
    }

    return this->currentNode <= it.currentNode;
}

template <typename T>
bool ListIterator<T>::operator>=(const ListIterator<T>& it) const {
    if (this->currentList != it.currentList) {
        throw IteratorCompareError();
    }

    return this->currentNode >= it.currentNode;
}

//––––––––––––––––––––––––––––––––––––––––

template <typename T>
ListIteratorConst<T>::ListIteratorConst(const List<T>& l) {
    this->currentList = &l;
    this->currentNode = l.head;
}

template <typename T>
ListIteratorConst<T>::ListIteratorConst(const ListIteratorConst<T>& it) {
    this->currentList = it.currentList;
    this->currentNode = it.currentNode;
}

template <typename T>
ListIteratorConst<T>::~ListIteratorConst() {
    this->currentList = nullptr;
    this->currentNode = nullptr;
}

template <typename T>
void ListIteratorConst<T>::first() {
    this->currentNode = this->currentList->get_head();
}

template <typename T>
void ListIteratorConst<T>::last() {
    if (this->currentList->get_head() == nullptr) {
        throw EmptyList();
    }

    this->currentNode = this->currentList->get_tail();
}

template <typename T>
void ListIteratorConst<T>::next() {
    if (!this->range()) {
        throw ListOutOfBounds();
    }

    this->currentNode = this->currentNode->getNext();
}

template <typename T>
bool ListIteratorConst<T>::range() {
    return this->currentNode == nullptr;
}

template <typename T>
const T& ListIteratorConst<T>::current() const {
    if (!this->range()) {
        throw EmptyList();
    }

    return this->currentNode->getData();
}

template <typename T>
const Shared<ListNode<T>> ListIteratorConst<T>::operator*() {
    return *this->currentNode;
}

template <typename T>
const Shared<ListNode<T>> ListIteratorConst<T>::operator->() {
    return this->currentNode;
}

template <typename T>
bool ListIteratorConst<T>::operator!=(const ListIteratorConst<T>& it) const {
    if (this->currentList != it.currentList) {
        throw IteratorCompareError();
    }

    return this->currentNode != it.currentNode;
}

template <typename T>
bool ListIteratorConst<T>::operator==(const ListIteratorConst<T>& it) const {
    if (this->currentList != it.currentList) {
        throw IteratorCompareError();
    }

    return this->currentNode == it.currentNode;
}

template <typename T>
bool ListIteratorConst<T>::operator<(const ListIteratorConst<T>& it) const {
    if (this->currentList != it.currentList) {
        throw IteratorCompareError();
    }

    return this->currentNode < it.currentNode;
}

template <typename T>
bool ListIteratorConst<T>::operator>(const ListIteratorConst<T>& it) const {
    if (this->currentList != it.currentList) {
        throw IteratorCompareError();
    }

    return this->currentNode > it.currentNode;
}

template <typename T>
bool ListIteratorConst<T>::operator<=(const ListIteratorConst<T>& it) const {
    if (this->currentList != it.currentList) {
        throw IteratorCompareError();
    }

    return this->currentNode <= it.currentNode;
}

template <typename T>
bool ListIteratorConst<T>::operator>=(const ListIteratorConst<T>& it) const {
    if (this->currentList != it.currentList) {
        throw IteratorCompareError();
    }

    return this->currentNode >= it.currentNode;
}

#endif  // __LIST_ITERATOR_H
