#include "Square.h"
#include "Figure.h"
#include <iostream>
using namespace std;
Square::Square(float a1) : Figure() {
  a = a1;
  cout << "Konstruktor klasy Square" << endl;
}
Square::~Square() { cout << "Destruktor klasy Square" << endl; }
void Square::calculateArea() {
  float p = a * a;
  setArea(p);
}
