#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED
#include "Figure.h"

class Circle : public Figure {
private:
  float r;

public:
  Circle(float r1);
  ~Circle();
  virtual void calculateArea() override;
  virtual void obliczObwod() override;
};
#endif // CIRCLE_H_INCLUDED
