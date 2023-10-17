#include <iostream>
#include "Drawing.h"

Drawing::Drawing(){
  shapes = new ListArray<Shape*>;
}
Drawing::~Drawing(){
  delete shapes;
}
void Drawing::add_front(Shape* shape){
  shapes->prepend(shape);
}
void Drawing::add_back(Shape* shape){
  shapes->append(shape);
}
void Drawing::print_all(){
  
  std::cout<<"Información de todas las figuras del dibujo"<<std::endl;
  for(int i=0; i<shapes->size(); i++){
    shapes->get(i)->print();
    
  }
}
double Drawing::get_area_all_circles(){
  double totalArea = 0.0;
  for(int i=0; i<shapes->size(); i++){
    Circle* circle = dynamic_cast<Circle*>(shapes->get(i));//convierto a puntero tipo Circle* si realmente es de ese tipo, devuelve nullptr si no es
    if (circle !=nullptr) {//si es un círculo
     totalArea += circle->area();
   }
  }
  return totalArea;
}

void Drawing::move_squares(double incX, double incY){
  for(int i=0; i<shapes->size(); i++){
    Square* square = dynamic_cast<Square*>(shapes->get(i));
    if(square){ //si es un cuadrado
      square->translate(incX,incY);
    }
  }
}
