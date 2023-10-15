#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <stdexcept>
#include <iostream>
#include "Shape.h"
#include "Point2D.h"

class Rectangle: public Shape{
 protected:
  Point2D* vs; //puntero a un ar de 4 el (cada vértice)
 public:
  static int const N_VERTICES = 4;
 private:
  static bool check(Point2D* vertices);
 public:
  double area() const override{
    double base = Point2D::distance(vs[0], vs[1]);
    double altura = Point2D::distance(vs[1], vs[2]);
    return base * altura;
   
  }
  double perimeter() const override{
   double lado1 = Point2D::distance(vs[0], vs[1]);
    double lado2 = Point2D::distance(vs[1], vs[2]);
    return 2 * (lado1 + lado2);
  }
  void translate(double incX, double incY) override{
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i].x += incX;
        vs[i].y += incY;
    }
  }
  void print() override{
    std::cout << "Rectángulo: " << std::endl
              << "Color: " << get_color() << ", "
              << "Vértices: ";
    for (int i = 0; i < N_VERTICES; ++i) {
        std::cout << "(" << vs[i].x << ", " << vs[i].y << ")";
        if (i < N_VERTICES - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

  Rectangle();
  Rectangle(std::string color, Point2D* vertices);
  Rectangle(const Rectangle &r);
  ~Rectangle();
  Point2D get_vertex(int ind) const;
  Point2D operator[](int ind) const;
  virtual void set_vertices (Point2D* vertices);
  Rectangle& operator = (const Rectangle &r);
  friend std::ostream &operator<<(std::ostream &out, const Rectangle &r);
  
};
#endif
