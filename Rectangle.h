#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <stdexcept>
#include <iostream>
#include "Shape.h"
#include "Point2D.h"

class Rectangle : public Shape {
    protected:
        Point2D* vs; // Array de vértices

    private:
        static bool check(Point2D* vertices);

    public:
        static const int N_VERTICES = 4;

        // Constructores
        Rectangle();
        Rectangle(std::string color, Point2D* vertices);
        
        // Constructor de copia (Regla de los 3)
        Rectangle(const Rectangle &r);

        // Destructor (Regla de los 3)
        ~Rectangle();

        // Operador de asignación (Regla de los 3)
        Rectangle& operator=(const Rectangle &r);

        // Getters y Operadores
        Point2D get_vertex(int ind) const;
        Point2D operator[](int ind) const;

        // Modificadores
        virtual void set_vertices(Point2D* vertices);

        // Métodos virtuales de Shape
        double area() const override;
        double perimeter() const override;
        void translate(double incX, double incY) override;
        void print() override;

        // Amiga para impresión
        friend std::ostream& operator<<(std::ostream &out, const Rectangle &r);
};

#endif
