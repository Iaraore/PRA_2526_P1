#include "Circle.h"
#include <iostream>
#include <cmath>

Circle::Circle() : Shape(), center(0, 0), radius(1.0) {}

Circle::Circle(std::string color, Point2D center, double radius) 
    : Shape(color), center(center), radius(radius) {}

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

double Circle::area() const {
    return M_PI * radius * radius;
}

double Circle::perimeter() const {
    return 2 * M_PI * radius;
}

void Circle::translate(double incX, double incY) {
    center.x += incX;
    center.y += incY;
}

void Circle::print() const {
    std::cout << *this;
}

std::ostream& operator<<(std::ostream &out, const Circle &c) {
    out << "Circle(color=" << c.color << ", center=(" << c.center.x << ", " 
        << c.center.y << "), radius=" << c.radius << ")";
    return out;
}

