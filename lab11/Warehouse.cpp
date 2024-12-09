#include "Warehouse.h"
#include <iostream>

using namespace std;

Warehouse::Warehouse(Towary _towar, int _liczba) {
  towar = _towar;
  liczbaSztuk = _liczba;
  cout << "Konstruktor Warehouse" << endl;
}

Warehouse::~Warehouse() { cout << "Destruktor Warehouse" << endl; }
Towary Warehouse::getTowar() { return towar; }
int Warehouse::getLiczba() { return liczbaSztuk; }
void Warehouse::setTowar(Towary t) { towar = t; }
void Warehouse::setLiczba(int l) { liczbaSztuk = l; }
void Warehouse::show() {
  switch (towar) {
  case ksiazki:
    cout << "ksiazki, ";
    break;
  case komputery:
    cout << "komputery, ";
    break;
  case lozka:
    cout << "lozka, ";
    break;
  }
  cout << liczbaSztuk << endl;
}
