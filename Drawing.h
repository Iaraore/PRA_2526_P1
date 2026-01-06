#ifndef DRAWING_H
#define DRAWING_H

#include <iostream>
#include "Shape.h"
#include "List.h" 

class Drawing {
    private:
        List<Shape*>* shapes; // Puntero a una lista de punteros a Shape

    public:
        Drawing();
        ~Drawing();

        void add_front(Shape* shape);
        void add_back(Shape* shape);
        void print_all();
        double get_area_all_circles();
        void move_squares(double incX, double incY);
};

#endif
