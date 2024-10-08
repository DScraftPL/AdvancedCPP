#pragma once
#include "Employee.h"
#include <iostream>

class TeamLeader : public Employee {
public:
  float calculateBonus(int value);
  virtual int calculateSalary(int value) override;
  virtual void show() override;
  TeamLeader();
  TeamLeader(std::string _surname, int _age, int _experience, float _salary);
};
