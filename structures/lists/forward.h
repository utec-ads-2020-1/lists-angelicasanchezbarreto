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

    ForwardIterator<T> begin();
    ForwardIterator<T> end();

    string name() {
        return "Forward List";
    }

    /**
     * Merges x into the list by transferring all of its elements at their respective
     * ordered positions into the container (both containers shall already be ordered).
     *
     * This effectively removes all the elements in x (which becomes empty), and inserts
     * them into their ordered position within container (which expands in size by the number
     * of elements transferred). The operation is performed without constructing nor destroying
     * any element: they are transferred, no matter whether x is an lvalue or an rvalue,
     * or whether the value_type supports move-construction or not.
    */
    void merge(ForwardList<T>&);
};


template<typename T>
T ForwardList<T>::front() {
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
T ForwardList<T>::back() {
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
    try{
        if(empty())
            throw SinElementos("No hay elementos");
        else{
            auto temp = new Node<T>;
            temp = this->head;
            this->head = this->head->next;
            delete temp;
            --this->nodes;
        }
    }
    catch(const SinElementos &e){
        cerr << "POP_FRONT: " << e.what() << endl;
    }
}

template<typename T>
void ForwardList<T>::pop_back() {
    try{
        if(empty())
            throw SinElementos("No hay elementos");
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
    catch(const SinElementos &e){
        cerr << "POP_BACK: " << e.what() << endl;
    }
}

template<typename T>
T ForwardList<T>::operator[](int pos) {
    try {
        if (pos > size()-1 || pos < 0)
            throw IndiceInexistente("El indice no existe");
        else {
            auto temp = this->head;
            for(int i=0; i<pos;i++)
                temp = temp->next;
            return temp->data;
        }
    }
    catch(const IndiceInexistente &e){
        cerr << "ERROR: " << e.what() << endl;
    }
    return -1;
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
void ForwardList<T>::reverse() {
    try{
        if(this->nodes == 1)
            throw SinElementos("No se puede hacer reverse");
        else if(empty())
            throw SinElementos("No hay elementos");
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
    catch (SinElementos &e) {
        cerr << "REVERSE: " << e.what() << endl;
    }
}


#endif