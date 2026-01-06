#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <stdexcept>

class Shape {
protected:
    std::string color;

    bool isValidColor(const std::string& c) const;

public:
    Shape();
    Shape(std::string color);
    virtual ~Shape() {}
    
    std::string get_color() const;
    void set_color(std::string c);
    
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void translate(double incX, double incY) = 0;
    virtual void print() const = 0;
};

#endif
