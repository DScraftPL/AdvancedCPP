#include "MeanBufor.h"

double MeanBufor::calculate() {
  double sum = 0;
  for (int i = 0; i < getIndex(); i++) {
    sum += getTab(i);
  }
  return sum / (getIndex() + 1);
}
