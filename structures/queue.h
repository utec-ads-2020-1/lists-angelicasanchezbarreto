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

class CapacidadExcedida: public runtime_error {
public:
    CapacidadExcedida(const char *msg) : runtime_error( msg )
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
    int pop();
    int front();
    int back();

    int size();
    bool empty();
};

template <typename T>
queue<T>::queue(int size) {
    capacity = size;
    pos_front = -1;
    pos_back = -1;
    data = new T[capacity];
}

template <typename T>
void queue<T>::push(T dato){
    try{
        if (pos_back >= capacity - 1)
            throw CapacidadExcedida("Excede la capacidad");
        else {
            if(pos_front==-1)
                pos_front=0;

            pos_back++;
            data[pos_back] = dato;
        }
    }
    catch(const CapacidadExcedida &e) {
        cerr << "ERROR: " << e.what() << endl;
    }
}

template<typename T>
int queue<T>::pop() {
    try {
        if (empty())
            throw ArrayVacio("No existe data");
        else {
            int first = data[pos_front];
            pos_front++;
            pos_back--;
            return first;
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
            int first = data[pos_front];
            return first;
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
            int last = data[pos_back];
            return last;
        }
    }
    catch (const ArrayVacio &e) {
        cerr << "ERROR: " << e.what() << endl;
    }
}

template<typename T>
int queue<T>::size() {
    return capacity;
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
