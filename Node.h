#ifndef NODE_H
#define NODE_H

#include <ostream>
using namespace std;

template <typename T>
class Node {
    public:
        T data;           // El dato almacenado
        Node<T>* next;    // Puntero al siguiente nodo

        // Constructor
        // 'next' es nullptr por defecto si no se especifica (útil para el último nodo)
        Node(T data, Node<T>* next = nullptr) {
            this->data = data;
            this->next = next;
        }

        // Destructor: No eliminamos 'next' aquí recursivamente, eso lo gestionará la lista.
        ~Node() {}

        // Sobrecarga del operador << para imprimir el nodo individualmente
        friend ostream& operator<<(ostream &out, const Node<T> &node) {
            out << node.data;
            return out;
        }
};

#endif

