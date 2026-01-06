#ifndef LISTARRAY_H
#define LISTARRAY_H

#include "List.h"
#include <ostream>
#include <stdexcept>

template <typename T>
class ListArray : public List<T> {
private:
    T* arr;
    int max;
    int n;
    static const int MINSIZE = 2;
    
    void resize(int new_size) {
        T* new_arr = new T[new_size];
        for (int i = 0; i < n; i++) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        max = new_size;
    }

public:
    ListArray() {
        max = MINSIZE;
        arr = new T[max];
        n = 0;
    }
    
    ~ListArray() {
        delete[] arr;
    }
    
    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Posición fuera de rango");
        }
        
        if (n == max) {
            resize(max * 2);
        }
        
        for (int i = n; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        
        arr[pos] = e;
        n++;
    }
    
    void append(T e) override {
        insert(n, e);
    }
    
    void prepend(T e) override {
        insert(0, e);
    }
    
    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición fuera de rango");
        }
        
        T elemento = arr[pos];
        
        for (int i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        
        n--;
        
        if (n <= max / 4 && max / 2 >= MINSIZE) {
            resize(max / 2);
        }
        
        return elemento;
    }
    
    T get(int pos) const override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición fuera de rango");
        }
        return arr[pos];
    }
    
    int search(T e) const override {
        for (int i = 0; i < n; i++) {
            if (arr[i] == e) {
                return i;
            }
        }
        return -1;
    }
    
    bool empty() const override {
        return n == 0;
    }
    
    int size() const override {
        return n;
    }
    
    T operator[](int pos) {
        return get(pos);
    }
    
    template <typename U>
    friend std::ostream& operator<<(std::ostream& out, const ListArray<U>& list);
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const ListArray<T>& list) {
    out << "[";
    for (int i = 0; i < list.n; i++) {
        out << list.arr[i];
        if (i < list.n - 1) {
            out << ", ";
        }
    }
    out << "]";
    return out;
}
#endif

