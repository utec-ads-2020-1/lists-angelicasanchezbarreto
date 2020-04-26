#ifndef LIST_H
#define LIST_H

#include "node.h"

// TODO: Implement all methods

class SinElementos: public runtime_error {
public:
    SinElementos(const char *msg) : runtime_error( msg )
    {}
};

class IndiceInexistente: public out_of_range {
public:
    IndiceInexistente(const char *msg) : out_of_range( msg )
    {}
};

template <typename T>
class List {
    protected:
        Node<T>* head;
        Node<T>* tail;
        int nodes;

    public:
        List() : head(nullptr), tail(nullptr), nodes(0) {};
        ~List();

        virtual T front() = 0;
        virtual T back() = 0;
        virtual void push_front(T) = 0;
        virtual void push_back(T) = 0;
        virtual void pop_front() = 0;
        virtual void pop_back() = 0;
        virtual T operator[](int) = 0;
        virtual bool empty() = 0;
        virtual int size() = 0;
        virtual void clear() = 0;
        virtual void sort() = 0;
        virtual void reverse() = 0;
        virtual string name() = 0;
};

template<typename T>
List<T>::~List() {
    auto temp = new Node<T>;
    while(this->nodes!=0){
        temp = this->head;
        this->head = temp->next;
        delete temp;
        --this->nodes;
    }
    this->tail = nullptr;
}

template<typename T>
void swapData(T &temp, T &tempNext){
    auto dato = temp;
    temp = tempNext;
    tempNext = dato;
}

#endif