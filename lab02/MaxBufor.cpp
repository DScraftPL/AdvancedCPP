#include "MaxBufor.h"

double MaxBufor::calculate() {
  double sum = 0;
  for (int i = 0; i < getIndex(); i++) {
    sum += getTab(i);
  }
  return sum / (getIndex() + 1);
}

void MaxBufor::add(int value) {
  if (getFirst() >= getSize()) {
    std::cout << "nie ma miejsca w tablicy" << std::endl;
  } else {
    setFirst(value);
    setFirst(getFirst() + 1);
  }
}
