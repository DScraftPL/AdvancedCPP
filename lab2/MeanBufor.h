#pragma once
#include "Bufor.h"
#include <iostream>

class MeanBufor : public Bufor {
  MeanBufor() : Bufor() {}
  MeanBufor(int _rozmiar) : Bufor(_rozmiar) {}
  virtual double calculate() override;
};
