#ifndef SQUARE_H
#define SQUARE_H

#include <stdexcept>
#include <iostream>
#include "Rectangle.h"

class Square : public Rectangle{
 private:
  static bool check(Point2D* vertices);
 public:
  Square();
  Square(std::string color, Point2D* vertices);
  void set_vertices(Point2D* vertices);
  friend std::ostream& operator<<(std::ostream &out, const Square &square);

  void print() override{
    std::cout << "Cuadrado: " << std::endl
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
};
#endif
