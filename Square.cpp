#include <iostream>
#include "Square.h"
#include "Rectangle.h"


bool Square::check(Point2D* vertices){
    bool aristas = (Point2D::distance(vertices[0], vertices[1]) == Point2D::distance(vertices[1], vertices[2]) &&
                    Point2D::distance(vertices[1], vertices[2]) == Point2D::distance(vertices[2], vertices[3]) &&
                    Point2D::distance(vertices[2], vertices[3]) == Point2D::distance(vertices[3], vertices[0]));

    return aristas;
}
Square::Square(){
    vs = new Point2D[N_VERTICES];
  color = "red";
  
  vs[0] = Point2D(-1,1);
  vs[1] = Point2D(1,1);
  vs[2] = Point2D(1,-1);
  vs[3] = Point2D(-1,-1);
}
  
Square::Square(std::string color, Point2D* vertices){
    set_color(color);
  vs = new Point2D[N_VERTICES];
  if(!check(vertices)){
    throw std::invalid_argument("Los vértices no forman un cuadrado.");
  }
      // Asignar los vértices al array vs
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = vertices[i];
    }
}
void Square::set_vertices(Point2D* vertices){
    if(!check(vertices))
    throw std::invalid_argument("Cuadrado no válido");
  else
       for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = vertices[i];
    }
}
std::ostream& operator<<(std::ostream &out, const Square &s){
    out << "Square: " << std::endl
            << "Color: " << s.get_color() << ", "
            << "Vertices: ";
  for (int i = 0; i < s.N_VERTICES; i++) {
    out << "(" << s.vs[i].x << ", " << s.vs[i].y << ")";
    if (i < s.N_VERTICES - 1) out << ", ";
  }
  out << std::endl;
  return out;
}
