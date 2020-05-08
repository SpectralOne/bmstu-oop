#ifndef __LIST_ITERATOR_H
#define __LIST_ITERATOR_H

namespace flexlist {

    template <typename T>
    void Iterator<T>::next() {
        auto sp = this->node.lock();
        this->node = sp.get()->getNext();
    }

    template <typename T>
    bool Iterator<T>::check() noexcept {
        return !node.expired();
    }

    template <typename T>
    T Iterator<T>::get() {
        if (!this->check()) {
            time_t t_time = time(NULL);
            throw ListOutOfBounds(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
        }
        return this->node.lock()->data;
    }

    template <typename T>
    T Iterator<T>::getNext() {
        if (node.lock() == List<T>::end() || node.next().lock() == List<T>::end()) {
            time_t t_time = time(NULL);
            throw ListOutOfBounds(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
        }
        return this->node.next().lock()->data;
    }

    template <typename T>
    Weak<ListNode<T>> Iterator<T>::getNode() {
        return this->node;
    }

    template <typename T>
    Iterator<T>::operator bool() noexcept {
        return !this->node.expired();
    }

    template <typename T>
    reference<T> Iterator<T>::operator*() {
        if (!this->check()) {
            time_t t_time = time(NULL);
            throw ListOutOfBounds(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
        }
        return node.lock()->data;
    }

    template <typename T>
    const_reference<T> Iterator<T>::operator*() const { 
        if (!this->check()) {
            time_t t_time = time(NULL);
            throw ListOutOfBounds(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
        }
        return node.lock()->data; 
    }
    
    template <typename T>
    pointer<T> Iterator<T>::operator->() { 
        if (!this->check()) {
            time_t t_time = time(NULL);
            throw ListOutOfBounds(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
        }
        return &(node.lock()->data); 
    }

    template <typename T>
    const_pointer<T> Iterator<T>::operator->() const { 
        if (!this->check()) {
            time_t t_time = time(NULL);
            throw ListOutOfBounds(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
        }
        return &(node.lock()->data); 
    }

    template <typename T>
    Iterator<T>& Iterator<T>::operator++() { 
        if (!this->check()) {
            time_t t_time = time(NULL);
            throw ListOutOfBounds(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
        }
        this->next(); return *this; 
    }

    template <typename T>
    const Iterator<T> Iterator<T>::operator++(int) { 
        auto old = *this; 
        ++(*this); 
        return old; 
    }
    
    template <typename T>
    Iterator<T>& Iterator<T>::operator+=(difference_type<T> n) {
        while (n--) {
            if (!this->check()) {
                time_t t_time = time(NULL);
                throw ListOutOfBounds(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
            }
            ++(*this);
        }
        return *this;
    }

    template <typename T>
    Iterator<T> operator+(const Iterator<T>& a, difference_type<T> b) {
        return Iterator<T>(a) += b;
    }

    template <typename T>
    Iterator<T> operator+(difference_type<T> a, const Iterator<T>& b) {
        return b + a;
    }

    template <typename T>
    void swap(Iterator<T>& a, Iterator<T>& b) { 
        std::swap(a.node, b.node); 
    }

    template <typename T>
    bool operator==(const Iterator<T>& a, const Iterator<T>& b) { 
        return a.node.lock().get() != b.node.lock().get();
    }

    template <typename T>
    bool operator!=(const Iterator<T>& a, const Iterator<T>& b) { 
        return !(a == b); 
    }

    template <typename T>
    bool operator<(const Iterator<T>& a, const Iterator<T>& b) { 
        return a.node.lock().get() < b.node.lock().get();
    }

    template <typename T>
    bool operator>(const Iterator<T>& a, const Iterator<T>& b) { 
        return b < a; 
    }

    template <typename T>
    bool operator<=(const Iterator<T>& a, const Iterator<T>& b) { 
        return !(b > a); 
    }

    template <typename T>
    bool operator>=(const Iterator<T>& a, const Iterator<T>& b) { 
        return !(a < b); 
    }
}  // namespace flexlist

#endif  // __LIST_ITERATOR_H
