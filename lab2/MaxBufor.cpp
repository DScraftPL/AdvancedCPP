#include "MaxBufor.h"

double MaxBufor::calculate() {
  double sum = 0;
  for (int i = 0; i < getIndex(); i++) {
    sum += getTab(i);
  }
  return sum / (getIndex() + 1);
}

void MaxBufor::add(int value) {
  // do this
}
