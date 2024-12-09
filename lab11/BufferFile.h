#pragma once
#include "Buffer.h"
#include <string>

class BufferFile : public Buffer {
private:
  std::string sciezka;

public:
  BufferFile(std::string);
  virtual ~BufferFile();
  void virtual add(int) override;
  void virtual write() override;
};
