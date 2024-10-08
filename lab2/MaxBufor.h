#pragma once
#include "Bufor.h"
#include <iostream>

class MaxBufor : public Bufor {
  MaxBufor() : Bufor() {}
  MaxBufor(int _rozmiar) : Bufor(_rozmiar) {}
  virtual double calculate() override;
  virtual void add(int value) override;
};
