#ifndef LISTLINKED_H
#define LISTLINKED_H

#include "List.h"
#include "Node.h"
#include <ostream>
#include <stdexcept>

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first;
    int n;

public:
    ListLinked() {
        first = nullptr;
        n = 0;
    }
    
    ~ListLinked() {
        Node<T>* current = first;
        while (current != nullptr) {
            Node<T>* aux = current->next;
            delete current;
            current = aux;
        }
    }
    
    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Posición fuera de rango");
        }
        
        if (pos == 0) {
            first = new Node<T>(e, first);
        } else {
            Node<T>* current = first;
            for (int i = 0; i < pos - 1; i++) {
                current = current->next;
            }
            current->next = new Node<T>(e, current->next);
        }
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
        
        Node<T>* toDelete;
        T elemento;
        
        if (pos == 0) {
            toDelete = first;
            first = first->next;
            elemento = toDelete->data;
        } else {
            Node<T>* current = first;
            for (int i = 0; i < pos - 1; i++) {
                current = current->next;
            }
            toDelete = current->next;
            current->next = toDelete->next;
            elemento = toDelete->data;
        }
        
        delete toDelete;
        n--;
        return elemento;
    }
    
    T get(int pos) const override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición fuera de rango");
        }
        
        Node<T>* current = first;
        for (int i = 0; i < pos; i++) {
            current = current->next;
        }
        return current->data;
    }
    
    int search(T e) const override {
        Node<T>* current = first;
        int pos = 0;
        while (current != nullptr) {
            if (current->data == e) {
                return pos;
            }
            current = current->next;
            pos++;
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
    friend std::ostream& operator<<(std::ostream& out, const ListLinked<U>& list);
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const ListLinked<T>& list) {
    out << "[";
    Node<T>* current = list.first;
    while (current != nullptr) {
        out << current->data;
        if (current->next != nullptr) {
            out << ", ";
        }
        current = current->next;
    }
    out << "]";
    return out;
}
#endif

