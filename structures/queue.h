#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

#define MAX 1000 

// TODO: Implement all methods

class ArrayVacio: public runtime_error {
public:
    ArrayVacio(const char *msg) : runtime_error( msg )
    {}
};


template <typename T>
class queue {
    T* data;
    int pos_front;
    int pos_back;
    int capacity;

public:
    queue(int size = MAX);
    ~queue();

    void push(T);
    void pop();
    int front();
    int back();

    int size();
    bool empty();

    void replace(T *nuevo);
};

template <typename T>
void queue<T>::replace(T *nuevo) {
    for(int i=0; i<size(); i++){
        nuevo[i] = data[i];
    }
    data = nuevo;
}

template <typename T>
queue<T>::queue(int size) {
    capacity = size;
    pos_front = -1;
    pos_back = -1;
    data = new T[capacity];
}

template <typename T>
void queue<T>::push(T dato){
    if (pos_back >= capacity - 1){
        capacity *= 2;
        T* nuevo = new T[capacity];
        replace(nuevo);
        push(dato);
    } else {
        if(pos_front==-1)
            pos_front=0;

        pos_back++;
        data[pos_back] = dato;
    }
}

template<typename T>
void queue<T>::pop() {
    try {
        if (empty())
            throw ArrayVacio("No existe data");
        else {
            pos_back--;
        }
    }
    catch (const ArrayVacio &e) {
        cerr << "ERROR: " << e.what() << endl;
    }
}

template<typename T>
int queue<T>::front() {
    try {
        if (empty())
            throw ArrayVacio("No existe data");
        else {
            return data[pos_front];
        }
    }
    catch (const ArrayVacio &e) {
        cerr << "ERROR: " << e.what() << endl;
    }
}

template<typename T>
int queue<T>::back() {
    try {
        if (empty())
            throw ArrayVacio("No existe data");
        else {
            return data[pos_back];
        }
    }
    catch (const ArrayVacio &e) {
        cerr << "ERROR: " << e.what() << endl;
    }
}

template<typename T>
int queue<T>::size() {
    return pos_back+1;
}

template<typename T>
bool queue<T>::empty() {
    return pos_back < 0;
}

template<typename T>
queue<T>::~queue() {
    delete [] data;
}

#endif
