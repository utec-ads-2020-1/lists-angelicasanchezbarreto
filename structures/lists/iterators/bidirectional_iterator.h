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
        BidirectionalIterator(Node<T>*); // Usa explicit para ver posibles errores
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
    it = current;// Esto sería al revés 
    return it;
}

template<typename T>
bool BidirectionalIterator<T>::operator!=(BidirectionalIterator<T> it) {
    return current != it.current;
}

template<typename T>
BidirectionalIterator<T> BidirectionalIterator<T>::operator++() {
    current = current->next; // Estás construyendo nuevos iteradores
    return current;
}

template<typename T>
BidirectionalIterator<T> BidirectionalIterator<T>::operator--() {
    current = current->prev; // Estás construyendo nuevos iteradores
    return current;
}

template<typename T>
T BidirectionalIterator<T>::operator*() {
    // Si current es null?
    return current->data;
}

#endif