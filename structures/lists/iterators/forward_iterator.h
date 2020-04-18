#ifndef FORWARD_ITERATOR_H
#define FORWARD_ITERATOR_H

#include "../node.h"

// TODO: Implement all methods
template <typename T> 
class ForwardIterator {
    private:
        Node<T> *current;
    public:
        ForwardIterator(){};
        ForwardIterator(Node<T>*);
        ForwardIterator<T> operator=(ForwardIterator<T>);
        bool operator!=(ForwardIterator<T>);
        ForwardIterator<T> operator++();
        T operator*();
};

template<typename T>
ForwardIterator<T>::ForwardIterator(Node<T> *data){
    current=data;
}

template<typename T>
ForwardIterator<T> ForwardIterator<T>::operator=(ForwardIterator<T> it) {
    it = current;
    return it;
}

template<typename T>
bool ForwardIterator<T>::operator!=(ForwardIterator<T> it) {
    return current != it.current;
}

template<typename T>
ForwardIterator<T> ForwardIterator<T>::operator++() {
    current = current->next;
    return current;
}

template<typename T>
T ForwardIterator<T>::operator*() {
    return current->data;
}

#endif