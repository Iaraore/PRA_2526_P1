#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
        Node<T>* first; // Puntero al primer nodo
        int n;          // Número de elementos

    public:
        // Constructor
        ListLinked() {
            first = nullptr;
            n = 0;
        }

        // Destructor
        ~ListLinked() override {
            while (first != nullptr) {
                Node<T>* aux = first->next;
                delete first;
                first = aux;
            }
        }

        // Sobrecarga operador []
        T operator[](int pos) {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Posición inválida en operator[]");
            }
            // Recorremos hasta la posición
            Node<T>* aux = first;
            for (int i = 0; i < pos; i++) {
                aux = aux->next;
            }
            return aux->data;
        }

        // Sobrecarga global operador <<
        friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list) {
            out << "[";
            Node<T>* aux = list.first;
            while (aux != nullptr) {
                out << aux->data;
                if (aux->next != nullptr) out << ", ";
                aux = aux->next;
            }
            out << "]";
            return out;
        }

        // --- Implementación de métodos heredados de List<T> ---

        void insert(int pos, T e) override {
            if (pos < 0 || pos > n) {
                throw std::out_of_range("Posición inválida en insert");
            }

            // Caso especial: Insertar al principio (o lista vacía)
            if (pos == 0) {
                // El nuevo nodo apunta a lo que antes era first
                first = new Node<T>(e, first);
            } 
            // Caso general: Insertar en medio o final
            else {
                Node<T>* prev = first;
                // Avanzamos hasta el nodo ANTERIOR a la posición (pos-1)
                for (int i = 0; i < pos - 1; i++) {
                    prev = prev->next;
                }
                // Creamos nodo nuevo que apunte al siguiente del previo
                // Y actualizamos el previo para que apunte al nuevo
                prev->next = new Node<T>(e, prev->next);
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
                throw std::out_of_range("Posición inválida en remove");
            }

            Node<T>* toDelete;
            T dataRemoved;

            // Caso especial: Eliminar el primero
            if (pos == 0) {
                toDelete = first;
                first = first->next;
            } 
            // Caso general: Eliminar en medio o final
            else {
                Node<T>* prev = first;
                for (int i = 0; i < pos - 1; i++) {
                    prev = prev->next;
                }
                toDelete = prev->next;
                prev->next = toDelete->next;
            }

            dataRemoved = toDelete->data;
            delete toDelete;
            n--;
            
            return dataRemoved;
        }

        T get(int pos) override {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Posición inválida en get");
            }
            Node<T>* aux = first;
            for (int i = 0; i < pos; i++) {
                aux = aux->next;
            }
            return aux->data;
        }

        int search(T e) override {
            Node<T>* aux = first;
            int i = 0;
            while (aux != nullptr) {
                if (aux->data == e) {
                    return i;
                }
                aux = aux->next;
                i++;
            }
            return -1;
        }

        bool empty() override {
            return n == 0;
        }

        int size() override {
            return n;
        }
};

#endif

