#include "Shop.h"
#include <iostream>
#include <vector>

using namespace std;

Shop::Shop(string _nazwa) {
  nazwa = _nazwa;
  cout << "Konstruktor Shop" << endl;
}
Shop::~Shop() { cout << "Destuktor Shop" << endl; }
void Shop::add(shared_ptr<Warehouse> w) { magazyny.push_back(w); }
void Shop::sell(Towary towar, int liczba) {
  for (auto &m : magazyny) {
    if (m->getTowar() == towar && m->getLiczba() >= liczba) {
      m->setLiczba(m->getLiczba() - liczba);
      cout << "Sprzedano " << liczba << " sztuk" << endl;
      break;
    }
  }
}
void Shop::showWar() {
  for (auto &m : magazyny) {
    m->show();
  }
}

void Shop::showName() { cout << nazwa << endl; }
