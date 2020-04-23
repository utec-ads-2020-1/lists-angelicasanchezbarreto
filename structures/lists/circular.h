#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"

// TODO: Implement all methods
template <typename T>
class CircularLinkedList : public List<T> {
public:
    CircularLinkedList() : List<T>() {}

    T front();
    T back();
    void push_front(T);
    void push_back(T);
    void pop_front();
    void pop_back();
    T operator[](int);
    bool empty();
    int size();
    void clear();
    void sort();
    void reverse();
    void merge(CircularLinkedList<T>&);

    BidirectionalIterator<T> begin(){
        return BidirectionalIterator<T>(this->head);
    }
    BidirectionalIterator<T> end(){
        return BidirectionalIterator<T>(this->tail);
    }

    string name() {
        return "Circular Linked List";
    }
};

template<typename T>
T CircularLinkedList<T>::front() {
    if(empty())
        throw SinElementos("FRONT: No hay elementos");
    else
        return this->head->data;
}

template<typename T>
T CircularLinkedList<T>::back() {
    if (empty())
        throw SinElementos("BACK: No hay elementos");
    else
        return this->head->prev->data;
}

template<typename T>
void CircularLinkedList<T>::push_front(T dato) {
    auto nuevo = new Node<T>(dato);
    nuevo->data = dato;
    if(empty())
        this->head = this->tail = nuevo;
    else{
        nuevo->next = this->head;
        this->tail->next = nuevo;
        this->head->prev = nuevo;
        nuevo->prev = this->tail;
        this->head = nuevo;
    }
    ++this->nodes;
}

template<typename T>
void CircularLinkedList<T>::push_back(T dato) {
    auto nuevo = new Node<T>(dato);
    nuevo->data=dato;
    if(empty())
        this->head = this->tail = nuevo;
    else {
        this->tail->next = nuevo;
        nuevo->prev = this->tail;
        this->head->prev = nuevo;
        nuevo->next = this->head;
        this->tail = nuevo;
    }
    ++this->nodes;
}

template<typename T>
void CircularLinkedList<T>::pop_front() {
    if(empty())
        throw SinElementos("POP_FRONT: No hay elementos");
    else{
        auto temp = new Node<T>;
        temp = this->head;
        this->head = this->head->next;
        this->head->prev = this->tail;
        this->tail->next = this->head;
        delete temp;
        --this->nodes;
    }
}

template<typename T>
void CircularLinkedList<T>::pop_back() {
    if(empty())
        throw SinElementos("POP_BACK: No hay elementos");
    else{
        auto temp = new Node<T>;
        temp = this->tail;
        this->tail = this->tail->prev;
        this->tail->next = this->head;
        this->head->prev = this->tail;
        delete temp;
        --this->nodes;
    }
}

template<typename T>
T CircularLinkedList<T>::operator[](int pos) {
    if (pos > this->nodes || pos < 0)
        throw IndiceInexistente("ERROR: El indice no existe");
    else {
        int mitad = size()/2;
        if(pos<=mitad){
            auto temp = this->head;
            for(int i=0; i<pos;i++)
                temp = temp->next;
            return temp->data;
        }
        else{
            auto temp = this->tail;
            for(int i=size()-1; i>pos;i--)
                temp = temp->prev;
            return temp->data;
        }
    }
}

template<typename T>
bool CircularLinkedList<T>::empty() {
    return this->nodes == 0;
}

template<typename T>
int CircularLinkedList<T>::size() {
    return this->nodes;
}

template<typename T>
void CircularLinkedList<T>::clear() {
    if (empty())
        throw SinElementos("CLEAR: No hay elementos");
    else {
        auto temp = new Node<T>;
        while(this->nodes!=0){
            temp = this->head;
            this->head = temp->next;
            delete temp;
            --this->nodes;
        }
        //this->head = nullptr;
        this->tail = nullptr;
    }
}

template<typename T>
void CircularLinkedList<T>::sort() {
    if (this->nodes == 1)
        throw SinElementos("SORT: No se puede hacer sort");
    else if (empty())
        throw SinElementos("SORT: No hay elementos");
    else {
        for (int i = 0; i < size() - 1; i++) {
            auto temp = this->head;
            auto tempNext = this->head->next;
            while (temp->next != this->head) {
                if (temp->data > tempNext->data)
                    swapData(temp->data, tempNext->data);
                else {
                    temp = temp->next;
                    tempNext = tempNext->next;
                }
            }
        }
    }
}

template<typename T>
void CircularLinkedList<T>::reverse() {
    if(this->nodes == 1)
        throw SinElementos("REVERSE: No se puede hacer reverse");
    else if(empty())
        throw SinElementos("REVERSE: No hay elementos");
    else {
        auto tailAux = this->tail;
        this->tail = this->head;
        this->head = tailAux;

        auto temp = this->head;
        auto aux = temp->prev;

        while(temp!= this->tail){
            temp->prev = temp->next;
            temp->next = aux;

            aux->next = aux->prev;
            aux->prev = temp;

            temp = aux;
            aux = temp->next;
        }
    }
}

template<typename T>
void CircularLinkedList<T>::merge(CircularLinkedList<T> &nueva) {
    if(empty()){
        this->head = nueva.head;
        this->tail = nueva.tail;
    }
    else if(nueva.empty())
        throw SinElementos("MERGE: La nueva lista esta vacía");
    else{
        this->tail->next = nueva.head;
        nueva.head->prev = this->tail;
        this->head->prev = nueva.tail;
        nueva.tail->next = this->head;
        this->tail = nueva.head;
    }
    this->nodes+=nueva.size();
}

#endif