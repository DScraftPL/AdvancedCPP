#pragma once
#include "Employee.h"

class Developer : public Employee {
public:
  float calculateBonus(int value);
  virtual int calculateSalary(int value) override;
  Developer();
  Developer(std::string _surname, int _age, int _experience, float _salary);
};
