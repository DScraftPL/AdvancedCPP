#pragma once
#include "Warehouse.h"
#include <memory>
#include <string>
#include <vector>

class Shop {
private:
  std::vector<std::shared_ptr<Warehouse>> magazyny;
  std::string nazwa;

public:
  Shop(std::string);
  ~Shop();
  void add(std::shared_ptr<Warehouse>);
  void sell(Towary, int);
  void showWar();
  void showName();
};
