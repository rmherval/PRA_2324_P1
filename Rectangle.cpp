#include <iostream>
#include "Rectangle.h"

bool Rectangle::check(Point2D* vertices){
  bool aristas1 = (Point2D::distance(vertices[0],vertices[1]) == Point2D::distance(vertices[2],vertices[3]));
  bool aristas2 = (Point2D::distance(vertices[1],vertices[2]) == Point2D::distance(vertices[3],vertices[0]));

  return aristas1 && aristas2;
}
Rectangle::Rectangle(){
  vs = new Point2D[N_VERTICES];
  color = "red";
  
  vs[0] = Point2D(-1, 0.5);
  vs[1] = Point2D(1, 0.5);
  vs[2] = Point2D(1, -0.5);
  vs[3] = Point2D(-1, -.5);
}
Rectangle::Rectangle(std::string color, Point2D* vertices){
  set_color(color);
  vs = new Point2D[N_VERTICES];
  if(!check(vertices)){
    throw std::invalid_argument("Los vértices no forman un rectángulo.");
  }
      // Asignar los vértices al array vs
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = vertices[i];
    }
}

Rectangle::Rectangle(const Rectangle &r){
  vs = new Point2D[N_VERTICES];
  /* for(int i=0; i<N_VERTICES; i++){
    r.vs[i] = vs[i];
    }*/
       // Copiar atributos de Shape
    set_color(r.get_color());
    // Copiar atributos específicos de Rectangle
        set_vertices(r.vs);
}
Rectangle::~Rectangle(){
  delete[] vs;
}

Point2D Rectangle::get_vertex(int ind) const{
  if(ind<0 || ind>N_VERTICES-1)
    throw std::out_of_range("Rango inválido");
  else
    return vs[ind];
}

Point2D Rectangle::operator[](int ind) const{
   if(ind<0 || ind>N_VERTICES-1)
    throw std::out_of_range("Rango inválido");
   else
     return vs[ind];
}
void Rectangle::set_vertices (Point2D* vertices){
  if(!check(vertices))
    throw std::invalid_argument("Rectángulo no válido");
  else
       for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = vertices[i];
    }
}
Rectangle& Rectangle::operator = (const Rectangle &r){
     // Copiar atributos de Shape
    set_color(r.get_color());
    // Copiar atributos específicos de Rectangle
        set_vertices(r.vs);

    return *this;
}

std::ostream &operator<<(std::ostream &out, const Rectangle &r){
  /* r.print();//porque con r. ????????????????????????????'
     return out;*/
    out << "Rectangle: " << std::endl
            << "Color: " << r.get_color() << ", "
            << "Vertices: ";
  for (int i = 0; i < r.N_VERTICES; i++) {
    out << "(" << r.vs[i].x << ", " << r.vs[i].y << ")";
    if (i < r.N_VERTICES - 1) out << ", ";
  }
  out << std::endl;
  return out;
}

  
