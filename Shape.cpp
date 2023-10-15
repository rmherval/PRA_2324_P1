#include "Shape.h"
#include <iostream>

// Implementación de los constructores
Shape::Shape(){
  color = "rojo";
}


// Implementación del constructor con color especificado
Shape::Shape(std::string color) {
    // Verificar si el color es válido
    if (color == "red" || color == "green" || color == "blue") {
        this->color = color;
    } else {
        // Lanzar una excepción si el color no es válido
        throw std::invalid_argument("Color debe ser 'red', 'green', o 'blue'.");
    }
}

// Implementación de get_color()
std::string Shape::get_color() const {
    return color;
}

// Implementación de set_color()
void Shape::set_color(std::string c) {
    // Verificar si el color es válido antes de modificarlo
    if (c == "red" || c == "green" || c == "blue") {
        color = c;
    } else {
        // Lanzar una excepción si el color no es válido
        throw std::invalid_argument("Color debe ser 'red', 'green', o 'blue'.");
    }
}
