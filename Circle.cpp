// Circle.cpp
#include <iostream>
#include "Circle.h"

// Constructor por defecto
Circle::Circle() {
  color = "red";
  center.x = 0;
  center.y = 0;
  radius= 1.0;
}

// Constructor con argumentos
Circle::Circle(std::string color, Point2D center, double radius) {
  this->color = color;
  this->center= center;
  this->radius = radius;
}

// Getter para el centro
Point2D Circle::get_center() const {
  return center; //si  lo imprimo accede a la función de sobrecarga de Point2D
}

// Setter para el centro
void Circle::set_center(Point2D p) {
    center = p;
}

// Getter para el radio
double Circle::get_radius() const {
    return radius;
}

// Setter para el radio
void Circle::set_radius(double r) {
    radius = r;
}

// Operador de salida
std::ostream& operator<<(std::ostream &out, const Circle &c) {
    out << "Circle: " << std::endl
        << "Color: " << c.get_color() << ", "
        << "Radius: " << c.get_radius() << ", "
        << "Center: (" << c.get_center().x << ", " << c.get_center().y << ")" << std::endl;
    return out;
}
