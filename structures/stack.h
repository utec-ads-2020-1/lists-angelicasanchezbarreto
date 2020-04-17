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


template <typename T>
class stack {
    T* data;
    int pos_top;
    int capacity;

public:
    stack(int size = MAX);
    ~stack();

    void push(T dato);
    void pop();
    int top();

    int size();
    bool empty();

    void replace(T* nuevo);

};

template <typename T>
void stack<T>::replace(T *nuevo) {
    for(int i=0; i<size(); i++){
        nuevo[i] = data[i];
    }
    data = nuevo;
}


template <typename T>
stack<T>::stack(int size) {
    capacity = size;
    pos_top = -1;
    data = new T[capacity];
}

template <typename T>
void stack<T>::push(T dato){
    if (pos_top >= capacity - 1) {
        capacity *= 2;
        T* nuevo = new T[capacity];
        replace(nuevo);
        push(dato);
    }
    else {
        data[pos_top + 1] = dato;
        pos_top++;
    }
}

template<typename T>
void stack<T>::pop() {
    try {
        if (empty())
            throw ArrayVacio("No existe data");
        else {
            pos_top--;
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
    return pos_top+1;
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
