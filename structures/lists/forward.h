#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "iterators/forward_iterator.h"

// TODO: Implement all methods

template <typename T>
class ForwardList : public List<T> {
public:
    ForwardList() : List<T>() {}
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
    void merge(ForwardList<T>&);

    ForwardIterator<T> begin(){
        return ForwardIterator<T>(this->head);
    }
    ForwardIterator<T> end(){
        return ForwardIterator<T>(this->tail);
    }
    string name() {
        return "Forward List";
    }
};

template<typename T>
T ForwardList<T>::front() {
    if(empty())
        throw SinElementos("FRONT: No hay elementos");
    else
        return this->head->data;
}

template<typename T>
T ForwardList<T>::back() {
    if (empty())
        throw SinElementos("BACK: No hay elementos");
    else
        return this->tail->data;
}

template<typename T>
void ForwardList<T>::push_front(T dato) {
    auto nuevo = new Node<T>(dato);
    nuevo->data = dato;
    if(empty())
        this->head = this->tail = nuevo;
    else{
        nuevo->next = this->head;
        this->head = nuevo;
    }
    ++this->nodes;
}

template<typename T>
void ForwardList<T>::push_back(T dato) {
    auto nuevo = new Node<T>(dato);
    nuevo->data=dato;
    if(empty())
        this->head = this->tail = nuevo;
    else {
        this->tail->next = nuevo;
        this->tail = nuevo;
    }
    ++this->nodes;
}

template<typename T>
void ForwardList<T>::pop_front() {
    if(empty())
        throw SinElementos("POP_FRONT: No hay elementos");
    else{
        auto temp = new Node<T>;
        temp = this->head;
        this->head = this->head->next;
        delete temp;
        --this->nodes;
    }
}

template<typename T>
void ForwardList<T>::pop_back() {
    if(empty())
        throw SinElementos("POP_BACK: No hay elementos");
    else{
        auto temp = new Node<T>;
        temp = this->head;
        while(temp->next!= this->tail)
            temp = temp->next;
        this->tail = temp;
        temp = temp->next;
        this->tail->next = nullptr;
        delete temp;
        --this->nodes;
    }
}

template<typename T>
T ForwardList<T>::operator[](int pos) {
    if (pos > size()-1 || pos < 0)
        throw IndiceInexistente("ERROR: El indice no existe");
    else {
        auto temp = this->head;
        for(int i=0; i<pos;i++)
            temp = temp->next;
        return temp->data;
    }
}

template<typename T>
bool ForwardList<T>::empty() {
    return this->nodes == 0;
}

template<typename T>
int ForwardList<T>::size() {
    return this->nodes;
}

template<typename T>
void ForwardList<T>::clear() {
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
        this->tail = nullptr;
    }
}

template<typename T>
void ForwardList<T>::sort() {
    if (this->nodes == 1)
        throw SinElementos("SORT: No se puede hacer sort");
    else if (empty())
        throw SinElementos("SORT: No hay elementos");
    else {
        for (int i = 0; i < size() - 1; i++) {
            auto temp = this->head;
            auto tempNext = this->head->next;
            while (temp->next != nullptr) {
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
void ForwardList<T>::reverse() {
    if(this->nodes == 1)
        throw SinElementos("REVERSE: No se puede hacer reverse");
    else if(empty())
        throw SinElementos("REVERSE: No hay elementos");
    else{
        auto tailAux = this->tail;
        this->tail = this->head;
        this->head = tailAux;

        auto temp = this->head;

        while(temp!= this->tail){
            auto aux = this->tail;
            while(aux->next != temp){
                aux = aux->next;
            }
            temp->next = aux;
            temp = aux;
        }
    }
}

template<typename T>
void ForwardList<T>::merge(ForwardList<T> &nueva) {
    if(empty()){
        this->head = nueva.head;
        this->tail = nueva.tail;
    }
    else if(nueva.empty())
        throw SinElementos("MERGE: La nueva lista esta vacía");
    else{
        this->tail->next = nueva.head;
        this->tail = nueva.head;
    }
    this->nodes+=nueva.size();
}

#endif