#pragma once
#include <iostream>

class Bufor {
private:
  int *liczby;
  int rozmiar;
  int ostatni;

public:
  Bufor();
  Bufor(int _rozmiar);
  virtual ~Bufor();
  virtual void add(int value);
  virtual double calculate() = 0;
  int getIndex() { return ostatni; }
  int getSize() { return rozmiar; }
  int getTab(int i) { return liczby[i]; }
  int getFirst() { return ostatni + 1; }
  void setFirst(int value) {
    liczby[ostatni] = value;
    ostatni++;
  }
  void setTab(int pos, int value) { liczby[pos] = value; }
  void show() {
    for (int i = 0; i < rozmiar; i++) {
      std::cout << liczby[i] << " ";
    }
    std::cout << std::endl;
  }
};
