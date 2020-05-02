#ifndef BASE_ITERATOR_H
#define BASE_ITERATOR_H

template <typename T>
class BaseIterator {
 public:
    virtual void first() = 0;
    virtual void next() = 0;
    virtual void last() = 0;
    virtual bool range() = 0;
};

#endif