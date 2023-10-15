#ifndef _CIRCLE_H
#define _CIRCLE_H

#include <iostream>
#include "Shape.h"

class Circle : public Shape {
 private:
  Point2D center; //centro del círculo
  double radius;

 public:
  double area() const override{
    double pi = 3.141592;
    return pi*radius*radius;
  }
  double perimeter() const override{
       double pi = 3.141592;
       return 2*pi*radius;
  }
  void translate(double incX, double incY) override{
    center.x+=incX;
    center.y+=incY;
  }
  void print() override{
    std::cout << "Circle: "<<std::endl
              << "Color: " << get_color() << ", "
              << "Radius: " << radius << ", "
              << "Center: (" << center.x << ", " << center.y << ")" << std::endl;
}
  Circle();
  Circle(std::string color, Point2D center, double radius);
  Point2D get_center() const;
  void set_center(Point2D p);
  double get_radius() const;
  void set_radius(double r);
  friend std::ostream& operator<<(std::ostream &out, const Circle&c);



  
};
#endif
