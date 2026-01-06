#include "Circle.h"
#include <cmath>

// Constructor por defecto: llama al constructor de Shape() implícitamente (rojo)
Circle::Circle() : Shape() {
    this->center = Point2D(0, 0);
    this->radius = 1.0;
}

// Constructor parametrizado: llama al constructor de Shape(color)
Circle::Circle(std::string color, Point2D center, double radius) : Shape(color) {
    this->center = center;
    this->radius = radius;
}

// Getters y Setters
Point2D Circle::get_center() const {
    return center;
}

void Circle::set_center(Point2D p) {
    center = p;
}

double Circle::get_radius() const {
    return radius;
}

void Circle::set_radius(double r) {
    radius = r;
}

// Métodos virtuales
double Circle::area() const {
    // Área = π * r^2
    return 3.141592 * std::pow(radius, 2);
}

double Circle::perimeter() const {
    // Perímetro = 2 * π * r
    return 2 * 3.141592 * radius;
}

void Circle::translate(double incX, double incY) {
    // Movemos el centro sumando los incrementos
    center.x += incX;
    center.y += incY;
}

void Circle::print() {
    // Reutilizamos el operador << para imprimir por pantalla
    std::cout << *this;
}

// Sobrecarga operador <<
std::ostream& operator<<(std::ostream &out, const Circle &c) {
    out << "[Circle: color = " << c.get_color() 
        << "; center = " << c.center 
        << "; radius = " << c.radius << "]";
    return out;
}
