#pragma once
#include <string>

class Car {
private:
  std::string model;
  int rok;
  int pojemnosc;

public:
  Car(std::string, int, int);
  std::string getMod();
  int getRok();
  int getPoj();
  void setMod(std::string);
  void setRok(int);
  void setPoj(int);
  void show();
};
