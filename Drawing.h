#ifndef DRAWING_H
#define DRAWING_H

#include <stdexcept>
#include <iostream>
#include "Shape.h"
#include "Point2D.h"
#include "List.h"
#include "Node.h"
#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"
#include "ListArray.h"

class Drawing{
 private:
  List<Shape*>* shapes; //lista de figuras representadas en el dibujo
 public:
  Drawing();
  ~Drawing();
  void add_front(Shape* shapes);
  void add_back(Shape* shapes);
  void print_all();
  double get_area_all_circles();
  void move_squares(double incX, double incY);
};
#endif
