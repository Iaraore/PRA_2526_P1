#include "Drawing.h"
#include "ListArray.h"
#include "Circle.h"
#include "Square.h"

// Constructor: Instanciamos la lista concreta (ListArray)
Drawing::Drawing() {
    shapes = new ListArray<Shape*>();
}

// Destructor: Solo liberamos la memoria de la propia lista 'shapes'.
Drawing::~Drawing() {
    delete shapes;
}

// Añadir al frente (usamos prepend de la lista)
void Drawing::add_front(Shape* shape) {
    shapes->prepend(shape);
}

// Añadir al fondo (usamos append de la lista)
void Drawing::add_back(Shape* shape) {
    shapes->append(shape);
}

// Imprimir todas las figuras
void Drawing::print_all() {
    std::cout << "Drawing contents:" << std::endl;
    for (int i = 0; i < shapes->size(); i++) {
        shapes->get(i)->print();
        std::cout << std::endl;
    }
}

// Calcular área solo de los círculos
double Drawing::get_area_all_circles() {
    double totalArea = 0.0;
    
    for (int i = 0; i < shapes->size(); i++) {
        Shape* s = shapes->get(i);
        // Intentamos convertir la Shape genérica a Circle
        Circle* c = dynamic_cast<Circle*>(s);
        
        if (c != nullptr) {
            // Si c no es nulo, es un círculo. Sumamos su área.
            totalArea += c->area();
        }
    }
    return totalArea;
}

// Mover solo los cuadrados
void Drawing::move_squares(double incX, double incY) {
    for (int i = 0; i < shapes->size(); i++) {
        Shape* s = shapes->get(i);
        // Intentamos convertir la Shape genérica a Square
        Square* sq = dynamic_cast<Square*>(s);
        
        if (sq != nullptr) {
            // Si sq no es nulo, es un cuadrado. Lo movemos.
            sq->translate(incX, incY);
        }
    }
}
