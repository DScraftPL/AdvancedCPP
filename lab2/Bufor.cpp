#include "Bufor.h"

Bufor::Bufor() {
  rozmiar = 10;
  liczby = new int[rozmiar];
  ostatni = 0;
  liczby[ostatni] = 0;
}
//_rozmiar = 10 zrobi to samo?
Bufor::Bufor(int _rozmiar) {
  rozmiar = _rozmiar;
  liczby = new int[rozmiar];
  ostatni = 0;
  liczby[ostatni] = 0;
}
Bufor::~Bufor() { delete[] liczby; }
void Bufor::add(int value) {
  liczby[ostatni] = value;
  ostatni++;
}
