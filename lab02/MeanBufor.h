#pragma once
#include "Bufor.h"
#include <iostream>

class MeanBufor : public Bufor {
public:
  MeanBufor() : Bufor() {}
  MeanBufor(int _rozmiar) : Bufor(_rozmiar) {}
  virtual double calculate() override;
};
