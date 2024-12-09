#pragma once

class Buffer {
public:
  void virtual add(int a) = 0;
  void virtual write() = 0;
  Buffer();
  virtual ~Buffer();
};
