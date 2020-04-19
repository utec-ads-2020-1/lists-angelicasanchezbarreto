#ifndef LINKED_H
#define LINKED_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"

// TODO: Implement all methods


template <typename T>
class LinkedList : public List<T> {
public:
    LinkedList() : List<T>() {}
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
    void merge(LinkedList<T>&);

    BidirectionalIterator<T> begin(){
        return BidirectionalIterator<T>(this->head);
    }
    BidirectionalIterator<T> end(){
        return BidirectionalIterator<T>(this->tail);
    }
    string name() {
        return "Linked List";
    }
};


template<typename T>
T LinkedList<T>::front() {
    try{
        if(empty())
            throw SinElementos("No hay elementos");
        else
            return this->head->data;
    }
    catch(const SinElementos &e){
        cerr << "FRONT: " << e.what() << endl;
    }
    return -1;
}

template<typename T>
T LinkedList<T>::back() {
    try {
        if (empty())
            throw SinElementos("No hay elementos");
        else {
            return this->tail->data;
        }
    }
    catch(const SinElementos &e){
        cerr << "BACK: " << e.what() << endl;
    }
    return -1;
}

template<typename T>
void LinkedList<T>::push_front(T dato) {
    auto nuevo = new Node<T>(dato);
    nuevo->data = dato;
    if(empty())
        this->head = this->tail = nuevo;
    else{
        nuevo->next = this->head;
        this->head->prev = nuevo;
        this->head = nuevo;
    }
    ++this->nodes;
}

template<typename T>
void LinkedList<T>::push_back(T dato) {
    auto nuevo = new Node<T>(dato);
    nuevo->data=dato;
    if(empty())
        this->head = this->tail = nuevo;
    else {
        this->tail->next = nuevo;
        nuevo->prev = this->tail;
        this->tail = nuevo;
    }
    ++this->nodes;
}

template<typename T>
void LinkedList<T>::pop_front() {
    try{
        if(empty())
            throw SinElementos("No hay elementos");
        else{
            auto temp = new Node<T>;
            temp = this->head;
            this->head = this->head->next;
            this->head->prev = nullptr;
            delete temp;
            --this->nodes;
        }
    }
    catch(const SinElementos &e){
        cerr << "POP_FRONT: " << e.what() << endl;
    }
}

template<typename T>
void LinkedList<T>::pop_back() {
    try{
        if(empty())
            throw SinElementos("No hay elementos");
        else{
            auto temp = new Node<T>;
            temp = this->tail;
            this->tail = this->tail->prev;
            this->tail->next = nullptr;
            delete temp;
            --this->nodes;
        }
    }
    catch(const SinElementos &e){
        cerr << "POP_BACK: " << e.what() << endl;
    }
}

template<typename T>
T LinkedList<T>::operator[](int pos) {
    try {
        if (pos > this->nodes || pos < 0)
            throw IndiceInexistente("El indice no existe");
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
    catch(const IndiceInexistente &e){
        cerr << "ERROR: " << e.what() << endl;
    }
    return -1;
}

template<typename T>
bool LinkedList<T>::empty() {
    return this->nodes == 0;
}

template<typename T>
int LinkedList<T>::size() {
    return this->nodes;
}

template<typename T>
void LinkedList<T>::clear() {
    try {
        if (empty())
            throw SinElementos("No hay elementos");
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
    catch(const SinElementos &e){
        cerr << "CLEAR: " << e.what() << endl;
    }
}

template<typename T>
void LinkedList<T>::sort() {
    try {
        if (this->nodes == 1)
            throw SinElementos("No se puede hacer reverse");
        else if (empty())
            throw SinElementos("No hay elementos");
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
    catch (SinElementos &e) {
        cerr << "REVERSE: " << e.what() << endl;
    }
}

template<typename T>
void LinkedList<T>::reverse() {
    try{
        if(this->nodes == 1)
            throw SinElementos("No se puede hacer reverse");
        else if(empty())
            throw SinElementos("No hay elementos");
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
    catch (SinElementos &e) {
        cerr << "REVERSE: " << e.what() << endl;
    }
}

template<typename T>
void LinkedList<T>::merge(LinkedList<T> &nueva) {
    if(empty()){
        this->head = nueva.head;
        this->tail = nueva.tail;
    }
    else{
        this->tail->next = nueva.head;
        nueva.head->prev = this->tail;
        this->tail = nueva.tail;
    }
    this->nodes+=nueva.size();
}

#endif