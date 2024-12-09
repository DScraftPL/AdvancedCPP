#pragma once
#include "Buffer.h"

class BufferArr : public Buffer {
private:
  int *tab;
  int rozmiar;
  int last;

public:
  BufferArr(int);
  virtual ~BufferArr();
  int getRozmiar();
  void setRozmiar(int);
  void virtual add(int a) override;
  void virtual write() override;
};
