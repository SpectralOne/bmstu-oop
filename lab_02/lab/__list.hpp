#ifndef __LIST_H
#define __LIST_H
#include <ctime>

namespace flexlist {
    template <typename T>
    List<T>::List() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    template <typename T>
    List<T>::List(const List<T>& l) {
        if (!l.head) {
            this->head = nullptr;
            this->tail = nullptr;
        } else {
            time_t t_time = time(NULL);
            Shared<ListNode<T>> cur(nullptr);
            Shared<ListNode<T>> head = std::make_shared<ListNode<T>>();
            if (head == nullptr) {
                throw MemmoryError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
            }

            head->setData(l.head->getData());
            this->head = head;

            Shared<ListNode<T>> tmp(head);
            cur = l.head->next;

            for (; cur; cur = cur->next) {
                Shared<ListNode<T>> node = std::make_shared<ListNode<T>>();
                if (node == nullptr) {
                    throw MemmoryError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
                }

                tmp->setNext(node);
                node->setData(cur->getData());
                this->tail = node;
                tmp = tmp->next;
            }
        }
    }

    template <typename T>
    List<T>::List(List<T>&& l) noexcept {
        this->head = l.head;
        this->tail = l.tail;
    }

    template <typename T>
    List<T>::List(T data, size_t n) {
        time_t t_time = time(NULL);
        if (n < 0) {
            throw ConstructorBadArguments(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
        }

        if (n == 0) {
            this->head = nullptr;
        } else {
            Shared<ListNode<T>> head = std::make_shared<ListNode<T>>();
            if (head == nullptr) {
                throw MemmoryError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
            }

            head->setData(data);
            this->head = head;

            Shared<ListNode<T>> cur = head;
            for (size_t i = 0; i < n - 1; ++i) {
                Shared<ListNode<T>> node = std::make_shared<ListNode<T>>();
                if (node == nullptr) {
                    throw MemmoryError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
                }

                node->setData(data);
                cur->setNext(node);
                cur = node;
            }
            this->tail = cur;
        }
    }

    template <typename T>
    List<T>::List(T* array, const size_t size) {
        if (array == nullptr) {
            time_t t_time = time(NULL);
            throw MemmoryError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
        }
        for (size_t i = 0; i < size; ++i) {
            this->pushBack(array[i]);
        }
    }

    template <typename T>
    List<T>::List(std::istream& is) {
        this->head = nullptr;
        this->tail = nullptr;

        time_t t_time = time(NULL);
        if (!is) {
            throw InvalidListStream(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
        }

        if (is.peek() == std::ifstream::traits_type::eof()) {
            throw InvalidListStream(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
        }

        T arg;
        while (is >> arg) {
            this->pushBack(arg);
        }

        if (!is.eof()) {
            throw InvalidListStream(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
        }
    }

    template <typename T>
    List<T>::List(const std::initializer_list<T>& il) {
        this->head = nullptr;
        this->tail = nullptr;

        if (il.size()) {
            for (auto &node : il) {
                this->pushBack(node);
            }
        }
    }

    template <typename T>
    List<T>::~List() {
        if (this->head) {
            Shared<ListNode<T>> next;
            for (; this->head; this->head = next) {
                next = this->head->next;
                this->head.reset();
            }
        }

        this->head = nullptr;
        this->tail = nullptr;
    }

    template <typename T>
    List<T>& List<T>::operator=(List<T>&& l) {
        this->head = l.head;
        this->tail = l.tail;
        return *this;
    }

    template <typename T>
    List<T>& List<T>::operator=(const std::initializer_list<T>& il) {
        for (auto &i : il) {
            this->pushBack(i);
        }
    }

    template <typename T>
    List<T>& List<T>::operator+=(const List<T>& l) {
        this->pushBack(l);
        return *this;
    }

    template <typename T>
    List<T>& List<T>::operator+=(const Shared<ListNode<T>> data) {
        this->pushBack(data);
        return *this;
    }

    template <typename T>
    List<T>& List<T>::operator+=(const T data) {
        this->pushBack(data);
        return *this;
    }

    template <typename T>
    bool List<T>::operator==(const List<T>& l) const {
        Shared<ListNode<T>> curt(this->head);
        Shared<ListNode<T>> curl(l.head);
        while (curt && curl && curt->data == curl->data) {
            curt = curt->next;
            curl = curl->next;
        }

        if (curt == nullptr && curl == nullptr) {
            return true;
        } else {
            return false;
        }
    }

    template <typename T>
    bool List<T>::operator!=(const List<T>& l) const {
        return !(*this == l);
    }

    template <typename T>
    void List<T>::clear() {
        if (!this->head) {
            time_t t_time = time(NULL);
            throw EmptyList(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
        }
        this->~List();
    }

    template <typename T>
    bool List<T>::isEmpty() const noexcept {
        return (this->head == nullptr);
    }

    template <typename T>
    constexpr size_t List<T>::size() const noexcept {
        Shared<ListNode<T>> cur(this->head);
        size_t s = 0;
        for (; cur; cur = cur->next) {
            ++s;
        }

        return s;
    }

    template <typename T>
    List<T>& List<T>::pushBack(const List<T>& l) {
        if (this->head == nullptr) {
            *this = l;
            return *this;
        }

        Shared<ListNode<T>> tmp(l.head);
        for (; tmp; tmp = tmp->next) {
            Shared<ListNode<T>> node = std::make_shared<ListNode<T>>();
            if (node == nullptr) {
                time_t t_time = time(NULL);
                throw MemmoryError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
            }
            node->setData(tmp->getData());
            this->pushBack(node);
        }

        return *this;
    }

    template <typename T>
    List<T>& List<T>::pushBack(const T data) {
        Shared<ListNode<T>> node = std::make_shared<ListNode<T>>();
        if (node == nullptr) {
            time_t t_time = time(NULL);
            throw MemmoryError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
        }
        node->setData(data);
        this->pushBack(node);
        return *this;
    }

    template <typename T>
    List<T>& List<T>::pushBack(Shared<ListNode<T>> node) {
        if (this->head == nullptr) {
            Shared<ListNode<T>> head = std::make_shared<ListNode<T>>();
            if (head == nullptr) {
                time_t t_time = time(NULL);
                throw MemmoryError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
            }
            head->data = node->data;
            this->head = head;
            this->tail = head;
            return *this;
        }

        Shared<ListNode<T>> cur(this->tail);
        Shared<ListNode<T>> new_node = std::make_shared<ListNode<T>>();
        if (new_node == nullptr) {
            time_t t_time = time(NULL);
            throw MemmoryError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
        }
        new_node->data = node->data;
        cur->setNext(new_node);
        this->tail = new_node;
        return *this;
    }

    template <typename T>
    List<T>& List<T>::pushFront(const List<T>& l) {
        if (l.head == nullptr) {
            return *this;
        }

        if (this->head == nullptr) {
            this->pushBack(l);
            return *this;
        }
        Shared<ListNode<T>> cur;
        Shared<ListNode<T>> head = std::make_shared<ListNode<T>>();
        if (head == nullptr) {
            time_t t_time = time(NULL);
            throw MemmoryError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
        }
        head->setData(l.head->getData());

        Shared<ListNode<T>> tmp(head);
        cur = l.head->next;

        for (; cur; cur = cur->next) {
            Shared<ListNode<T>> node = std::make_shared<ListNode<T>>();
            if (node == nullptr) {
                time_t t_time = time(NULL);
                throw MemmoryError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
            }
            tmp->setNext(node);
            node->setData(cur->getData());
            node->setNext(this->head);
            tmp = tmp->next;
        }

        this->head = head;
        return *this;
    }

    template <typename T>
    List<T>& List<T>::pushFront(const T data) {
        Shared<ListNode<T>> new_head = std::make_shared<ListNode<T>>();
        if (new_head == nullptr) {
            time_t t_time = time(NULL);
            throw MemmoryError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
        }
        new_head->setData(data);
        this->pushFront(new_head);
        return *this;
    }

    template <typename T>
    List<T>& List<T>::pushFront(Shared<ListNode<T>> node) {
        if (this->head == nullptr) {
            this->pushBack(node);
            return *this;
        }

        Shared<ListNode<T>> new_head = std::make_shared<ListNode<T>>();
        if (new_head == nullptr) {
            time_t t_time = time(NULL);
            throw MemmoryError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
        }
        new_head->setData(node->data);
        new_head->setNext(this->head);
        this->head = new_head;
        return *this;
    }

    template <typename T>
    T List<T>::popBack() {
        if (this->head == nullptr) {
            time_t t_time = time(NULL);
            throw EmptyList(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
        }
        Shared<ListNode<T>> ptr(head);
        Shared<ListNode<T>> prev(head);
        while (ptr != tail) {
            prev = ptr;
            ptr = ptr->next;
        }
        T data = ptr->data;
        ptr.reset();
        tail = prev;
        tail->next = nullptr;
        return data;
    }

    template <typename T>
    T List<T>::popFront() {
        if (this->head == nullptr) {
            time_t t_time = time(NULL);
            throw EmptyList(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
        }
        Shared<ListNode<T>> cur(head->next);
        T data = head->data;
        head.reset();
        this->head = cur;

        return data;
    }

    template<typename T>
    void List<T>::remove(Iterator<T>& prev) {
        if (this->head == nullptr) {
            time_t t_time = time(NULL);
            throw EmptyList(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
        }

        Weak<ListNode<T>> curr = prev.getNode().lock()->next;
        prev.getNode().lock()->next = curr.lock()->next;
        curr.reset();
    }

    template<typename T>
    void List<T>::insert(Iterator<T>& prev, const T& data) {
        Shared<ListNode<T>> new_ptr = std::make_shared<ListNode<T>>(data);
        Shared<ListNode<T>> next = prev.getNode().lock()->next;
        prev.getNode().lock()->next = new_ptr;
        new_ptr->next = next;
    }


    template <typename T>
    void List<T>::reverse() {
        if (this->head == nullptr) {
            time_t t_time = time(NULL);
            throw EmptyList(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
        }

        Shared<ListNode<T>> prev(nullptr);
        Shared<ListNode<T>> current(this->head);
        Shared<ListNode<T>> next;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        this->head = prev;
    }

    template <typename T>
    Iterator<T> List<T>::begin() noexcept {
        return Iterator<T>(this->head);
    }

    template <typename T>
    Iterator<const T> List<T>::begin() const noexcept {
        return Iterator<const T>(this->head);
    }

    template <typename T>
    Iterator<T> List<T>::end() noexcept {
        return Iterator<T>(this->tail);
    }

    template <typename T>
    Iterator<const T> List<T>::end() const noexcept {
        return Iterator<const T>(this->tail);
    }

    template <typename T>
    std::ostream& operator<<(std::ostream& os, List<T>& l) {
        os << "List: ";

        Iterator<T> i(l);
        if (!i.check()) {
            os << "empty";
            return os;
        }
        for (; i.check(); i++) {
            os << *i << " -> ";
        }
        os << "nullptr\n";
        return os;
    }

    template <typename T>
    std::istream& operator>>(std::istream& is, List<T>& l) {
        time_t t_time = time(NULL);
        if (!is) {
            throw InvalidListStream(__FILE__, "istream >> overload", __LINE__, ctime(&t_time));
        }

        if (is.peek() == std::ifstream::traits_type::eof()) {
            throw InvalidListStream(__FILE__, "istream >> overload", __LINE__, ctime(&t_time));
        }

        T arg;
        while (is >> arg) {
            l.pushBack(arg);
        }

        if (!is.eof()) {
            throw InvalidListStream(__FILE__, "istream >> overload", __LINE__, ctime(&t_time));
        }
        return is;
    }
}  // namespace flexlist

#endif  // __LIST_H
