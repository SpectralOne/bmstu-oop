#ifndef __LIST_H
#define __LIST_H
#include <assert.h>
#include <stdlib.h>

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
            Shared<ListNode<T>> cur(nullptr);
            Shared<ListNode<T>> head = std::make_shared<ListNode<T>>();
            if (head == nullptr) {
                throw MemmoryError();
            }

            head->set(l.head->getData());
            this->head = head;

            Shared<ListNode<T>> tmp(head);
            cur = l.head->next;

            for (; cur; cur = cur->next) {
                Shared<ListNode<T>> node = std::make_shared<ListNode<T>>();
                if (node == nullptr) {
                    throw MemmoryError();
                }

                tmp->setNext(node);
                node->set(cur->getData());
                this->tail = node;
                tmp = tmp->next;
            }
        }
    }

    template <typename T>
    List<T>::List(List<T>&& l) {
        this->head = l.head;
        this->tail = l.tail;
    }

    template <typename T>
    List<T>::List(T data, size_t n) {
        if (n < 0) {
            throw ConstructorBadArguments();
        }

        if (n == 0) {
            this->head = nullptr;
        } else {
            Shared<ListNode<T>> head = std::make_shared<ListNode<T>>();
            if (head == nullptr) {
                throw MemmoryError();
            }

            head->set(data);
            this->head = head;

            Shared<ListNode<T>> cur = head;
            for (size_t i = 0; i < n - 1; ++i) {
                Shared<ListNode<T>> node = std::make_shared<ListNode<T>>();
                if (node == nullptr) {
                    throw MemmoryError();
                }

                node->set(data);
                cur->setNext(node);
                cur = node;
            }
            this->tail = cur;
        }
    }

    template <typename T>
    List<T>::List(ListIterator<T>& first, ListIterator<T>& last) {
        if (!first.range() || !last.range()) {
            throw ListOutOfBounds();
        }

        ListIterator<T> f(first);
        Shared<ListNode<T>> head = std::make_shared<ListNode<T>>();
        if (head == nullptr) {
            throw MemmoryError();
        }

        head->set(f.current());
        this->head = head;
        ++f;
        Shared<ListNode<T>> cur(head);

        for (; f != last; ++f) {
            Shared<ListNode<T>> node = std::make_shared<ListNode<T>>();
            if (node == nullptr) {
                throw MemmoryError();
            }

            node->set(f.current());
            cur->setNext(node);
            cur = node;
        }
        this->tail = cur;
    }

    template <typename T>
    List<T>::List(std::vector<T> vec) {
        this->head = nullptr;
        this->tail = nullptr;

        if (vec.size()) {
            for (auto &node : vec) {
                this->append(node);
            }
        }
    }

    template <typename T>
    List<T>::List(std::istream& is) {
        this->head = nullptr;
        this->tail = nullptr;

        if (!is) {
            throw InvalidListStream();
        }

        if (is.peek() == std::ifstream::traits_type::eof()) {
            throw InvalidListStream();
        }

        T arg;
        while (is >> arg) {
            this->append(arg);
        }

        if (!is.eof()) {
            throw InvalidListStream();
        }
    }

    template <typename T>
    List<T>::List(std::initializer_list<T> il) {
        this->head = nullptr;
        this->tail = nullptr;

        if (il.size()) {
            for (auto &node : il) {
                this->append(node);
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
    T& List<T>::operator[](const size_t pos) {
        if (this->head == nullptr) {
            throw EmptyList();
        }

        if (pos >= this->length()) {
            throw ListOutOfBounds();
        }

        Shared<ListNode<T>> cur(this->head);
        for (size_t i = 0; i < pos; ++i) {
            cur = cur->next;
        }

        return cur->data;
    }

    template <typename T>
    T List<T>::operator[](const size_t pos) const {
        if (this->head == nullptr) {
            throw EmptyList();
        }

        if (pos >= this->length()) {
            throw ListOutOfBounds();
        }

        Shared<ListNode<T>> cur(this->head);
        for (size_t i = 0; i < pos; ++i) {
            cur = cur->next;
        }

        return cur->data;
    }

    template <typename T>
    List<T>& List<T>::operator=(List<T>&& l) {
        this->head = l.head;
        this->tail = l.tail;
        return *this;
    }

    template <typename T>
    List<T>& List<T>::operator+=(const List<T>& l) {
        this->append(l);
        return *this;
    }

    template <typename T>
    List<T>& List<T>::operator+=(const Shared<ListNode<T>> data) {
        this->append(data);
        return *this;
    }

    template <typename T>
    List<T>& List<T>::operator+=(const T data) {
        this->append(data);
        return *this;
    }

    template <typename T>
    List<T>& List<T>::operator+(const List<T>& l) {
        this->append(l);
        return *this;
    }

    template <typename T>
    List<T>& List<T>::operator+(const Shared<ListNode<T>> data) {
        this->append(data);
        return *this;
    }

    template <typename T>
    List<T>& List<T>::operator+(const T data) {
        this->append(data);
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
    size_t List<T>::size() const {
        return (this->length() * sizeof(ListNode<T>));
    }

    template <typename T>
    void List<T>::reset() {
        Shared<ListNode<T>> cur(this->head);
        for (; cur; cur = cur->next) {
            cur->set(0);
        }
    }

    template <typename T>
    void List<T>::reset(T data) {
        Shared<ListNode<T>> cur(this->head);
        for (; cur; cur = cur->next) {
            cur->set(data);
        }
    }

    template <typename T>
    void List<T>::clear() {
        if (!this->head) {
            throw EmptyList();
        }
        this->~List();
    }

    template <typename T>
    bool List<T>::isEmpty() const {
        return (this->head == nullptr);
    }

    template <typename T>
    size_t List<T>::length() const {
        Shared<ListNode<T>> cur(this->head);
        size_t s = 0;
        for (; cur; cur = cur->next) {
            ++s;
        }

        return s;
    }

    template <typename T>
    void List<T>::unique() {
        if (this->head == nullptr) {
            throw EmptyList();
        }

        if (this->length() < 2) {
            throw NotEnoughNodes();
        }

        this->sort();
        Shared<ListNode<T>> current(this->head);
        Shared<ListNode<T>> next_next(nullptr);
        while (current->next) {
            if (current->data == current->next->data) {
                next_next = current->next->next;
                del(current->next);
                current->setNext(next_next);
            } else {
                current = current->next;
            }
        }
    }

    template <typename T>
    ListIterator<T>& List<T>::begin() {
        ListIterator<T> it(*this);
        it.first();

        return it;
    }

    template <typename T>
    ListIterator<T>& List<T>::end() {
        ListIterator<T> it(*this);
        it.last();

        return it;
    }

    template <typename T>
    ListIteratorConst<T>& List<T>::begin() const {
        ListIteratorConst<T> it(*this);
        it.first();

        return it;
    }

    template <typename T>
    ListIteratorConst<T>& List<T>::end() const {
        ListIteratorConst<T> it(*this);
        it.last();

        return it;
    }

    template <typename T>
    List<T>& List<T>::append(const List<T>& l) {
        if (this->head == nullptr) {
            *this = l;
            return *this;
        }

        Shared<ListNode<T>> tmp(l.head);
        for (; tmp; tmp = tmp->next) {
            Shared<ListNode<T>> node = std::make_shared<ListNode<T>>();
            if (node == nullptr) {
                throw MemmoryError();
            }
            node->set(tmp->getData());
            this->append(node);
        }

        return *this;
    }

    template <typename T>
    List<T>& List<T>::append(const T data) {
        Shared<ListNode<T>> node = std::make_shared<ListNode<T>>();
        if (node == nullptr) {
            throw MemmoryError();
        }
        node->set(data);
        this->append(node);
        return *this;
    }

    template <typename T>
    List<T>& List<T>::append(Shared<ListNode<T>> node) {
        if (this->head == nullptr) {
            Shared<ListNode<T>> head = std::make_shared<ListNode<T>>();
            if (head == nullptr) {
                throw MemmoryError();
            }
            head->data = node->data;
            this->head = head;
            this->tail = head;
            return *this;
        }

        Shared<ListNode<T>> cur(this->tail);
        Shared<ListNode<T>> new_node = std::make_shared<ListNode<T>>();
        if (new_node == nullptr) {
            throw MemmoryError();
        }
        new_node->data = node->data;
        cur->setNext(new_node);
        this->tail = new_node;
        return *this;
    }

    template <typename T>
    T List<T>::popBackArg() {
        if (this->tail == nullptr) {
            throw EmptyList();
        }
        T arg = this->tail->getData();
        del(this->tail);

        return arg;
    }

    template <typename T>
    void List<T>::popBack() {
        if (this->tail == nullptr) {
            throw EmptyList();
        }
        del(this->tail);
    }

    template <typename T>
    T List<T>::popFrontArg() {
        if (this->head == nullptr) {
            throw EmptyList();
        }
        T arg = this->head->getData();

        del(this->head);

        return arg;
    }

    template <typename T>
    void List<T>::popFront() {
        if (this->head == nullptr) {
            throw EmptyList();
        }

        del(this->head);
    }

    template <typename T>
    List<T>& List<T>::insertFront(const List<T>& l) {
        if (l.head == nullptr) {
            return *this;
        }

        if (this->head == nullptr) {
            this->append(l);
            return *this;
        }
        Shared<ListNode<T>> cur;
        Shared<ListNode<T>> head = std::make_shared<ListNode<T>>();
        if (head == nullptr) {
            throw MemmoryError();
        }
        head->set(l.head->getData());

        Shared<ListNode<T>> tmp(head);
        cur = l.head->next;

        for (; cur; cur = cur->next) {
            Shared<ListNode<T>> node = std::make_shared<ListNode<T>>();
            if (node == nullptr) {
                throw MemmoryError();
            }
            tmp->setNext(node);
            node->set(cur->getData());
            node->setNext(this->head);
            tmp = tmp->next;
        }

        this->head = head;
        return *this;
    }

    template <typename T>
    List<T>& List<T>::insertFront(const T data) {
        Shared<ListNode<T>> new_head = std::make_shared<ListNode<T>>();
        if (new_head == nullptr) {
            throw MemmoryError();
        }
        new_head->set(data);
        this->insertFront(new_head);
        return *this;
    }

    template <typename T>
    List<T>& List<T>::insertFront(Shared<ListNode<T>> node) {
        if (this->head == nullptr) {
            this->append(node);
            return *this;
        }

        Shared<ListNode<T>> new_head = std::make_shared<ListNode<T>>();
        if (new_head == nullptr) {
            throw MemmoryError();
        }
        new_head->set(node->data);
        new_head->setNext(this->head);
        this->head = new_head;
        return *this;
    }

    template <typename T>
    List<T>& List<T>::insertAfter(Shared<ListNode<T>> after, const T data) {
        Shared<ListNode<T>> f(this->find(after));
        Shared<ListNode<T>> tmp(f->getNext());
        Shared<ListNode<T>> node = std::make_shared<ListNode<T>>();
        if (node == nullptr) {
            throw MemmoryError();
        }

        node->set(data);
        f->setNext(node);
        node->setNext(tmp);
        if (f == this->tail) {
            this->tail = node;
        }

        return *this;
    }

    template <typename T>
    List<T>& List<T>::insertAfter(Shared<ListNode<T>> after, List<T>& l) {
        Shared<ListNode<T>> f(this->find(after));
        Shared<ListNode<T>> buf(f->getNext());
        Shared<ListNode<T>> cur;
        Shared<ListNode<T>> head = std::make_shared<ListNode<T>>();
        if (head == nullptr) {
            throw MemmoryError();
        }
        head->set(l.head->getData());

        Shared<ListNode<T>> tmp(head);
        cur = l.head->getNext();

        for (; cur; cur = cur->getNext()) {
            Shared<ListNode<T>> node = std::make_shared<ListNode<T>>();
            if (node == nullptr) {
                throw MemmoryError();
            }

            tmp->setNext(node);
            node->set(cur->getData());
            node->setNext(buf);

            if (f == this->tail) {
                this->tail = node;
            }
            tmp = tmp->getNext();
        }
        f->setNext(head);

        return *this;
    }

    template <typename T>
    List<T>& List<T>::insertAfter(Shared<ListNode<T>> after, Shared<ListNode<T>> node) {
        Shared<ListNode<T>> f(this->find(after));
        Shared<ListNode<T>> tmp(f->next);
        Shared<ListNode<T>> new_node = std::make_shared<ListNode<T>>();
        if (new_node == nullptr) {
            throw MemmoryError();
        }

        new_node->set(node->getData());
        f->setNext(new_node);
        new_node->setNext(tmp);

        if (f == this->tail) {
            this->tail = new_node;
        }
        return *this;
    }

    template <typename T>
    List<T>& List<T>::insertBefore(Shared<ListNode<T>> before, const T data) {
        Shared<ListNode<T>> cur(this->head);
        Shared<ListNode<T>> tmp(nullptr);
        while (cur && cur->next != before->next) {
            tmp = cur;
            cur = cur->getNext();
        }

        if (tmp != nullptr) {
            Shared<ListNode<T>> node = std::make_shared<ListNode<T>>();
            if (node == nullptr) {
                throw MemmoryError();
            }

            node->set(data);
            tmp->setNext(node);
            node->setNext(cur);
            return *this;
        } else {
            this->insertFront(data);
            return *this;
        }
    }

    template <typename T>
    List<T>& List<T>::insertBefore(Shared<ListNode<T>> before, List<T>& l) {
        Shared<ListNode<T>> cur(this->head);
        Shared<ListNode<T>> tmp(nullptr);
        while (cur && cur->next != before->next) {
            tmp = cur;
            cur = cur->getNext();
        }

        if (tmp != nullptr) {
            Shared<ListNode<T>> curr;
            Shared<ListNode<T>> head = std::make_shared<ListNode<T>>();
            if (head == nullptr) {
                throw MemmoryError();
            }
            head->set(l.head->getData());

            Shared<ListNode<T>> buf(head);
            curr = l.head->getNext();

            for (; curr; curr = curr->getNext()) {
                Shared<ListNode<T>> node = std::make_shared<ListNode<T>>();
                if (node == nullptr) {
                    throw MemmoryError();
                }

                buf->setNext(node);
                node->set(curr->getData());
                node->setNext(cur);
                buf = buf->getNext();
            }

            tmp->setNext(head);
            return *this;

        } else {
            this->insertFront(l);
            return *this;
        }
    }

    template <typename T>
    List<T>& List<T>::insertAfter(ListIterator<T>& iter, const T data) {
        Shared<ListNode<T>> f(this->find(*iter));
        Shared<ListNode<T>> node = std::make_shared<ListNode<T>>();
        if (node == nullptr) {
            throw MemmoryError();
        }
        node->set(data);
        this->insertAfter(f, node);
        return *this;
    }

    template <typename T>
    List<T>& List<T>::insertAfter(ListIterator<T>& iter, const List<T>& l) {
        Shared<ListNode<T>> f = this->find(*iter);
        Shared<ListNode<T>> buf(f->next);
        Shared<ListNode<T>> cur;
        Shared<ListNode<T>> head = std::make_shared<ListNode<T>>();
        if (head == nullptr) {
            throw MemmoryError();
        }
        head->set(l.head->getData());

        Shared<ListNode<T>> tmp(head);
        cur = l.head->next;

        for (; cur; cur = cur->next) {
            Shared<ListNode<T>> node = std::make_shared<ListNode<T>>();
            if (node == nullptr) {
                throw MemmoryError();
            }
            tmp->setNext(node);
            node->set(cur->getData());
            node->setNext(buf);
            if (f == this->tail) {
                this->tail = node;
            }
            tmp = tmp->next;
        }
        f->setNext(head);

        return *this;
    }

    template <typename T>
    List<T>& List<T>::insertBefore(Shared<ListNode<T>> before, Shared<ListNode<T>> node) {
        Shared<ListNode<T>> cur(this->head);
        Shared<ListNode<T>> tmp(nullptr);
        while (cur && cur->next != before->next) {
            tmp = cur;
            cur = cur->next;
        }

        if (tmp != nullptr) {
            Shared<ListNode<T>> new_node = std::make_shared<ListNode<T>>();
            if (new_node == nullptr) {
                throw MemmoryError();
            }

            new_node->set(node->getData());
            tmp->setNext(new_node);
            new_node->setNext(cur);
            return *this;
        } else {
            this->insertFront(node);
            return *this;
        }
    }

    template <typename T>
    List<T>& List<T>::insertBefore(ListIterator<T>& iter, const T data) {
        Shared<ListNode<T>> before(*iter);
        Shared<ListNode<T>> node = std::make_shared<ListNode<T>>();
        if (node == nullptr) {
            throw MemmoryError();
        }
        node->set(data);
        this->insertBefore(before, node);
        return *this;
    }

    template <typename T>
    List<T>& List<T>::insertBefore(ListIteratorConst<T>& iter, const T data) {
        Shared<ListNode<T>> before(*iter);
        Shared<ListNode<T>> node = std::make_shared<ListNode<T>>();
        if (node == nullptr) {
            throw MemmoryError();
        }
        node->set(data);
        this->insertBefore(before, node);
        return *this;
    }

    template <typename T>
    List<T>& List<T>::insertBefore(ListIterator<T>& iter, const List<T>& l) {
        Shared<ListNode<T>> cur(this->head);
        Shared<ListNode<T>> before(*iter);
        Shared<ListNode<T>> tmp(nullptr);
        while (cur && cur->next != before->next) {
            tmp = cur;
            cur = cur->next;
        }

        if (tmp != nullptr) {
            Shared<ListNode<T>> curr;
            Shared<ListNode<T>> head = std::make_shared<ListNode<T>>();
            if (head == nullptr) {
                throw MemmoryError();
            }
            head->set(l.head->getData());

            Shared<ListNode<T>> buf = head;
            curr = l.head->next;

            for (; curr; curr = curr->next) {
                Shared<ListNode<T>> node = std::make_shared<ListNode<T>>();
                if (node == nullptr) {
                    throw MemmoryError();
                }
                buf->setNext(node);
                node->set(curr->getData());
                node->setNext(cur);
                buf = buf->next;
            }

            tmp->setNext(head);
            return *this;

        } else {
            this->insertFront(l);
            return *this;
        }
    }

    template <typename T>
    List<T>& List<T>::insertBefore(ListIteratorConst<T>& iter, const List<T>& l) {
        Shared<ListNode<T>> cur = this->head;
        Shared<ListNode<T>> before = (*iter);
        Shared<ListNode<T>> tmp = nullptr;
        while (cur && cur->next != before->next) {
            tmp = cur;
            cur = cur->next;
        }

        if (tmp != nullptr) {
            Shared<ListNode<T>> curr;
            Shared<ListNode<T>> head = std::make_shared<ListNode<T>>();
            if (head == nullptr) {
                throw MemmoryError();
            }
            head->set(l.head->getData());

            Shared<ListNode<T>> buf = head;
            curr = l.head->next;

            for (; curr; curr = curr->next) {
                Shared<ListNode<T>> node = std::make_shared<ListNode<T>>();
                if (node == nullptr) {
                    throw MemmoryError();
                }
                buf->setNext(node);
                node->set(curr->getData());
                node->setNext(cur);
                buf = buf->next;
            }

            tmp->setNext(head);
            return *this;

        } else {
            this->insertFront(l);
            return *this;
        }
    }

    template <typename T>
    Shared<ListNode<T>> List<T>::find(const Shared<ListNode<T>> node) const {
        if (this->head == nullptr) {
            throw EmptyList();
        }
        Shared<ListNode<T>> cur = this->head;
        while (cur && cur->getData() != node->getData()) {
            cur = cur->next;
        }

        return cur;
    }

    template <typename T>
    Shared<ListNode<T>> List<T>::find(const T data) const {
        if (this->head == nullptr) {
            throw EmptyList();
        }
        Shared<ListNode<T>> cur(this->head);
        while (cur && cur->getData() != data) {
            cur = cur->getNext();
        }

        return cur;
    }

    template <typename T>
    void List<T>::sort(bool ascending) {
        if (this->head == nullptr) {
            throw EmptyList();
        }

        if (this->head->next == nullptr) {
            throw NotEnoughNodes();
        }

        bool done = false;
        while (!done) {
            Shared<ListNode<T>> *pv(&this->head);
            Shared<ListNode<T>> cur(this->head);
            Shared<ListNode<T>> nxt(this->head->next);

            done = true;

            while (nxt) {
                bool swap = false;
                if (ascending) {
                    if (cur > nxt) {
                        swap = true;
                    }
                } else {
                    if (cur < nxt) {
                        swap = true;
                    }
                }

                if (swap) {
                    cur->next = nxt->next;
                    nxt->next = cur;
                    *pv = nxt;
                    done = false;
                }

                pv = &cur->next;
                cur = nxt;
                nxt = nxt->next;
            }
        }
    }

    template <typename T>
    void List<T>::reverse() {
        if (this->head == nullptr) {
            throw EmptyList();
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
    std::vector<T> List<T>::to_vect() const {
        if (this->head == nullptr) {
            throw EmptyList();
        }

        std::vector<T> vec;
        vec.reserve(this->length());
        Shared<ListNode<T>> tmp = this->head;
        for (; tmp; tmp = tmp->next) {
            vec.push_back(tmp->getData());
        }

        return vec;
    }

    template <typename T>
    List<T>& List<T>::reset(Shared<ListNode<T>> node, T data) {
        Shared<ListNode<T>> f(this->find(node));
        f->set(data);
        return *this;
    }

    template <typename T>
    List<T>& List<T>::reset(Shared<ListNode<T>> node, Shared<ListNode<T>> temp) {
        Shared<ListNode<T>> f(this->find(node));
        f->set(temp->getData());
        return *this;
    }

    template <typename T>
    List<T>& List<T>::reset(ListIterator<T>& iter, T data) {
        Shared<ListNode<T>> f = this->find(*iter);
        f->set(data);
        return *this;
    }

    template <typename T>
    Shared<ListNode<T>> List<T>::del(const Shared<ListNode<T>> node) {
        if (!this->head)
            throw EmptyList();
        Shared<ListNode<T>> f = this->find(node);

        Shared<ListNode<T>> cur = this->head;
        if (cur->getData() == node->getData()) {
            this->head = this->head->next;
            return cur;
        }
        for (; cur && cur->next != f; cur = cur->next)
            ;
        if (cur == nullptr)
            return nullptr;
        cur->setNext(f->next);

        if (f == this->tail) {
            Shared<ListNode<T>> tmp = this->head;
            for (; tmp->next; tmp = tmp->next)
                ;
            this->tail = tmp;
        }
        return f;
    }

    template <typename T>
    Shared<ListNode<T>> List<T>::del(ListIterator<T>& iter) {
        if (!this->head)
            throw EmptyList();
        if ((!*iter) == this->tail)
            throw ListOutOfBounds();

        Shared<ListNode<T>> f = this->find(*iter);

        f = f->getNext();

        this->del(f);

        return f;
    }

    template <typename T>
    std::ostream& operator<<(std::ostream& os, List<T>& l) {
        os << "List: ";
        ListIterator<T> i(l);
        if (!i.range()) {
            os << "empty";
            return os;
        }
        for (i.first(); i.range(); i++) {
            os << i.current() << " ";
        }
        os << "\n";
        return os;
    }
}  // namespace flexlist

#endif  // __LIST_H
