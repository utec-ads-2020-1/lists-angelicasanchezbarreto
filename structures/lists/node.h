#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(T elem);

    Node();

    //void killSelf();
};

template<typename T>
Node<T>::Node(T elem) {
    data = elem;
}

template<typename T>
Node<T>::Node() {}


#endif