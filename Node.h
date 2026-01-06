#ifndef NODE_H
#define NODE_H

#include <ostream>

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
    
    Node(T data, Node<T>* next = nullptr) : data(data), next(next) {}
    
    template <typename U>
    friend std::ostream& operator<<(std::ostream& out, const Node<U>& node);
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Node<T>& node) {
    out << node.data;
    return out;
}
#endif

