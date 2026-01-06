#include "Shape.h"
#include <algorithm>

bool Shape::isValidColor(const std::string& c) const {
    return (c == "red" || c == "green" || c == "blue");
}

Shape::Shape() : color("red") {}

Shape::Shape(std::string color) {
    if (!isValidColor(color)) {
        throw std::invalid_argument("Color no válido");
    }
    this->color = color;
}

std::string Shape::get_color() const {
    return color;
}

void Shape::set_color(std::string c) {
    if (!isValidColor(c)) {
        throw std::invalid_argument("Color no válido");
    }
    color = c;
}

