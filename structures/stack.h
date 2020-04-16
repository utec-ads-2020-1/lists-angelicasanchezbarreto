#ifndef STACK_H
#define STACK_H

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
class stack {
    T* data;
    int pos_top;
    int capacity;

public:
    stack(int size = MAX);
    ~stack();

    void push(T dato);
    int pop();
    int top();

    int size();
    bool empty();
};

template <typename T>
stack<T>::stack(int size) {
    capacity = size;
    pos_top = -1;
    data = new T[capacity];
}

template <typename T>
void stack<T>::push(T dato){
    try{
        if (pos_top >= capacity - 1)
            throw CapacidadExcedida("Excede la capacidad");
        else {
            data[pos_top + 1] = dato;
            pos_top++;
        }
    }
    catch(const CapacidadExcedida &e) {
        cerr << "ERROR: " << e.what() << endl;
    }
}

template<typename T>
int stack<T>::pop() {
    try {
        if (empty())
            throw ArrayVacio("No existe data");
        else {
            int last = data[pos_top];
            pos_top--;
            return last;
        }
    }
    catch (const ArrayVacio &e) {
        cerr << "ERROR: " << e.what() << endl;
    }
}

template<typename T>
int stack<T>::top() {
    try {
        if (empty())
            throw ArrayVacio("No existe data");
        else {
            int last = data[pos_top];
            return last;
        }
    }
    catch (const ArrayVacio &e) {
        cerr << "ERROR: " << e.what() << endl;
    }
}

template<typename T>
int stack<T>::size() {
    return capacity;
}

template<typename T>
bool stack<T>::empty() {
    return pos_top < 0;
}

template<typename T>
stack<T>::~stack() {
    delete [] data;
}

#endif
