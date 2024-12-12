#ifndef FIGURE_H_INCLUDED
#define FIGURE_H_INCLUDED
class Figure {
private:
  float area;
  float obwod;

public:
  Figure();
  virtual ~Figure();
  float getArea();
  void setArea(float area1);
  virtual void calculateArea() = 0;
  void show();
  virtual void obliczObwod() = 0;
  void setObwod(float _obwod);
};
#endif // FIGURE_H_INCLUDED
