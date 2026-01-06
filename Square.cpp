#include "Square.h"
#include <iostream>
#include <cmath>
#include <stdexcept>

bool Square::check(Point2D* vertices) {
    if (!vertices) return false;
    
    // Primero verificar que sea un rectángulo válido
    double d01 = Point2D::distance(vertices[0], vertices[1]);
    double d12 = Point2D::distance(vertices[1], vertices[2]);
    double d23 = Point2D::distance(vertices[2], vertices[3]);
    double d30 = Point2D::distance(vertices[3], vertices[0]);
    double d02 = Point2D::distance(vertices[0], vertices[2]);
    double d13 = Point2D::distance(vertices[1], vertices[3]);
    
    const double EPSILON = 1e-9;
    
    bool oppositeSidesEqual = (fabs(d01 - d23) < EPSILON) && (fabs(d12 - d30) < EPSILON);
    bool diagonalsEqual = fabs(d02 - d13) < EPSILON;
    
    if (!oppositeSidesEqual || !diagonalsEqual) {
        return false;
    }
    
    // Para ser cuadrado, todos los lados deben ser iguales
    return fabs(d01 - d12) < EPSILON;
}

Square::Square() : Rectangle() {
    // Rectangle ya crea un cuadrado (lados 2x1), necesitamos ajustar a un cuadrado 2x2
    Point2D* vertices = new Point2D[4];
    vertices[0] = Point2D(-1.0, 1.0);
    vertices[1] = Point2D(1.0, 1.0);
    vertices[2] = Point2D(1.0, -1.0);
    vertices[3] = Point2D(-1.0, -1.0);
    set_vertices(vertices);
    delete[] vertices;
}

Square::Square(std::string color, Point2D* vertices) : Rectangle(color, vertices) {
    if (!vertices || !check(vertices)) {
        throw std::invalid_argument("Vértices no forman un cuadrado válido");
    }
    
    // Ya verificado por el constructor de Rectangle y por check
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = vertices[i];
    }
}

void Square::set_vertices(Point2D* vertices) {
    if (!vertices || !check(vertices)) {
        throw std::invalid_argument("Vértices no forman un cuadrado válido");
    }
    
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = vertices[i];
    }
}

std::ostream& operator<<(std::ostream &out, const Square &square) {
    out << "Square(color=" << square.color << ", vertices=[";
    for (int i = 0; i < Square::N_VERTICES; i++) {
        out << "(" << square.vs[i].x << ", " << square.vs[i].y << ")";
        if (i < Square::N_VERTICES - 1) {
            out << ", ";
        }
    }
    out << "])";
    return out;
}

