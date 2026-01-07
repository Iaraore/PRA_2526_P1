#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <ostream>
#include <stdexcept> // Para std::out_of_range
#include "List.h"

template <typename T>
class ListArray : public List<T> {

    private:
        T* arr;             // Puntero al array dinámico
        int max;            // Capacidad actual del array
        int n;              // Número actual de elementos
        static const int MINSIZE = 2; // Tamaño mínimo

        // Estrategia de redimensionado
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
        // Constructor
        ListArray() {
            arr = new T[MINSIZE];
            max = MINSIZE;
            n = 0;
        }

        // Destructor
        ~ListArray() override {
            delete[] arr;
        }

        // Sobrecarga operador []
        T operator[](int pos) {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Posición fuera de rango en operator[]");
            }
            return arr[pos];
        }

        // Sobrecarga global operador <<
        // Se define friend dentro de la clase para acceder a atributos privados si fuera necesario,
        // o simplemente para imprimir usando el formato de lista.
        friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list) {
            out << "[";
            for (int i = 0; i < list.n; i++) {
                out << list.arr[i];
                if (i < list.n - 1) out << ", ";
            }
            out << "]";
            return out;
        }

        // --- Implementación de métodos heredados de List<T> ---

        void insert(int pos, T e) override {
            if (pos < 0 || pos > n) {
                throw std::out_of_range("Posición inválida en insert");
            }
            // Si el array está lleno, duplicamos el tamaño
            if (n == max) {
                resize(max * 2);
            }
            // Desplazamos elementos a la derecha para hacer hueco (mantenimiento de contigüidad)
            for (int i = n; i > pos; i--) {
                arr[i] = arr[i - 1];
            }
            arr[pos] = e;
            n++;
        }

        void append(T e) override {
            insert(n, e); // Inserta al final
        }

        void prepend(T e) override {
            insert(0, e); // Inserta al principio
        }

        T remove(int pos) override {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Posición inválida en remove");
            }
            
            T elementoEliminado = arr[pos];

            // Desplazamos elementos a la izquierda para tapar el hueco (mantenimiento de contigüidad)
            for (int i = pos; i < n - 1; i++) {
                arr[i] = arr[i + 1];
            }
            n--;

            // Si está "demasiado vacío" (ej: usamos menos de 1/4 y es mayor que MINSIZE), reducimos a la mitad
            // Esta lógica evita estar redimensionando constantemente si insertamos/borramos en el límite.
            /* Nota: La lógica exacta de reducción queda a criterio, pero esta es segura */
            if (max > MINSIZE && n < max / 4) {
                resize(max / 2);
            }

            return elementoEliminado;
        }

        T get(int pos) override {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Posición inválida en get");
            }
            return arr[pos];
        }

        int search(T e) override {
            for (int i = 0; i < n; i++) {
                if (arr[i] == e) {
                    return i;
                }
            }
            return -1; // No encontrado
        }

        bool empty() override {
            return n == 0;
        }

        int size() override {
            return n;
        }
};

#endif

