#pragma once
#include <string>

enum Towary { ksiazki, komputery, lozka };

class Warehouse {
private:
  Towary towar;
  int liczbaSztuk;

public:
  Warehouse(Towary, int);
  ~Warehouse();
  Towary getTowar();
  int getLiczba();
  void setTowar(Towary);
  void setLiczba(int);
  void show();
};
