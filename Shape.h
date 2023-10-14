#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include "Point2D.h"

class Shape{
 protected:
  std::string color;

 public:
  Shape();
  Shape(std::string color);
  std::string get_color() const ;
  void set_color(std::string c);
  virtual double area() const = 0;
  virtual double perimeter() const = 0;
  virtual void translate(double incX, double incY)const = 0;
  virtual void print() const = 0;
};
#endif

