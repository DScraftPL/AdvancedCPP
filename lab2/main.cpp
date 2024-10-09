#include "Bufor.h"
#include "Circle.h"
#include "Developer.h"
#include "Employee.h"
#include "Figure.h"
#include "MaxBufor.h"
#include "MeanBufor.h"
#include "Square.h"
#include "TeamLeader.h"

void whoWorkMoreThan5Years(Employee **tablica, int rozmiar) {
  for (int i = 0; i < rozmiar; i++) {
    if (tablica[i]->getExperience() > 5) {
      tablica[i]->show();
    }
  }
}

int howManyEarnLessThanMeanBonus(Employee **tablica, int rozmiar) {
  int suma, srednia, count = 0;
  for (int i = 0; i < rozmiar; i++) {
    suma += tablica[i]->calculateSalary(10);
  }
  srednia = suma / rozmiar;
  for (int i = 0; i < rozmiar; i++) {
    if (tablica[i]->calculateSalary(10) > srednia) {
      count++;
    }
  }
  return count;
}

using namespace std;
int main() {
  Figure *f1 = new Square(4);
  Figure *f2 = new Circle(2);
  f1->calculateArea();
  f1->show();
  f2->calculateArea();
  f2->show();
  delete f1;
  delete f2;
  Employee **tablica;
  tablica = new Employee *[3];
  tablica[0] = new Developer("wiacek1", 6, 6, 100);
  tablica[1] = new Developer("wiacek2", 10, 5, 3000);
  tablica[2] = new TeamLeader("wiacek3", 99, 99, 9999);
  whoWorkMoreThan5Years(tablica, 3);
  std::cout << howManyEarnLessThanMeanBonus(tablica, 3) << std::endl;
  MeanBufor *tab = new MeanBufor(5);
  tab->add(10);
  tab->add(20);
  tab->add(30);
  tab->add(40);
  tab->add(50);
  tab->show();
  cout << tab->calculate() << endl;
  Bufor **pepe = new Bufor *[2];
  pepe[0] = new MaxBufor(2);
  pepe[1] = new MeanBufor(2);
  pepe[0]->add(2);
  pepe[0]->add(4);
  pepe[1]->add(2);
  pepe[1]->add(3);
  pepe[1]->add(4);
  pepe[0]->show();
  cout << pepe[0]->calculate() << endl;
  pepe[1]->show();
  cout << pepe[1]->calculate() << endl;
  return 0;
}
