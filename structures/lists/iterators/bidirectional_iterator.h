#ifndef BIDIRECTIONAL_ITERATOR_H
#define BIDIRECTIONAL_ITERATOR_H

#include "../node.h"

// TODO: Implement all methods
template <typename T> 
class BidirectionalIterator {
    private:
        Node<T> *current;

    public:
        BidirectionalIterator(){};
        BidirectionalIterator(Node<T>*);
        BidirectionalIterator<T> operator=(BidirectionalIterator<T>);
        bool operator!=(BidirectionalIterator<T>);
        BidirectionalIterator<T> operator++();
        BidirectionalIterator<T> operator--();
        T operator*();
};

template<typename T>
BidirectionalIterator<T>::BidirectionalIterator(Node<T> *data) {
    current=data;
}

template<typename T>
BidirectionalIterator<T> BidirectionalIterator<T>::operator=(BidirectionalIterator<T> it) {
    it = current;
    return it;
}

template<typename T>
bool BidirectionalIterator<T>::operator!=(BidirectionalIterator<T> it) {
    return current != it.current;
}

template<typename T>
BidirectionalIterator<T> BidirectionalIterator<T>::operator++() {
    current = current->next;
    return current;
}

template<typename T>
BidirectionalIterator<T> BidirectionalIterator<T>::operator--() {
    current = current->prev;
    return current;
}

template<typename T>
T BidirectionalIterator<T>::operator*() {
    return current->data;
}

#endif